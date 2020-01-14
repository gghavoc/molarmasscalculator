//
// Created by clarence on 13/01/2020.
//

#include "MainApp.h"
#include "MainFrame.h"

bool MainApp::OnInit()
{
    frame = new MainFrame(appName);
    frame->Show(true);

    return wxAppConsoleBase::OnInit();
}

MainApp::MainApp()
        : frame(nullptr), appName(wxT("Molar Mass Calculator"))
{
    this->SetAppDisplayName(appName);
}

MainApp::~MainApp()
{

}
