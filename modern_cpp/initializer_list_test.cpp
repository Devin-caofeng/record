#include "./need.h"

class InitListTest {
public:
    explicit InitListTest(int a) {
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

void F(const InitListTest &ilt) {
    std::cout << '\n';
}

void Separator() {
    std::cout << "-----------------------------------------------" << std::endl;
}

int main() {

    F(static_cast<InitListTest>(1, 2));
    F(static_cast<InitListTest>(1));

    auto ilt{InitListTest{1}};
    auto ilt1 = InitListTest{1, 2};
    // InitListTest ilt0{1, 2};
    InitListTest ilt2{ 1, 2, 3 };

    // Separator();
    // InitListTest ilt0{1, 2};
    // Separator();
    // InitListTest ilt1[]{1, 2};
    // Separator();
    // InitListTest ilt2{1, 2, 3};
    // Separator();
    // InitListTest ilt3[]{1, 2, 3};

    // InitListTest ilt4(1, 2);
    // InitListTest(1, 2);
    // InitListTest{1, 2};

    return 0;
}
