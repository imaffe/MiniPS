#include "optionwindow.h"
OptionWindow::OptionWindow(QWidget *parent):QWidget(parent)
{
    
    setwid();
    setlist();

    toplay=new QHBoxLayout;
    toplay->addWidget(stack);
    toplay->addWidget(list);
    setLayout(toplay);

}
void OptionWindow::setwid(){
    stack=new QStackedWidget;
    
    //³õÊ¼»¯
    setconwid();
    setfilwid();
    stack->addWidget(contrast);
    stack->addWidget(filter);
}
void OptionWindow::setlist(){
    list=new QListWidget;
    list->insertItem(0,tr("contrast"));
    list->insertItem(1,tr("filter"));
    connect(list,SIGNAL(currentRowChanged(int)),stack,SLOT(setCurrentIndex(int)));

}
void OptionWindow::setconwid() {
    contrast = new QWidget;
    QGridLayout *laycon = new QGridLayout;
    butconsub = new QPushButton;
    butconsub->setText("try");
    butconsub->setFixedSize(100, 50);

    sldcon = new QSlider(Qt::Horizontal);
    sldcon->setMinimum(0);
    sldcon->setMaximum(150);
    sldcon->setFixedSize(200, 10);
    sldcon->setValue(50);

    spncon = new QSpinBox;
    spncon->setMaximum(150);
    spncon->setMinimum(0);
    spncon->setFixedSize(100, 50);
    spncon->setValue(50);
    spncon->setSingleStep(5);

    connect(sldcon, SIGNAL(valueChanged(int)),spncon , SLOT(setValue(int)));
    connect(spncon, SIGNAL(valueChanged(int)), sldcon, SLOT(setValue(int)));
    laycon->addWidget(spncon, 0, 0);
    laycon->addWidget(butconsub, 0, 1);
    laycon->addWidget(sldcon, 1, 0);

    butbrisub = new QPushButton;
    butbrisub->setText("try");
    butbrisub->setFixedSize(100, 50);

    sldbri = new QSlider(Qt::Horizontal);
    sldbri->setMinimum(0);
    sldbri->setMaximum(150);
    sldbri->setFixedSize(200, 10);
    sldbri->setValue(50);

    spnbri = new QSpinBox;
    spnbri->setMaximum(150);
    spnbri->setMinimum(0);
    spnbri->setFixedSize(100, 50);
    spnbri->setValue(50);
    spnbri->setSingleStep(5);

    connect(sldbri, SIGNAL(valueChanged(int)), spnbri, SLOT(setValue(int)));
    connect(spnbri, SIGNAL(valueChanged(int)), sldbri, SLOT(setValue(int)));
    laycon->addWidget(spnbri, 3, 0);
    laycon->addWidget(butbrisub, 3, 1);
    laycon->addWidget(sldbri, 4, 0);
    contrast->setLayout(laycon);
    contrast->setFixedSize(640, 320);
}
void OptionWindow::setfilwid() {
    filter = new QWidget;
    QGridLayout *layfil = new QGridLayout;

    butguassfil = new QPushButton;
    butblurfil= new QPushButton;
    butfil1_past = new QPushButton;
    butfil2_black= new QPushButton;
    
    butguassfil->setText("GuassFilter");
    butblurfil->setText("BlurFilter");
    butfil1_past->setText("PastFilter");
    butfil2_black->setText("BlackFilter");
    
    butguassfil->setFixedSize(80, 40);
    butblurfil->setFixedSize(80, 40);
    butfil1_past->setFixedSize(80, 40);
    butfil2_black->setFixedSize(80, 40);

    layfil->addWidget(butguassfil, 0, 0);
    layfil->addWidget(butblurfil, 0, 1);
    layfil->addWidget(butfil1_past, 1, 0);
    layfil->addWidget(butfil2_black, 1, 1);
    filter->setLayout(layfil);
    filter->setFixedSize(640, 320);
}
