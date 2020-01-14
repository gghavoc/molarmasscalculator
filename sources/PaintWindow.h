//
// Created by clarence on 14/01/2020.
//

#ifndef PAINTWINDOW_H
#define PAINTWINDOW_H

#include <wx/wx.h>


class PaintWindow : public wxWindow
{

public:
    PaintWindow(wxWindow* parent);

private:
    void OnMotion(wxMouseEvent& event);

    DECLARE_EVENT_TABLE();

};


#endif //PAINTWINDOW_H
