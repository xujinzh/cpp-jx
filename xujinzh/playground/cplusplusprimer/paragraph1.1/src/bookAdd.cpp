#include <iostream>
#include "Sales_item.h"

/*
编译
g++ -std=c++17 -O3 -march=native -pthread -Wall -o bookAdd -I ../ bookAdd.cpp
运行
./bookAdd
在命令行输入
0-210-70353-x 4 34.99
回车，再输入
0-210-70353-x 5 43.22
回车，得到结果
0-210-70353-x 9 356.06 -> avg_price: 39.5622
*/
int main()
{
    Sales_item item1, item2;
    std::cin >> item1 >> item2;
    // 首先检查 item1 和 item2 是否表示相同的书
    if (item1.isbn() == item2.isbn())
    {
        std::cout << item1 + item2 << std::endl;
        return 0;
    }
    else
    {
        std::cerr << "Data must refer to same ISBN"
                  << std::endl;
        return -1;
    }
}