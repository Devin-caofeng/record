#include <array>
#include <future>
#include <iostream>
#include <thread>
#include <boost/asio/io_service.hpp>
#include <boost/asio/ip/udp.hpp>
#include <boost/asio/use_future.hpp>


void GetDaytime(boost::asio::io_service& io, const char* hostname)
{
    using udp = boost::asio::ip::udp;
    try
    {
        udp::resolver resolver(io);
        std::future<udp::resolver::iterator> iter =
          resolver.async_resolve(
              { udp::v4(), hostname, "daytime" },
              boost::asio::use_future);

        udp::socket socket(io, udp::v4());

        std::array<char, 1> send_buf = {{ 0 }};
        std::future<std::size_t> send_length =
          socket.async_send_to(
              boost::asio::buffer(send_buf),
              *iter.get(), // ... until here, This call may block.
              boost::asio::use_future);

        send_length.get(); // Blocks until the send is complete.

        std::array<char, 128> recv_buf;
        udp::endpoint sender_endpoint;
        std::future<std::size_t> recv_length =
          socket.async_receive_from(
              boost::asio::buffer(recv_buf),
              sender_endpoint,
              boost::asio::use_future);

        // Block until receive is complete.
        std::cout.write(recv_buf.data(), recv_length.get());
    }
    catch (std::system_error& e)
    {
        std::cerr << e.what() << std::endl;
    }
}

int main(int argc, char* argv[])
{
    try
    {
        if (argc != 2)
        {
            std::cerr << "Usage: daytime_client <host>" << std::endl;
            return 1;
        }

        boost::asio::io_service io;
        boost::asio::io_service::work work(io);
        std::thread t([&io]() { io.run(); });

        GetDaytime(io, argv[1]);

        io.stop();
        t.join();
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
