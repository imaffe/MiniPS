#pragma once

#include "Comman/Comman.h"
#include <opencv2/opencv.hpp>
#include <QtGui/QImage>

class Model;
class OpenFileCommand;
class IPropertyNotification;

class ViewModel
{
private:
    std::shared_ptr<QImage> qimg;
    std::shared_ptr<cv::Mat> cvimg;
    std::shared_ptr<Model> model;
private:
    std::shared_ptr<ICommandBase> openFileCommand;
    std::shared_ptr<IPropertyNotification> convertImageFormatSink;
    std::shared_ptr<IPropertyNotification> updateViewNotifier;
public:
    ViewModel();
    void bind(std::shared_ptr<Model> model);
    std::shared_ptr<ICommandBase> GetOpenFileCommand();
    void SetUpdateViewNotifier(std::shared_ptr<IPropertyNotification>);
    std::shared_ptr<IPropertyNotification> GetConvertImageFormatSink();
    void ExecOpenFileCommand(std::string&);
    void ConvertImageFormat();
    QImage MatToQImage(cv::Mat);
    std::shared_ptr<QImage> GetQImage();
    void SetCvImage(std::shared_ptr<cv::Mat>);
};
