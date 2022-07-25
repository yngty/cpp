//
// Created by yanghao on 2022/7/5.
//

#include <map>
#include <iostream>
#include <string>

// 没有具有相应非普通构造函数/运算符/析构函数
struct Trivial {
    int i;
private:
    int j;
};

// 没有具有相应非普通构造函数/运算符/析构函数
struct Trivial2 {
    int i;
    Trivial2(int a, int b): i(a), j(b){}
    Trivial2() =default;
private:
    int j;
};


// 虚函数
struct Trivial3 {
    int i;
    virtual void func() {}
private:
    int j;
};


struct Base{

};

// 虚基类
struct Trivial4: public virtual Base {
    int i;
private:
    int j;
};

// 没有具有相应非普通构造函数/运算符/析构函数的基类
struct Base1{
    Base1() {}
//    Base1() = default;
};

struct Trivial5: public Base1 {
    int i;
private:
    int j;
};

struct One{
    One() {}
//    One() = default;
};

// 没有具有相应非普通构造函数/运算符/析构函数的类类型的数据成员
struct Trivial6{
    One one;
private:
    int j;
};


struct TrivialCopy {
//    ~TrivialCopy() {};

//    TrivialCopy(int a) : i(a) {}
    int i;
};
int main(int argc, char* argv[]) {

    std::cout << std::boolalpha;
    std::cout <<  "Trivial is trivial: " << std::is_trivial_v<Trivial> << "\n";
    std::cout <<  "Trivial2 is trivial: " << std::is_trivial_v<Trivial2> << "\n";
    std::cout <<  "Trivial3 is trivial: " << std::is_trivial_v<Trivial3> << "\n";
    std::cout <<  "Trivial4 is trivial: " << std::is_trivial_v<Trivial4> << "\n";
    std::cout <<  "Trivial5 is trivial: " << std::is_trivial_v<Trivial5> << "\n";
    std::cout <<  "Trivial6 is trivial: " << std::is_trivial_v<Trivial6> << "\n";


    std::cout << "TrivialCopy is trivial copy: " << std::is_trivially_copyable_v<TrivialCopy> << "\n";
    std::cout << "TrivialCopy is trivial : " << std::is_trivial_v<TrivialCopy> << "\n";
    return 0;
}