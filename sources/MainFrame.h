//
// Created by clarence on 13/01/2020.
//

#ifndef MAINFRAME_H
#define MAINFRAME_H

#include <wx/frame.h>

// Forward Declarations
class PaintWindow;
class CompoundTextArea;
class wxButton;
class wxStaticText;
class wxBoxSizer;
class ElementResultsList;
class TotalTextOutput;

enum CUSTOM_ID : unsigned int
{
    BtnCalculate = wxID_HIGHEST,
    TxtInputArea,
    TxtElementList,
    TxtTotalMass,
};

class MainFrame : public wxFrame
{

public:
    MainFrame(const wxString& title);
    ~MainFrame();

private:
    // private methods
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void OnButtonCalculate(wxCommandEvent& event);
    void OnClick(wxMouseEvent& event);

private:
    // private data members
    wxMenu* menuFile;
    wxMenuBar* menuBar;
    wxStatusBar* statusBar;
    wxButton* buttonCalculate;
    CompoundTextArea* textArea;
    ElementResultsList* elementResultsList;
    TotalTextOutput* totalTextOutput;
    wxBoxSizer* topVertSizer; // top level sizer
    wxBoxSizer* childTopHorSizer; // sizer of textArea and buttonCalculate

    // THIS CLASS HANDLES EVENTS
    wxDECLARE_EVENT_TABLE();
};


#endif //MAINFRAME_H