#include <iostream>
#include <boost/asio.hpp>

const int kMaxIPPackSize = 65536;
const int kHeadLen = 4;

class RWHandler
{
    using tcp = boost::asio::ip::tcp;
public:
    RWHandler(boost::asio::io_service& io) : socket_(io)
    {
    }

    void HandleRead()
    {
        boost::asio::async_read(socket_,
            boost::asio::buffer(buff_),
            boost::asio::transfer_at_least(kHeadLen),
            [this](const boost::system::error_code& ec, size_t /*size*/)
            {
                if (ec != nullptr)
                {
                    HandleError(ec);
                    return;
                }
                std::cout << buff_.data() + kHeadLen << std::endl;
                HandleRead();
            });
    }

    void HandleWrite(char* data, int len)
    {
        boost::system::error_code ec;
        write(socket_, boost::asio::buffer(data, len), ec);
        if (ec != nullptr)
        {
            HandleError(ec);
        }
    }

    tcp::socket& GetSocket()
    {
        return socket_;
    }

    void CloseSocket()
    {
        boost::system::error_code ec;
        socket_.shutdown(tcp::socket::shutdown_send, ec);
        socket_.close(ec);
    }

    void SetConnID(int conn_id)
    {
        conn_id_ = conn_id;
    }

    int GetConnID() const
    {
        return conn_id_;
    }

    template<typename F>
    void SetCallBackError(F f)
    {
        callback_error_ = f;
    }

private:
    void HandleError(const boost::system::error_code& ec)
    {
        CloseSocket();
        std::cout << ec.message() << std::endl;
        if (callback_error_)
        {
            callback_error_(conn_id_);
        }
    }

private:
    int conn_id_;
    tcp::socket socket_;
    std::array<char, kMaxIPPackSize> buff_;
    std::function<void(int)> callback_error_;
};
