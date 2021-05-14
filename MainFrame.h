#ifndef GRAPH_MAINFRAME_H
#define GRAPH_MAINFRAME_H

#include "GraphPanel.h"

class MainFrame : public wxFrame {
public:
    MainFrame(const wxString& title, int xPos, int yPos, int width, int height);

    void OnChange(wxScrollEvent& event);

    DECLARE_EVENT_TABLE()
private:
    GraphPanel *mpGraph;
    wxSlider *mpSlider;
};

enum {
    SLIDER_ID = wxID_HIGHEST + 1
};

#endif //GRAPH_MAINFRAME_H
