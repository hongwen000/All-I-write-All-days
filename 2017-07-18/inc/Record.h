#include "opencv2/opencv.hpp"
#include <string>
#include <mutex>
#include <stdexcept>

using std::lock_guard;
using std::mutex;
using std::string;
using std::unique_lock;
using cv::Mat;
using cv::VideoCapture;
using cv::VideoWriter;

class Record {
public:
    Record() :
        _flag_stop{false}
        {}
    bool open();
    bool startRecord(string file_name); 
    void stopRecord();
    bool close();
private:
    mutex _mut;
    VideoCapture _camera;
    VideoWrite _video;
    int _frameWidth;
    int _frameHeight;
    bool _flag_stop;
    const auto _video_format = CV_FOURCC('M', 'P', '4', '2');
    const auto _video_fps = 30;
    const auto _is_colored = true;
    bool isStoped();
    }
};