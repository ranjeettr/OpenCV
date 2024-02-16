#pragma once

#include "opencv2/opencv.hpp"
#include <functional>

typedef std::function<bool(cv::Mat&)> StreamCallback;

/**
 * Stream the supplied video at the correct FPS.
 * @param callback The callback will be called for each received frame. If it returns false, the streaming will stop
 */
void Stream(cv::VideoCapture&, StreamCallback callback);
