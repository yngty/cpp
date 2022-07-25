//
// Created by yanghao on 2022/7/5.
//

#include <iostream>
#include <future>
#include <utility>
#include <exception>

std::mutex coutMutex;

struct Div {
    void operator()(std::promise<int>&& intProm, int a, int b) {
        try {
            if (b == 0) {
                std::string errMsg = std::string("Illegal division by zero: ") + std::to_string(a) + "/" + std::to_string(b);
                throw std::runtime_error(errMsg);
//                intProm.set_exception(std::make_exception_ptr(std::runtime_error(errMsg)));
            }
            intProm.set_value(a/b);
        }
        catch (...) {
            intProm.set_exception(std::current_exception());

        }

    }
};
void executeDivision(int nom, int denom) {
    std::promise<int> divProm;
    std::future<int> divResult = divProm.get_future();

    Div div;
    std::thread divThread(div, std::move(divProm), nom, denom);

    try {
        std::cout << nom << "/" << denom << " = " << divResult.get() << "\n";
    } catch (std::runtime_error& e) {
        std::cout << e.what() << "\n";
    }

    divThread.join();

}

int main(int argc, char* argv[]) {

    executeDivision(20, 0);
    executeDivision(20, 10);
    return 0;
}