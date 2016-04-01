#pragma once
#ifndef REFERENTIAL_SERVER_H_
#define REFERENTIAL_SERVER_H_

#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/io_service.hpp>

class ReferentialServer
{
public:
    explicit ReferentialServer(boost::asio::io_service& io_service, const short port);
    ~ReferentialServer() = default;
    ReferentialServer(const ReferentialServer&) = delete;
    ReferentialServer& operator=(const ReferentialServer&) = delete;

    void Start();
    void Stop();

    void SetReferential(std::string&& referential);

private:
    std::string referential_;
    boost::asio::ip::tcp::socket socket_;
    boost::asio::ip::tcp::acceptor acceptor_;
};

#endif