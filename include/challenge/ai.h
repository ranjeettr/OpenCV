#pragma once

#include <vector>

#include "opencv2/opencv.hpp"

const int input_width = 400;
const int input_height = 225;

struct Detection {
    int x;
    int y;
    int width;
    int height;
};

/**
 * Detect runs the extremely proprietary algorithm to detect areas of interest in the input image.
 * @param[in] input Matrix that represents the input image. Needs to have the correct dimensions
 *                  defined in input_width and input_height. If the dimensions are not correct
 *                  no detection will be performed.
 * @return a vector of Detection structs that describe the areas of interest. Values are relative
 *         to the size of the input image.
 */
std::vector<Detection> Detect(const cv::Mat &input);
