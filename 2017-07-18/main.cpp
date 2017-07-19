//Version 1.0 
//Todo:Add comments, other improments
#include "inc/Record.h"
#include <algorithm>
#include <condition_variable>
#include <iostream>
#include <map>
#include <mutex>
#include <string>
#include <thread>

std::mutex mut;
std::string cmd;

void input()
{
    while (1) {
        std::string tmp_cmd;
        std::getline(std::cin, tmp_cmd);
        std::unique_lock<std::mutex> lk(mut);
        cmd = tmp_cmd;
        lk.unlock();
        if (tmp_cmd == "quit")
            break;
    }
}

struct Capture {
private:
    bool flag_out_from_record;
    Record _record;
    bool flag_stop;
    std::map<std::string, int> commands = {
        { "", 1 },
        { "quit", 2 },
        { "stop", 3 },
        { "start", 4 }
    };

    void process(std::string tmp_cmd, std::mutex& mut, std::string& cmd)
    {
        std::string option = tmp_cmd.substr(0, tmp_cmd.find(" "));
        if (commands.find(option) == commands.end()) {
            std::cerr << "Wrong Input" << std::endl;
        } else {
            auto i = commands[option];
            switch (i) {
            case 1:
                break;
            case 2: {
                try {
                    _record.close();
                } catch (std::logic_error&) {
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
                flag_out_from_record = _record.startRecord(tmp_cmd, mut, cmd);
                break;
            }
            default:
                break;
            }
        }
    }

public:
    Capture()
        : flag_out_from_record(false)
    {
    }
    void operator()()
    {
        flag_stop = false;
        _record.open();
        while (!flag_stop) {
            std::unique_lock<std::mutex> lk(mut);
            auto tmp_cmd = cmd;
            process(tmp_cmd, mut, cmd);
            if (flag_out_from_record == true)
                flag_out_from_record = false;
            else
                cmd = "";
            lk.unlock();
        }
    }
};

int main()
{
    std::thread t1(Capture{});
    std::thread t2(input);
    t1.join();
    t2.join();
}
