//
// Created by clarence on 25/01/2020.
//

#include "TotalTextOutput.h"
#include <wx/stattext.h>
#include <wx/sizer.h>

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
    topVertSizer = new wxBoxSizer(wxVERTICAL);
    return;
}

void TotalTextOutput::SetText(const wxString& total)
{
    // checks if totaltext has value, delete it if it is
    if (totalText)
    {
        totalText->Destroy();
    };

    totalText = new wxStaticText(this, wxID_ANY, wxEmptyString);
    totalText->SetLabel(total);

    return;
}

TotalTextOutput::~TotalTextOutput()
{
    return;
}



