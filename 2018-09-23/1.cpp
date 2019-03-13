#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/opencv.hpp"
#include "opencv2/core/core.hpp"
#include <cstdlib>
#include <vector>
using namespace std;
using namespace cv;
bool detectObstacles(int choice) {
    /// config
    const int threshold_diff_h = 20;
    const int threshold_min_s = 127;
    const int threshold_max_s = 80;
    const int threshold_min_v = 128;
    const double min_area_size = 150;
    const double min_red_or_green_ratio = 0.6;

    /// definitions
    const int color_red = 253;
    const int color_green = 254;
    /// read input frame
    Mat input_frame = imread("1.png", IMREAD_COLOR);
    Mat filtered_frame = Mat(input_frame.size(), CV_8UC1);
    Mat dst = Mat(input_frame.size(), CV_8UC3);
    /// convert to HSV format and remove blue ground
    cvtColor(input_frame, input_frame, CV_BGR2HSV);
    for(int r = 0; r<input_frame.rows; r++){
        for(int c=0; c<input_frame.cols; c++) {
            Vec3b pixel = input_frame.at<Vec3b>(r, c);

            if (choice < 1) continue;
            /// also ignore pixels that are too dark
            if (pixel[2] < threshold_min_v) {
                filtered_frame.at<uint8_t>(r, c) = 0;
            }
            else if (choice < 2) continue;
            else if (abs(pixel[0] - 120) < threshold_diff_h && pixel[1] > threshold_min_s) {
                /// blue
                filtered_frame.at<uint8_t>(r, c) = 0;
            }
            else if (choice < 3) continue;
            else if ((pixel[0] < threshold_diff_h || pixel[0] > 180 - threshold_diff_h)
                     && pixel[1] > threshold_min_s)
            {
                /// red
                cout << "red" << endl;
                filtered_frame.at<uint8_t>(r, c) = color_red;
            }
            else if (choice < 4) continue;
            else if (abs(pixel[0] - 60) < threshold_diff_h && pixel[1] > threshold_min_s){
                /// green
                cout << "green" << endl;
                filtered_frame.at<uint8_t>(r, c) = color_green;
            }
            else if (choice < 5) continue;
            else if((abs(pixel[0] - 120) > 30 && pixel[1] < threshold_max_s)
                    || abs(pixel[0] - 30) < 30 - threshold_diff_h){
                /// white or yellow
                cout << "white or yellow" << endl;
                filtered_frame.at<uint8_t>(r,c) = 255;
            }
            else if (choice < 6) continue;
            else {
                filtered_frame.at<uint8_t>(r,c) = 0;
            }
        }
    }
    imshow("test", filtered_frame);
    /// find all ground robots(include obstacles) by finding contours
    vector<vector<Point>> robots;
    Mat kernel = getStructuringElement(MORPH_ELLIPSE , Size(7,7));
    Mat filtered_frame_2;
    erode(filtered_frame, filtered_frame_2, kernel);
    imshow("test", filtered_frame_2);
    dilate(filtered_frame_2, filtered_frame_2, kernel);
    imshow("test", filtered_frame_2);
    GaussianBlur(filtered_frame_2, filtered_frame_2, Size(7,7), 1.0);
    imshow("test", filtered_frame_2);

    vector<Vec4i> hierarchy;
    findContours(filtered_frame_2, robots, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
    Vec2f circle_center;
     int idx = 0;
     for( ; idx >= 0; idx = hierarchy[idx][0] )
    {
         Scalar color( rand()&255, rand()&255, rand()&255 );
         drawContours( dst, robots, idx, color, FILLED, 8, hierarchy );
    }
    imshow("Comp", dst);
    waitKey(0);
    int obstacle_num=0;
    if (!robots.empty())
    {
        for(int i=0; i<robots.size(); i++){
            double size = contourArea(robots[i]);
            if(size < min_area_size)
                continue;
            /// crate a bouding box and iterate pixels in the box
            auto rect = boundingRect(robots[i]);
            int min_x = rect.x;
            int max_x = rect.x + rect.width;
            int min_y = rect.y;
            int max_y = rect.y + rect.height;
            int counter = 0, pixel_counter = 0;
            for(int x = min_x; x < max_x; x++){
                for(int y = min_y; y < max_y; y++){
                    if(filtered_frame_2.at<uint8_t>(y,x) != 0){
                        pixel_counter++;
                        if(filtered_frame.at<uint8_t>(y,x) == color_red || filtered_frame.at<uint8_t>(y,x) == color_green)
                            counter++;
                    }
                }
            }
            /// judge whether there are enough red/green pixels
            if(1.0*counter/pixel_counter < min_red_or_green_ratio)
                obstacle_num++;
        }
    }
    return obstacle_num > 0;
}

int main(int argc, char** argv)
{
    int choice = argv[1][0] - '0';
    cout << choice << endl;
    cout << detectObstacles(choice) << endl;;
    waitKey(0);
}
