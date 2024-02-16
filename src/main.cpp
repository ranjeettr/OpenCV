#include "challenge/app.h"
#include <thread>

int main() {
    App app;

    std::thread tid = std::thread(&App::DetectionThread, &app);

    if(!app.init()){
        return -1;
    }

    app.run();

    tid.join();

    return 0;
}
