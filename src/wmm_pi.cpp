/******************************************************************************
 * $Id: wmm_pi.cpp,v 1.0 2011/02/26 01:54:37 nohal Exp $
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


#include "wx/wxprec.h"

#ifndef  WX_PRECOMP
  #include "wx/wx.h"
#endif //precompiled headers

#include "wmm_pi.h"


// the class factories, used to create and destroy instances of the PlugIn

extern "C" DECL_EXP opencpn_plugin* create_pi(void *ppimgr)
{
    return new wmm_pi(ppimgr);
}

extern "C" DECL_EXP void destroy_pi(opencpn_plugin* p)
{
    delete p;
}

//---------------------------------------------------------------------------------------------------------
//
//    WMM PlugIn Implementation
//
//---------------------------------------------------------------------------------------------------------

#include "icons.h"

//---------------------------------------------------------------------------------------------------------
//
//          PlugIn initialization and de-init
//
//---------------------------------------------------------------------------------------------------------

wmm_pi::wmm_pi(void *ppimgr)
      :opencpn_plugin(ppimgr)
{
      // Create the PlugIn icons
      initialize_images();
}

int wmm_pi::Init(void)
{
      AddLocaleCatalog( _T("opencpn-wmm_pi") );

      // Set some default private member parameters
      m_wmm_dialog_x = 0;
      m_wmm_dialog_y = 0;

      ::wxDisplaySize(&m_display_width, &m_display_height);

      //    Get a pointer to the opencpn display canvas, to use as a parent for the POI Manager dialog
      m_parent_window = GetOCPNCanvasWindow();

      //    Get a pointer to the opencpn configuration object
      m_pconfig = GetOCPNConfigObject();

      //    And load the configuration items
      LoadConfig();

      m_buseable = true;

      //    WMM initialization
      /* Memory allocation */
	int NumTerms = ( ( WMM_MAX_MODEL_DEGREES + 1 ) * ( WMM_MAX_MODEL_DEGREES + 2 ) / 2 );    /* WMM_MAX_MODEL_DEGREES is defined in WMM_Header.h */

	MagneticModel 	  = WMM_AllocateModelMemory(NumTerms);  /* For storing the WMM Model parameters */
	TimedMagneticModel  = WMM_AllocateModelMemory(NumTerms);  /* For storing the time modified WMM Model parameters */
	if(MagneticModel == NULL || TimedMagneticModel == NULL)
	{
		//WMM_Error(2); Nohal - We don't want the printf's
            wxLogMessage(_T("WMM initialization error"));
            m_buseable = false;
	}

	WMM_SetDefaults(&Ellip, MagneticModel, &Geoid); /* Set default values and constants */
	/* Check for Geographic Poles */
	//WMM_readMagneticModel_Large(filename, MagneticModel); //Uncomment this line when using the 740 model, and comment out the  WMM_readMagneticModel line.

      filename = m_wmm_dir + _T("/WMM.COF");
      char cstring[1024];
      strncpy(cstring, (const char*)filename.mb_str(wxConvUTF8), 1023);
      if (0 == WMM_readMagneticModel(cstring, MagneticModel))
      {
            wxLogMessage(wxString::Format(_T("Warning: WMM model data file %s can't be loaded, using the bundled data."), filename.c_str()));
            WMM_setupMagneticModel(wmm_cof_data, MagneticModel);
      }

 //     filename = m_wmm_dir + _T("/EGM9615.BIN");
 //     strncpy(geoiddatapath, (const char*)filename.mb_str(wxConvUTF8), 1023);
 //     if (FALSE == WMM_InitializeGeoid(&Geoid))    /* Read the Geoid file */
 //     {
 //           wxLogMessage(wxString::Format(_T("Warning: WMM model data file %s can't be loaded. Switching off the geoid calculations. The accuracy will be reduced"), filename.c_str()));
 //           m_busegeoid = false;
 //     }
	//WMM_GeomagIntroduction(MagneticModel);  /* Print out the WMM introduction */

      //    This PlugIn needs a toolbar icon, so request its insertion
      m_leftclick_tool_id  = InsertPlugInTool(_T(""), _img_wmm, _img_wmm, wxITEM_NORMAL,
            _("WMM"), _T(""), NULL,
             WMM_TOOL_POSITION, 0, this);

      m_pWmmDialog = NULL;

      return (WANTS_CURSOR_LATLON       |
              WANTS_TOOLBAR_CALLBACK    |
              INSTALLS_TOOLBAR_TOOL     |
	        WANTS_NMEA_EVENTS         |
              WANTS_PREFERENCES         |
              WANTS_CONFIG
           );
}

