#include <iostream>
#include "Sales_item.h"

// 需求：从一个文件中读取销售报告，显示售出册数、总销售额和平均售价。
// 假定每个销售记录在文件中是聚在一起保存的。

// 编译
// g++ -std=c++17 -O3 -march=native -pthread -o ./bin/mainBook -I ./include/ ./src/main.cpp

// 运行
// ./bin/mainBook < ./resources/data > ./resources/output

// 也可以不使用resources/data里的数据，手动在命令行输入书的销售信息，但需要注意
// 每一本书的销售信息应该是连续输入的，不能出现乱序输入不同书（ISBN）的销售信息
// 否则，程序运行的结果将会不正确。
// 收入一本书的信息完成后，当输入另一本数的信息并回车后，将显示上一本书的统计信息
// 当想要终止输入，CTRL+D，会显示最后一本书的统计信息

int main()
{
    /*
    将每个ISBN的所有数据合并起来，存入名为total的变量中。使用另一个名为trans
    的变量保存读取的每条销售记录。如果trans和total指向相同的ISBN，那么更新total
    的值。否则，打印total的值，并将其重置为刚读取的数据trans。
    */
    // 声明一个Sales_item变量，保存下一条交易记录数据
    Sales_item total;
    // 读入第一条交易数据，并确保有数据可以处理
    if (std::cin >> total)
    {
        // 声明另一个Sales_item变量，保存和
        Sales_item trans;
        // 读取剩余的交易记录
        while (std::cin >> trans)
        {
            // 如果处理的是两个相同的书。这里假设同一本书的销售数据是连续的
            if (total.isbn() == trans.isbn())
            {
                total += trans;
            }
            else
            {
                // 先打印前一本书的统计结果
                std::cout << total << std::endl;
                // 再用total表示下一本书的销售额
                total = trans;
            }
        }
        // 打印最后一本书的统计结果
        std::cout << total << std::endl;
    }
    else
    {
        // 没有输入信息，发出警告信息
        std::cerr << "No data?" << std::endl;
        // 表示失败
        return -1;
    }
    return 0;
}