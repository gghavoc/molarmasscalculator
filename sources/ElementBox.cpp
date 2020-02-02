//
// Created by clarence on 02/02/2020.
//

#include "ElementBox.h"
#include "Element.h"
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/msgdlg.h>

wxBEGIN_EVENT_TABLE(ElementBox, wxWindow)
                EVT_ENTER_WINDOW(ElementBox::OnEnterWindow)
                EVT_LEFT_DOWN(ElementBox::OnClick)
wxEND_EVENT_TABLE();

ElementBox::ElementBox
(
    wxWindow *parent,
    Element& element,
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
    this->SetInitialSize(wxSize(50,50));
    this->mainVertSizer = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(mainVertSizer);
    this->elementSymbol = new wxStaticText(this, wxID_ANY, wxString::Format(wxT("%s"), element.Symbol));
    this->mainVertSizer->Add(this->elementSymbol, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 2);
    return;
}

void ElementBox::SetElement(Element &element)
{
    return;
};

void ElementBox::OnEnterWindow(wxMouseEvent &event)
{
    this->SetCursor(wxCursor(wxCURSOR_HAND));
    return;
}

void ElementBox::OnClick(wxMouseEvent &event)
{
    wxMessageBox(wxT("OPENED ELEMENT INFO"));
    return;
}

ElementBox::~ElementBox()
{
    return;
}
