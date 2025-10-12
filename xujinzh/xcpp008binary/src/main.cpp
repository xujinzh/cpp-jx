#include <iostream>

int main() {
    int a = 0b1010;
    int b = 0B1100;
    int c = 012;  // 八进制
    int d = 0xA;  // 十六进制
    int e = 0Xa;  // 十六进制

    std::cout << "a: " << a << ", b: " << b << std::endl;
    std::cout << "c: " << c << ", d: " << d << ", e: " << e << std::endl;
    return 0;
}