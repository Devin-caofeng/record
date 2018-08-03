#include <list>
#include <unordered_map>
#include <boost/asio/buffer.hpp>
#include "Message.hpp"
#include "RWHandler.hpp"

const int kMaxConnectionNum = 65536;
const int kMaxRecvSize = 65536;

class Server
{
    using tcp = boost::asio::ip::tcp;
public:
    Server(boost::asio::io_service& io, short port)
        : io_(io),
          conn_id_poll_(kMaxRecvSize),
          acceptor_(io, tcp::endpoint(tcp::v4(), port))
    {
        int current = 0;
        std::generate_n(conn_id_poll_.begin(), kMaxConnectionNum, [&current]
        {
            return ++current;
        });
    }

    void Accept()
    {
        std::cout << "Start listening " << std::endl;
        std::shared_ptr<RWHandler> handler = CreateHandler();

        acceptor_.async_accept(handler->GetSocket(),
            [this, handler](const boost::system::error_code& ec)
            {
                if (ec)
                {
                    std::cout << ec.value() << " "
                        << ec.message() << std::endl;
                    HandleAcpError(handler, ec);
                }
                handlers_.insert(
                    std::make_pair(handler->GetConnID(), handler));
                std::cout << "Current connect count: "
                    << handlers_.size() << std::endl;

                handler->HandleRead();
                Accept();
            });
    }

private:
    void HandleAcpError(std::shared_ptr<RWHandler> event_handler,
                        const boost::system::error_code& ec)
    {
        std::cout << "Error, error reason: "
            << ec.value() << ec.message() << std::endl;
        event_handler->CloseSocket();
        StopAccept();
    }

    void StopAccept()
    {
        boost::system::error_code ec;
        acceptor_.cancel(ec);
        acceptor_.close(ec);
        io_.stop();
    }

    std::shared_ptr<RWHandler> CreateHandler()
    {
        int conn_id = conn_id_poll_.front();
        conn_id_poll_.pop_front();
        auto handler = std::make_shared<RWHandler>(io_);
        handler->SetConnID(conn_id);
        handler->SetCallBackError([this](int conn_id)
        {
            RecyclConnID(conn_id);
        });
        return handler;
    }

    void RecyclConnID(int conn_id)
    {
        auto iter = handlers_.find(conn_id);
        if (iter != handlers_.end())
        {
            handlers_.erase(iter);
        }
        std::cout << "Current connect count: "
            << handlers_.size() << std::endl;
        conn_id_poll_.push_back(conn_id);
    }

private:
    boost::asio::io_service& io_;
    std::list<int> conn_id_poll_;
    boost::asio::ip::tcp::acceptor acceptor_;
    std::unordered_map<int, std::shared_ptr<RWHandler>> handlers_;
};
