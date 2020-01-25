//
// Created by clarence on 13/01/2020.
//

#include "MainFrame.h"
#include "CompoundTextArea.h"
#include "MolarMass.h"
#include "ElementResultsList.h"
#include "TotalTextOutput.h"
#include <wx/button.h>
#include <wx/stattext.h>
#include <wx/menu.h>
#include <wx/app.h>
#include <wx/msgdlg.h>
#include <wx/sizer.h>

// STATIC BINDING
wxBEGIN_EVENT_TABLE(MainFrame,wxFrame)
                EVT_MOUSE_EVENTS(MainFrame::OnClick)
                EVT_MENU(wxID_EXIT, MainFrame::OnExit)
                EVT_MENU(wxID_ABOUT, MainFrame::OnAbout)
                EVT_BUTTON(CUSTOM_ID::BtnCalculate, MainFrame::OnButtonCalculate)
                EVT_SIZE(MainFrame::OnSize)
                EVT_TEXT_ENTER(CUSTOM_ID::TxtInputArea, MainFrame::OnButtonCalculate)
wxEND_EVENT_TABLE();

MainFrame::MainFrame(const wxString& title)
        : wxFrame
            (
            nullptr,
            wxID_ANY,
            title,
            wxDefaultPosition,
            wxDefaultSize,
            wxMINIMIZE_BOX  | wxSYSTEM_MENU | wxCAPTION | wxCLOSE_BOX |
            wxCLIP_CHILDREN | wxRESIZE_BORDER | wxMAXIMIZE_BOX
            )
{
    // Sets minimum size to the main frame
    this->SetMinSize(wxSize(500,460));

    // Make frame focusable
    this->SetCanFocus(true);

    // Create buttons
    buttonCalculate = new wxButton
            (
            this,
            CUSTOM_ID::BtnCalculate,
            wxT("&Calculate"),
            wxPoint(390, 10),
            wxSize(100,50)
            );

    // Create a text input area
    textArea = new CompoundTextArea
            (
            this,
            CUSTOM_ID::TxtInputArea,
            wxEmptyString,
            wxPoint(10,10),
            wxSize(370,50)
            );

    // Creates an area where parsed elements are listed
    elementResultsList = new ElementResultsList
            (
            this,
            CUSTOM_ID::TxtElementList,
            wxPoint(10, 70),
            wxSize(480, 250)
            );
    elementResultsList->Show(true);

    // Creates a text area for total mass
    totalTextOutput = new TotalTextOutput
            (
                this,
                wxID_ANY,
                wxDefaultPosition,
                wxDefaultSize
            );


    // Creates menu
    menuFile = new wxMenu();

    // Adds entries in the menu
    menuFile->Append(wxID_ABOUT, wxT("&About\tF1"),
            wxT("Show information about the program."));
    menuFile->Append(wxID_EXIT, wxT("&Exit\tALT+F4"),
            wxT("Exit the program."));

    // Creates a menu bar
    menuBar = new wxMenuBar();

    // Adds menu entry in menu bar
    menuBar->Append(menuFile, wxT("&File"));

    // Tells the object to attach the menu bar, must be done explicitly
    this->SetMenuBar(menuBar);

    // Creates a status bar
    statusBar = new wxStatusBar(this, wxID_ANY);

    // Attaches status bar to frame
    SetStatusBar(statusBar);

    // Sets icon of window
    this->SetIcon(wxIcon());

    // event handler, experiment
    this->eventHandler = new EventHandler();
    this->PushEventHandler(eventHandler);

    // sizer
    topVertSizer = new wxBoxSizer(wxVERTICAL);
    childTopHorSizer = new wxBoxSizer(wxHORIZONTAL);
    childBottomHorSizer = new wxBoxSizer(wxHORIZONTAL);
    childBottomVertSizer = new wxBoxSizer(wxVERTICAL);

    // Attaches top level sizer to the frame
    this->SetSizer(topVertSizer, true);

    // input area
    childTopHorSizer->Add(textArea, 1,   wxALL | wxEXPAND, 5);
    childTopHorSizer->Add(buttonCalculate, 0,  wxALL , 5);

    // total mass
    childBottomHorSizer->Add(childBottomVertSizer, 1,   wxALIGN_CENTER_VERTICAL | wxALL , 5);
    childBottomVertSizer->Add(totalTextOutput, 1, wxALIGN_CENTER_HORIZONTAL | wxALL, 5);

    // Adds children to the top level sizer
    topVertSizer->Add(childTopHorSizer, 0, wxALL | wxEXPAND, 5);
    topVertSizer->Add(elementResultsList, 1, wxALL | wxEXPAND , 10);
    topVertSizer->Add(childBottomHorSizer, 0, wxALL | wxEXPAND, 5);

    return;
}

void MainFrame::OnExit(wxCommandEvent &event)
{
    this->Close(true);
    return;
}

void MainFrame::OnAbout(wxCommandEvent &event)
{
    wxString msg, caption;
    msg.Printf(wxT("Hello! Welcome to %s"),
               wxTheApp->GetAppDisplayName());
    caption.Printf(wxT("About %s"),
            wxTheApp->GetAppDisplayName());
    wxMessageBox(msg, caption, wxOK | wxICON_INFORMATION, this);
    return;
}

void MainFrame::OnSize(wxSizeEvent &event)
{
    wxTopLevelWindowBase::OnSize(event);
    return;
}

void MainFrame::OnButtonCalculate(wxCommandEvent &event)
{
    std::string Compound = textArea->GetValue().ToStdString();
    std::vector<std::pair<std::string, uint32_t>> elementMap = ParseElementCompoundToVector(Compound);

    elementResultsList->ClearResults();

    double totalMass = 0;

    for (const std::pair<const std::string, uint32_t >& PairRef : elementMap)
    {
        if (IsValidElement(PairRef.first))
        {
            elementResultsList->AddResult(PairRef.first, PairRef.second);
        }
        else
        {
            wxLogMessage(wxT("Please recheck your entries."));
        }
    }
//    wxString massString = wxString::Format(wxT("Total Mass: %f"), totalMass);
//    totalTextOutput->SetText(massString);

    return;
}

void MainFrame::OnClick(wxMouseEvent &event)
{
    if (event.ButtonDown())
    {
        this->SetFocus();
    }
    return;
}


MainFrame::~MainFrame()
{
    this->PopEventHandler(true);
    return;
}