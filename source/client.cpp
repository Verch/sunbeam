#include "client.h"

Client::Client(std::string name, boost::asio::io_service& io)
: m_username(name)
, m_sock(io)
{

}

bool Client::connect(boost::asio::ip::tcp::endpoint& point)
{
    m_sock.connect(point);
    return true;
}


//void run_client(const std::string & client_name)
//{
//    talk_to_svr client(client_name);
//    try {
//        client.connect(ep);
//        client.loop();
//    }
//    catch (boost::system::system_error & err) {
//        std::cout << "client terminated " << client.username()
//            << ": " << err.what() << std::endl;
//    }
//}