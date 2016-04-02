#include "ReferentialServer.h"

ReferentialServer::ReferentialServer(const short port)
    : service_(),
    acceptor_(service_, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port)),
    socket_(service_)
{
    Accept();
}

void ReferentialServer::Start()
{
    service_.run();
}

void ReferentialServer::Stop()
{
    service_.stop();
}

void ReferentialServer::SetReferential(std::string&& referential)
{
    referential_ = std::move(referential);
}

void ReferentialServer::Accept()
{
    acceptor_.async_accept(socket_,
        [this](const boost::system::error_code& errorCode)
    {
        if (!errorCode)
        {
            boost::asio::async_write(socket_, boost::asio::buffer(referential_, referential_.size()),
                [](boost::system::error_code ec, std::size_t /*length*/) {});
        }
        Accept();
    }
    );
}