#ifndef GRAPH_MAINAPP_H
#define GRAPH_MAINAPP_H

#include "MainFrame.h"

class MainApp : public wxApp {
public:
    virtual bool OnInit();
};

DECLARE_APP(MainApp)


#endif //GRAPH_MAINAPP_H
