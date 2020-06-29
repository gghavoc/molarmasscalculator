//
// Created by clarence on 14/01/2020.
//

#include "PaintWindow.h"
#include <wx/dcclient.h>

BEGIN_EVENT_TABLE(PaintWindow, wxWindow)
                EVT_MOTION(PaintWindow::OnMotion)
END_EVENT_TABLE();

PaintWindow::PaintWindow(wxWindow* parent) :
    wxWindow(parent, wxID_ANY, wxPoint(200,200), wxSize(200,200))
{
    return;
}

void PaintWindow::OnMotion(wxMouseEvent& event)
{
    if (event.Dragging())
    {
        wxClientDC dc(this);
        wxPen pen(*wxRED, 20); // red pen of width 1
        dc.SetPen(pen);
        dc.DrawPoint(event.GetPosition());
        dc.SetPen(wxNullPen);
    }

    return;
}

