#include <iostream>

/*
用if语句写一个程序，统计从命令行输入的整数中每个值连续出现了多少次

编译
g++ -std=c++17 -O3 -march=native -pthread -Wall -o ../bin/mainIf ./mainIf.cpp
运行
../bin/mainIf
然后在命令行中输入
42 42 42 42 42 55 55 62 100 100 100
回车后，返回
42 occurs 5 times
55 occurs 2 times
62 occurs 1 times
CTRL+D退出
*/
int main()
{
    // currVal 是我们正在统计的数
    // 将读入的新值存入 newVal
    int currVal = 0, newVal = 0;
    // 读取第一个数，并确保确实有数据可以处理
    if (std::cin >> currVal)
    {
        int cnt = 1; // 保存我们正在处理的当前值的个数
        // 循环统计后面的数
        while (std::cin >> newVal)
        {
            // 如果新数和当前待记录的数一致，那么该数字的计数累加
            if (newVal == currVal)
            {
                ++cnt;
            }
            else // 否则，是出现了与上一个数不同的数，记为新数，计数设为1，第一次出现
            {
                std::cout << currVal << " occurs " << cnt << " times" << std::endl;
                currVal = newVal;
                cnt = 1;
            }
        }
        // 循环结束后，打印最后的一个新数的信息
        std::cout << currVal << " occurs " << cnt << " times" << std::endl;
    }
    return 0;
}