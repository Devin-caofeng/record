#include <iostream>
#include <string>
#include <ctime>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>

using boost::asio::ip::tcp;

std::string MakeDaytimeString()
{
    std::time_t now = std::time(0);
    return std::ctime(&now);
}

class TcpConnection : public boost::enable_shared_from_this<TcpConnection>
{
public:
    using Pointer = boost::shared_ptr<TcpConnection>;

    static Pointer Create(boost::asio::io_service& io)
    {
        return Pointer(new TcpConnection(io));
    }

    tcp::socket& Socket()
    {
        return socket_;
    }

    void Start()
    {
        message_ = MakeDaytimeString();
        boost::asio::async_write(
            socket_,
            boost::asio::buffer(message_),
            boost::bind(
                &TcpConnection::HandleWrite,
                shared_from_this(),
                boost::asio::placeholders::error,
                boost::asio::placeholders::bytes_transferred));
    }

private:
    TcpConnection(boost::asio::io_service& io)
        : socket_(io)
    {
    }

    void HandleWrite(
        const boost::system::error_code& /*error*/,
        size_t /*bytes_transferred*/)
    {
    }

private:
    tcp::socket socket_;
    std::string message_;
};


class TcpServer
{
public:
    TcpServer(boost::asio::io_service& io)
        : acceptor_(io, tcp::endpoint(tcp::v4(), 13))
    {
        StartAccept();
    }

private:
    void StartAccept()
    {
        TcpConnection::Pointer new_connection =
            TcpConnection::Create(acceptor_.get_io_service());

        acceptor_.async_accept(
            new_connection->Socket(),
            boost::bind(
                &TcpServer::HandleAccept,
                this, new_connection, boost::asio::placeholders::error));
    }

    void HandleAccept(
        TcpConnection::Pointer new_connection,
        const boost::system::error_code& error)
    {
        if (!error)
        {
            new_connection->Start();
        }

        StartAccept();
    }

private:
    tcp::acceptor acceptor_;
};


int main()
{
    try
    {
        boost::asio::io_service io;
        TcpServer server(io);
        io.run();
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
