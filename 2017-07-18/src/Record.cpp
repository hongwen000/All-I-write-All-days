#include "../inc/Record.h"

bool isStoped()
{
    lock_guard<mutex> lk(_mut);
    return _flag_stop;
}
bool Record::open() 
{
    if(_camera.isOpen())
        return false;
    _camera(0);
    _frame_width = _camera.get(CV_CAP_PROP_FRAME_WIDTH);
    _frame_height = _camera.get(CV_CAP_PROP_FRAME_HEIGHT);
    is_opened = _camera.isOpened();
    return is_opened;
}

bool startRecord(string file_name)
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

void stopRecord()
{
    lock_guard<mutex> lk(mut);
    _flag_stop = true;
}

bool close()
{
    if(_video.isOpen() || !isStoped())
        throw logic_error("Still Recording");
    _camera.release();
    return !_camera.isOpen();
}