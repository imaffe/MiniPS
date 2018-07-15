#include "ViewModel.h"
void ViewModel::bind(std::shared_ptr<Model> model) {
    this->model = model;
}

std::shared_ptr<Command> ViewModel::GetOpenFileCommand() {
    return openFileCommand;
}

void ViewModel::ExecOpenFileCommand(std::string& path) {
    model->OpenFile(path);
}
void ViewModel::UpdatePicture(){
    cv::Mat cvimg = model->GetImage();
    qimg = new(ToQImage(cvimg));
    ////////////////////////////////////////////////////
    updateViewNotification->Exec();
}

void ViewModel::ExecCommandNotification(bool){

}

QImage ViewModel::ToQImage(cv::Mat cvimg){
    cv::Mat tempimg;
    cv::cvtColor(cvimg, tempimg, cv::COLOR_BGR2RGB);
    return QImage(temp_img.data, temp_img.cols, temp_img.rows,
                static_cast<int>(temp_img.step), format);
}

QImage ViewModel::GetImage(){
    return qimg;
}

void ViewModel::setUpdateViewNotification(std::shared_ptr<Notification> updateViewNotification){
    this->updateViewNotification = updateViewNotification;
}