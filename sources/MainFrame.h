//
// Created by clarence on 13/01/2020.
//

#ifndef MAINFRAME_H
#define MAINFRAME_H

#include <wx/frame.h>
#include "EventHandler.h"

// Forward Declarations
class PaintWindow;
class CompoundTextArea;
class ElementListBox;
class EventHandler;
class wxButton;
class wxStaticText;

enum CUSTOM_ID : unsigned int
{
    BtnCalculate = 1,
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
    void OnSize(wxSizeEvent& event);
    void OnButtonCalculate(wxCommandEvent& event);
    void OnClick(wxMouseEvent& event);

    // private data members
    wxMenu* menuFile;
    wxMenuBar* menuBar;
    wxStatusBar* statusBar;
    wxButton* buttonCalculate;
    CompoundTextArea* textArea;
    ElementListBox* elementListBox;
    wxStaticText* totalMassText;
    EventHandler* eventHandler;

    // THIS CLASS HANDLES EVENTS
    wxDECLARE_EVENT_TABLE();
};


#endif //MAINFRAME_H