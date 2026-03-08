#include <iostream>     // 包含来自标准库的头文件用尖括号包围头文件
#include "Sales_item.h" // 不属于标准库的头文件用双引号包围

#if 0

// 在src上一层目录编译。因为编译命令中有 /* 出现，在块注释中出现这个组合会导致警告，因此这里采用行注释
// g++ -std=c++17 -O3 -march=native -pthread -Wall -o ./bin/mainBook -I ./inlcude/ ./src/*cpp

/**
运行
./bin/mainBook

在命令行输入
0-201-78345-X 3 20.00
0-201-78345-X 2 25.00

预期输出
0-201-70353-X 4 99.96 -> avg_price: 24.99

或者直接如下方式运行，将 resources/data 里的内容输入程序中
./bin/mainBook < resources/data

或者将命令行输出结果也保存到本地 resource/output 中
./bin/mainBook < resources/data > resources/output
*/
#endif

int main()
{
    // 声明2个 Sales_item 书类类型变量 book
    Sales_item item1, item2;
    // 读入一对：ISBN号、售出的册数以及销售价格
    std::cin >> item1 >> item2;
    // 打印它们的和：ISBN、售出的册数、总销售额和平均价格
    std::cout << item1 + item2 << std::endl;
    // 程序退出返回
    return 0;
}