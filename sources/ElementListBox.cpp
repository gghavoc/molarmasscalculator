//
// Created by clarence on 14/01/2020.
//

#include "ElementListBox.h"

wxBEGIN_EVENT_TABLE(ElementListBox, wxTextCtrl)
wxEND_EVENT_TABLE();

ElementListBox::ElementListBox
    (
        wxWindow* parent,
        wxWindowID id,
        const wxString& value,
        const wxPoint& position,
        const wxSize& size

    ) :
    wxTextCtrl(parent, id, value, position, size, wxTE_MULTILINE | wxTE_READONLY )
{
    this->SetCanFocus(false);
    return;
}