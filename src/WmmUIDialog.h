///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep  8 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __WmmUIDialog__
#define __WmmUIDialog__

#include <wx/intl.h>

#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/textctrl.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class WmmUIDialog
///////////////////////////////////////////////////////////////////////////////
class WmmUIDialog : public wxFrame 
{
	private:
	
	protected:
		wxStaticText* m_staticText8;
		wxStaticText* m_staticText9;
		wxStaticText* m_staticText10;
		wxStaticText* m_staticText11;
		wxStaticText* m_staticText12;
		wxStaticText* m_staticText13;
		wxStaticText* m_staticText14;
		wxStaticText* m_staticText81;
		wxStaticText* m_staticText91;
		wxStaticText* m_staticText101;
		wxStaticText* m_staticText111;
		wxStaticText* m_staticText121;
		wxStaticText* m_staticText131;
		wxStaticText* m_staticText141;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnClose( wxCloseEvent& event ) { event.Skip(); }
		
	
	public:
		wxTextCtrl* m_tbF;
		wxTextCtrl* m_tbH;
		wxTextCtrl* m_tbX;
		wxTextCtrl* m_tbY;
		wxTextCtrl* m_tbZ;
		wxTextCtrl* m_tbD;
		wxTextCtrl* m_tbI;
		wxTextCtrl* m_tcF;
		wxTextCtrl* m_tcH;
		wxTextCtrl* m_tcX;
		wxTextCtrl* m_tcY;
		wxTextCtrl* m_tZ;
		wxTextCtrl* m_tcD;
		wxTextCtrl* m_tcI;
		
		WmmUIDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("WMM"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 240,415 ), long style = wxCAPTION|wxCLOSE_BOX|wxDEFAULT_FRAME_STYLE|wxSTAY_ON_TOP|wxTAB_TRAVERSAL );
		~WmmUIDialog();
	
};

#endif //__WmmUIDialog__
