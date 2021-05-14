#include "MainFrame.h"

BEGIN_EVENT_TABLE(MainFrame, wxFrame)
    EVT_COMMAND_SCROLL_THUMBTRACK(SLIDER_ID, MainFrame::OnChange)
    EVT_COMMAND_SCROLL_CHANGED(SLIDER_ID, MainFrame::OnChange)
END_EVENT_TABLE()

MainFrame::MainFrame(const wxString& title, int xPos, int yPos, int width, int height)
    : wxFrame(NULL, -1, title, wxPoint(xPos, yPos), wxSize(width, height))
    {
    mpGraph = new GraphPanel(this, 300, 0, height, height);
    mpSlider = new wxSlider(this, SLIDER_ID, 10, 10, 300,
                            wxPoint(20, 20), wxSize(200, 30));
}

void MainFrame::OnChange(wxScrollEvent &event) {
    mpGraph->SetStep(event.GetPosition() / 100.0);
    mpGraph->Refresh();
}