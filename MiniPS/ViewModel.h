#pragma once
#include "Command.h"
#include "Model.h"
#include "Notification.h"

class ViewModel
{
private:
    std::shared_ptr<QImage> qimg;
    std::shared_ptr<Model> model;
public:
    std::shared_ptr<Command> openFileCommand;
    std::shared_ptr<Notification> updatePictureNotification;
    std::shared_ptr<Notification> completeCommandNotification;
    std::shared_ptr<Notification> updateViewNotification;
public:
    ViewModel(){
        std::shared_ptr<openFileCommand> openFileCommandPtr = new OpenFileCommand(std::shared_ptr<ViewModel>(this));
        openFileCommand = std::static_pointer_cast<Command, OpenFileCommand>(openFileCommandPtr);
        std::shared_ptr<UpdatePictureNotifier> updatePictureNotifierPtr = new UpdatePictureNotifier(std::shared_ptr<ViewModel>(this));
        updatePictureNotification = std::static_pointer_cast<Notification, UpdatePictureNotifier>(updatePictureNotifierPtr);
    }
    void bind(std::shared_ptr<Model> model);
    std::shared_ptr<Command> GetOpenFileCommand();
    void setUpdatePictureNotification(std::shared_ptr<Notification>);
    void setCompleteCommandNotification(std::shared_ptr<Notification>);
    void setUpdateViewNotification(std::shared_ptr<Notification>);
    void ExecOpenFileCommand(std::string&);
    void UpdatePicture();
    void ExecCommandNotification(bool);
};

