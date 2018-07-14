#include "Model.h"
#include <iostream>

void Model::OpenFile(const std::string& path) {
    img = cv::imread(path);
    if (img.empty()) {
        this->notify(false);
    }
    else {
        std::string s = "image";
        this->notify(s);
    }
}
