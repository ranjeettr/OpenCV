#include "challenge/overlay.h"

void Overlay(const cv::Mat &frame, const std::vector<Detection> &detections) {
    for( auto it = detections.begin(); it != detections.end(); it++ )
    {
	    cv::Rect rect(it->x, it->y, it->width, it->height);
	    cv::rectangle(frame,rect,cv::Scalar(255,0,0),1,8,0);
    }
}
