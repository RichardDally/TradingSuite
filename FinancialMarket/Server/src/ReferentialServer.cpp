#include "ReferentialServer.h"

ReferentialServer::ReferentialServer(boost::asio::io_service& io_service, const short port)
    : acceptor_(io_service, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port)),
    socket_(io_service)
{
}

void ReferentialServer::Start()
{
}

void ReferentialServer::Stop()
{
}

void ReferentialServer::SetReferential(std::string&& referential)
{
    referential_ = std::move(referential);
}
