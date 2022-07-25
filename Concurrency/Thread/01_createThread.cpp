//
// Created by yanghao on 2022/7/5.
//

#include <iostream>
#include <thread>

void helloFunction() {
    std::cout << "Hello from a function. \n";
}

class  HelloFunctionObject {
public:
    void operator()() const {
        std::cout << "Hello from a function Object. \n";
    }
};
int main(int argc, char* argv[]) {

    std::thread t1(helloFunction);
    HelloFunctionObject helloFunctionObject;
    std::thread t2(helloFunctionObject);
    std::thread t3([]() {
       std::cout << "Hello from a lambda.\n";
    });

    t1.join();
    t2.join();
    t3.join();

    return 0;
}