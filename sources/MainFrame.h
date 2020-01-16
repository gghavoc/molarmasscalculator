//
// Created by clarence on 13/01/2020.
//

#ifndef MAINFRAME_H
#define MAINFRAME_H

#include <wx/wx.h>
#include "EventHandler.h"

// Forward Declarations
class PaintWindow;
class CompoundTextArea;
class ElementListBox;
class EventHandler;

enum CUSTOM_ID : unsigned int
{
    BtnCalculate = 1,
    WnwPaint,
    TxtInputArea,
    TxtElementList,
    FrmClick,
    TxtTotalMass,
};

class MainFrame : public wxFrame
{

public:
    MainFrame(const wxString& title);
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

    // THIS CLASS HANDLES EVENTS
    wxDECLARE_EVENT_TABLE();
};

#endif //MAINFRAME_H
