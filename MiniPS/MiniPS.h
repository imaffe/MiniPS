#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MiniPS.h"
#include "Command.h"
#include "Notification.h"

class MiniPS : public QMainWindow
{
    Q_OBJECT

public:
    MiniPS(QWidget *parent = Q_NULLPTR);
    ~MiniPS(){}
    void SetOpenFileCommand(std::shared_ptr<Command>);
    //std::shared_ptr<Notification> GetUpdateViewNotification();
private slots:
    void OnOpenButtonClicked();
private:
    Ui::MiniPSClass ui;
    std::shared_ptr<QImage> img;
    std::shared_ptr<Command> openFileCommand;
    //std::shared_ptr<Notification> updateViewNotificaition;
};
