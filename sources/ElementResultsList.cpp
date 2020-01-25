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
    this->SetBackgroundColour(wxColor(255,255,255,255));

    return;
}

void ElementResultsList::AddResult(const wxString& Symbol, uint32_t AtomCount)
{
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

    staticTextPtrArr[this->staticTextPtrArr.size()-1]->SetLabelText(ResultString); // REMEMBER THIS FUCKING SHIT!!!
    // std::cout << this->staticTextPtrArr.size() << std::endl;

    return;
}

void ElementResultsList::ClearResults()
{
    if (!this->staticTextPtrArr.empty())
    {
        for (wxStaticText* ref : staticTextPtrArr)
        {
            ref->Destroy();
            // std::cout << "Clearing static text..." << std::endl;

        }
        staticTextPtrArr.clear();
    }

    return;
}

ElementResultsList::~ElementResultsList()
{
    this->ClearResults();
    return;
}