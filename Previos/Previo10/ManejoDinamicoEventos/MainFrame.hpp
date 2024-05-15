#include <wx/wx.h>

class MainFrame : public wxFrame{
    public:
        // Constructor del main frame
        MainFrame(const wxString& title);
    private:
        void OnButtonClicked(wxCommandEvent& evt);
        void OnSliderChanged(wxCommandEvent& evt);
        void OnTextChanged(wxCommandEvent& evt);
};