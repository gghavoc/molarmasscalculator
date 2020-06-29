//
// Created by clarence on 14/01/2020.
//

#include "CompoundTextArea.h"

wxBEGIN_EVENT_TABLE(CompoundTextArea, wxTextCtrl)
                EVT_CHAR(CompoundTextArea::OnKeyPress)
wxEND_EVENT_TABLE();

CompoundTextArea::CompoundTextArea
    (
        wxWindow* parent,
        wxWindowID id,
        const wxString& value,
        const wxPoint& position,
        const wxSize& size
    ) :
        wxTextCtrl(parent, id, value, position, size, wxTE_PROCESS_ENTER | wxTE_PROCESS_TAB | wxBORDER_SIMPLE )
{
    return;
}

void CompoundTextArea::OnKeyPress(wxKeyEvent &event)
{
    if
        (
        wxIsalnum(event.GetUnicodeKey()) ||
        wxIscntrl(event.GetUnicodeKey()) ||
        event.GetUnicodeKey() == '(' ||
        event.GetUnicodeKey() == ')' ||
        event.GetUnicodeKey() == '[' ||
        event.GetUnicodeKey() == ']' ||
        event.GetUnicodeKey() == '{' ||
        event.GetUnicodeKey() == '}' ||
        event.GetUnicodeKey() == '<' ||
        event.GetUnicodeKey() == '>'
        ) // Alphanumeric, control characters or types of brackets
    {
        wxTextCtrl::OnChar(event); // control goes up a hierarchy
        // you can also use event.Skip() to go up a hierarchy
    }
    return;
}

