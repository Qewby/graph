#ifndef GRAPH_HELLOWORLDAPP_H
#define GRAPH_HELLOWORLDAPP_H

#include "wx/wxprec.h"

#ifndef WX_PRECOMP
#	include "wx/wx.h"
#endif

class HelloWorldApp : public wxApp
{
public:
    virtual bool OnInit();
};

DECLARE_APP(HelloWorldApp)


#endif //GRAPH_HELLOWORLDAPP_H
