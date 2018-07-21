#pragma once
#include "Comman/Comman.h"
#include "ViewModel/ViewModel.h"

class ViewModel;

class OpenFileCommand : public ICommandBase {
public:
    OpenFileCommand(){}
    OpenFileCommand(std::shared_ptr<ViewModel> _viewmodel) : viewmodel(_viewmodel) {}
    void SetParameter(const std::shared_ptr<ICommandParameter>& _param) {
        pathParam = std::static_pointer_cast<PathParameter>(_param);
    }
    void Exec() {
        std::string path = pathParam->GetPath();
        viewmodel->ExecOpenFileCommand(path);
    }
protected:
    std::shared_ptr<ViewModel> viewmodel;
    std::shared_ptr<PathParameter> pathParam;
};