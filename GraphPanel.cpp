#include "GraphPanel.h"

BEGIN_EVENT_TABLE(GraphPanel, wxPanel)
    EVT_SIZE(GraphPanel::OnSizeChanged)
END_EVENT_TABLE()

GraphPanel::GraphPanel(wxWindow *parent, int xPos, int yPos, int width, int height)
    : wxPanel(parent, -1, wxPoint(xPos, yPos), wxSize(width, height))
    {
        mpFunction = new MyFunction(0.1);
        mpFunction->SetContinuity(true);

        mpPanel = new mpWindow(this, -1, wxPoint(0, 0), wxSize(width, height));

        mpAxisX = new mpScaleX(_T("x"), mpALIGN_CENTER, false, mpX_NORMAL);
        mpAxisY = new mpScaleY(_T("y"), mpALIGN_CENTER, false);

        mpAxisX->SetDrawOutsideMargins(false);
        mpAxisY->SetDrawOutsideMargins(false);

        mpPanel->SetMargins(30, 30, 30, 30);
        mpPanel->AddLayer(mpAxisX);
        mpPanel->AddLayer(mpAxisY);
        mpPanel->AddLayer(mpFunction);

        wxPen myPen(*wxRED, 1, wxSOLID);
        mpFunction->SetPen(myPen);

        mpPanel->Fit();
}

void GraphPanel::SetStep(double step) {
    mpFunction->SetStep(step);
}

void GraphPanel::SaveScreenshot(const wxString &filename, wxBitmapType type, wxSize imageSize, bool fit) {
    mpPanel->SaveScreenshot(filename, type, imageSize, fit);
}

void GraphPanel::EnableGrid(bool enable) {
    mpAxisX->SetTicks(!enable);
    mpAxisY->SetTicks(!enable);
}

void GraphPanel::EnableAxis(bool enable) {
    mpAxisX->SetVisible(enable);
    mpAxisY->SetVisible(enable);
}

void GraphPanel::OnSizeChanged(wxSizeEvent& event) {
    mpPanel->SetSize(event.GetSize());
    mpPanel->Fit();
}
