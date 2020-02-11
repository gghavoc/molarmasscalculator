//
// Created by clarence on 25/01/2020.
//

#ifndef MOLARMASSCALCULATOR_TOTALTEXTOUTPUT_H
#define MOLARMASSCALCULATOR_TOTALTEXTOUTPUT_H

#include <wx/scrolwin.h>
#include <wx/button.h>

// forward declaration
class wxStaticText;
class wxBoxSizer;

class TotalTextOutput : public wxScrolledWindow
{
public:
    TotalTextOutput
    (
        wxWindow* parent,
        wxWindowID Id = wxID_ANY,
        const wxPoint& pos = wxDefaultPosition,
        const wxSize& size = wxDefaultSize,
        long style = wxBORDER_SIMPLE | wxHSCROLL,
        const wxString& name = wxPanelNameStr
    );
    ~TotalTextOutput();

public:
    void SetText(const wxString& total);

private:
    wxStaticText* totalText;
    wxBoxSizer* topHorSizer;

private:

private:
    wxDECLARE_EVENT_TABLE();
};


#endif //MOLARMASSCALCULATOR_TOTALTEXTOUTPUT_H
