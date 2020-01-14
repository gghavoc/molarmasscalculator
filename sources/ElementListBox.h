//
// Created by clarence on 14/01/2020.
//

#ifndef UNTITLED_ELEMENTLISTBOX_H
#define UNTITLED_ELEMENTLISTBOX_H

#include <wx/wx.h>


class ElementListBox : public wxTextCtrl
{
    wxDECLARE_EVENT_TABLE();

public:
    ElementListBox
        (
            wxWindow* parent,
            wxWindowID id,
            const wxString& value = wxEmptyString,
            const wxPoint& position = wxDefaultPosition,
            const wxSize& size = wxDefaultSize
        );

private:

};


#endif //UNTITLED_ELEMENTLISTBOX_H
