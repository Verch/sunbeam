#pragma once
#ifndef sunbeam_client_h__
#define sunbeam_client_h__

#include <string>


#include <boost/asio.hpp>

class Client
{
    Client() = delete;
public:
    Client(std::string name, boost::asio::io_service& io);

    bool connect(boost::asio::ip::tcp::endpoint& ep);

private:
    bool                         m_is_started;
    std::string                  m_username;
    boost::asio::ip::tcp::socket m_sock;

};

#endif//sunbeam_client_h__