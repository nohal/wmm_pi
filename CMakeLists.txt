##---------------------------------------------------------------------------
## Author:      nohal aka. Pavel Kalian
## Copyright:   
## License:     wxWidgets License
##---------------------------------------------------------------------------
 
# define minimum cmake version
CMAKE_MINIMUM_REQUIRED(VERSION 2.6.2)

PROJECT(wmm_pi)

SET(PACKAGE_NAME wmm_pi)
SET(CPACK_PACKAGE_CONTACT "Pavel Kalian")
MESSAGE (STATUS "*** Building ${PACKAGE_NAME} ***")

SET(VERSION_MAJOR "0")
SET(VERSION_MINOR "6")

#SET(CMAKE_BUILD_TYPE Debug)

INCLUDE("cmake/PluginConfigure.cmake")

SET(SRC_WMM
            src/wmm_pi.h
            src/wmm_pi.cpp
            src/MagneticPlotMap.h
            src/MagneticPlotMap.cpp
            src/icons.h
            src/icons.cpp
	    src/WMMHeader.h
	    src/WMM_SubLibrary.c
	    src/WmmUIDialog.h
	    src/WmmUIDialog.cpp
	    src/WMM_COF.h
	    src/json_defs.h
	    src/jsonreader.h
	    src/jsonval.h
	    src/jsonwriter.h
	    src/jsonreader.cpp
	    src/jsonval.cpp
	    src/jsonwriter.cpp
	)
ADD_LIBRARY(${PACKAGE_NAME} SHARED ${SRC_WMM})

INCLUDE("cmake/PluginInstall.cmake")
INCLUDE("cmake/PluginLocalization.cmake")
INCLUDE("cmake/PluginPackage.cmake")
