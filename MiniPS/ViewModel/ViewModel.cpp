#include "ViewModel/ViewModel.h"
#include "Model/Model.h"
#include "Command//OpenFileCommand.h"
#include "Notification/Notification.h"
#include <QtGui/QImage>

ViewModel::ViewModel() {
    openFileCommand = std::static_pointer_cast<OpenFileCommand> \
        (std::shared_ptr<OpenFileCommand>(new OpenFileCommand(std::shared_ptr<ViewModel>(this))));
    convertImageFormatSink = std::static_pointer_cast<ConvertImageFormatNotification>
        (std::shared_ptr<ConvertImageFormatNotification>(new ConvertImageFormatNotification(std::shared_ptr<ViewModel>(this))));
}

void ViewModel::bind(std::shared_ptr<Model> model) {
    this->model = model;
}

std::shared_ptr<ICommandBase> ViewModel::GetOpenFileCommand() {
    return openFileCommand;
}

void ViewModel::SetUpdateViewNotifier(std::shared_ptr<IPropertyNotification> _updateViewNotifier) {
    this->updateViewNotifier = _updateViewNotifier;
}

std::shared_ptr<IPropertyNotification> ViewModel::GetConvertImageFormatSink() {
    return convertImageFormatSink;
}
void ViewModel::ExecOpenFileCommand(std::string& path) {
    model->OpenFile(path);
}
void ViewModel::ConvertImageFormat(){
    *qimg = MatToQImage(*cvimg);
    updateViewNotifier->OnPropertyChanged();
}


QImage ViewModel::MatToQImage(cv::Mat cvimg){
    cv::Mat tempimg;
    cv::cvtColor(cvimg, tempimg, cv::COLOR_BGR2RGB);
    QImage::Format format = QImage::Format_RGB888;
    return QImage(tempimg.data, tempimg.cols, tempimg.rows,
                static_cast<int>(tempimg.step), format);
}

std::shared_ptr<QImage> ViewModel::GetQImage(){
    return qimg;
}

void ViewModel::SetCvImage(std::shared_ptr<cv::Mat> _cvimg){
    cvimg = _cvimg;
}



