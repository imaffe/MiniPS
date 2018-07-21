#include "Model/Model.h"
#include "Notification/Notification.h"
#include <iostream>
#include <vector>

bool Model::OpenFile(const std::string& path) {
    using namespace cv;
    *img = imread(path);


    if (img->empty()) {
        return 0;
    }
    else {
        convertImageFormatNotifier->OnPropertyChanged();
        return 1;
    } 
}


std::shared_ptr<cv::Mat> Model::GetCvImage(){
    return img;
}

void Model::SetConvertImageFormatNotifier(std::shared_ptr<IPropertyNotification> _convertImageFormatNotifier) {
    convertImageFormatNotifier = _convertImageFormatNotifier;
}