bool wmm_pi::DeInit(void)
{
      //    Record the dialog position
      if (NULL != m_pWmmDialog)
      {
            wxPoint p = m_pWmmDialog->GetPosition();
            SetWmmDialogX(p.x);
            SetWmmDialogY(p.y);

            m_pWmmDialog->Close();
            delete m_pWmmDialog;
            m_pWmmDialog = NULL;
      }
      SaveConfig();
      WMM_FreeMagneticModelMemory(MagneticModel);
      WMM_FreeMagneticModelMemory(TimedMagneticModel);

      /*if (Geoid.GeoidHeightBuffer)
      {
            free(Geoid.GeoidHeightBuffer);
            Geoid.GeoidHeightBuffer = NULL;
      }*/
      return true;
}

int wmm_pi::GetAPIVersionMajor()
{
      return MY_API_VERSION_MAJOR;
}

int wmm_pi::GetAPIVersionMinor()
{
      return MY_API_VERSION_MINOR;
}

int wmm_pi::GetPlugInVersionMajor()
{
      return PLUGIN_VERSION_MAJOR;
}

int wmm_pi::GetPlugInVersionMinor()
{
      return PLUGIN_VERSION_MINOR;
}

wxBitmap *wmm_pi::GetPlugInBitmap()
{
      return _img_wmm_pi;
}

wxString wmm_pi::GetCommonName()
{
      return _("WMM");
}


wxString wmm_pi::GetShortDescription()
{
      return _("World Magnetic Model PlugIn for OpenCPN");
}

wxString wmm_pi::GetLongDescription()
{
      return _("World Magnetic Model PlugIn for OpenCPN\n\
Implements the NOAA World Magnetic Model\n\
More information: http://www.ngdc.noaa.gov/geomag/WMM/\n\
The bundled WMM2010 model expires on December 31, 2014.\n\
After then, if new version of the plugin will not be released\n\
in time, get a new WMM.COF from NOAA and place it to the\n\
location you can find in the OpenCPN logfile.");
}


int wmm_pi::GetToolbarToolCount(void)
{
      return 1;
}

void wmm_pi::SetColorScheme(PI_ColorScheme cs)
{
      if (NULL == m_pWmmDialog)
            return;

      wxColour cl;
      GetGlobalColor(_T("DILG1"), &cl);
      m_pWmmDialog->SetBackgroundColour(cl);

      GetGlobalColor(_T("DILG2"), &cl);
      m_pWmmDialog->m_tbD->SetBackgroundColour(cl);
      m_pWmmDialog->m_tbF->SetBackgroundColour(cl);
      m_pWmmDialog->m_tbH->SetBackgroundColour(cl);
      m_pWmmDialog->m_tbI->SetBackgroundColour(cl);
      m_pWmmDialog->m_tbX->SetBackgroundColour(cl);
      m_pWmmDialog->m_tbY->SetBackgroundColour(cl);
      m_pWmmDialog->m_tbZ->SetBackgroundColour(cl);
      m_pWmmDialog->m_tcD->SetBackgroundColour(cl);
      m_pWmmDialog->m_tcF->SetBackgroundColour(cl);
      m_pWmmDialog->m_tcH->SetBackgroundColour(cl);
      m_pWmmDialog->m_tcI->SetBackgroundColour(cl);
      m_pWmmDialog->m_tcX->SetBackgroundColour(cl);
      m_pWmmDialog->m_tcY->SetBackgroundColour(cl);
      m_pWmmDialog->m_tcZ->SetBackgroundColour(cl);

      m_pWmmDialog->Refresh(false);
}

