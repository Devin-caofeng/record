#include <iostream>
#include <thread>
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

        t->expires_at(t->expires_at() + boost::posix_time::milliseconds(666));
        t->async_wait(boost::bind(
            Print, boost::asio::placeholders::error, t, cnt));
    }
}

int main()
{
    boost::asio::io_service io;

    int cnt = 0;
    boost::asio::deadline_timer t(io, boost::posix_time::seconds(1));

    t.async_wait(boost::bind(
        Print, boost::asio::placeholders::error, &t, &cnt));

    boost::asio::deadline_timer t2(io, boost::posix_time::seconds(3));
    t2.async_wait([](const boost::system::error_code&) { exit(-1); });

    std::thread run([&io] { io.run(); });
    run.detach();
    //io.run();

    for (;;)
    {
        std::cout << "Final cnt is " << cnt << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(666));
    }

    return 0;
}
