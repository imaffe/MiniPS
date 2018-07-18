#pragma once

#include <Comman/Comman.h>
#include <string>
#include <opencv2/opencv.hpp>
class Model
{
private:
    std::shared_ptr<cv::Mat> img;
    std::shared_ptr<IPropertyNotification> convertImageFormatNotifier;
public:
    Model(){}
    ~Model(){}
    bool OpenFile(const std::string& path);
    std::shared_ptr<cv::Mat> GetCvImage();
    void SetConvertImageFormatNotifier(std::shared_ptr<IPropertyNotification>);

};

