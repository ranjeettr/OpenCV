#include <thread>

#include "challenge/input.h"

using namespace std;
using namespace std::chrono;

void Stream(cv::VideoCapture &vc, StreamCallback callback) {
    auto frame_start = high_resolution_clock::now();
    cv::Mat frame;

    int fps = (int) vc.get(cv::CAP_PROP_FPS);
    duration<double, milli> expected_frame_time(1000.0 / fps);

    while(true) {
        bool success = vc.read(frame);
        if (!success) {
            break;
        }

        if(!callback(frame)) {
            break;
        }

        // calculate per-frame timing, so we can read the video at the correct speed/FPS
        auto now = high_resolution_clock::now();
        duration<double, milli> frame_time = now - frame_start;
        frame_start = now;

        if (frame_time < expected_frame_time) {
            this_thread::sleep_for(expected_frame_time - frame_time);
        }
    }
}
