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
    void OpenFile(const std::string& path);
    
};

