#include "app.h"

App::App() : view(new MiniPS), model(new Model), viewmodel(new ViewModel) {
    viewmodel->bind(model);
    
}

void App::run() {

}