#include "MainApp.h"

IMPLEMENT_APP(MainApp)

// This is executed upon startup, like 'main()' in non-wxWidgets programs.
bool MainApp::OnInit()
{
    wxFrame *window = new wxFrame(NULL, -1, "Main Window", wxDefaultPosition, wxSize(800, 500));
    GraphPanel *frame = new GraphPanel(window, 300, 0, 500, 500);
    window->Show(true);
    SetTopWindow(frame);

    return true;
}
