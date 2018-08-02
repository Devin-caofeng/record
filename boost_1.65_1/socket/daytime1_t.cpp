#include <iostream>
#include <boost/array.hpp>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

int main(int argc, char* argv[])
{
    try
    {
        if (argc != 2)
        {
            std::cerr << "Usage: client <host>" << std::endl;
            return 1;
        }

        boost::asio::io_service io;
        tcp::resolver resolver(io);
        tcp::resolver::query query(argv[1], "daytime");
        tcp::resolver::iterator endpoint_iter = resolver.resolve(query);

        tcp::socket socket(io);
        boost::asio::connect(socket, endpoint_iter);

        // boost::asio::deadline_timer t(io, boost::posix_time::seconds(5));
        // t.async_wait([&socket](const boost::system::error_code&)
        // {
        //     socket.close();
        // });

        for (int i = 0; i < 6; ++i)
        {
            boost::array<char, 128> buf;
            boost::system::error_code error;

            size_t len = socket.read_some(boost::asio::buffer(buf), error);

            if (error == boost::asio::error::eof)
            {
               break;
            }
            else if (error)
            {
                throw boost::system::system_error(error);
            }

            std::cout.write(buf.data(), len);
        }

        socket.shutdown(tcp::socket::shutdown_receive);
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
