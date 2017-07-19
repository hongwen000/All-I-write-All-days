#ifndef H_CAPTURE_H
#define H_CAPTURE_H
#include "opencv2/opencv.hpp"
#include <mutex>
#include <stdexcept>
#include <string>

class Record {
public:
    Record()
        : _flag_stop{ true }
    {
    }
    bool open();
    bool startRecord(std::string tmp_cmd, std::mutex& mut, std::string& cmd);
    bool stopRecord();
    bool close();

private:
    cv::VideoCapture _camera;
    cv::VideoWriter _video;
    int _frame_width;
    int _frame_height;
    bool _flag_stop;
    const int _video_format = CV_FOURCC('M', 'J', 'P', 'G');
    static constexpr auto _video_fps = 10;
    static constexpr auto _is_colored = true;
    bool isStoped();
};
#endif
