#include "challenge/app.h"
#include "challenge/ai.h"
#include "challenge/overlay.h"
#include "challenge/input.h"
#include <thread>

using namespace std;
using namespace std::placeholders;
using namespace std::chrono;

App::App() : m_ready(true)
{}

bool App::init() {
    if (!vc_.open(0)) {
        cout << "Could not open input file!" << endl;
        return false;
    }

    return true;
}

void App::DetectionThread()
{
	cout << "Starting Detect Thread" << endl;
	while(m_ready)
	{
		cv::Mat resized;
		{
			std::unique_lock<std::mutex> lck(m_mutex);
			if( m_resizedFrame.empty() )
			{
				//Wait until we get a resized frame
				m_resizedCv.wait(lck);
			}
	
			resized = m_resizedFrame.back();
			m_resizedFrame.clear();
		}

	        auto boxes = Detect(resized);
		for(auto it = boxes.begin(); it != boxes.end(); it++)
		{
			it->x = (double)it->x/m_scale;
			it->y = (double)it->y/m_scale;
			it->width = (double)it->width/m_scale;
			it->height = (double)it->height/m_scale;
		}
	        // scaled bounding boxes to input frame
		std::unique_lock<std::mutex> lck(m_mutex);
		m_scaled.clear();
		m_scaled = boxes;
	}
	cout << "Detect Thread exiting" << endl;
}

bool App::callback(cv::Mat &frame)
{
        // resize image to size expected by the Detect function
        cv::Mat resized;
	m_scale = (double)input_width/(double)frame.cols;
	cv::resize(frame, resized, cv::Size(input_width, m_scale*(double)frame.rows));
	{
		std::unique_lock<std::mutex> lck(m_mutex);
		m_resizedFrame.clear();
		m_resizedFrame.push_back(resized);
		m_resizedCv.notify_all(); //notify DetectionThread that a frame is available to process
	}


	{
        	// draw most recent boxes onto current frame
		std::unique_lock<std::mutex> lck(m_mutex);
        	Overlay(frame, m_scaled);
	}

        cv::imshow("Output", frame);

        // keep running until a key is pressed
        return cv::pollKey() < 0;
}

void App::run() {
    Stream(vc_, std::bind(&App::callback, this, _1));
    cout << "Stream done" << endl;
    m_ready = false;
    cv::destroyWindow("Output");
    cout << "Destroyed Window" << endl;
}
