#include <iostream>

int main() {
    int* p1;
    long* p2;
    long long* p3;
    std::cout << "p1 length: " << sizeof(p1) << std::endl;
    std::cout << "p2 length: " << sizeof(p2) << std::endl;
    std::cout << "p3 length: " << sizeof(p3) << std::endl;

    int a = 1;
    p1 = &a;
    *p1 = 3;
    std::cout << "a = " << a << std::endl;

    int* p4;
    p4 = nullptr;
    std::cout << "p4 = " << p4 << std::endl;

    int* p5;
    p5 = NULL; // #define NULL 0
    std::cout << "p5 = " << p5 << std::endl;

    int* p6;
    p6 = 0; // 相当于没有指向任何对象
    std::cout << "p6 = " << p6 << std::endl;

    int* p7;
    // std::cout << "*p7 = " << *p7 << std::endl; // segmentation fault (core dumped) 

    int i = 10;
    std::string s = "hello";

    void* p8 = &i;
    p8 = &s;

    std::cout << "p8 = " << p8 << std::endl;
    std::cout << "the length of p8 = " << sizeof(p8) << std::endl;
    // std::cout << "*p8 = " << *p8 << std::endl; // 错误，不能通过 void* 指针访问对象

}