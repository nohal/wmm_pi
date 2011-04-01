///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Mar 22 2011)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "WmmUIDialog.h"

///////////////////////////////////////////////////////////////////////////

WmmUIDialog::WmmUIDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	bSframe = new wxBoxSizer( wxVERTICAL );
	
	sbSboat = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Boat") ), wxVERTICAL );
	
	gSboat = new wxGridSizer( 6, 2, 0, 0 );
	
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
	
	m_staticText14 = new wxStaticText( this, wxID_ANY, _("Incl"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText14->Wrap( -1 );
	m_staticText14->SetToolTip( _("(DIP) - Geomagnetic Inclination ") );
	
	gSboat->Add( m_staticText14, 0, wxALL, 5 );
	
	m_tbI = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxSIMPLE_BORDER );
	gSboat->Add( m_tbI, 0, wxALL, 5 );
	
	sbSboat->Add( gSboat, 1, wxFIXED_MINSIZE, 5 );
	
	wxGridSizer* gSizer3;
	gSizer3 = new wxGridSizer( 1, 2, 0, 0 );
	
	m_staticText13 = new wxStaticText( this, wxID_ANY, _("Decl"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText13->Wrap( -1 );
	m_staticText13->SetToolTip( _("D (DEC) - Geomagnetic Declination") );
	
	gSizer3->Add( m_staticText13, 0, wxALL, 5 );
	
	m_tbD = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxSIMPLE_BORDER );
	m_tbD->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );
	
	gSizer3->Add( m_tbD, 0, wxALL, 5 );
	
	sbSboat->Add( gSizer3, 0, wxEXPAND, 0 );
	
	bSframe->Add( sbSboat, 1, wxFIXED_MINSIZE, 5 );
	
	sbScursor = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Cursor") ), wxVERTICAL );
	
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
	
	m_tcZ = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxSIMPLE_BORDER );
	gScursor->Add( m_tcZ, 0, wxALL, 5 );
	
	m_staticText141 = new wxStaticText( this, wxID_ANY, _("Incl"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText141->Wrap( -1 );
	m_staticText141->SetToolTip( _("(DIP) - Geomagnetic Inclination ") );
	
	gScursor->Add( m_staticText141, 0, wxALL, 5 );
	
	m_tcI = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxSIMPLE_BORDER );
	gScursor->Add( m_tcI, 0, wxALL, 5 );
	
	sbScursor->Add( gScursor, 1, wxFIXED_MINSIZE, 5 );
	
	wxGridSizer* gSizer4;
	gSizer4 = new wxGridSizer( 2, 2, 0, 0 );
	
	m_staticText131 = new wxStaticText( this, wxID_ANY, _("Decl"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText131->Wrap( -1 );
	m_staticText131->SetToolTip( _("D (DEC) - Geomagnetic Declination") );
	
	gSizer4->Add( m_staticText131, 0, wxALL, 5 );
	
	m_tcD = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxSIMPLE_BORDER );
	m_tcD->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );
	
	gSizer4->Add( m_tcD, 0, wxALL, 5 );
	
	sbScursor->Add( gSizer4, 0, wxEXPAND, 0 );
	
	bSframe->Add( sbScursor, 1, wxFIXED_MINSIZE, 5 );
	
	this->SetSizer( bSframe );
	this->Layout();
	
	this->Centre( wxBOTH );
}

WmmUIDialog::~WmmUIDialog()
{
}

WmmPrefsDialog::WmmPrefsDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );
	
	wxString m_rbViewTypeChoices[] = { _("Extended"), _("Declination only") };
	int m_rbViewTypeNChoices = sizeof( m_rbViewTypeChoices ) / sizeof( wxString );
	m_rbViewType = new wxRadioBox( this, wxID_ANY, _("View"), wxDefaultPosition, wxDefaultSize, m_rbViewTypeNChoices, m_rbViewTypeChoices, 2, wxRA_SPECIFY_COLS );
	m_rbViewType->SetSelection( 0 );
	bSizer2->Add( m_rbViewType, 0, wxALL|wxEXPAND, 5 );
	
	m_cbShowAtCursor = new wxCheckBox( this, wxID_ANY, _("Show also data at cursor position"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( m_cbShowAtCursor, 0, wxALL, 5 );
	
	wxStaticBoxSizer* sbSizer4;
	sbSizer4 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Window transparency") ), wxVERTICAL );
	
	m_sOpacity = new wxSlider( this, wxID_ANY, 255, 0, 255, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL|wxSL_INVERSE );
	sbSizer4->Add( m_sOpacity, 0, wxBOTTOM|wxEXPAND|wxTOP, 5 );
	
	bSizer2->Add( sbSizer4, 1, wxALL|wxEXPAND, 5 );
	
	m_sdbSizer1 = new wxStdDialogButtonSizer();
	m_sdbSizer1OK = new wxButton( this, wxID_OK );
	m_sdbSizer1->AddButton( m_sdbSizer1OK );
	m_sdbSizer1Cancel = new wxButton( this, wxID_CANCEL );
	m_sdbSizer1->AddButton( m_sdbSizer1Cancel );
	m_sdbSizer1->Realize();
	bSizer2->Add( m_sdbSizer1, 0, wxBOTTOM|wxEXPAND|wxTOP, 5 );
	
	this->SetSizer( bSizer2 );
	this->Layout();
	bSizer2->Fit( this );
	
	this->Centre( wxBOTH );
}

WmmPrefsDialog::~WmmPrefsDialog()
{
}
