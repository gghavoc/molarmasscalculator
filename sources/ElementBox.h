//
// Created by clarence on 02/02/2020.
//

#ifndef MOLARMASSCALCULATOR_ELEMENTBOX_H
#define MOLARMASSCALCULATOR_ELEMENTBOX_H

#include <wx/window.h>

// forw decl
class Element;
class wxBoxSizer;
class wxStaticText;

class ElementBox : public wxWindow
{
public:
    ElementBox
    (
        wxWindow* parent,
        Element& element,
        wxWindowID Id = wxID_ANY,
        const wxPoint& pos = wxDefaultPosition,
        const wxSize& size = wxDefaultSize,
        long style = wxBORDER_THEME,
        const wxString& name = wxPanelNameStr
    );
    ~ElementBox();

public:
    void SetElement(Element& element);

private:
    void OnEnterWindow(wxMouseEvent& event);
    void OnClick(wxMouseEvent& event);

private:
    wxStaticText* elementSymbol;
    wxBoxSizer* mainVertSizer;

private:
    wxDECLARE_EVENT_TABLE();
};


#endif //MOLARMASSCALCULATOR_ELEMENTBOX_H
