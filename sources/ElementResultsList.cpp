//
// Created by clarence on 19/01/2020.
//

#include "ElementResultsList.h"
#include "MolarMass.h"
#include "ElementResultsListEntry.h"
#include <wx/log.h>
#include <wx/sizer.h>

wxBEGIN_EVENT_TABLE(ElementResultsList, wxScrolledWindow)
wxEND_EVENT_TABLE();

ElementResultsList::ElementResultsList
(
    wxWindow *parent,
    wxWindowID Id,
    const wxPoint &pos,
    const wxSize &size,
    long style,
    const wxString &name
) : wxScrolledWindow(parent, Id, pos, size, style, name)
{
    this->TotalMass = 0;
    this->SetBackgroundColour(wxColor(255,255,255,255));
    this->mainSizer = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(this->mainSizer);
    this->SetScrollRate(5,5);

    return;
}

void ElementResultsList::AddResult(const wxString& Symbol, uint32_t AtomCount)
{
    Element RetrievedElement = GetElementDataFromMap(Symbol.ToStdString());

    double ElementTotalMass = RetrievedElement.GetAtomicWeight() * (double) AtomCount;

    entryArr.insert(entryArr.end(), new ElementResultsListEntry(this, RetrievedElement, AtomCount));

    entryArr[this->entryArr.size()-1]->SetBackgroundColour(wxColour(0,255,255,20));

    // adds to the sizer
    this->mainSizer->Add(entryArr[this->entryArr.size()-1], 0, wxEXPAND | wxRIGHT | wxTOP | wxRIGHT | wxLEFT, 5);

    // to refresh layout without needing to resize the app
    this->Layout();

    // to recalculate the "virtual size" so you can scroll
    //
    this->FitInside();

    // adds to the total mass
    this->TotalMass += ElementTotalMass;

    return;
}

void ElementResultsList::ClearResults()
{
    if (!this->entryArr.empty())
    {
        for (ElementResultsListEntry* ref : entryArr)
        {
            this->mainSizer->Detach(ref);
            ref->Destroy();
            this->TotalMass = 0;
        }
        entryArr.clear();
    }

    return;
}

double ElementResultsList::GetTotalMass() const
{
    return this->TotalMass;
}
ElementResultsList::~ElementResultsList()
{
    this->ClearResults();
    return;
}
