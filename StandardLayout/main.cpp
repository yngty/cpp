//
// Created by yanghao on 2022/7/5.
//

#include <map>
#include <iostream>
#include <string>

// 虚函数
struct SL3 {
    int i;
    virtual void func() {}
    int j;
};

// 虚基类
struct Base{

};

struct SL4: public virtual Base {
    int i;
    int j;
};

// 所有非静态数据成员都具有相同的访问控制
struct SL {
    int i;
private:
    int j;
};


// 类类型的所有非静态成员均为标准布局
struct One{
    int a;
private:
    int b;
};

struct SL6{
    One one;
    int j;
};

// 所有基类都为标准布局
struct Base1{
    Base1() {}
};

// 虚基类
struct SL5: public Base1 {
    int i;
    int j;
};

// 所有基类都为标准布局
struct Base2{
    Base2() {}
};

// 没有与第一个非静态数据成员类型相同的基类
struct SL7: public Base2 {
    Base2 base;
    int j;
};


//满足以下条件之一：
//最底层派生类中没有非静态数据成员，并且具有非静态数据成员的基类不超过一个，或者
//没有含非静态数据成员的基类

struct Base3
{
    int i;
    int j;
};

struct SL8 : public Base3
{
    int x;
    int y;
};

int main(int argc, char* argv[]) {

    std::cout << std::boolalpha;
    std::cout <<  "SL is standard layout: " << std::is_standard_layout_v<SL> << "\n";
//    std::cout <<  "SL2 is standard layout: " << std::is_standard_layout_v<SL2> << "\n";
    std::cout <<  "SL3 is standard layout: " << std::is_standard_layout_v<SL3> << "\n";
    std::cout <<  "SL4 is standard layout: " << std::is_standard_layout_v<SL4> << "\n";
    std::cout <<  "SL5 is standard layout: " << std::is_standard_layout_v<SL5> << "\n";
    std::cout <<  "SL6 is standard layout: " << std::is_standard_layout_v<SL6> << "\n";
    std::cout <<  "SL7 is standard layout: " << std::is_standard_layout_v<SL7> << "\n";
    std::cout <<  "SL8 is standard layout: " << std::is_standard_layout_v<SL8> << "\n";
    return 0;
}