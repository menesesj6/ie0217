#include <wx/wx.h>

class App : public wxApp{
    public:
        bool OnInit(){
            // Crear puntero de la ventana
            wxFrame* window = new wxFrame(NULL, wxID_ANY, "GUI Test", wxDefaultPosition, wxSize(600, 400));

            // Crear puntero del sizer
            wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);

            // Crear puntero del texto
            wxStaticText* text = new wxStaticText(window, wxID_ANY, "Well Done!\nEverything seems to be working", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL);

            // Establecer el font
            text->SetFont(wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));

            // Configurar el sizer
            sizer->Add(text, 1, wxALIGN_CENTER);

            // ASignar sizer a la ventana
            window->SetSizer(sizer);

            // MOstrar la ventana resultante
            window->Show();
            return true;
        }
};

wxIMPLEMENT_APP(App);