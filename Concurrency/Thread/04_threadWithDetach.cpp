//
// Created by yanghao on 2022/7/5.
//

#include <iostream>
#include <thread>

int main(int argc, char* argv[]) {
    std::thread t([]() {
        using namespace std::chrono_literals;
        std::this_thread::sleep_for(2s);
       std::cout << std::this_thread::get_id()  << "\n";
    });
    t.detach();
    std::cout << "main thread\n";
    return 0;
}