#include "View/MiniPS.h"
#include "ui_MiniPS.h"
#include "Command/OpenFileCommand.h"
#include "Notification//Notification.h"
#include <string>
#include <QFileDialog>  
#include <QMessageBox>
#include <QLabel>

MiniPS::MiniPS(QWidget *parent)
    : QMainWindow(parent) {
    ui.setupUi(this);
    updateViewSink = std::static_pointer_cast<UpdateViewNotification> \
        (std::shared_ptr<UpdateViewNotification>(new UpdateViewNotification(std::shared_ptr<MiniPS>(this)))); 
}

void MiniPS::SetOpenFileCommand(std::shared_ptr<ICommandBase> cmd) {
    openFileCommand = cmd;
}

std::shared_ptr<IPropertyNotification> MiniPS::GetUpdateViewSink() {
    return updateViewSink;
}


void MiniPS::SetQImage(std::shared_ptr<QImage> _qimg) {
    qimg = _qimg;
}
void MiniPS::OnOpenButtonClicked() {
    QString filename;
    filename = QFileDialog::getOpenFileName(this,
        tr("Choose an image"),
        "",
        tr("Image (*.png *.bmp *.jpg *.tif *.GIF)"));
    if (filename.isEmpty()) {
        QMessageBox::information(this, tr("Open file failed!"), tr("OK"));
        return;
    }
    else {
        openFileCommand->SetParameter(std::static_pointer_cast<PathParameter>(std::shared_ptr<PathParameter>(new PathParameter(filename.toStdString()))));
        openFileCommand->Exec();
    }
}

void MiniPS::ShowPicture(){
    QLabel *label = new QLabel();
    label->setPixmap(QPixmap::fromImage(*qimg));
    label->resize(QSize(qimg->width(), qimg->height()));
    ui.pic->setWidget(label);
}
