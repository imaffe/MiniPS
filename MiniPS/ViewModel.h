#pragma once
#include "Command.h"
#include "Model.h"
#include "Notification.h"

class ViewModel
{
private:
    std::shared_ptr<Model> model;
    std::shared_ptr<Command> open_file_command;
    std::shared_ptr<Notification> update_display_data_notification;
    std::shared_ptr<Notification> update_view_notification;
public:
    ViewModel();
    void bind(std::shared_ptr<Model> model);
    void exec_open_file_command(std::string path);
    void set_update_view_notification(std::shared_ptr<Notification> notification);

    std::shared_ptr<Command> get_open_file_command();

    std::shared_ptr<Notification> get_update_display_data_notification();
    void notified();
    ~ViewModel();
};

