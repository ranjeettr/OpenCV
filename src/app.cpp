#include "challenge/app.h"
#include "challenge/ai.h"
#include "challenge/overlay.h"
#include "challenge/input.h"

using namespace std;
using namespace std::chrono;

bool App::init() {
    if (!vc_.open("video.mp4")) {
        cout << "Could not open input file!" << endl;
        return false;
    }

    return true;
}

void App::run() {
    Stream(vc_, [](cv::Mat &frame) {
        // TODO: resize image to size expected by the Detect function
        cv::Mat resized;

        // TODO: Detection takes too much time, run it in a separate thread
        auto boxes = Detect(resized);

        // TODO: scale bounding boxes to input frame
        auto scaled = boxes;

        // TODO: draw most recent boxes onto current frame
        Overlay(frame, scaled);

        cv::imshow("Output", frame);

        // keep running until a key is pressed
        return cv::pollKey() < 0;
    });

    cv::destroyWindow("Output");
}
