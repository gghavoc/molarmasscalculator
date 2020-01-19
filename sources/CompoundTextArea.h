//
// Created by clarence on 14/01/2020.
//

#ifndef COMPOUNDTEXTAREA_H
#define COMPOUNDTEXTAREA_H
#include <wx/textctrl.h>


class CompoundTextArea : public wxTextCtrl
{
    wxDECLARE_EVENT_TABLE();

public:
    CompoundTextArea
        (
            wxWindow* parent,
            wxWindowID id,
            const wxString& value = wxEmptyString,
            const wxPoint& position = wxDefaultPosition,
            const wxSize& size = wxDefaultSize
        );

private:
    void OnKeyPress(wxKeyEvent &event);

};


#endif //COMPOUNDTEXTAREA_H
