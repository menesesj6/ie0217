#include "MainFrame.hpp"
#include <wx/wx.h>

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title){
    wxPanel* panel = new wxPanel(this);

    CreateStatusBar();

    panel->Bind(wxEVT_LEFT_DOWN, &MainFrame::OnMouseEvent, this);
}

void MainFrame::OnMouseEvent(wxMouseEvent& evt){
    wxPoint mousePos = evt.GetPosition();
    wxString message = wxString::Format("Mouse event detected! (x: %d, y: %d)", mousePos.x, mousePos.y);
    wxLogStatus(message);
}
