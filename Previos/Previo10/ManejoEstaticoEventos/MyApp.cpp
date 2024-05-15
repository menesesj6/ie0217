#include "MyApp.hpp"
#include "MainFrame.hpp"

wxIMPLEMENT_APP(App);

bool App::OnInit(){
    // ALocar memoria para un nuevo main frame
    MainFrame* mainFrame = new MainFrame("C++ GUI");
    // mainFrame->SetClientSize(800, 600);
    // mainFrame->Center();
    // Mostrar ventana resultante
    mainFrame->Show();
    return true;
}