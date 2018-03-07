#include <boost/asio.hpp>
#include <atomic>
#include <string>
#include <deque>
#include <memory>
#include "chat_message.hpp"
using boost::asio::ip::tcp;
class TcpPusher
{
public:
    TcpPusher(int port){
        std::thread(&TcpPusher::init, this, port).detach();
    }
    void tcp_send(chat_message* msg);
    ~TcpPusher() {
        disconnect();
        server_thread_working = false;
        server_thread.join();
        //delete p_socket;
        delete p_acceptor;
        delete p_endpoint;
    }
private:
    void server_thread_func();
    void init(int port);
    void disconnect();
    tcp::acceptor* p_acceptor;
    boost::asio::io_context io_context;
    tcp::endpoint* p_endpoint;
    std::unique_ptr<tcp::socket> p_socket;
    //tcp::socket* p_socket;
    std::atomic_bool server_thread_working = false;
    std::atomic_bool connected = false;
    std::deque<chat_message*> msg_que;
    std::mutex mut;
    std::thread server_thread;
};

TcpPusher* getTcpServer();

template<typename T, class Enable = void>
class Watcher {};

template<typename T>
struct is_pod_or_string : std::integral_constant<bool,std::is_pod<T>::value> {};

template<>
struct is_pod_or_string<std::string> : std::true_type{};

template<typename T>
class Watcher<T, typename std::enable_if<is_pod_or_string<T>::value>::type>
{
public:
    Watcher(const std::string& className_,
            const std::string& varType_,
            const std::string& varName_)
        :className(className_),
         varType(varType_),
         varName(varName_){
            std::string fullName = (className + varType + varName);
            md5 = Thilo::md5(fullName);
            send();
         }
    void update(const std::string& varValue)
    {
        if(!sent_)
            return;
        auto msg3 = new chat_message (4, 3, md5, varValue);
        getTcpServer()->tcp_send(msg3);
    }
    void update(double varValue)
    {
        if(!sent_)
            return;
        update(std::to_string(varValue));
    }
    void update(bool varValue)
    {
        if(!sent_)
            return;
        update(varValue ? std::string("true") : std::string("false"));
    }
    
private:
    const std::string className;
    const std::string varType;
    const std::string varName;
    std::string md5;
    bool sent_ = false;
    void send()
    {
        auto msg0 = new chat_message (4, 0, md5, className);
        auto msg1 = new chat_message (4, 1, md5, varType);
        auto msg2 = new chat_message (4, 2, md5, varName);
        getTcpServer()->tcp_send(msg0);
        getTcpServer()->tcp_send(msg1);
        getTcpServer()->tcp_send(msg2);
        sent_ = true;
    }
};

std::map<std::string, AbstractWatcherObject::info_type>* getRegisteredClassInfo();

template<typename T>
class Watcher<T, typename std::enable_if<std::is_base_of<AbstractWatcherObject, T>::value>::type>
{
public:
    Watcher(const std::string& className_,
            const std::string& varType_,
            const std::string& varName_)
        :className(className_),
         varType(varType_),
         varName(varName_){
            std::string fullName = (className + varType + varName);
            md5 = Thilo::md5(fullName);
            send();
         }
    void update(const T& varValue)
    {
        if(!sent_)
            return;
        auto values = varValue.watcher_property_value();
        for(int i = 0; i < pts; ++i)
        {
            auto msg = new chat_message(total,  3 * i + 3 + 2, md5, values[i]);
            getTcpServer()->tcp_send(msg);
        }
    }
private:
    const std::string className;
    const std::string varType;
    const std::string varName;
    std::string md5;
    uint16_t total = 0;
    uint16_t pts = 0;
    std::string name_of_T;
    bool sent_ = false;
    void send()
    {
        static_assert(std::is_default_constructible_v<T>, 
                "Deriving AbstractWatcherObject requires derived class provide default constructor");
        name_of_T = _TYPE_TO_NAME<T>::name;
        auto ref = getRegisteredClassInfo();
        auto info = (*ref)[name_of_T];
        pts = info.size();
        total = 3 * info.size() + 3;

        auto msg0 = new chat_message (total, 0, md5, className);
        auto msg1 = new chat_message (total, 1, md5, varType);
        auto msg2 = new chat_message (total, 2, md5, varName);
        getTcpServer()->tcp_send(msg0);
        getTcpServer()->tcp_send(msg1);
        getTcpServer()->tcp_send(msg2);
        if(pts == 0)
            throw(std::runtime_error("Class with no property can not be observed"));
        for(int i = 0; i < pts; ++i)
        {
            auto msg_type = new chat_message (total, 3 * i + 1 + 2, md5, info[i].first);
            auto msg_name = new chat_message (total, 3 * i + 2 + 2, md5, info[i].second);
            getTcpServer()->tcp_send(msg_type);
            getTcpServer()->tcp_send(msg_name);
        }
        sent_ = true;
    }
};

template<typename T>
class Watcher<T, std::enable_if_t<std::is_base_of_v<WatcherObject, T>>>
{
public:
    Watcher(const std::string& className_,
            const std::string& varType_,
            const std::string& varName_)
        :className(className_),
         varType(varType_),
         varName(varName_){
            std::string fullName = (className + varType + varName);
            md5 = Thilo::md5(fullName);
            send();
         }
    void update(const T& varValue)
    {
        if(!sent_)
            return;
        auto values = varValue.watcher_property_value();
        for(int i = 0; i < pts; ++i)
        {
            auto msg = new chat_message(total,  3 * i + 3 + 2, md5, values[i]);
            getTcpServer()->tcp_send(msg);
        }
    }
private:
    const std::string className;
    const std::string varType;
    const std::string varName;
    std::string md5;
    uint16_t total = 0;
    uint16_t pts = 0;
    std::string name_of_T;
    bool sent_ = false;
    void send()
    {
        static_assert(std::is_default_constructible_v<T>, 
                "Deriving AbstractWatcherObject requires derived class provide default constructor");
        auto info = T::watcher_property_info();
        pts = info.size();
        total = 3 * info.size() + 3;

        auto msg0 = new chat_message (total, 0, md5, className);
        auto msg1 = new chat_message (total, 1, md5, varType);
        auto msg2 = new chat_message (total, 2, md5, varName);
        getTcpServer()->tcp_send(msg0);
        getTcpServer()->tcp_send(msg1);
        getTcpServer()->tcp_send(msg2);
        if(pts == 0)
            throw(std::runtime_error("Class with no property can not be observed"));
        for(int i = 0; i < pts; ++i)
        {
            auto msg_type = new chat_message (total, 3 * i + 1 + 2, md5, info[i].first);
            auto msg_name = new chat_message (total, 3 * i + 2 + 2, md5, info[i].second);
            getTcpServer()->tcp_send(msg_type);
            getTcpServer()->tcp_send(msg_name);
        }
        sent_ = true;
    }
};

extern TcpPusher* globalTcpPusher;
