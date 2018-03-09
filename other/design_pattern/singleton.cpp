#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using std::vector;
using std::string;

// 保证一个类仅有一个实例，并提供一个该实例的全局访问点

class Singleton {
public:
    Singleton() = default;
    Singleton(const Singleton &) = delete;

    static Singleton* GetInstance();

public:
    static Singleton *instance_;
};

Singleton* Singleton::instance_ = nullptr;

Singleton* Singleton::GetInstance() {
    if (instance_ == nullptr) {
        instance_ = new Singleton();
    }

    return instance_;
}

// 线程安全，但锁的代价过高
Singleton* Singleton::GetInstance() {
    // 加锁
    if (instance_ == nullptr) {
        instance_ = new Singleton();
    }

    return instance_;
}

// 双检查锁，但由于内存读写 reorder 不安全
Singleton* Singleton::GetInstance() {
    if (instance_ == nullptr) {
        // 加锁
        if (instance_ == nullptr) {
            /*
             * 1. 分配内存
             * 2. 调用构造函数
             * 3. 将内存首地址赋给 instance_
             */
            instance_ = new Singleton();
        }
    }

    return instance_;
}

// c++11 的跨平台实现，msvc 2005版加入了 volatile 关键字来避免 reorder
std::atomic<Singleton*> Singleton::instance_;
std::mutex Singleton::mutex;
Singleton* Singleton::GetInstance() {
    Singleton *temp = instance_.load(std::memory_order_relaxed);
    std::atomic_thread_fence(std::memory_order_acquire); // 获取内存 fence
    if (temp == nullptr) {
        std::lock_guard<std::mutex> lock(mutex);
        temp = instance_.load(std::memory_order_relaxed);
        if (temp == nullptr) {
            temp = new Singleton();
            std::atomic_thread_fence(std::memory_order_release); // 释放内存 fence
            instance_.store(temp, std::memory_order_relaxed);
        }
    }

    return temp;
}

int main() {



    return 0;
}
