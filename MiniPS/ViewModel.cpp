#include "ViewModel.h"

void ViewModel::bind(std::shared_ptr<Model> model) {
    this->model = model;
}

std::shared_ptr<Command> ViewModel::GetOpenFileCommand() {
    return openFileCommand;
}

void ViewModel::ExecOpenFileCommand(std::string& path) {
    model->OpenFile(path);
}
