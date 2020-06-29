//
// Created by clarence on 13/01/2020.
//

#ifndef MAINAPP_H
#define MAINAPP_H

#include <wx/app.h>

class MainFrame;

class MainApp : public wxApp
{
public:
    MainApp();
    ~MainApp();

    virtual bool OnInit() override;


private:
    MainFrame* frame;
    wxString appName;
};

wxDECLARE_APP(MainApp);

#endif //MAINAPP_H
