#include <iostream>
#include <string>
#include <ctime>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

std::string MakeDaytimeStr()
{
    std::time_t now = std::time(0);
    return std::ctime(&now);
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
            boost::asio::write(
                socket, boost::asio::buffer(message), ignored_error);
        }
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
