#include <mutex>
#include <stdexcept>
#include <iostream>
#include "../inc/Record.h"
#include "opencv2/opencv.hpp"

bool Record::isStoped()
{
    return _flag_stop;
}
bool Record::open() 
{
    if(_camera.isOpened())
        throw std::logic_error("invariant broken:camera already opened");
    _camera = cv::VideoCapture(1);
    _frame_width = _camera.get(CV_CAP_PROP_FRAME_WIDTH);
    _frame_height = _camera.get(CV_CAP_PROP_FRAME_HEIGHT);
    return  _camera.isOpened();
}

bool Record::startRecord(std::string tmp_cmd, std::mutex& mut, std::string& cmd)
{
    mut.unlock();
    auto file_name = tmp_cmd.substr(tmp_cmd.find(" ") + 1);
    if(!_camera.isOpened()) {
                throw std::runtime_error("device error: error open camera");
    }
    if(!isStoped() || _video.isOpened()) {
        std::cerr << "Previous Recording is forced to stop to start the new one" << std::endl;
        _video.release();
        _flag_stop = true;
    }
    _video = cv::VideoWriter(file_name, _video_format, _video_fps, cv::Size(_frame_width, _frame_height), _is_colored);
    if(!_video.isOpened()) {
        throw std::runtime_error("devoce error: error open video");
    }
    _flag_stop = false;
    for(;;) {
        mut.lock();
        if(cmd!=tmp_cmd) {
            return true;
        }
        mut.unlock();
        cv::Mat frame;
        _camera >> frame;
        _video.write(frame);
        cv::imshow("Video", frame);
    }
}

bool Record::stopRecord()
{
    _flag_stop = true;
    _video.release();
    return _video.isOpened();
}

bool Record::close()
{
    if(_video.isOpened() || !isStoped())
        throw std::logic_error("invariant broken: _video is open or still recording");
    _camera.release();
    return !_camera.isOpened();
}
