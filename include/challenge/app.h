#pragma once

#include "opencv2/opencv.hpp"
#include "challenge/ai.h"
#include <vector>
#include <mutex>
#include <condition_variable>

class App {
public:
    App();
    ~App() = default;
    bool init();
    void run();
    bool callback(cv::Mat&);
    void DetectionThread();
private:
    cv::VideoCapture vc_{};
    bool m_ready;

    std::vector<cv::Mat> m_resizedFrame;
    std::mutex m_resizedMtx;
    std::condition_variable m_resizedCv;

    double m_scale;
    std::vector<Detection> m_scaled;
};
