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
        //lock std::cout
        std::lock_guard countGuard(coutMutex);
        std::cout << "ThreadId(" << std::this_thread::get_id() << "): ";
        std::cout << "20/10=" << shareFut.get() << "\n";
    }
};
int main(int argc, char* argv[]) {

    std::cout << std::boolalpha;
    std::promise<int> divProm;

    std::future<int> divResult = divProm.get_future();

    std::cout << "divResult.valid(): " << divResult.valid() << "\n";


    Div div;
    std::thread divThread(div, std::move(divProm), 20, 10);

    std::cout << "divResult.valid(): " << divResult.valid() << "\n";
    std::shared_future<int>sharedResult = divResult.share();
    std::cout << "divResult.valid(): " << divResult.valid() << "\n";

    Requestor req;

    std::thread sharedThread1(req, sharedResult);
    std::thread sharedThread2(req, sharedResult);
    std::thread sharedThread3(req, sharedResult);
    std::thread sharedThread4(req, sharedResult);
    std::thread sharedThread5(req, sharedResult);


    divThread.join();

    sharedThread1.join();
    sharedThread2.join();
    sharedThread3.join();
    sharedThread4.join();
    sharedThread5.join();


    return 0;
}