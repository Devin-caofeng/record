#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

void Print(const boost::system::error_code&,
           boost::asio::deadline_timer* t,
           int* cnt)
{
    if (*cnt < 6)
    {
        std::cout << *cnt << std::endl;
        ++(*cnt);

        t->expires_at(t->expires_at() + boost::posix_time::seconds(1));
        t->async_wait(
            boost::bind(Print, boost::asio::placeholders::error, t, cnt));
    }
}

int main()
{
    boost::asio::io_service io;

    int cnt = 0;
    boost::asio::deadline_timer t(io, boost::posix_time::seconds(1));

    t.async_wait(
        boost::bind(Print, boost::asio::placeholders::error, &t, &cnt));

    io.run();

    std::cout << "Final cnt is " << cnt << std::endl;

    return 0;
}
