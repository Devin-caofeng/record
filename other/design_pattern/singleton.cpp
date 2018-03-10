#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <atomic>
#include <mutex>


class Singleton {
public:
    Singleton(const Singleton &) = delete;

    static Singleton* GetInstance();

private:
    Singleton() = default;

    static std::atomic<Singleton *> instance_;  //首先声明了一个原子的对象。
    static std::mutex mutex_;
};

std::atomic<Singleton *> Singleton::instance_;  //首先声明了一个原子的对象。
std::mutex Singleton::mutex_;

Singleton* Singleton::GetInstance() {
    // 通过原子的对象的load方法获得对象的指针。
    Singleton *tmp = instance_.load(std::memory_order_relaxed);
    std::atomic_thread_fence(std::memory_order_acquire);         // 获取内存屏障

    if (tmp == nullptr) {
        std::lock_guard<std::mutex> lock(mutex_);
        tmp = instance_.load(std::memory_order_relaxed);
        if (tmp == nullptr) {
            tmp = new Singleton();
            std::atomic_thread_fence(std::memory_order_release); // 释放内存屏障
            instance_.store(tmp, std::memory_order_relaxed);
        }
    }
    return tmp;
}

int main() {


    return 0;
}
