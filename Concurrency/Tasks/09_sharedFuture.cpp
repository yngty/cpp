//
// Created by yanghao on 2022/7/5.
//

#include <iostream>
#include <future>
#include <utility>

std::mutex coutMutex;

struct Div {
    void operator()(std::promise<int>&& intProm, int a, int b) {
        intProm.set_value(a/b);
    }
};

struct Requestor {
    void operator()(std::shared_future<int> shareFut) {
        std::lock_guard countGuard(coutMutex);
        std::cout << "ThreadId(" << std::this_thread::get_id() << "): ";
        std::cout << "20/10=" << shareFut.get() << "\n";
    }
};
int main(int argc, char* argv[]) {

    std::promise<int> divProm;
    std::shared_future<int> divResult = divProm.get_future();
    Div div;
    std::thread divThread(div, std::move(divProm), 20, 10);

    Requestor req;

    std::thread sharedThread1(req, divResult);
    std::thread sharedThread2(req, divResult);
    std::thread sharedThread3(req, divResult);
    std::thread sharedThread4(req, divResult);
    std::thread sharedThread5(req, divResult);


    divThread.join();

    sharedThread1.join();
    sharedThread2.join();
    sharedThread3.join();
    sharedThread4.join();
    sharedThread5.join();


    return 0;
}