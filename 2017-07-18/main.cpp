#include "inc/Record.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <thread>
#include <map>

using std::map;
using std::string;
using std::getline;
using std::thread;

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
    map<string, int> commands= {
        {"", 1},
        {"quit", 2},
        {"stop", 3},
        {"start", 4}
    }
    void reset()
    {
        lk.lock();
        cmd = "";
        lk.unlock();
    }
    void process(int opinion)
    {
        switch(opinion)
        {
            case 1: continue;
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
                continue;
            }
            case 4: {
                auto file_name = tmp_cmd.substr(command.find(" ") + 1); 
                record.startRecord(file_name);
                continue;
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
            unique_lock<mutex> lk(mut);
            lk.lock();
            auto tmp_cmd = cmd;
            lk.unlock();
            auto option = tmp_cmd.substr(0, tmp_cmd.find(""));
            if(commands.find(option) == commands.end())
            {
                cout << "Wrong Input" << endl;
                continue;
            }
            else
            {
                process(commands[option]);
            }
            reset();
        }
    }
};
int main(){

}