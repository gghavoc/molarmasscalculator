//
// Created by clarence on 14/01/2020.
//

#include "CompoundTextArea.h"

wxBEGIN_EVENT_TABLE(CompoundTextArea, wxTextCtrl)
                EVT_KEY_DOWN(CompoundTextArea::OnKeyPress)
wxEND_EVENT_TABLE();

CompoundTextArea::CompoundTextArea
    (
        wxWindow* parent,
        wxWindowID id,
        const wxString& value,
        const wxPoint& position,
        const wxSize& size
    ) :
        wxTextCtrl(parent, id, value, position, size, wxTE_PROCESS_ENTER | wxTE_NO_VSCROLL | wxTE_PROCESS_TAB )
{
    this->SetHint("Compound");
    return;
}

void CompoundTextArea::OnKeyPress(wxKeyEvent &event)
{
    if  (
        wxIsalnum(event.GetUnicodeKey()) ||
        event.GetUnicodeKey() == '\b' ||
        event.GetUnicodeKey() == '\r'
        ) // Alphanumeric or backspace
    {
        wxTextCtrl::OnChar(event); // control goes up a hierarchy
        // you can also use event.Skip() to go up a hierarchy
    }
    else
    {
        wxBell();
    }
    return;
}

