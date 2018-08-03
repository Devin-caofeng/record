#include <iostream>
#include <boost/asio.hpp>

int main()
{

    boost::asio::io_service io;

    boost::asio::deadline_timer t(io, boost::posix_time::seconds(1));

    t.async_wait([] { std::cout << "hh"; });

    io.run();


    std::cout << "aa" << std::endl;

    return 0;
}
