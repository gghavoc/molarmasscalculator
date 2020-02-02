//
// Created by clarence on 02/02/2020.
//

#include "ElementResultsListEntry.h"
#include "ElementBox.h"
#include "Element.h"
#include <wx/sizer.h>
#include <wx/stattext.h>

wxBEGIN_EVENT_TABLE(ElementResultsListEntry, wxWindow)
wxEND_EVENT_TABLE()

ElementResultsListEntry::ElementResultsListEntry
(
    wxWindow *parent,
    Element& element,
    uint32_t elementCount,
    wxWindowID Id,
    const wxPoint &pos,
    const wxSize &size,
    long style,
    const wxString &name
) : wxWindow
(
    parent,
    Id,
    pos,
    size,
    style,
    name
)
{
    this->mainHorSizer = new wxBoxSizer(wxHORIZONTAL);
    this->SetSizer(mainHorSizer);
    this->elementBox = new ElementBox(this, element);
    this->elementNameSText = new wxStaticText(this, wxID_ANY, wxString::Format(wxT("%s : "), element.Name));
    this->elementAtomCountSText = new wxStaticText(this, wxID_ANY, wxString::Format(wxT("%i"), elementCount));
    this->elementAtomicWeightSText = new wxStaticText(this, wxID_ANY, wxString::Format(wxT("X %f"), element.GetAtomicWeight()));
    this->totalSText = new wxStaticText(this, wxID_ANY, wxString::Format(wxT("= %f"), element.GetAtomicWeight() * (double) elementCount));

    // setting up the sizer
    this->mainHorSizer->Add(elementBox, 0, wxALL | wxALIGN_CENTER_VERTICAL | wxFIXED_MINSIZE, 3);
    this->mainHorSizer->Add(elementNameSText, 1, wxALL | wxALIGN_CENTER_VERTICAL | wxFIXED_MINSIZE, 3);
    this->mainHorSizer->Add(elementAtomCountSText, 0, wxTOP | wxBOTTOM | wxALIGN_CENTER_VERTICAL | wxFIXED_MINSIZE, 3);
    this->mainHorSizer->Add(elementAtomicWeightSText, 1, wxTOP | wxBOTTOM | wxALIGN_CENTER_VERTICAL | wxFIXED_MINSIZE, 3);
    this->mainHorSizer->Add(totalSText, 0, wxALL | wxALIGN_CENTER_VERTICAL | wxFIXED_MINSIZE, 3);
    return;
}

void ElementResultsListEntry::SetEntry(const Element &element, const uint32_t count)
{
    this->elementNameSText->SetLabel(element.Name);
    this->elementAtomCountSText->SetLabel(wxString::Format(wxT("%i"), count));
    this->elementAtomicWeightSText->SetLabel(wxString::Format(wxT("%f"), element.GetAtomicWeight()));
    this->totalSText->SetLabel(wxString::Format(wxT("%f"), element.GetAtomicWeight() * (double) count));
    return;
};

void ElementResultsListEntry::SetElementBox()
{
    return;
}

ElementResultsListEntry::~ElementResultsListEntry()
{
    return;
}