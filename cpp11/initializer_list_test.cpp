#include "./need.h"

class InitListTest {
public:
    InitListTest(int a) {
        std::cout << "InitListTest(int) " << a << std::endl;
    }

    InitListTest(int a, int b) {
        std::cout << "InitListTest(int, int) " << a << b << std::endl;
    }

    // InitListTest(std::initializer_list<int> init_list) {
    //     std::cout << "InitListTest(std::initializer_list<int>) ";
    //     for (auto iter : init_list) {
    //         std::cout << iter;
    //     }
    //     std::cout << std::endl;
    // }
};

void Separator() {
    std::cout << "-----------------------------------------------" << std::endl;
}

int main() {

    Separator();
    InitListTest ilt0{1};
    Separator();
    InitListTest ilt1[]{1, 2};
    // Separator();
    // InitListTest ilt2{1, 2, 3};
    // Separator();
    // InitListTest ilt3[]{1, 2, 3};

    // InitListTest ilt4(1, 2);
    // InitListTest(1, 2);
    // InitListTest{1, 2};

    return 0;
}
