#ifndef H_CAPTURE_H
#define H_CAPTURE_H
#include "opencv2/opencv.hpp"
#include <string>
#include <mutex>
#include <stdexcept>

using cv::Mat;
using cv::VideoCapture;
using cv::VideoWriter;

class Record {
public:
    Record() :
        _flag_stop{false}
        {}
    bool open();
    bool startRecord(std::string file_name); 
    void stopRecord();
    bool close();
private:
    VideoCapture _camera;
    VideoWriter _video;
    int _frame_width;
    int _frame_height;
    bool _flag_stop;
    const int _video_format = CV_FOURCC('M', 'P', '4', '2');
    static constexpr auto  _video_fps = 30;
    static constexpr auto _is_colored = true;
    bool isStoped();
};
#endif
