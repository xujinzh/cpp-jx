#include <iostream>

// 全局变量声明时可以不用初始化，使用默认值
int number; // 全局变量

int main() {
    // variable declaration
    int a = 1, b;
    std::cout << "a = " << a << std::endl;
    b = 10;
    std::cout << "b = " << b << std::endl;
    b = 25;
    std::cout << "b = " << b << std::endl;
    
    // 定义局部变量；局部变量声明时，或者后面必须初始化；
    // 否则使用未初始化的局部变量会导致不可预期的结果
    int number;
    number = 20;
    std::cout << "number = " << number << std::endl;
    std::cout << "global number = " << ::number << std::endl; // 访问全局变量

}