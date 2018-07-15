#include "Model.h"
#include <iostream>


bool Model::OpenFile(const std::string& path) {
    img = cv::imread(path);
    if (img.empty()) {
        return FALSE;
    }
    else {
        updatePictureNotification.Notify();
        return TRUE;
    } 
}

std::shared_ptr<cv::Mat> Model::GetImage(){
    return img;
}
