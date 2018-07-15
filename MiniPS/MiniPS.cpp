#include "MiniPS.h"
#include <string>
#include <QFileDialog>  
#include <QMessageBox>

MiniPS::MiniPS(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    updatePictureNotificaition = std::static_pointer_cast<Notification, UpdateViewNotification> \
        (std::shared_ptr<UpdateViewNotification>(new UpdateViewNotification(std::shared_ptr<MiniPS>(this))));
}

void MiniPS::SetOpenFileCommand(std::shared_ptr<Command> cmd) {
    openFileCommand = cmd;
}

std::shared_ptr<Notification> MiniPS::GetUpdatePictureNotification(){
    return updatePictureNotification;
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
        openFileCommand->SetParameters(std::static_pointer_cast<Parameters, PathParameters>(std::shared_ptr<PathParameters>(new PathParameters(filename.toStdString()))));
        openFileCommand->Exec();
    }
}

void MiniPS::ShowPicture(const std::shared_ptr<QImage> qimg){
    
}
