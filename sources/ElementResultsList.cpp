//
// Created by clarence on 19/01/2020.
//

#include "ElementResultsList.h"
#include "MolarMass.h"
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

    double ElementTotalMass = RetrievedElement.GetAtomicWeight() * (double)AtomCount;

    staticTextPtrArr.insert(staticTextPtrArr.end(), new wxStaticText(this, wxID_ANY, wxT("")));

    wxString ResultString =
            RetrievedElement.Name
            + ": "
            + std::to_string(RetrievedElement.GetAtomicWeight())
            + " X "
            + std::to_string(AtomCount)
            + " = "
            + std::to_string(ElementTotalMass)
            + " g/mol\n";

    // sets label
    staticTextPtrArr[this->staticTextPtrArr.size()-1]->SetLabelText(ResultString);
    staticTextPtrArr[this->staticTextPtrArr.size()-1]->SetBackgroundColour(wxColour(0,255,255,50));

    // adds to the sizer
    this->mainSizer->Add(staticTextPtrArr[this->staticTextPtrArr.size()-1], 0, wxEXPAND | wxALIGN_CENTER_HORIZONTAL | wxALL , 5);

    // to refresh layout
    this->Layout();

    this->FitInside();

    // adds to the total mass
    this->TotalMass += ElementTotalMass;

    return;
}

void ElementResultsList::ClearResults()
{
    if (!this->staticTextPtrArr.empty())
    {
        for (wxStaticText* ref : staticTextPtrArr)
        {
            this->mainSizer->Detach(ref);
            ref->Destroy();
            this->TotalMass = 0;
        }
        staticTextPtrArr.clear();
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
