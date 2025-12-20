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

    // 无效指针，野指针
    // int* p7;
    // std::cout << "*p7 = " << *p7 << std::endl; // segmentation fault (core dumped) 

    int i = 10;
    std::string s = "hello";

    void* p8 = &i;
    p8 = &s;

    std::cout << "p8 = " << p8 << std::endl;
    std::cout << "the length of p8 = " << sizeof(p8) << std::endl;
    // std::cout << "*p8 = " << *p8 << std::endl; // 错误，不能通过 void* 指针访问对象

    std::cout << "=========指针与数组=========" << std::endl;
    int arr[] = {1, 2, 3, 4, 5};
    int* parr = arr;
    // 使用指针访问数组的第一个元素
    std::cout << "*parr = " << *parr << std::endl;
    // 将数组名看作指针，访问数组的第一个元素，效果类似于 arr[0]
    std::cout << "*arr = " << *arr << std::endl;
    // 使用数组名指针访问第二个元素，效果类似于 arr[1]
    std::cout << "*(arr + 1) = " << *(arr + 1) << std::endl;
}
