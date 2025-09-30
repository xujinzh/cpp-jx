#include <iostream>

int main() {
    short a = 10;
    std::cout << "a = " << a << std::endl;
    std::cout << "sizeof(a) = " << sizeof(a) << std::endl;
    std::cout << "sizeof a = " << sizeof a << std::endl;
    std::cout << "sizeof(short) = " << sizeof(short) << std::endl;
 
    int a2 = 10;
    std::cout << "a2 = " << a2 << std::endl;
    std::cout << "sizeof(a2) = " << sizeof(a2) << std::endl;
    std::cout << "sizeof a2 = " << sizeof a2 << std::endl;
    std::cout << "sizeof(int) = " << sizeof(int) << std::endl;

    long long a3 = 10;
    std::cout << "a3 = " << a3 << std::endl;
    std::cout << "sizeof(a3) = " << sizeof(a3) << std::endl;
    std::cout << "sizeof a3 = " << sizeof a3 << std::endl;
    std::cout << "sizeof(long long) = " << sizeof(long long) << std::endl;

    unsigned short a4 = 32768;
    std::cout << "a4 = " << a4 << std::endl;
    std::cout << "sizeof(a4) = " << sizeof(a4) << std::endl;
    std::cout << "sizeof a4 = " << sizeof a4 << std::endl;
    std::cout << "sizeof(unsigned short) = " << sizeof(unsigned short) << std::endl;
    
    return 0;
}