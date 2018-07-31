#include <iostream>
#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

void Print(const boost::system::error_code&) {
    std::cout << "hello, world" << std::endl;
}

int main() {

    boost::asio::io_service io;

    boost::asio::deadline_timer t(io, boost::posix_time::seconds(6));

    t.async_wait(Print);

    io.run();

    return 0;
}
