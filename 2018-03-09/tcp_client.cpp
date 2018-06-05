#include "tcp_client.h"
Client::Client()
{

}

bool Client::init(const std::string &hostname, const std::string &port)
{
    try {
        p_resolver =new tcp::resolver(io_context);
        endpoint = p_resolver->resolve(hostname, port);
        p_socket = new tcp::socket(io_context);
        boost::asio::connect(*p_socket, endpoint);
        working_flag.test_and_set();
        working_thread = std::thread(&Client::clientThread, this);
        return true;
    } catch(...) {
        throw;
    }
}

void Client::clientThread()
{
    try{
        std::vector<char> bufs;
        header_t* header = nullptr;
        while(working_flag.test_and_set())
        {
            char buf[chat_message::header_length + chat_message::md5_length + chat_message::max_body_length];
            boost::system::error_code error;
            size_t len = p_socket->read_some(boost::asio::buffer(buf), error);
            if(error == boost::asio::error::eof)
            {
                boost::asio::deadline_timer t(io_context, boost::posix_time::milliseconds(10));
                t.wait();
                boost::asio::connect(*p_socket, endpoint);
                continue;
            }
            else if(error)
            {
                throw boost::system::system_error(error);
            }
            else{
                if(true)
                {
                    bufs.reserve(bufs.size() + len);
                    std::cout << "bufs now reserves " << len << " bytes" << std::endl;
                    bufs.insert(bufs.end(), buf, buf + len);
                    std::cout << "bufs now has size: " << bufs.size() << std::endl;
                    while(true)
                    {
                        if(bufs.size() < 4)
                        {
                            std::cout << "Less than 4 bytes (size of a header) in bufs, reloading" << std::endl;
                            std::cout << std::endl;
                            break;
                        }
                        if(header == nullptr) 
                        {
                            header = new header_t;
                            memcpy(header, &bufs[0], sizeof(header_t));
                        }
                        uint16_t body_length = header->body_length;
                        size_t msg_len_in_buf = chat_message::header_length +
                                                chat_message::md5_length +
                                                body_length;
                        std::cout << "New msg should occupy : " << msg_len_in_buf << " in bufs" << std::endl;
                        if(bufs.size() < msg_len_in_buf)
                        {
                            std::cout << "Howerver, less than this size in buffer, reloading" << std::endl;
                            std::cout << std::endl;
                            break;
                        }
                        std::cout << "Creating" << std::endl;
                        std::cout << "total : " << (unsigned)header->total << std::endl;
                        std::cout << "stage : " << (unsigned)header->stage << std::endl;
                        std::cout << "body_len : " << body_length << std::endl;
                        chat_message received_message(
                                header->total, 
                                header->stage,
                                &bufs[0] + chat_message::header_length,
                                &bufs[0] + chat_message::header_length + chat_message::md5_length
                                );
                        bufs.erase(bufs.begin(), bufs.begin() + msg_len_in_buf);
                        std::cout << "Received: [" << (unsigned)received_message.stage() + 1 << "/" << (unsigned)received_message.total() <<
                                    "] " << received_message.md5() << ":" << received_message.body() << std::endl;
                        std::cout << "After this, " << bufs.size() << " remains in buffer" << std::endl;
                        delete header;
                        header = nullptr;
                        std::cout << std::endl;
                    }
                }
                else
                {
                    throw(std::runtime_error("global model interface is not initialized"));
                }
            }
        }
        p_socket->close();
        delete p_socket;
        p_socket = nullptr;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

bool Client::stop()
{
    working_flag.clear();
    working_thread.join();
    return true;
}

Client::~Client()
{
    if(p_socket && p_socket->is_open())
        p_socket->close();
    delete p_resolver;
    delete p_socket;
}

std::string ClientInterface::startClient(const std::string &hostname, const std::string &port)
{
    try {
        if(client.init(hostname, port))
        {
            setWorking(true);
        }
        return "true";
    } catch(std::exception& e) {
        return e.what();
    }
}

bool ClientInterface::stopClient()
{
    if(client.stop())
    {
        setWorking(false);
    }
    return !working();
}

