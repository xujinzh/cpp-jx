#include <iostream>
#include <unordered_map>
#include <string>
#include "Sales_item.h"

// 读取多条消费记录（从命令行或者从数据文件中），统计每个ISBN（每本书）有几条销售记录。
// 这里假设每个ISBN的销售记录可能不是连续记录在一起的

// 编译程序
// g++ -std=c++17 -O3 -march=native -pthread -Wall -I ./include/ -o ./bin/mainBook ./src/main.cpp

// 运行程序
// 假设销售记录在文件 resources/data 中。把统计结果写入到 resources/output 中
// ./bin/mainBook < ./resources/data > ./resources/output

// 假设从命令行输入数据
// ./bin/mainBook
/*
0-201-78345-X 3 20.00
0-201-78346-X 2 25.00
0-201-78345-X 3 20.00
0-201-78347-X 2 25.00
0-201-78346-X 3 20.00
0-201-78348-X 2 25.00
0-201-78345-X 3 20.00
0-201-78345-X 2 25.00
*/
// 输出
/*
0-201-78348-X: 1
0-201-78347-X: 1
0-201-78346-X: 2
0-201-78345-X: 4
*/

int main()
{
    // 创建一个无序字典存储消费记录，key是消费书籍的ISBN号，value是消费记录数
    std::unordered_map<std::string, int> umap;
    // 创建2个Sales_item类型变量，存储消费记录信息
    Sales_item item;
    // 检测第一个命令行输入非空
    if (std::cin >> item)
    {
        // 如果非空，把消费记录的信息存储到字典中
        umap.insert(std::make_pair(item.isbn(), 1));
        // 循环读取命令行输入，直到为空，CTRL+D
        while (std::cin >> item)
        {
            // 检测当前的输入是否已经在字典中出现过
            auto it = umap.find(item.isbn());
            if (it != umap.end())
            {
                // 如果找到了，那么在原来的基础上把消费记录累加1
                umap[item.isbn()]++;
            }
            else
            {
                // 如果没有找到，那么直接创建一条新记录在字典中
                umap.insert({item.isbn(), 1});
            }
        }
    }
    // 如果字典中的内容不是空的，那么循环打印
    if (umap.size() != 0)
    {

        // 无序循环打印记录信息
        for (const auto &m : umap)
        {
            std::cout << m.first << ": " << m.second << std::endl;
        }
    }
    return 0;
}