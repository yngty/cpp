//
// Created by yanghao on 2022/7/5.
//

#include <type_traits>
template<typename T>
requires std::is_integral_v<T> && std::is_signed_v<T>
struct X {

};
// 1. 是一个初等表达式或带括号的任意表达式
constexpr bool bar() { return true;}

template<typename T>
requires (bar())
struct X1{

};

// 使用&&或者||运算符链接上述表达式:
template<typename T>
requires (bar()) || false
struct X2 {

};


template<typename T> requires std::is_integral_v<T>
void foo();

template<typename T>
void foo() requires std::is_integral_v<T>;

int main(int argc, char* argv[]) {

//    X<double>x1;
    X<int> x2;
    return 0;
}