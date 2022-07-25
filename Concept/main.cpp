//
// Created by yanghao on 2022/7/5.
//

#include <iostream>
#include <thread>
#include <future>

template<typename C>
concept IntegerType = std::is_integral_v<C>;
template<IntegerType T>
struct X {

};

// 约束表达式应该是一个bool类型的纯右值常量表达式
template<typename C>
concept TestConcept = true;

// 合取
template<typename C>
concept SignedIntegerType = std::is_integral_v<C> && std::is_signed_v<C>;

template<SignedIntegerType T>
struct SignedInteger {

};

//  析取
template<typename C>
concept IntegerFloatingType = std::is_integral_v<C> || std::is_floating_point_v<C>;
template<IntegerFloatingType T>
struct IntegerFloating {

};

int main(int argc, char* argv[]) {

//    X<double>x1;
    X<int> x2;
    static_assert(TestConcept<int>);

    SignedInteger<int> integer1;
//    SignedInteger<unsigned int> integer1;

    IntegerFloating<int> y1;
    IntegerFloating<double> y2;
    return 0;
}