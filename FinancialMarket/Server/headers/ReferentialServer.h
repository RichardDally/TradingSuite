#pragma once
#ifndef REFERENTIAL_SERVER_H_
#define REFERENTIAL_SERVER_H_

#include <thread>
#include <boost/asio.hpp>

class ReferentialServer
{
public:
    explicit ReferentialServer(const short port);
    ~ReferentialServer() = default;
    ReferentialServer(const ReferentialServer&) = delete;
    ReferentialServer& operator=(const ReferentialServer&) = delete;

    void Start();
    void Stop();

    void SetReferential(std::string&& referential);

private:
    void Accept();

    std::string referential_;
    boost::asio::io_service service_;
    std::thread serviceThread_;
    boost::asio::ip::tcp::socket socket_;
    boost::asio::ip::tcp::acceptor acceptor_;
};

#endif