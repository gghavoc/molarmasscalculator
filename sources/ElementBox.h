//
// Created by clarence on 02/02/2020.
//

#ifndef MOLARMASSCALCULATOR_ELEMENTBOX_H
#define MOLARMASSCALCULATOR_ELEMENTBOX_H

#include <wx/window.h>

class ElementBox : public wxWindow
{
public:
    ElementBox
    (
        wxWindow* parent,
        wxWindowID Id = wxID_ANY,
        const wxPoint& pos = wxDefaultPosition,
        const wxSize& size = wxDefaultSize,
        long style = wxBORDER_SIMPLE,
        const wxString& name = wxPanelNameStr
    );
    ~ElementBox();

public:

private:

private:

private:
    wxDECLARE_EVENT_TABLE();
};


#endif //MOLARMASSCALCULATOR_ELEMENTBOX_H
