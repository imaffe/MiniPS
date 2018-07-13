#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MiniPS.h"

class MiniPS : public QMainWindow
{
    Q_OBJECT

public:
    MiniPS(QWidget *parent = Q_NULLPTR);

private:
    Ui::MiniPSClass ui;
};
