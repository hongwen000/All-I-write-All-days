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
    Record record;
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
            continue;
        }
        else
        {
            switch(opinion)
            {
                case 1: break;
                case 2: {
                    try {
                        record.close();
                    }
                    catch(std::logic_error)
                    {
                        record.stopRecord();
                        record.close();
                    }
                    flag_stop = true;
                    break;
                }
                case 3: {
                    record.stopRecord();
                    break;
                }
                case 4: {
                    auto file_name = tmp_cmd.substr(command.find(" ") + 1); 
                    record.startRecord(file_name);
                    break;
                }
            }
        }
    }
public:
    void operator()
    {
        bool flag_stop = false;
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
