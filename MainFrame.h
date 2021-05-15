#ifndef GRAPH_MAINFRAME_H
#define GRAPH_MAINFRAME_H

#include <wx/filename.h>

#include "GraphPanel.h"

class MainFrame : public wxFrame {
public:
    MainFrame(const wxString& title, int xPos, int yPos, int width, int height);

    void OnChange(wxScrollEvent& event);
    void OnClickSaveButton(wxCommandEvent& event);

    DECLARE_EVENT_TABLE()
private:
    GraphPanel *mpGraph;
    wxSlider *mpSlider;
    wxButton *mpSaveButton;
};

enum {
    SLIDER_ID = wxID_HIGHEST + 1,
    SAVE_BUTTON_ID = wxID_HIGHEST + 2
};

#endif //GRAPH_MAINFRAME_H
