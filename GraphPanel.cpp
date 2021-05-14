#include "GraphPanel.h"

GraphPanel::GraphPanel(wxWindow *parent, int xPos, int yPos, int width, int height)
    : wxPanel(parent, -1, wxPoint(xPos, yPos), wxSize(width, height))
    {
        mpFunction = new MyFunction(2.05);
        mpFunction->SetContinuity(true);

        mpPanel = new mpWindow(this, -1, wxPoint(xPos, yPos), wxSize(width, height), wxSUNKEN_BORDER );

        mpScaleX* xAxis = new mpScaleX(wxT("X"), mpALIGN_CENTER, false, mpX_NORMAL);
        mpScaleY* yAxis = new mpScaleY(wxT("Y"), mpALIGN_CENTER, false);

        xAxis->SetDrawOutsideMargins(false);
        yAxis->SetDrawOutsideMargins(false);

        mpPanel->SetMargins(30, 30, 20, 40);
        mpPanel->AddLayer(xAxis);
        mpPanel->AddLayer(yAxis);
        mpPanel->AddLayer(mpFunction);

        wxPen myPen(*wxRED, 1, wxSOLID);
        mpFunction->SetPen(myPen);

        mpWindow::zoomIncrementalFactor = 1;
        mpPanel->LockAspect(true);
        mpPanel->EnableMousePanZoom(false);
        mpPanel->Fit();
}

void GraphPanel::SetStep(double step) {
    mpFunction->SetStep(step);
}