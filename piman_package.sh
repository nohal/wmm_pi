#!/bin/bash
# Script to create a PluginManifest skeleton and package the common data and the platform specific data for the current platform
# (c) 2014 - Pavel Kalian
# Licensed under GPLv2
# TODO:
#    We currently assume that a plug-in has just the localizations and exactly one platform-specific component etc. Allow for more data files, more post-install actions, etc.


PI="wmm_pi"
VERSION_MAJOR="0"
VERSION_MINOR="8"
API_MAJOR="1"
API_MINOR="8"
VERBOSE_NAME="World Magnetic Model"
DESCRITPION="The plugin providing the data from the NOAA World Magnetic Model. \
The data provided can be used on systems not having the deviation available from instruments. \
Plotting allows users to cross reference the magnetic deviation values printed on many raster charts."
AUTHOR="Pavel Kalian"
HOMEPAGE="https://github.com/nohal"
#RELEASE_DATE="2014-01-01T00:00:00.0" 	#If not set, current timestamp will be used
POSTINSTALL_MSG="" 						#Here you can fill a post-install message for all the platforms
PLATFORM_POSTINSTALL_MSG="" 			#Here you can fill a post-install message for the current platform
POSTINSTALL_ACTION="" 					#Here you can define the post-install action to be executed on the current platform

TARGET_BASE_URL="http://www.kalian.cz/plugins/${PI}/"
ICON_URL=${TARGET_BASE_URL}icon.png
SHOT_URL=${TARGET_BASE_URL}screenshot.png

PLATFORM_FILES=( build/lib${PI}.so )

OUTPUT_PATH="."

### Should not need to change anything past this point
MO_PATH="build"
WRK_PATH="/tmp/${PI}"

if [ -x ${RELEASE_DATE} ]; then
  RELEASE_DATE=$(date +%Y-%m-%dT%H:%M:%S.0)
fi

