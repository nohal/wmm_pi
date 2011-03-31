///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep  8 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "WmmUIDialog.h"

///////////////////////////////////////////////////////////////////////////

WmmUIDialog::WmmUIDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSframe;
	bSframe = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSboat;
	sbSboat = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Boat") ), wxVERTICAL );
	
	wxGridSizer* gSboat;
	gSboat = new wxGridSizer( 7, 2, 0, 0 );
	
	m_staticText8 = new wxStaticText( this, wxID_ANY, _("F"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText8->Wrap( -1 );
	m_staticText8->SetToolTip( _("Total Intensity") );
	
	gSboat->Add( m_staticText8, 0, wxALL, 5 );
	
	m_tbF = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxSIMPLE_BORDER );
	gSboat->Add( m_tbF, 0, wxALL, 5 );
	
	m_staticText9 = new wxStaticText( this, wxID_ANY, _("H"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText9->Wrap( -1 );
	m_staticText9->SetToolTip( _("Horizontal Intensity") );
	
	gSboat->Add( m_staticText9, 0, wxALL, 5 );
	
	m_tbH = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxSIMPLE_BORDER );
	gSboat->Add( m_tbH, 0, wxALL, 5 );
	
	m_staticText10 = new wxStaticText( this, wxID_ANY, _("X"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText10->Wrap( -1 );
	m_staticText10->SetToolTip( _("North Component") );
	
	gSboat->Add( m_staticText10, 0, wxALL, 5 );
	
	m_tbX = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxSIMPLE_BORDER );
	gSboat->Add( m_tbX, 0, wxALL, 5 );
	
	m_staticText11 = new wxStaticText( this, wxID_ANY, _("Y"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText11->Wrap( -1 );
	m_staticText11->SetToolTip( _("East Component") );
	
	gSboat->Add( m_staticText11, 0, wxALL, 5 );
	
	m_tbY = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxSIMPLE_BORDER );
	gSboat->Add( m_tbY, 0, wxALL, 5 );
	
	m_staticText12 = new wxStaticText( this, wxID_ANY, _("Z"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText12->Wrap( -1 );
	m_staticText12->SetToolTip( _("Vertical Component") );
	
	gSboat->Add( m_staticText12, 0, wxALL, 5 );
	
	m_tbZ = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxSIMPLE_BORDER );
	gSboat->Add( m_tbZ, 0, wxALL, 5 );
	
	m_staticText13 = new wxStaticText( this, wxID_ANY, _("D"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText13->Wrap( -1 );
	m_staticText13->SetToolTip( _("D (DEC) - Geomagnetic Declination") );
	
	gSboat->Add( m_staticText13, 0, wxALL, 5 );
	
	m_tbD = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxSIMPLE_BORDER );
	gSboat->Add( m_tbD, 0, wxALL, 5 );
	
	m_staticText14 = new wxStaticText( this, wxID_ANY, _("I"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText14->Wrap( -1 );
	m_staticText14->SetToolTip( _("(DIP) - Geomagnetic Inclination ") );
	
	gSboat->Add( m_staticText14, 0, wxALL, 5 );
	
	m_tbI = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxSIMPLE_BORDER );
	gSboat->Add( m_tbI, 0, wxALL, 5 );
	
	sbSboat->Add( gSboat, 1, wxFIXED_MINSIZE, 5 );
	
	bSframe->Add( sbSboat, 1, wxFIXED_MINSIZE, 5 );
	
	wxStaticBoxSizer* sbScursor;
	sbScursor = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Cursor") ), wxVERTICAL );
	
	wxGridSizer* gScursor;
	gScursor = new wxGridSizer( 7, 2, 0, 0 );
	
	m_staticText81 = new wxStaticText( this, wxID_ANY, _("F"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText81->Wrap( -1 );
	m_staticText81->SetToolTip( _("Total Intensity") );
	
	gScursor->Add( m_staticText81, 0, wxALL, 5 );
	
	m_tcF = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxSIMPLE_BORDER );
	gScursor->Add( m_tcF, 0, wxALL, 5 );
	
	m_staticText91 = new wxStaticText( this, wxID_ANY, _("H"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText91->Wrap( -1 );
	m_staticText91->SetToolTip( _("Horizontal Intensity") );
	
	gScursor->Add( m_staticText91, 0, wxALL, 5 );
	
	m_tcH = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxSIMPLE_BORDER );
	gScursor->Add( m_tcH, 0, wxALL, 5 );
	
	m_staticText101 = new wxStaticText( this, wxID_ANY, _("X"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText101->Wrap( -1 );
	m_staticText101->SetToolTip( _("North Component") );
	
	gScursor->Add( m_staticText101, 0, wxALL, 5 );
	
	m_tcX = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxSIMPLE_BORDER );
	gScursor->Add( m_tcX, 0, wxALL, 5 );
	
	m_staticText111 = new wxStaticText( this, wxID_ANY, _("Y"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText111->Wrap( -1 );
	m_staticText111->SetToolTip( _("East Component") );
	
	gScursor->Add( m_staticText111, 0, wxALL, 5 );
	
	m_tcY = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxSIMPLE_BORDER );
	gScursor->Add( m_tcY, 0, wxALL, 5 );
	
	m_staticText121 = new wxStaticText( this, wxID_ANY, _("Z"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText121->Wrap( -1 );
	m_staticText121->SetToolTip( _("Vertical Component") );
	
	gScursor->Add( m_staticText121, 0, wxALL, 5 );
	
	m_tZ = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxSIMPLE_BORDER );
	gScursor->Add( m_tZ, 0, wxALL, 5 );
	
	m_staticText131 = new wxStaticText( this, wxID_ANY, _("D"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText131->Wrap( -1 );
	m_staticText131->SetToolTip( _("D (DEC) - Geomagnetic Declination") );
	
	gScursor->Add( m_staticText131, 0, wxALL, 5 );
	
	m_tcD = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxSIMPLE_BORDER );
	gScursor->Add( m_tcD, 0, wxALL, 5 );
	
	m_staticText141 = new wxStaticText( this, wxID_ANY, _("I"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText141->Wrap( -1 );
	m_staticText141->SetToolTip( _("(DIP) - Geomagnetic Inclination ") );
	
	gScursor->Add( m_staticText141, 0, wxALL, 5 );
	
	m_tcI = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxSIMPLE_BORDER );
	gScursor->Add( m_tcI, 0, wxALL, 5 );
	
	sbScursor->Add( gScursor, 1, wxFIXED_MINSIZE, 5 );
	
	bSframe->Add( sbScursor, 1, wxFIXED_MINSIZE, 5 );
	
	this->SetSizer( bSframe );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( WmmUIDialog::OnClose ) );
}

WmmUIDialog::~WmmUIDialog()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( WmmUIDialog::OnClose ) );
	
}
