#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    // 创建堆内存，把指针指向堆内存。这片堆内存里存在不确定的东西
    char *p = new char[200];
    // 把一段话拷贝到堆内存中
    strcpy(p, "hello, 大话编程. How do you do?");
    // 打印堆内存里的东西
    cout << p << endl;

    // 释放堆内存
    delete[] p;

    // 为指针 p 重新开辟一片堆内存，并执行它。这片堆内存里存在的是不确定的值
    /**
     * 这块新内存里存放的是之前其他程序或函数残留的旧数据（即“垃圾值”）。
     * 因为 cout << p 在打印字符串时，会一直向后读取直到遇到空字符 \0（字符串结束标记）。
     * 如果这块内存开头恰好没有 \0，它就会把这些残留的旧数据当作字符打印出来，
     * 直到在内存的某个随机位置遇到 \0 为止，从而导致乱码甚至程序崩溃。
     */
    p = new char[200];
    // 直接打印会是乱码或不确定的内容
    cout << p << endl;

    // 如果希望新申请的内存是干净的
    // method 1. 在申请时直接初始化为 0
    p = new char[200](); // 注意加了小括号 ()
    cout << p << endl;   // 此时会打印出一个空行，不再是乱码

    // method 2. 使用 memset 手动清空
    p = new char[200];
    memset(p, 0, 200); // set 200 bytes of p to 0
    cout << p << endl;
    return 0;
}