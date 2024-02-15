#pragma once

#include "opencv2/opencv.hpp"

class App {
public:
    ~App() = default;
    bool init();
    void run();
private:
    cv::VideoCapture vc_{};
};