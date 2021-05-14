#include "GraphFrame.h"

GraphFrame::GraphFrame(wxWindow *parent, const wxString& title, int xPos, int yPos, int width, int height)
    : wxFrame(parent, -1, title, wxPoint(xPos, yPos), wxSize(width, height))
    {
        mpFunction = new MyFunction(2.05);
        mpFunction->SetContinuity(true);

        moFrame = new mpWindow(this, -1, wxPoint(0,0), wxSize(900,900), wxSUNKEN_BORDER );

        /*mpScaleX* xAxis = new mpScaleX(wxT("X"), mpALIGN_BOTTOM, true, mpX_NORMAL);
        mpScaleY* yAxis = new mpScaleY(wxT("Y"), mpALIGN_LEFT, true);

        xAxis->SetDrawOutsideMargins(false);
        yAxis->SetDrawOutsideMargins(false);*/

        /*plot->SetMargins(30, 30, 50, 100);
        moFrame->AddLayer(xAxis);
        moFrame->AddLayer(yAxis);*/
        moFrame->AddLayer(mpFunction);

        wxPen myPen(*wxRED, 2, wxSOLID);
        mpFunction->SetPen(myPen);

        mpWindow::zoomIncrementalFactor = 1;
        moFrame->LockAspect(true);
        moFrame->EnableMousePanZoom(false);
        moFrame->Fit();
}

void GraphFrame::SetStep(double step) {
    mpFunction->SetStep(step);
}