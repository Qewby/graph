#include "MainFrame.h"

BEGIN_EVENT_TABLE(MainFrame, wxFrame)
    EVT_COMMAND_SCROLL_THUMBTRACK(SLIDER_ID, MainFrame::OnChange)
    EVT_COMMAND_SCROLL_CHANGED(SLIDER_ID, MainFrame::OnChange)
    EVT_BUTTON(SAVE_BUTTON_ID, MainFrame::OnClickSaveButton)
END_EVENT_TABLE()

MainFrame::MainFrame(const wxString& title, int xPos, int yPos, int width, int height)
    : wxFrame(NULL, -1, title, wxPoint(xPos, yPos), wxSize(width, height))
    {
    mpGraph = new GraphPanel(this, width - height, 0, height, height);
    mpSlider = new wxSlider(this, SLIDER_ID, 10, 10, 300,
                            wxPoint(20, 20), wxSize(200, 30));
    mpSaveButton = new wxButton(this, SAVE_BUTTON_ID, _T("Save"),
                                wxPoint(20, 80), wxSize(200, 30));
}

void MainFrame::OnChange(wxScrollEvent &event) {
    mpGraph->SetStep(event.GetPosition() / 100.0);
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