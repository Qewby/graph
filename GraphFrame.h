#ifndef GRAPH_GRAPHFRAME_H
#define GRAPH_GRAPHFRAME_H

#include "wx/wxprec.h"
#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif

#include "libs/mathplot.h"

#include "MyFunction.h"

class GraphFrame : public wxFrame {
public:
    GraphFrame(wxWindow *parent, const wxString& title, int xPos, int yPos, int width, int height);
    void SetStep(double step);

private:
    mpWindow *moFrame;
    MyFunction *mpFunction;
};


#endif //GRAPH_GRAPHFRAME_H
