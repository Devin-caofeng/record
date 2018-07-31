#include <iostream>
#include <boost/asio.hpp>
#include <boost/thread/thread.hpp>

int main() {

    boost::asio::io_service io;
    boost::asio::deadline_timer t(io, boost::posix_time::seconds(5));

    boost::this_thread::sleep(boost::posix_time::seconds(6));

    t.wait();

    std::cout << "Hello, world!" << std::endl;

    return 0;
}
