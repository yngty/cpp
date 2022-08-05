//
// Created by yanghao on 2022/7/5.
//

#include <iostream>

template<typename... Args>
void foo(Args... args) {}

template<typename... Args>
struct bar {
    bar(Args... args) {
        foo(args...);
    }
};

int main(int argc, char* argv[]) {


    return 0;
}