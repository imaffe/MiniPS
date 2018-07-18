#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MiniPS.h"
#include "Comman/Comman.h"


class MiniPS : public QMainWindow
{
    Q_OBJECT

public:
    MiniPS(QWidget *parent = Q_NULLPTR);
    void SetOpenFileCommand(std::shared_ptr<ICommandBase>);
    std::shared_ptr<IPropertyNotification> GetUpdateViewSink();
    void SetQImage(std::shared_ptr<QImage>);
    void ShowPicture();
    
private slots:
    void OnOpenButtonClicked();
private:
    Ui::MiniPSClass ui;
    std::shared_ptr<QImage> qimg;
public:
    std::shared_ptr<ICommandBase> openFileCommand;
    std::shared_ptr<IPropertyNotification> updateViewSink;
    
};
