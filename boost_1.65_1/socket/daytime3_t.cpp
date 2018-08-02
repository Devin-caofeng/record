#include <iostream>
#include <string>
#include <ctime>
#include <thread>
#include <list>
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

    void Start(int voice, int angle)
    {
        message_ = "vioce:" + std::to_string(voice) +
            "angle:" + std::to_string(angle);
        // boost::asio::async_write(socket_, boost::asio::buffer(message_),
        //     boost::bind(&TcpConnection::HandleWrite,
        //         shared_from_this(),
        //         boost::asio::placeholders::error,
        //         boost::asio::placeholders::bytes_transferred));

        boost::system::error_code ec;
        auto ret = socket_.send(boost::asio::buffer(message_), 0, ec);
        if (ret == 0)
        {
            socket_.close();
        }
    }

private:
    TcpConnection(boost::asio::io_service& io) : socket_(io)
    {
    }

    void HandleWrite(const boost::system::error_code& error,
                     size_t /*bytes_transferred*/)
    {
        if (error)
        {
            socket_.close();
        }
    }

private:
    tcp::socket socket_;
    std::string message_;
};


class TcpServer
{
public:
    TcpServer(const TcpServer&) = delete;
    TcpServer& operator=(const TcpServer&) = delete;

    static TcpServer& GetInstance(boost::asio::io_service& io)
    {
        static TcpServer tcp_server(io);
        return tcp_server;
    }

    void Notify()
    {
        int cnt = 0;
        for (auto iter = connections_.cbegin();
             iter != connections_.cend(); ++cnt)
        {
            if ((*iter)->Socket().is_open())
            {
                (*iter)->Start();
                ++iter;
            }
            else
            {
                iter = connections_.erase(iter);
            }
        }
        std::cout << "Send to " << cnt << " observers" << std::endl;
    }

private:
    TcpServer(boost::asio::io_service& io)
        : acceptor_(io, tcp::endpoint(tcp::v4(), 13)),
          accept_thread_(std::bind(&TcpServer::StartAccept, this))
    {
    }

    void StartAccept()
    {
        for (;;)
        {
            TcpConnection::Pointer new_connection =
                TcpConnection::Create(acceptor_.get_io_service());

            boost::system::error_code ec;
            acceptor_.accept(new_connection->Socket(), ec);
            if (!ec)
            {
std::cout << "New connection" << std::endl;
                connections_.emplace_back(std::move(new_connection));
            }
        }
    }

private:
    tcp::acceptor acceptor_;
    std::list<TcpConnection::Pointer> connections_;
    std::thread accept_thread_;
};


int main()
{
    try
    {
        boost::asio::io_service io;
        static TcpServer &server = TcpServer::GetInstance(io);
        for (;;)
        {
            server.Notify();
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
