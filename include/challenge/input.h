#pragma once

#include "opencv2/opencv.hpp"

typedef bool (*StreamCallback)(cv::Mat&);

/**
 * Stream the supplied video at the correct FPS.
 * @param callback The callback will be called for each received frame. If it returns false, the streaming will stop
 */
void Stream(cv::VideoCapture&, StreamCallback callback);