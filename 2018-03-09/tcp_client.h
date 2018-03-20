#ifndef SERVER_H
#define SERVER_H
#include <iostream>
#include <memory>
#include <atomic>
#include <thread>
#include <array>
#include "boost/asio.hpp"
#include "boost/date_time.hpp"
#include "/Users/lixinrui/code_snip/2018-02-27/server/chat_message.hpp"

using boost::asio::ip::tcp;

class Client
{
    boost::asio::io_context io_context;
    tcp::resolver* p_resolver;
    tcp::resolver::results_type endpoint;
    tcp::socket* p_socket;
    std::atomic_flag working_flag = ATOMIC_FLAG_INIT;
    std::thread working_thread;
public:
    Client();
    bool init(const std::string& hostname, const std::string& port);
    void clientThread();
    bool stop();
    ~Client();
};


class ClientInterface
{

    Client client;
public:

    ~ClientInterface()
    {
        stopClient();
    }    
    std::string startClient(const std::string& hostname, const std::string& port);
    bool stopClient();

    bool working() const
    {
        return m_working;
    }

    void setWorking(bool working)
    {
        if (m_working == working)
            return;

        m_working = working;
    }

    bool m_working = false;
};

#endif // SERVER_H

