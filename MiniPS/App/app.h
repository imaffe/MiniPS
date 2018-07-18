#pragma once
#include "View/MiniPS.h"
#include "Model/Model.h"
#include "ViewModel/ViewModel.h"
#include "Notification/Notification.h"
#include "Comman/Comman.h"

class App {
public:
    App(): view(new MiniPS), model(new Model), viewmodel(new ViewModel){
        viewmodel->bind(model);
        view->SetOpenFileCommand(viewmodel->GetOpenFileCommand());
        viewmodel->SetUpdateViewNotifier(view->GetUpdateViewSink());
        model->SetConvertImageFormatNotifier(viewmodel->GetConvertImageFormatSink());
        view->SetQImage(viewmodel->GetQImage());
        viewmodel->SetCvImage(model->GetCvImage());
    }
    

private:
    std::shared_ptr<MiniPS> view;
    std::shared_ptr<Model> model;
    std::shared_ptr<ViewModel> viewmodel;

public:
    void show();
};