void wmm_pi::RearangeWindow()
{
      if (NULL == m_pWmmDialog)
            return;
      if (m_iViewType == 1)
      {
            m_pWmmDialog->sbScursor->Hide(m_pWmmDialog->gScursor, true);
            m_pWmmDialog->sbSboat->Hide(m_pWmmDialog->gSboat, true);
      }
      else
      {
            m_pWmmDialog->sbScursor->Show(m_pWmmDialog->gScursor, true, true);
            m_pWmmDialog->sbSboat->Show(m_pWmmDialog->gSboat, true, true);
      }

      if (!m_bShowAtCursor)
      {
            m_pWmmDialog->bSframe->Hide(m_pWmmDialog->sbScursor, true);
      }
      else
      {
            m_pWmmDialog->bSframe->Show(m_pWmmDialog->sbScursor, true, true);
            if (m_iViewType == 1)
                  m_pWmmDialog->sbScursor->Hide(m_pWmmDialog->gScursor, true);
      }

      SetColorScheme(PI_ColorScheme());

      m_pWmmDialog->Fit();

      if (m_pWmmDialog->CanSetTransparent())
            m_pWmmDialog->SetTransparent(m_iOpacity);
}

void wmm_pi::OnToolbarToolCallback(int id)
{
      if(NULL == m_pWmmDialog)
      {
            m_pWmmDialog = new WmmUIDialog(m_parent_window);
            m_pWmmDialog->Move(wxPoint(m_wmm_dialog_x, m_wmm_dialog_y));
      }

      RearangeWindow();
      /*m_pWmmDialog->SetMaxSize(m_pWmmDialog->GetSize());
      m_pWmmDialog->SetMinSize(m_pWmmDialog->GetSize());*/
      m_pWmmDialog->Show(!m_pWmmDialog->IsShown());
}

void wmm_pi::SetCursorLatLon(double lat, double lon)
{
      if (!m_bShowAtCursor)
            return; //We don't want to waste CPU cycles that much...
      if (lat < -90 || lat > 90 || lon < -180 || lon > 180 || NULL == m_pWmmDialog || !m_pWmmDialog->IsShown())
            return;
      if (!m_buseable)
      {
            m_pWmmDialog->m_tbD->SetValue(_("Error, see log."));
            return;
      }
      CoordGeodetic.lambda = lon;
      CoordGeodetic.phi = lat;
      CoordGeodetic.HeightAboveEllipsoid = 0;
      CoordGeodetic.HeightAboveGeoid = 0;
      CoordGeodetic.UseGeoid = 0;
      UserDate.Year = wxDateTime::GetCurrentYear();
      UserDate.Month = wxDateTime::GetCurrentMonth() + 1; //WHY is it 0 based????????
      UserDate.Day = wxDateTime::Now().GetDay();
      char err[255];
      WMM_DateToYear(&UserDate, err);
      WMM_GeodeticToSpherical(Ellip, CoordGeodetic, &CoordSpherical);    /*Convert from geodeitic to Spherical Equations: 17-18, WMM Technical report*/
      WMM_TimelyModifyMagneticModel(UserDate, MagneticModel, TimedMagneticModel); /* Time adjust the coefficients, Equation 19, WMM Technical report */
      WMM_Geomag(Ellip, CoordSpherical, CoordGeodetic, TimedMagneticModel, &GeoMagneticElements);   /* Computes the geoMagnetic field elements and their time change*/
      WMM_CalculateGridVariation(CoordGeodetic,&GeoMagneticElements);
      //WMM_PrintUserData(GeoMagneticElements,CoordGeodetic, UserDate, TimedMagneticModel, &Geoid);     /* Print the results */
      m_pWmmDialog->m_tcF->SetValue(wxString::Format(_("%-9.1lf nT"), GeoMagneticElements.F));
      m_pWmmDialog->m_tcH->SetValue(wxString::Format(_("%-9.1lf nT"), GeoMagneticElements.H));
      m_pWmmDialog->m_tcX->SetValue(wxString::Format(_("%-9.1lf nT"), GeoMagneticElements.X));
      m_pWmmDialog->m_tcY->SetValue(wxString::Format(_("%-9.1lf nT"), GeoMagneticElements.Y));
      m_pWmmDialog->m_tcZ->SetValue(wxString::Format(_("%-9.1lf nT"), GeoMagneticElements.Z));
      m_pWmmDialog->m_tcD->SetValue(wxString::Format(_("%-5.1lf\u00B0 (%s)"), GeoMagneticElements.Decl, AngleToText(GeoMagneticElements.Decl).c_str()));
      m_pWmmDialog->m_tcI->SetValue(wxString::Format(_("%-5.1lf\u00B0"), GeoMagneticElements.Incl));
}

