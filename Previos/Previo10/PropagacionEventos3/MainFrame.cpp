#include "MainFrame.hpp"
#include <wx/wx.h>

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title){
    wxPanel* panel = new wxPanel(this);

    wxButton* button1 = new wxButton(panel, wxID_ANY, "Button1", wxPoint(300, 275), wxSize(200, 50));
    wxButton* button2 = new wxButton(panel, wxID_ANY, "Button2", wxPoint(300, 350), wxSize(200, 50));

    this->Bind(wxEVT_BUTTON, &MainFrame::OnAnyButtonClicked, this);
    button1->Bind(wxEVT_BUTTON, &MainFrame::OnButton1Clicked, this);
    button2->Bind(wxEVT_BUTTON, &MainFrame::OnButton2Clicked, this);

    CreateStatusBar();
}

void MainFrame::OnAnyButtonClicked(wxCommandEvent& evt){
    wxLogMessage("Button Clicked");
}

void MainFrame::OnButton1Clicked(wxCommandEvent& evt){
    wxLogStatus("Button 1 Clicked");
    evt.Skip();
}

void MainFrame::OnButton2Clicked(wxCommandEvent& evt){
    wxLogStatus("Button 2 Clicked");
}
