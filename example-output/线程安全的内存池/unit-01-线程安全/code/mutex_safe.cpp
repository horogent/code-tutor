// mutex_safe.cpp — 使用 std::mutex 保护临界区（线程安全）
// 编译: g++ -std=c++11 -pthread mutex_safe.cpp -o mutex_safe
// 运行: ./mutex_safe (多次运行，结果始终为 200000)

#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

int counter = 0;
std::mutex mtx;  // 互斥锁：保护 counter 的访问

void increment(int times) {
    for (int i = 0; i < times; i++) {
        std::lock_guard<std::mutex> lock(mtx);  // 构造时 lock()，析构时 unlock()
        counter = counter + 1;                   // 临界区：同一时刻只有一个线程在此
    }
}

int main() {
    std::thread t1(increment, 100000);
    std::thread t2(increment, 100000);
    t1.join();
    t2.join();
    std::cout << "期望值: 200000, 实际值: " << counter << std::endl;
}
