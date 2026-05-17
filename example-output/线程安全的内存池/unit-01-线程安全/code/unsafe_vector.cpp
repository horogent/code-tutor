// unsafe_vector.cpp — 多个线程同时修改同一个容器（线程不安全！）
// 编译: g++ -std=c++11 -pthread unsafe_vector.cpp -o unsafe_vector
// 运行: ./unsafe_vector (可能崩溃、输出损坏或异常结果)
// 警告: 本代码演示错误做法，运行结果不可预测

#include <iostream>
#include <thread>
#include <vector>

void append_to_vector(std::vector<int>& vec, int start, int count) {
    for (int i = 0; i < count; i++) {
        vec.push_back(start + i);  // vector 内部是共享的堆内存，无同步保护！
    }
}

int main() {
    std::vector<int> shared_vec;
    std::thread t1(append_to_vector, std::ref(shared_vec), 0, 1000);
    std::thread t2(append_to_vector, std::ref(shared_vec), 1000, 1000);
    t1.join();
    t2.join();
    std::cout << "期望大小: 2000, 实际大小: " << shared_vec.size() << std::endl;
}
