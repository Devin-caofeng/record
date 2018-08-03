#include <iostream>
#include <cstring>
#include <cstdio>

class Message
{
public:
    enum { kHeaderLength = 4 };
    enum { kMaxBodyLength = 512 };

    Message() : body_length_(0)
    {
    }

    const char* Data() const
    {
        return data_;
    }

    char* Data()
    {
        return data_;
    }

    std::size_t Length() const
    {
        return kHeaderLength + body_length_;
    }

    const char* Body() const
    {
        return data_ + kHeaderLength;
    }

    char* Body()
    {
        return data_ + kHeaderLength;
    }

    std::size_t BodyLength() const
    {
        return body_length_;
    }

    void BodyLength(std::size_t new_length)
    {
        body_length_ = new_length;
        if (body_length_ > kMaxBodyLength)
        {
            body_length_ = kMaxBodyLength;
        }
    }

    bool DecodeHeader()
    {
        char header[kHeaderLength + 1] = "";
        std::strncat(header, data_, kHeaderLength);
        body_length_ = std::atoi(header);
        if (body_length_ > kMaxBodyLength)
        {
            body_length_ = 0;
            return false;
        }
        return true;
    }

    void EncodeHeader()
    {
        char header[kHeaderLength + 1] = "";
        std::sprintf(header, "%4ld", body_length_);
        std::memcpy(data_, header, kHeaderLength);
    }

private:
    std::size_t body_length_;
    char data_[kHeaderLength + kMaxBodyLength];
};
