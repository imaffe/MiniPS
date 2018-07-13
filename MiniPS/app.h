#include "MiniPS.h"
#include "Model.h"
#include "ViewModel.h"

class App {
private:
    std::shared_ptr<MiniPS> view;
    std::shared_ptr<Model> model;
    std::shared_ptr<ViewModel> viewmodel;

public:
    App();
    void run();
};