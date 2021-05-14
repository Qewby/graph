#ifndef GRAPH_GRAPHPANEL_H
#define GRAPH_GRAPHPANEL_H

#include "wx/wxprec.h"
#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif

#include "libs/mathplot.h"

#include "MyFunction.h"

class GraphPanel : public wxPanel {
public:
    GraphPanel(wxWindow *parent, int xPos, int yPos, int width, int height);
    void SetStep(double step);

private:
    mpWindow *mpPanel;
    MyFunction *mpFunction;
};


#endif //GRAPH_GRAPHPANEL_H
