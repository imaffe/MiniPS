#pragma once
#include <string>
#include <opencv2/opencv.hpp>
class Model
{
protected:
    cv::Mat img;

public:
    Model(){}
    ~Model(){}
    bool OpenFile(const std::string& path);
    std::shared_ptr<cv::Mat> GetImage();
    std::shared_ptr<Notification> updatePictureNotification;
    std::shared_ptr<Notification> completeCommandNotification;
};

