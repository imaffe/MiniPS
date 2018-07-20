#ifndef OPTIONWINDOW_H
#define OPTIONWINDOW_H

#include <QtWidgets/QWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QSlider> 
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QLineEdit>
class OptionWindow: public QWidget
{
    Q_OBJECT
public:
    OptionWindow(QWidget *parent = 0);
    QPushButton *butconsub;
    QSlider *sldcon;
    QSpinBox *spncon;
    QPushButton *butbrisub;
    QSlider *sldbri;
    
    QSpinBox *spnbri;
    QPushButton *butguassfil;
    QPushButton *butblurfil;
    QPushButton *butfil1_past;
    QPushButton *butfil2_black;

 

private:
    void setlist();
    void setwid();
    QWidget *contrast;
    QWidget *filter;
    QHBoxLayout *toplay;
    QStackedWidget *stack;
    QListWidget *list;
    void setconwid();
    void setfilwid();

private slots:


};

#endif // OPTIONWINDOW_H
