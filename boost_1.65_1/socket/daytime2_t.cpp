#include <iostream>
#include <string>
#include <ctime>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

std::string MakeDaytimeStr()
{
    std::time_t now = std::time(0);
    std::string s;
    for (int i = 1; i < 999; ++i)
    {
        if (i != 998)
        {
            s += std::to_string(i) + "->";
        }
    }
    return std::ctime(&now) + s;
}

int main()
{
    try
    {
        boost::asio::io_service io;
        tcp::acceptor acceptor(io, tcp::endpoint(tcp::v4(), 13));

        for (;;)
        {
            tcp::socket socket(io);
            acceptor.accept(socket);
            std::string message = MakeDaytimeStr();

            boost::system::error_code ignored_error;
            for (int i = 0; i < 666; ++i)
            {
                boost::asio::async_write(
                    socket,
                    boost::asio::buffer(
                        message + " : " + std::to_string(i) + "\n"),
                    [](const boost::system::error_code&, std::size_t)
                    {
                        std::cout << "Send succ" << std::endl;
                    });
            }
        }
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
