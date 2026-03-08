#include <iostream>     // 包含来自标准库的头文件用尖括号包围头文件
#include "Sales_item.h" // 不属于标准库的头文件用双引号包围

/*
在src上一层目录编译
g++ -std=c++17 -O3 -march=native -pthread -Wall -o ./bin/mainBook -I ./inlcude/ ./src/*cpp

运行
./bin/mainBook

在命令行输入
0-201-70353-X 4 24.99

预期输出
0-201-70353-X 4 99.96 -> avg_price: 24.99
*/
int main()
{
    // 声明一个 Sales_item 书类类型变量 book
    Sales_item book;
    // 读入ISBN号、售出的册数以及销售价格
    std::cin >> book;
    // 写入ISBN、售出的册数、总销售额和平均价格
    std::cout << book << std::endl;
    // 程序退出返回
    return 0;
}