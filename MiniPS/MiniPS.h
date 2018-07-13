#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MiniPS.h"

class MiniPS : public QMainWindow
{
    Q_OBJECT

public:
    MiniPS(QWidget *parent = Q_NULLPTR);
    ~MiniPS();
    void set_open_file_command(std::shared_ptr<Command>);
    std::shared_ptr<Notification> get_update_view_notification();
private slots:
    void on_button_open_clicked();
private:
    Ui::MiniPSClass ui;
    std::shared_ptr<Command> open_file_command;
    std::shared_ptr<Notification> update_view_notification;
};
