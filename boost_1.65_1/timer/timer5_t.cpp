#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/thread/thread.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

class Printer
{
public:
    Printer(boost::asio::io_service& io)
        : cnt_(0),
          timer1_(io, boost::posix_time::seconds(1)),
          timer2_(io, boost::posix_time::seconds(1)),
          strand_(io)
    {
        timer1_.async_wait(boost::bind(&Printer::Print, this, "Timer 1"));
        timer2_.async_wait(boost::bind(&Printer::Print, this, "Timer 2"));
    }

    ~Printer()
    {
        std::cout << "Final cnt is " << cnt_ << std::endl;
    }

    void Print(const std::string& tid)
    {
        if (cnt_ < 6)
        {
            std::cout << tid << " : " << cnt_ << std::endl;
            ++cnt_;

            timer1_.expires_at(
                timer1_.expires_at() + boost::posix_time::seconds(1));
            timer1_.async_wait(boost::bind(&Printer::Print, this, tid));
        }
    }


private:
    int cnt_;
    boost::asio::deadline_timer timer1_;
    boost::asio::deadline_timer timer2_;
    boost::asio::io_service::strand strand_;
};

int main()
{
    boost::asio::io_service io;
    Printer p(io);
    boost::thread t(boost::bind(&boost::asio::io_service::run, &io));

    io.run();
    t.join();

    return 0;
}
