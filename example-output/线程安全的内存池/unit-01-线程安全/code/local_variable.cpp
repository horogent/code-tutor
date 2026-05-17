// local_variable.cpp — 线程局部变量天然安全
// 编译: g++ -std=c++11 -pthread local_variable.cpp -o local_variable
// 运行: ./local_variable

#include <iostream>
#include <thread>
#include <vector>

void safe_work(int thread_id) {
    int local = 0;  // 每个线程有自己的栈，local 是线程私有的
    for (int i = 0; i < 100000; i++) {
        local++;
    }
    std::cout << "线程 " << thread_id << " 的 local = " << local << std::endl;
}

int main() {
    std::thread t1(safe_work, 1);
    std::thread t2(safe_work, 2);
    t1.join();
    t2.join();
}
