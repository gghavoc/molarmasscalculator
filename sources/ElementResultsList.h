//
// Created by clarence on 19/01/2020.
//

#ifndef MOLARMASSCALCULATOR_ELEMENTRESULTSLIST_H
#define MOLARMASSCALCULATOR_ELEMENTRESULTSLIST_H

#include <wx/scrolwin.h>
#include <wx/stattext.h>

class ElementResultsList : public wxScrolledWindow
{
public:
    ElementResultsList
    (
        wxWindow* parent,
        wxWindowID Id = wxID_ANY,
        const wxPoint& pos = wxDefaultPosition,
        const wxSize& size = wxDefaultSize,
        long style = wxScrolledWindowStyle,
        const wxString& name = wxPanelNameStr
    );
    ~ElementResultsList();

public:
    void AddResult(const wxString Symbol, const uint32_t  AtomCount = 1);

public:

private:
    inline static uint32_t  elementAmount;
    wxVector<wxStaticText*> staticTextPtrArr;
    void OnMouse(wxMouseEvent& event);
private:
    wxDECLARE_EVENT_TABLE();
};

#endif //MOLARMASSCALCULATOR_ELEMENTRESULTSLIST_H
