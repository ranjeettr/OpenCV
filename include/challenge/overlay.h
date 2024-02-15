#pragma once

#include "opencv2/opencv.hpp"
#include "challenge/ai.h"

/**
 * Overlay takes a list of detected bounding boxes and draws them onto the supplied frame. See images folder for
 * an example.
 * @param frame a CV matrix
 * @param detections a list of detected bounding boxes
 */
void Overlay(const cv::Mat &frame, const std::vector<Detection> &detections);