void wmm_pi::SetPositionFix(PlugIn_Position_Fix &pfix)
{
      if (NULL == m_pWmmDialog || !m_pWmmDialog->IsShown())
            return;
      if (!m_buseable)
      {
            m_pWmmDialog->m_tbD->SetValue(_("Error, see log."));
            return;
      }
      CoordGeodetic.lambda = pfix.Lon;
      CoordGeodetic.phi = pfix.Lat;
      CoordGeodetic.HeightAboveEllipsoid = 0;
      CoordGeodetic.UseGeoid = 0;
      UserDate.Year = wxDateTime::GetCurrentYear();
      UserDate.Month = wxDateTime::GetCurrentMonth() + 1; //WHY is it 0 based????????
      UserDate.Day = wxDateTime::Now().GetDay();
      char err[255];
      WMM_DateToYear(&UserDate, err);
      WMM_GeodeticToSpherical(Ellip, CoordGeodetic, &CoordSpherical);    /*Convert from geodeitic to Spherical Equations: 17-18, WMM Technical report*/
      WMM_TimelyModifyMagneticModel(UserDate, MagneticModel, TimedMagneticModel); /* Time adjust the coefficients, Equation 19, WMM Technical report */
      WMM_Geomag(Ellip, CoordSpherical, CoordGeodetic, TimedMagneticModel, &GeoMagneticElements);   /* Computes the geoMagnetic field elements and their time change*/
      WMM_CalculateGridVariation(CoordGeodetic,&GeoMagneticElements);
      //WMM_PrintUserData(GeoMagneticElements,CoordGeodetic, UserDate, TimedMagneticModel, &Geoid);     /* Print the results */
      m_pWmmDialog->m_tbF->SetValue(wxString::Format(_("%-9.1lf nT"), GeoMagneticElements.F));
      m_pWmmDialog->m_tbH->SetValue(wxString::Format(_("%-9.1lf nT"), GeoMagneticElements.H));
      m_pWmmDialog->m_tbX->SetValue(wxString::Format(_("%-9.1lf nT"), GeoMagneticElements.X));
      m_pWmmDialog->m_tbY->SetValue(wxString::Format(_("%-9.1lf nT"), GeoMagneticElements.Y));
      m_pWmmDialog->m_tbZ->SetValue(wxString::Format(_("%-9.1lf nT"), GeoMagneticElements.Z));
      m_pWmmDialog->m_tbD->SetValue(wxString::Format(_T("%-5.1lf\u00B0 (%s)"), GeoMagneticElements.Decl, AngleToText(GeoMagneticElements.Decl).c_str()));
      m_pWmmDialog->m_tbI->SetValue(wxString::Format(_T("%-5.1lf\u00B0"), GeoMagneticElements.Incl));
}

wxString wmm_pi::AngleToText(double angle)
{
      int deg = abs(angle);
      int min = (fabs(angle) - deg) * 60;
      if (angle < 0)
            return wxString::Format(_("%u\u00B0%u' W"), deg, min);
      else
            return wxString::Format(_("%u\u00B0%u' E"), deg, min);
}

bool wmm_pi::LoadConfig(void)
{
      wxFileConfig *pConf = (wxFileConfig *)m_pconfig;

      if(pConf)
      {
            pConf->SetPath ( _T( "/Settings/WMM" ) );
            pConf->Read ( _T( "ViewType" ),  &m_iViewType, 1 );
            pConf->Read ( _T( "ShowAtCursor" ),  &m_bShowAtCursor, 1 );
            pConf->Read ( _T( "Opacity" ),  &m_iOpacity, 255 );

            m_wmm_dialog_x =  pConf->Read ( _T ( "DialogPosX" ), 20L );
            m_wmm_dialog_y =  pConf->Read ( _T ( "DialogPosY" ), 20L );

            if((m_wmm_dialog_x < 0) || (m_wmm_dialog_x > m_display_width))
                  m_wmm_dialog_x = 5;
            if((m_wmm_dialog_y < 0) || (m_wmm_dialog_y > m_display_height))
                  m_wmm_dialog_y = 5;
            pConf->SetPath ( _T ( "/Directories" ) );
            wxString def;
            def = ::wxGetCwd() + _T("/plugins");
            pConf->Read ( _T ( "WMMDataLocation" ), &m_wmm_dir, def);
            return true;
      }
      else
            return false;
}

