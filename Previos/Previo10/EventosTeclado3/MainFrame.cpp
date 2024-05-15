#include "MainFrame.hpp"
#include <wx/wx.h>

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title){
    wxPanel* panel = new wxPanel(this,  wxID_ANY, wxDefaultPosition,wxDefaultSize, wxWANTS_CHARS);
    wxButton* btn1 = new wxButton(panel, wxID_ANY, "Button 1", wxPoint(300, 150), wxSize(200, 100));
    wxButton* btn2 = new wxButton(panel, wxID_ANY, "Button 2", wxPoint(300, 350), wxSize(200, 100));

    panel->Bind(wxEVT_CHAR_HOOK, &MainFrame::OnKeyEvent, this);

    CreateStatusBar();
}

void MainFrame::OnKeyEvent(wxKeyEvent& evt){
    wxChar keyChar = evt.GetUnicodeKey();

    if(keyChar == WXK_NONE){
        int keyCode = evt.GetKeyCode();
        wxLogStatus("Key Event %d", keyCode); 
    }else{
        wxLogStatus("Key Event %c", keyChar);
    }
}
