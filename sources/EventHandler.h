//
// Created by clarence on 16/01/2020.
//

#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include <wx/event.h>

class EventHandler : public wxEvtHandler
{

public:
    EventHandler();
    ~EventHandler();

public:

private:

private:
    wxDECLARE_EVENT_TABLE();
};

#endif //EVENTHANDLER_H
