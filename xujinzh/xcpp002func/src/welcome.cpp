#include <iostream>

void welcome() {
    std::cout << "please input your name: " << std::endl;
    std::string name;
    std::cin >> name;
    std::cout << "hello, " << name << std::endl;
    return;
}