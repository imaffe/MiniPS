#pragma once
#include "MiniPS.h"
#include "Model.h"
#include "ViewModel.h"
#include "Notification.h"
#include "Command.h"

class App {
public:
    App(): view(new MiniPS), model(new Model), viewmodel(new ViewModel){
        viewmodel->bind(model);
        view->SetOpenFileCommand(viewmodel->GetOpenFileCommand());
        viewmodel->SetUpdateViewNotification(view->GetUpdateViewNotification());
    }
    

private:
    std::shared_ptr<MiniPS> view;
    std::shared_ptr<Model> model;
    std::shared_ptr<ViewModel> viewmodel;

public:
    App();
    void show();
};