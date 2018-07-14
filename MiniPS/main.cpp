#include "App.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    App* app = new App;
    app->run();
    return a.exec();
}
