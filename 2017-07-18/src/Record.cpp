#include <mutex>
#include <stdexcept>
#include "../inc/Record.h"
#include "opencv2/opencv.hpp"
using std::mutex;
using std::lock_guard;
using std::unique_lock;
using std::string;
bool Record::isStoped()
{
    return _flag_stop;
}
bool Record::open() 
{
    if(_camera.isOpened())
        return false;
    _camera = VideoCapture(0);
    _frame_width = _camera.get(CV_CAP_PROP_FRAME_WIDTH);
    _frame_height = _camera.get(CV_CAP_PROP_FRAME_HEIGHT);
    return  _camera.isOpened();
}

bool Record::startRecord(string file_name)
{
    if(!_camera.isOpened() || _video.isOpened() || !isStoped())
        return false;
    _video = VideoWriter(file_name, _video_format, _video_fps, cv::Size(_frame_width, _frame_height), _is_colored);
    if(!_video.isOpened())
        return false;
    for(;;) {
        Mat frame;
        _camera >> frame;
        _video.write(frame);
        cv::imshow("Video", frame);
        if(isStoped())
        {
            _video.release();
            return true;
        }
    }
}

void Record::stopRecord()
{
    _flag_stop = true;
}

bool Record::close()
{
    if(_video.isOpened() || !isStoped())
        throw std::logic_error("Still Recording");
    _camera.release();
    return !_camera.isOpened();
}
