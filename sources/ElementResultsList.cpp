//
// Created by clarence on 19/01/2020.
//

#include "ElementResultsList.h"
#include "MolarMass.h"
#include <wx/log.h>

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
    this->elementAmount = 0;

    return;
}

void ElementResultsList::AddResult(const wxString Symbol, uint32_t AtomCount)
{
    this->elementAmount++;

    Element RetrievedElement = GetElementDataFromMap(Symbol.ToStdString());

    double ElementTotalMass = RetrievedElement.GetAtomicWeight() * (double)AtomCount;

    staticTextPtrArr.insert(staticTextPtrArr.end(), new wxStaticText(this, wxID_ANY, wxT("Text")));

    wxString ResultString =
            RetrievedElement.Name
            + ": "
            + std::to_string(RetrievedElement.GetAtomicWeight())
            + " X "
            + std::to_string(AtomCount)
            + " = "
            + std::to_string(ElementTotalMass)
            + " g/mol\n";

    staticTextPtrArr[this->elementAmount-1]->SetLabelText(ResultString);

    return;
}

ElementResultsList::~ElementResultsList()
{
    for (uint32_t index = 0; index < this->elementAmount; index++)
    {
        delete staticTextPtrArr[index];
    }
    return;
}