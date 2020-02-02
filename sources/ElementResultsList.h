//
// Created by clarence on 19/01/2020.
//

#ifndef MOLARMASSCALCULATOR_ELEMENTRESULTSLIST_H
#define MOLARMASSCALCULATOR_ELEMENTRESULTSLIST_H

#include <wx/scrolwin.h>
#include <wx/stattext.h>

class wxBoxSizer;

class ElementResultsList : public wxScrolledWindow
{
public:
    ElementResultsList
    (
        wxWindow* parent,
        wxWindowID Id = wxID_ANY,
        const wxPoint& pos = wxDefaultPosition,
        const wxSize& size = wxDefaultSize,
        long style = wxVSCROLL | wxBORDER_SIMPLE,
        const wxString& name = wxPanelNameStr
    );
    ~ElementResultsList();

public:
    void AddResult(const wxString& Symbol, const uint32_t  AtomCount = 1);
    void ClearResults();
    double GetTotalMass() const;

private:
    wxVector<wxStaticText*> staticTextPtrArr;
    wxBoxSizer* mainSizer;
    double TotalMass;

private:

private:
    wxDECLARE_EVENT_TABLE();
};

#endif //MOLARMASSCALCULATOR_ELEMENTRESULTSLIST_H
