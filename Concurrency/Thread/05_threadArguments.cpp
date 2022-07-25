//
// Created by yanghao on 2022/7/5.
//

#include <iostream>
#include <thread>
#include <chrono>


class  Sleeper {
public:
    Sleeper(int& i): i_(i) {}

    void operator()(int k) {
        using namespace std::chrono_literals;
        for (int j = 0; j <= 5; ++j) {
            std::this_thread::sleep_for(100ms);
            i_ += k;
        }
        std::cout << std::this_thread::get_id() << "\n";
    }
private:
    int& i_;
};
int main(int argc, char* argv[]) {
   int valSleeper = 1000;
   std::thread t(Sleeper(valSleeper), 5);
//   t.detach();
    t.join();
   std::cout << "valSleeper = " << valSleeper << "\n";
    return 0;
}