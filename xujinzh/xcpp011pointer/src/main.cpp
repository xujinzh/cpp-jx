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
    p5 = NULL;
    std::cout << "p5 = " << p5 << std::endl;

    int* p6;
    p6 = 0;
    std::cout << "p6 = " << p6 << std::endl;
}