#pragma once
#ifndef REFERENTIAL_SERVER_H_
#define REFERENTIAL_SERVER_H_

#include <mutex>
#include <memory>
#include <boost/asio.hpp>

class ClientSession : public std::enable_shared_from_this<ClientSession>
{
public:
    ClientSession(boost::asio::ip::tcp::socket socket)
        : socket_(std::move(socket))
    {
    }

    void SendReferential(std::string referential)
    {
        referential_ = std::move(referential);
        auto self(shared_from_this());
        boost::asio::async_write(socket_, boost::asio::buffer(referential_.c_str(), referential_.size()),
            [this, self](boost::system::error_code ec, std::size_t /*length*/)
        {
            if (!ec)
            {
                self->CloseSocket();
            }
        });
    }

private:
    void CloseSocket()
    {
        socket_.close();
    }

    std::string referential_;
    boost::asio::ip::tcp::socket socket_;
};

class ReferentialServer
{
public:
    ReferentialServer(boost::asio::io_service& io_service, short port)
        : acceptor_(io_service, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port)),
        socket_(io_service)
    {
        do_accept();
    }

    void SetReferential(std::string&& referential)
    {
        std::lock_guard<std::mutex> lock(referentialMutex_);
        referential_ = std::move(referential);
    }

private:
    void do_accept()
    {
        acceptor_.async_accept(socket_,
            [this](boost::system::error_code ec)
        {
            if (!ec)
            {
                std::lock_guard<std::mutex> lock(referentialMutex_);
                std::make_shared<ClientSession>(std::move(socket_))->SendReferential(referential_);
            }

            do_accept();
        });
    }

    std::mutex referentialMutex_;
    std::string referential_;
    boost::asio::ip::tcp::acceptor acceptor_;
    boost::asio::ip::tcp::socket socket_;
};

#endif