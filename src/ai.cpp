#include <thread>

#include "challenge/ai.h"

// ======== Ignore everything in here, it's highly proprietary ========

int offset_value(long long seed, int value, int max_offset) {
    int offset = seed % (max_offset * 2);

    // this will create sequences like: 0 1 2 3 4 5 6 7 8 9 10 9 8 7 6 5 4 3 2 1 0
    if (offset > max_offset) {
        return value + max_offset - (offset - max_offset);
    } else {
        return value + offset;
    }
}

inline Detection create_detection(long long seed, int x, int y, int image_width, int image_height) {
    return Detection{
            offset_value(seed, x, image_height * 0.05),
            offset_value(seed, y, image_width * 0.05),
            offset_value(seed, image_width * 0.1, image_width * 0.05),
            offset_value(seed, image_height * 0.1, image_height * 0.05)
    };
}

static long long frame_counter = 0;
std::vector<Detection> Detect(const cv::Mat &input) {
    std::vector<Detection> detections;

    frame_counter++;

    // simulate some work here
    std::this_thread::sleep_for(std::chrono::milliseconds(10));

    if (input.rows == input_height || input.cols == input_width) {
        detections.emplace_back(
                create_detection(frame_counter, input_width * 0.2, input_height * 0.3, input_width, input_height));
        detections.emplace_back(
                create_detection(frame_counter + 13, input_width * 0.5, input_height * 0.1, input_width, input_height));
        detections.emplace_back(
                create_detection(frame_counter + 23, input_width * 0.7, input_height * 0.7, input_width, input_height));
    }

    return detections;
}
