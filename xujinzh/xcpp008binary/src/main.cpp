#include <iostream>
#include <typeinfo>

int main()
{
    int a = 0b1010;
    int b = 0B1100;
    int c = 012; // 八进制
    int d = 0xA; // 十六进制
    int e = 0Xa; // 十六进制

    std::cout << "a: " << a << ", b: " << b << std::endl;
    std::cout << "c: " << c << ", d: " << d << ", e: " << e << std::endl;

    std::cout << "Type of a: " << typeid(a).name() << std::endl;

    // 需要 C++14 或更高版本的编译器支持，如 GCC 4.9、MSVC 19.0、Clang 3.4 及以上版本。
    // int f = 0b1010'1100; // 使用单引号作为数字分隔符
    // std::cout << "f: " << f << std::endl;

    // int g = 1'000'000; // 使用单引号作为数字分隔符
    // std::cout << "g: " << g << std::endl;

    // int h = 0xFF'FF'FF; // 使用单引号作为数字分隔符
    // std::cout << "h: " << h << std::endl;

    int i = true * 1 + 'a' * 2;
    std::cout << "i: " << i << std::endl;

    std::cout << (~5) << std::endl;
    std::cout << (5 & 12) << std::endl;
    std::cout << (5 | 12) << std::endl;
    std::cout << (5 ^ 12) << std::endl;
    return 0;
}