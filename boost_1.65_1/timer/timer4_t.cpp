#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

class Printer {
public:
    Printer(boost::asio::io_service& io)
        : cnt_(0), timer_(io, boost::posix_time::seconds(1))
    {
        timer_.async_wait(boost::bind(&Printer::Print, this));
    }

    ~Printer()
    {
        std::cout << "Final cnt is " << cnt_ << std::endl;
    }

    void Print()
    {
        if (cnt_ < 6)
        {
            std::cout << cnt_ << std::endl;
            ++cnt_;

            timer_.expires_at(
                timer_.expires_at() + boost::posix_time::seconds(1));
            timer_.async_wait(boost::bind(&Printer::Print, this));
        }
    }


private:
    int cnt_;
    boost::asio::deadline_timer timer_;
};

int main()
{
    boost::asio::io_service io;

    Printer p(io);

    io.run();

    return 0;
}
