#include "MainFrame.h"

BEGIN_EVENT_TABLE(MainFrame, wxFrame)
    EVT_COMMAND_SCROLL_THUMBTRACK(SLIDER_ID, MainFrame::OnChange)
    EVT_COMMAND_SCROLL_CHANGED(SLIDER_ID, MainFrame::OnChange)
    EVT_BUTTON(SAVE_BUTTON_ID, MainFrame::OnClickSaveButton)
    EVT_CHECKBOX(GRID_CHECK_BOX_ID, MainFrame::OnGridEnable)
    EVT_CHECKBOX(AXIS_CHECK_BOX_ID, MainFrame::OnAxisEnable)
END_EVENT_TABLE()

MainFrame::MainFrame(const wxString& title, int xPos, int yPos, int width, int height)
    : wxFrame(NULL, -1, title, wxPoint(xPos, yPos), wxSize(width, height))
    {
    mpGraph = new GraphPanel(this, width - height, 0, height, height);
    mpSlider = new wxSlider(this, SLIDER_ID, 10, 10, 300,
                            wxPoint(20, 50), wxSize(200, 30));
    mpTextField = new wxTextCtrl(this, TEXT_FIELD_ID, _T("0.10"),
                                 wxPoint(20, 100), wxSize(200, 30), wxTE_CENTER);
    mpSaveButton = new wxButton(this, SAVE_BUTTON_ID, _T("Save"),
                                wxPoint(20, 150), wxSize(200, 30));
    mpAxisCheckBox = new wxCheckBox(this, AXIS_CHECK_BOX_ID, _T("Enable axis"),
                                        wxPoint(20, 200));
    mpAxisCheckBox->SetValue(true);
    mpGridCheckBox = new wxCheckBox(this, GRID_CHECK_BOX_ID, _T("Enable grid"),
                                    wxPoint(20, 220));
    mpGridCheckBox->SetValue(true);
    wxStaticText *domainText = new wxStaticText(this, wxID_ANY, _T("Domain: from 0 to 20π"));
    wxStaticText *stepText = new wxStaticText(this, wxID_ANY, _T("Step:"));

    mpControlSizer = new wxBoxSizer(wxVERTICAL);
    mpControlSizer->AddStretchSpacer(20);
    mpControlSizer->Add(mpSlider, 1, wxALIGN_CENTER);
    mpControlSizer->Add(stepText, 1, wxALIGN_CENTER);
    mpControlSizer->Add(mpTextField, 1, wxALIGN_CENTER);
    mpControlSizer->Add(domainText, 1, wxALIGN_CENTER);
    mpControlSizer->Add(mpAxisCheckBox, 1, wxALIGN_CENTER);
    mpControlSizer->Add(mpGridCheckBox, 1, wxALIGN_CENTER);
    mpControlSizer->Add(mpSaveButton, 1, wxALIGN_CENTER);
    mpControlSizer->AddStretchSpacer(20);

    mpTopSizer = new wxBoxSizer(wxHORIZONTAL);
    mpTopSizer->Add(mpControlSizer, 1, wxEXPAND);
    mpTopSizer->Add(mpGraph, 2,wxSHAPED | wxALIGN_RIGHT);
    this->SetSizer(mpTopSizer);

}

void MainFrame::OnChange(wxScrollEvent &event) {
    mpGraph->SetStep(event.GetPosition() / 100.0);
    wxString step = wxString::Format(_T("%.2f"), event.GetPosition() / 100.0);
    mpTextField->Clear();
    mpTextField->WriteText(step);
    mpGraph->Refresh();
}

void MainFrame::OnClickSaveButton(wxCommandEvent &event) {
    wxFileDialog fileDialog(this, _("Save a screenshot"), wxT(""), wxT(""),
                            wxT("BMP image (*.bmp) | *.bmp|JPEG image (*.jpg) | *.jpeg;*.jpg|PNG image (*.png) | *.png"), wxFD_SAVE);
    if (fileDialog.ShowModal() == wxID_OK) {
        wxFileName namePath(fileDialog.GetPath());
        wxBitmapType fileType = wxBITMAP_TYPE_BMP;
        if( namePath.GetExt().CmpNoCase(wxT("jpeg")) == 0 ) fileType = wxBITMAP_TYPE_JPEG;
        if( namePath.GetExt().CmpNoCase(wxT("jpg")) == 0 )  fileType = wxBITMAP_TYPE_JPEG;
        if( namePath.GetExt().CmpNoCase(wxT("png")) == 0 )  fileType = wxBITMAP_TYPE_PNG;
        wxSize imgSize(2000,2000);
        mpGraph->SaveScreenshot(fileDialog.GetPath(), fileType, imgSize, false);
    }
    event.Skip();
}

void MainFrame::OnGridEnable(wxCommandEvent &event) {
    mpGraph->EnableGrid(event.IsChecked());
    mpGraph->Refresh();
}

void MainFrame::OnAxisEnable(wxCommandEvent &event) {
    mpGraph->EnableAxis(event.IsChecked());
    mpGridCheckBox->Enable(event.IsChecked());
    mpGraph->Refresh();
}

