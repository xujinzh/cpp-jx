#include <iostream>
#include "Sales_item.h"

/*
在src上一层目录编译
g++ -std=c++17 -O3 -march=native -pthread -Wall -o ./bin/bookAdd -I ./include ./src/*.cpp
运行
./bin/bookAdd
在命令行输入 读入ISBN号、售出的册数以及销售价格
0-210-70353-x 4 34.99
回车，再输入相同书的 ISBN号、售出的册数以及销售价格
0-210-70353-x 5 43.22
回车，得到结果 ISBN、售出的册数、总销售额和平均价格
0-210-70353-x 9 356.06 -> avg_price: 39.5622
*/
int main()
{
    // 合并统计同一个书号的销售情况，计算平均价格
    Sales_item item1, item2;
    std::cin >> item1 >> item2;
    // 首先检查 item1 和 item2 是否表示相同的书
    if (item1.isbn() == item2.isbn())
    {
        std::cout << item1 + item2 << std::endl;
        return 0;
    }
    else // 如果命令行输入的2本书的书号（isbn）不一样，那么进行提示
    {
        std::cerr << "Data must refer to same ISBN"
                  << std::endl;
        return -1;
    }
}