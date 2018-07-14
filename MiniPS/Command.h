#include "Parameters.h"
#include "ViewModel.h"
#include <string>

class Command{
protected:
    std::shared_ptr<Parameters> params;
    std::shared_ptr<ViewModel> viewmodel;
public:
    Command(){}
    void SetParameters(std::shared_ptr<Parameters> parameters){
        params = parameters;
    }
    virtual void Exec() = 0;
};

class openFileCommand : public Command {
public:
    void Exec() {
        std::string path = std::static_pointer_cast<PathParameters, Parameters>(Command::params)->GetPath();
        viewmodel->ExecOpenFileCommand(path);
    }
};