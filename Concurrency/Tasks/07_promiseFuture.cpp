//
// Created by yanghao on 2022/7/5.
//

#include <iostream>
#include <future>
#include <functional>
#include <vector>

void product(std::promise<int>&& intPromise, int a, int b) {
    std::cout << std::this_thread::get_id() << "\n";
    intPromise.set_value(a*b);
}

struct Div {
    void operator()(std::promise<int>&& intPromise, int a , int b) const {
        std::cout << std::this_thread::get_id() << "\n";
        intPromise.set_value(a / b);
    }
};
int main(int argc, char* argv[]) {

    int a = 20;
    int b = 10;

    std::promise<int> prodPromise;
    std::promise<int> divPromise;

    std::future<int> prodResult = prodPromise.get_future();
    std::future<int> divResult =  divPromise.get_future();

    std::thread prodThread(product, std::move(prodPromise), a , b);

    Div div;
    std::thread divThread(div, std::move(divPromise), a , b);

    std::cout << "20 * 10 = " << prodResult.get() << "\n";
    std::cout << "20 / 10 = " << divResult.get() << "\n";

    prodThread.join();
    divThread.join();
    return 0;
}