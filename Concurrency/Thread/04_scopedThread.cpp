//
// Created by yanghao on 2022/7/5.
//

#include <iostream>
#include <thread>

class ScopedThread {
public:
    explicit ScopedThread(std::thread t): t_(std::move(t)) {
        if (!t_.joinable())
            throw std::logic_error("No thread");
    }
    ~ScopedThread() {
        t_.join();
    }

    ScopedThread(ScopedThread&) = delete;
    ScopedThread& operator=(const ScopedThread&) = delete;
private:
    std::thread t_;

};
int main(int argc, char* argv[]) {
    {
        ScopedThread st(std::thread ([]() {
            std::cout << std::this_thread::get_id()  << "\n";
        }));
    }

    return 0;
}