bool wmm_pi::SaveConfig(void)
{
      wxFileConfig *pConf = (wxFileConfig *)m_pconfig;

      if(pConf)
      {
            pConf->SetPath ( _T ( "/Settings/WMM" ) );
            pConf->Write ( _T ( "ViewType" ), m_iViewType );
            pConf->Write ( _T ( "ShowAtCursor" ), m_bShowAtCursor );
            pConf->Write ( _T ( "Opacity" ), m_iOpacity );

            pConf->Write ( _T ( "DialogPosX" ),   m_wmm_dialog_x );
            pConf->Write ( _T ( "DialogPosY" ),   m_wmm_dialog_y );
            pConf->SetPath ( _T ( "/Directories" ) );
            pConf->Write ( _T ( "WMMDataLocation" ), m_wmm_dir );

            return true;
      }
      else
            return false;
}

void wmm_pi::ShowPreferencesDialog( wxWindow* parent )
{
      WmmPrefsDialog *dialog = new WmmPrefsDialog( parent, wxID_ANY, _("WMM Preferences"), wxPoint( m_wmm_dialog_x, m_wmm_dialog_y), wxDefaultSize, wxDEFAULT_DIALOG_STYLE );
      dialog->Fit();
      wxColour cl;
      GetGlobalColor(_T("DILG1"), &cl);
      dialog->SetBackgroundColour(cl);

      dialog->m_rbViewType->SetSelection(m_iViewType);
      dialog->m_cbShowAtCursor->SetValue(m_bShowAtCursor);
      dialog->m_sOpacity->SetValue(m_iOpacity);

      if(dialog->ShowModal() == wxID_OK)
      {
            m_iViewType = dialog->m_rbViewType->GetSelection();
            m_bShowAtCursor = dialog->m_cbShowAtCursor->GetValue();
            m_iOpacity = dialog->m_sOpacity->GetValue();

            RearangeWindow();

            SaveConfig();
      }
}


/*!
 * \brief
 * sets up the magnetic model with our bundled data.
 * 
 * \param data
 * string containing the coefitient data
 * 
 * \param MagneticModel
 * Magnetic model
 * 
 * \returns
 * true on success
 * 
 * 
 * This is a modification of WMM_readMagneticModel() to set up the model in case the data files are missing.
 */
int WMM_setupMagneticModel(char *data, WMMtype_MagneticModel * MagneticModel)
{
	char c_str[81], c_new[5];   /*these strings are used to read a line from coefficient file*/
	int i, icomp, m, n, EOF_Flag = 0, index;
	double epoch, gnm, hnm, dgnm, dhnm;
      char *c_tmp;
      char *tmp_data;

      tmp_data = strdup(data);

	MagneticModel->Main_Field_Coeff_H[0] = 0.0;
	MagneticModel->Main_Field_Coeff_G[0] = 0.0;
	MagneticModel->Secular_Var_Coeff_H[0] = 0.0;
	MagneticModel->Secular_Var_Coeff_G[0] = 0.0;

	c_tmp = strtok(tmp_data, "\n");
      strncpy(c_str, c_tmp, 81);
	sscanf(c_str,"%lf%s",&epoch, MagneticModel->ModelName);
	MagneticModel->epoch = epoch;
	while (EOF_Flag == 0)
	{
            c_tmp = strtok(NULL, "\n");
            strncpy(c_str, c_tmp, 81);
		/* CHECK FOR LAST LINE IN FILE */
		for (i=0; i<4 && (c_str[i] != '\0'); i++)
		{
			c_new[i] = c_str[i];
			c_new[i+1] = '\0';
		}
		icomp = strcmp("9999", c_new);
		if (icomp == 0)
		{
			EOF_Flag = 1;
			break;
		}
		/* END OF FILE NOT ENCOUNTERED, GET VALUES */
		sscanf(c_str,"%d%d%lf%lf%lf%lf",&n,&m,&gnm,&hnm,&dgnm,&dhnm);
		if (m <= n)
		{
			index = (n * (n + 1) / 2 + m);
			MagneticModel->Main_Field_Coeff_G[index] = gnm;
			MagneticModel->Secular_Var_Coeff_G[index] = dgnm;
			MagneticModel->Main_Field_Coeff_H[index] = hnm;
			MagneticModel->Secular_Var_Coeff_H[index] = dhnm;
		}
	}

	return TRUE;
} /*WMM_setupMagneticModel */


