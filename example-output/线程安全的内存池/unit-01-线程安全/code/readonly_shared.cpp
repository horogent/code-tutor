// readonly_shared.cpp — 只读共享数据是线程安全的
// 编译: g++ -std=c++11 -pthread readonly_shared.cpp -o readonly_shared
// 运行: ./readonly_shared

#include <iostream>
#include <thread>
#include <vector>

const int DATA[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};  // 只读数据
const int DATA_SIZE = 10;

void reader(int thread_id) {
    int sum = 0;
    for (int i = 0; i < DATA_SIZE; i++) {
        sum += DATA[i];  // 多个线程同时读 — 安全，不需锁
    }
    std::cout << "线程 " << thread_id << " 求和结果: " << sum << std::endl;
}

int main() {
    std::thread t1(reader, 1);
    std::thread t2(reader, 2);
    t1.join();
    t2.join();
}