if [ -d "${WRK_PATH}" ]; then
  rm -rf ${WRK_PATH}/*}
else
  mkdir -p ${WRK_PATH}
fi

#Detect platform
if [[ "$OSTYPE" == "linux-gnu" ]]; then
  PLATFORM=$(uname -m)
  if [[ "$PLATFORM" == "x86_64" ]]; then
  	OS="Linux64"
  elif [[ "$PLATFORM" == i*86 ]]; then
  	OS="Linux32"
  else
  	OS="LinuxArmHf"
  fi
elif [[ "$OSTYPE" == "darwin"* ]]; then
  OS='Mac'
elif [[ "$OSTYPE" == "cygwin" ]]; then
  OS='Windows'
elif [[ "$OSTYPE" == "win32" ]]; then
  OS='Windows'
else
  OS='Unknown'
fi

#Create archive with all locales (they must be already built into .mo files)
TMP_LOCALE_PATH="${WRK_PATH}/locale"
mkdir -p "${WRK_PATH}/locale"
FILES="${MO_PATH}/*.mo"
LANGS="en"
for f in $FILES
do
  LANG=`echo ${f} | cut -d. -f 1 | sed -e "s|${MO_PATH}/||g"`
  d="${TMP_LOCALE_PATH}/${LANG}/LC_MESSAGES"
  mkdir -p "$d"
  cp "$f" "${d}/opencpn-${PI}.mo"
  LANGS=`echo "${LANGS} ${LANG}"`
done

if [ -f "${OUTPUT_PATH}/locale.tar" ]; then
  rm "${OUTPUT_PATH}/locale.tar"
fi
if [ -f "${OUTPUT_PATH}/locale.tar.xz" ]; then
  rm "${OUTPUT_PATH}/locale.tar.xz"
fi
tar -C "${WRK_PATH}" -cf "${OUTPUT_PATH}/locale.tar" locale
xz "${OUTPUT_PATH}/locale.tar"
rm -rf "${TMP_LOCALE_PATH}"
LOCALE_CRC=$(md5sum "${OUTPUT_PATH}/locale.tar.xz" | cut -d' ' -f 1)
LOCALE_SIZE=$(stat -c%s "${OUTPUT_PATH}/locale.tar.xz")
LOCALE_URL="${TARGET_BASE_URL}locale.tar.xz"
echo "Locales stored in ${OUTPUT_PATH}/locale.tar.xz"

#Create archive with platform dependent files
for f in $PLATFORM_FILES
do
	cp "${f}" "${WRK_PATH}"
done
strip ${WRK_PATH}/*.so
if [ -f "${OUTPUT_PATH}/${PI}-${OS}.tar" ]; then
  rm "${OUTPUT_PATH}/${PI}-${OS}.tar"
fi
if [ -f "${OUTPUT_PATH}/${PI}-${OS}.tar.xz" ]; then
  rm "${OUTPUT_PATH}/${PI}-${OS}.tar.xz"
fi
tar -C "${WRK_PATH}" -cf "${OUTPUT_PATH}/${PI}-${OS}.tar" .
xz "${OUTPUT_PATH}/${PI}-${OS}.tar"
PLUGIN_CRC=$(md5sum "${OUTPUT_PATH}/${PI}-${OS}.tar.xz" | cut -d' ' -f 1)
PLUGIN_SIZE=$(stat -c%s "${OUTPUT_PATH}/${PI}-${OS}.tar.xz")
PLUGIN_URL="${TARGET_BASE_URL}${PI}-${OS}.tar.xz"
echo "Binaries stored in ${OUTPUT_PATH}/${PI}-${OS}.tar.xz"

rm -rf "${WRK_PATH}"
#Create manifest...
MAN="${OUTPUT_PATH}/${PI}.xml"
#The header
echo "Creating manifest ${MAN}..."
echo '<?xml version="1.0" encoding="UTF-8"?>' > ${MAN}
echo '<PluginManifest xmlns="http://www.opencpn.org/pluginmanager/OpenCPNPluginManager/PluginManifest"' >> ${MAN}
echo ' xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"' >> ${MAN}
echo ' xsi:schemaLocation="http://www.opencpn.org/pluginmanager/OpenCPNPluginManager/PluginManifest OpenCPNPluginManager.PluginManifest.xsd"' >> ${MAN}
echo ' Version="1"' >> ${MAN}
echo " Name=\"${PI}\"" >> ${MAN}
echo " IconUrl=\"${ICON_URL}\"" >> ${MAN}
echo " ScreenshotUrl=\"${SHOT_URL}\"" >> ${MAN}
echo " HomepageUrl=\"${HOMEPAGE}\"" >> ${MAN}
echo " Author=\"${AUTHOR}\"" >> ${MAN}
echo " ReleaseDate=\"${RELEASE_DATE}\"" >> ${MAN}
echo " VersionMajor=\"${VERSION_MAJOR}\"" >> ${MAN}
echo " VersionMinor=\"${VERSION_MINOR}\"" >> ${MAN}
echo " APILevelMajor=\"${API_MAJOR}\"" >> ${MAN}
echo " APILevelMinor=\"${API_MINOR}\">" >> ${MAN}
echo "    <PluginName>${VERBOSE_NAME}</PluginName>" >> ${MAN}
echo "    <Description>${DESCRITPION}</Description>" >> ${MAN}
#Locale data
echo "    <CommonData Url=\"${LOCALE_URL}\" Size=\"${LOCALE_SIZE}\" Checksum=\"${LOCALE_CRC}\" Type=\"Required\">" >> ${MAN}
echo "        <PostInstallMessage>The plugin is available in the follofing languages: ${LANGS}</PostInstallMessage>" >> ${MAN}
if [ ! -z "${POSTINSTALL_MSG}" ]; then
echo "        <PostInstallMessage>${POSTINSTALL_MSG}</PostInstallMessage>" >> ${MAN}
fi
echo "    </CommonData>" >> ${MAN}
#Plug-in binary for current platform
echo "    <PlatformData Platform=\"${OS}\" Url=\"${PLUGIN_URL}\" Size=\"${PLUGIN_SIZE}\" Checksum=\"${PLUGIN_CRC}\" Type=\"Required\">" >> ${MAN}
if [ ! -z "${PLATFORM_POSTINSTALL_MSG}" ]; then
echo "        <PostInstallMessage>${PLATFORM_POSTINSTALL_MSG}</PostInstallMessage>" >> ${MAN}
fi
if [ ! -z "${POSTINSTALL_ACTION}" ]; then
echo "        <PostInstallAction>${POSTINSTALL_ACTION}</PostInstallAction>" >> ${MAN}
fi
echo "    </PlatformData>" >> ${MAN}
#The footer
echo "</PluginManifest>" >> ${MAN}

echo "DONE, do not forget to add it to the manifest list with something like:"
echo "   <Manifest Url=\"${TARGET_BASE_URL}${PI}.xml\" Name=\"${PI}\" />"