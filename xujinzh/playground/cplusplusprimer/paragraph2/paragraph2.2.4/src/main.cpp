#include <iostream>

// 该程序仅用于说明：函数内部不宜定义与全局变量同名的新变量
int reused = 42; // reused拥有全局作用域
int i = 33;
int main()
{
    int unique = 0; // unique 拥有块作用域
    // 输出#1： 使用全局变量 reused，输出 42 0
    std::cout << reused << " " << unique << std::endl;

    // 新建局部变量reused，覆盖全局变量reused
    int reused = 0;

    // 输出#2： 使用局部变量 reused，输出 0 0
    std::cout << reused << " " << unique << std::endl;

    // 输出#3： 显示地访问全局变量 reused，输出 42 0
    std::cout << ::reused << " " << unique << std::endl;

    // exercise 2.13
    int i = 100;
    int j = i;
    std::cout << j << std::endl;

    // exercise 2.14
    {
        int i = 100, sum = 0;
        for (int i = 0; i != 10; ++i)
        {
            sum += i;
        }
        std::cout << i << " " << sum << std::endl; // 100 45
    }
    return 0;
}