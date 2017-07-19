#include "inc/Record.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <thread>
#include <map>
#include <mutex>

using std::mutex;
using std::string;
using std::thread;
using std::cin;
using std::getline;
using std::unique_lock;
using std::endl;
using std::cout;
using std::map;

static mutex mut;
static string cmd;

void input()
{
    while(1)
    {
        string tmp_cmd;
        getline(cin, tmp_cmd);
        unique_lock<mutex> lk(mut);
        cmd = tmp_cmd;
        lk.unlock();
        if(tmp_cmd == "quit")
            break;
    }
}

struct capture {
private:
    Record _record;
    bool flag_stop;
    unique_lock<mutex> lk(mut);
    map<string, int> commands= {
        {"", 1},
        {"quit", 2},
        {"stop", 3},
        {"start", 4}
    };

    void reset()
    {
        lk.lock();
        cmd = "";
        lk.unlock();
    }

    void process(string tmp_cmd)
    {
        auto option = tmp_cmd.substr(0, tmp_cmd.find(""));
        if(commands.find(option) == commands.end())
        {
            cout << "Wrong Input" << endl;
        }
        else
        {
            switch(commands[option])
            {
                case 1: break;
                case 2: {
                    try {
                        _record.close();
                    }
                    catch(std::logic_error)
                    {
                        _record.stopRecord();
                        _record.close();
                    }
                    flag_stop = true;
                    break;
                }
                case 3: {
                    _record.stopRecord();
                    break;
                }
                case 4: {
                    auto file_name = tmp_cmd.substr(tmp_cmd.find(" ") + 1); 
                    _record.startRecord(file_name);
                    break;
                }
            }
        }
    }
public:
    void operator(void)
    {
        flag_stop = false;
        record.open();
        while(!flag_stop)
        {
            lk.lock();
            auto tmp_cmd = cmd;
            lk.unlock();
            process(tmp_cmd);
            reset();
        }
    }
};

int main(){

}
