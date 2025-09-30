#include <iostream>

int main() {
    char a = 65;
    char b = 'A';
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;

    std::cout << "b + 1: " << (b + 1) << std::endl;
    char c = b + 1;
    std::cout << "c: " << c << std::endl;
    return 0;
}