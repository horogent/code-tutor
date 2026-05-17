// race_condition.cpp — 演示竞态条件（线程不安全）
// 编译: g++ -std=c++11 -pthread race_condition.cpp -o race_condition
// 运行: ./race_condition (多次运行，观察每次结果不同)

#include <iostream>
#include <thread>
#include <vector>

int counter = 0;  // 全局共享的可变数据 — 无同步保护！

void increment(int times) {
    for (int i = 0; i < times; i++) {
        counter = counter + 1;  // 看似一行，实际三步：LOAD-ADD-STORE
    }
}

int main() {
    std::thread t1(increment, 100000);
    std::thread t2(increment, 100000);
    t1.join();
    t2.join();
    std::cout << "期望值: 200000, 实际值: " << counter << std::endl;
}
