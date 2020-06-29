//
// Created by clarence on 25/01/2020.
//

#include "TotalTextOutput.h"
#include <wx/stattext.h>
#include <wx/sizer.h>
#include <iostream>

wxBEGIN_EVENT_TABLE(TotalTextOutput, wxScrolledWindow)
wxEND_EVENT_TABLE()

TotalTextOutput::TotalTextOutput
(
    wxWindow *parent,
    wxWindowID Id,
    const wxPoint &pos,
    const wxSize &size,
    long style,
    const wxString &name
) :
    wxScrolledWindow(parent, Id, pos, size, style, name)
{
    this->totalText = nullptr;
    this->topHorSizer = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(this->topHorSizer);
    this->totalText = new wxStaticText(this, wxID_ANY, "");
    this->topHorSizer->Add(this->totalText, 1, wxALL | wxALIGN_CENTER_HORIZONTAL, 15);
    return;
}

void TotalTextOutput::SetText(const wxString& total)
{
    // checks if totaltext has value, detach it from sizer and destroy it if it has
    this->totalText->SetLabelMarkup("<big>" + total + "</big>");
    this->Layout();

    return;
}

TotalTextOutput::~TotalTextOutput()
{
    return;
}