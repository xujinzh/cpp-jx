#include <iostream>

/**
 * 函数传值和函数传引用
 * 实现对变量进行自增
 */

// 函数传值；使用指针
void increase(int *x)
{
    ++(*x);
}

// 函数传引用；引用就是指针的语法糖，但使用更方便
void increase(int &x)
{
    ++x;
}

int main()
{
    int n = 0;
    // 引用自增
    increase(n);
    std::cout << "n = " << n << std::endl;
    // 指针自增
    increase(&n);
    std::cout << "n = " << n << std::endl;

    return 0;
}
