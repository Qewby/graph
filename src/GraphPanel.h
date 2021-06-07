#ifndef GRAPH_GRAPHPANEL_H
#define GRAPH_GRAPHPANEL_H

#include "wx/wxprec.h"
#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif

#include "MyFunction.h"

class GraphPanel : public wxPanel {
public:
    GraphPanel(wxWindow *parent, int xPos, int yPos, int width, int height);
    void SetStep(double step);

    void SaveScreenshot(const wxString &filename, wxBitmapType type,
                        wxSize imageSize, bool fit);
    void EnableGrid(bool enable);
    void EnableAxis(bool enable);

    void OnSizeChanged(wxSizeEvent& event);

    DECLARE_EVENT_TABLE()
private:
    mpWindow *mpPanel;
    MyFunction *mpFunction;
    mpScaleX *mpAxisX;
    mpScaleY *mpAxisY;
};


#endif //GRAPH_GRAPHPANEL_H
