#include "../need.h"

class Screen {
public:
    void SomeMember() const { ++access_ctr_; };
    void Show() { };

private:
    mutable size_t access_ctr_ = 0;;
};

int main() {

    Screen const s;
    s.Show();

    return 0;
}
