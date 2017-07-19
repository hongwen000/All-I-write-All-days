#include <algorithm>
#include <thread>
#include <mutex>
#include <condition_variable>
#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

mutex mut;
string command;

void input()
{
    while(1)
    {
        string _m;
        getline(cin, _m);
        unique_lock<mutex> lk(mut);
        command = _m;
        lk.unlock();
        if(_m == "quit")
            break;
    }
}

void capture()
{
    VideoCapture vcap(0); 
      if(!vcap.isOpened()){
             cout << "Error opening video stream or file" << endl;
             return;
      }

   int frame_width=   vcap.get(CV_CAP_PROP_FRAME_WIDTH);
   int frame_height=   vcap.get(CV_CAP_PROP_FRAME_HEIGHT);
    
   while(1)
   {
       unique_lock<mutex> lk(mut);
       if(command == "")
           continue;
       else if(command == "quit")
           break;
       else if(command.substr(0, command.find(" ")) == "start")
       {
           auto filename = command.substr(command.find(" ") + 1);
           lk.unlock();
           VideoWriter video(filename,CV_FOURCC('M','J','P','G'),10, Size(frame_width,frame_height),true);
           for(;;)
           {
               lk.lock();
               if(command == "stop")
                   break;
               lk.unlock();
               Mat frame;
               vcap >> frame;
               video.write(frame);
               imshow( "Frame", frame );
           }
       }
       else if(command == "stop")
           command = "";
       else 
       {
            cout << "Wrong Input" << endl;
            command = "";
            continue;
       }
   }
}

int main(){
  thread t1(capture);
  thread t2(input);
  t1.join();
  t2.join();
  return 0;
}
