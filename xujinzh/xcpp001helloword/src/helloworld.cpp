#include <iostream>
#include <unistd.h> // for pause() function on Unix-like systems
using namespace std;

int main()
{
    // 这里表示单行注释
    /* 这里表示多行注释
        多行注释可以换行
    */


    // std 表示命名空间namespace，在一个文件中指定命名空间，可以避免冲突
    // :: 是作用域解析运算符，表示使用某个命名空间下的成员
    std::cout << "hello, world" << std::endl;
    cout << "hello, world" << endl; // 因为上面使用了命名空间 std， 所以这里可以省略 std::


    // 提示用户输入姓名
    std::cout << "请输入您的姓名：" << endl;
    // 用一个变量来保存键盘的输入信息
    string name; // string 是C++标准库中表示字符串的类型
    std::cin >> name; // 从键盘输入信息，并保存到变量 name 中
    // 输出欢迎信息
    std::cout << "欢迎您，" << name << "!" << std::endl;


    // system("pause"); // windows系统下让程序在结束前暂停，方便查看输出结果
    pause(); // ctrl+c 结束程序，适用于Unix-like系统
    // cin.get(); // 让程序在结束前暂停，等待用户按下回车键
    // return 0; // C++ main function will return 0 by default, so this line is optional.
}