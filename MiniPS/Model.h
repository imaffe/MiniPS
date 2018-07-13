#pragma once
class Model
{
private:
    cv:
public:
    Model();
    void set_update_display_data_notification(std::shared_ptr<Notification> notification);
    void open_file(std::string path);
    ~Model();
};

