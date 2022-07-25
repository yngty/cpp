//
// Created by yanghao on 2022/7/5.
//

#include <iostream>
#include <thread>

int main(int argc, char* argv[]) {
    std::thread t([]() {
       std::cout << std::this_thread::get_id()  << "\n";
    });
    t.join();
    return 0;
}