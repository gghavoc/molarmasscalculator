//
// Created by clarence on 02/02/2020.
//

#ifndef MOLARMASSCALCULATOR_ELEMENTRESULTSLISTENTRY_H
#define MOLARMASSCALCULATOR_ELEMENTRESULTSLISTENTRY_H

#include <wx/window.h>

// forw decl
class ElementBox;
class wxBoxSizer;
class wxStaticText;
class Element;

class ElementResultsListEntry : public wxWindow
{
public:
    ElementResultsListEntry
    (
        wxWindow* parent,
        Element& element,
        uint32_t elementCount,
        wxWindowID Id = wxID_ANY,
        const wxPoint& pos = wxDefaultPosition,
        const wxSize& size = wxDefaultSize,
        long style = wxBORDER_THEME,
        const wxString& name = wxPanelNameStr
    );
    ~ElementResultsListEntry();

public:
    void SetEntry(const Element& element, const uint32_t count);

private:
    void SetElementBox();

private:
    wxBoxSizer* mainHorSizer;
    ElementBox* elementBox;
    wxStaticText* elementNameSText;
    wxStaticText* elementAtomCountSText;
    wxStaticText* elementAtomicWeightSText;
    wxStaticText* totalSText;

private:
    wxDECLARE_EVENT_TABLE();
};


#endif //MOLARMASSCALCULATOR_ELEMENTRESULTSLISTENTRY_H
