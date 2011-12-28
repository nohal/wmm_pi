/******************************************************************************
 * $Id: wmm_pi.h,v 1.0 2011/02/26 01:54:37 nohal Exp $
 *
 * Project:  OpenCPN
 * Purpose:  WMM Plugin
 * Author:   Pavel Kalian
 *
 ***************************************************************************
 *   Copyright (C) 2011 by Pavel Kalian   *
 *   $EMAIL$   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************
 */

#ifndef _WMMPI_H_
#define _WMMPI_H_

#include "wx/wxprec.h"

#ifndef  WX_PRECOMP
  #include "wx/wx.h"
#endif //precompiled headers

#include <wx/fileconf.h>

#define     PLUGIN_VERSION_MAJOR    0
#define     PLUGIN_VERSION_MINOR    4

#define     MY_API_VERSION_MAJOR    1
#define     MY_API_VERSION_MINOR    6

#include "../../../include/ocpn_plugin.h"

#include "WMMHeader.h"
#include "WMM_SubLibrary.c"
#include "WmmUIDialog.h"
#include "WMM_COF.h"

#include "jsonwriter.h"

//----------------------------------------------------------------------------------------------------------
//    The PlugIn Class Definition
//----------------------------------------------------------------------------------------------------------

#define WMM_TOOL_POSITION    -1          // Request default positioning of toolbar tool

class wmm_pi : public opencpn_plugin
{
public:
      wmm_pi(void *ppimgr);

//    The required PlugIn Methods
      int Init(void);
      bool DeInit(void);

      int GetAPIVersionMajor();
      int GetAPIVersionMinor();
      int GetPlugInVersionMajor();
      int GetPlugInVersionMinor();
      wxBitmap *GetPlugInBitmap();
      wxString GetCommonName();
      wxString GetShortDescription();
      wxString GetLongDescription();

//    The required override PlugIn Methods
      void SetCursorLatLon(double lat, double lon);
      void SetPositionFix(PlugIn_Position_Fix &pfix);

      int GetToolbarToolCount(void);
      void ShowPreferencesDialog( wxWindow* parent );

      void OnToolbarToolCallback(int id);

//    Optional plugin overrides
      void SetColorScheme(PI_ColorScheme cs);
      void SetPluginMessage(wxString message_id, wxString message_body);
      

//    Other public methods
      void SetWmmDialogX    (int x){ m_wmm_dialog_x = x;};
      void SetWmmDialogY    (int x){ m_wmm_dialog_y = x;}

      void OnWmmDialogClose();

//    WMM Declarations
      WMMtype_MagneticModel *MagneticModel, *TimedMagneticModel;
      WMMtype_Ellipsoid Ellip;
      WMMtype_CoordSpherical CoordSpherical;
	WMMtype_CoordGeodetic CoordGeodetic;
	WMMtype_Date UserDate;
	WMMtype_GeoMagneticElements GeoMagneticElements;
	WMMtype_Geoid Geoid;
	wxString filename;

private:
      wxFileConfig     *m_pconfig;
      wxWindow         *m_parent_window;
      bool              LoadConfig(void);
      bool              SaveConfig(void);

      WmmUIDialog      *m_pWmmDialog;

      int               m_wmm_dialog_x, m_wmm_dialog_y;
      int               m_display_width, m_display_height;
      int               m_iViewType;
      bool              m_bShowAtCursor;
      int               m_iOpacity;

      int               m_leftclick_tool_id;

      wxString          AngleToText(double angle);

      void              RearangeWindow();
      wxString          m_wmm_dir;
      bool              m_buseable, m_busegeoid;

      void              SendBoatVariation();
      void              SendCursorVariation();

      WMMtype_GeoMagneticElements m_cursorVariation;
      WMMtype_GeoMagneticElements m_boatVariation;
};

int WMM_setupMagneticModel(char *data, WMMtype_MagneticModel * MagneticModel);

#endif
