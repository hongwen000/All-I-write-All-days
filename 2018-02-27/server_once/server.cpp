#include <boost/asio.hpp>
#include <iostream>
#include <string>
#include <ctime>
#include "server.h"

using boost::asio::ip::tcp;

TcpPusher* globalTcpPusher = nullptr; 

TcpPusher* getTcpServer()
{
    if(globalTcpPusher == nullptr)
        globalTcpPusher = new TcpPusher(7568);
    return globalTcpPusher;
}

std::map<std::string, AbstractWatcherObject::info_type>* registeredClassInfo = nullptr;

std::map<std::string, AbstractWatcherObject::info_type>* getRegisteredClassInfo()
{
    if(registeredClassInfo == nullptr)
        registeredClassInfo = new std::map<std::string, AbstractWatcherObject::info_type>();
    return registeredClassInfo;
}

void TcpPusher::init(int port) {
    try
    {
        p_endpoint = new  tcp::endpoint(tcp::v4(), port);
        p_acceptor = new tcp::acceptor(io_context, *p_endpoint);
        std::cout << "Thread init, waiting for connection at port " << port << std::endl;
        server_thread_working = true;
        server_thread = std::thread{&TcpPusher::server_thread_func, this};
    } catch (std::exception& e)
    {
        std::cerr << "Error when init tcp pusher: " << e.what() << std::endl;
    }
}

void TcpPusher::tcp_send(chat_message* msg)
{
    std::lock_guard<std::mutex> lock(mut);
    msg_que.push_back(msg);
}

void TcpPusher::disconnect()
{
    connected = false;
}
void TcpPusher::server_thread_func()
{
    while(server_thread_working)
    {
        boost::asio::deadline_timer timer(io_context);
        std::cout << "Waitting for client" << std::endl;
        try{
            p_socket.reset(new tcp::socket(io_context));
            p_acceptor->accept(*p_socket);
            std::cout << "Reconnect" << std::endl;
            //timer.expires_from_now(boost::posix_time::milliseconds(10));
            //timer.wait();
            std::lock_guard<std::mutex> lock(mut);
            if(!msg_que.empty()) {
                chat_message* msg = msg_que.front();
                try{
                    std::cout << "Info: Sending [" << (unsigned)msg->stage() + 1 << "/" << (unsigned)msg->total() <<
                            "] " << msg->md5() << ":" << msg->body() << std::endl;
                    boost::asio::write(*p_socket, boost::asio::buffer(msg->data(), msg->length()));
                    std::cout << "Info: sent "  << msg->length() << "byte" << std::endl;
                    delete msg;
                    msg_que.pop_front();
                }  catch(std::exception& e) {
                    std::cout << "Error when writting " << &msg << " to socket " << p_socket.get() << std::endl;
                    std::cout << e.what() << std::endl;
                }
            }
            p_socket->close();
        } catch(const std::exception& e) {
            std::cout << e.what() << std::endl;
        }
    }
}

