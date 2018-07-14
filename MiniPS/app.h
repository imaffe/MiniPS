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
        //viewmodel->set_update_view_notification(view->get_update_view_notification());
        //model->set_update_display_data_notification(viewmodel->get_update_display_data_notification());
    }
    

private:
    std::shared_ptr<MiniPS> view;
    std::shared_ptr<Model> model;
    std::shared_ptr<ViewModel> viewmodel;

public:
    App();
    void show();
};