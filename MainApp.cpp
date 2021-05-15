#include "MainApp.h"

IMPLEMENT_APP(MainApp)

// This is executed upon startup, like 'main()' in non-wxWidgets programs.
bool MainApp::OnInit()
{
    wxFrame *window = new MainFrame("Graph", 0, 0, 1300, 800);
    window->Show(true);
    SetTopWindow(window);

    return true;
}
