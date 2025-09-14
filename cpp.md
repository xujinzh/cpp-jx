# C++ 基本介绍
C++ 是一种静态类型、编译型、通用且支持面向对象、过程化及泛型编程的编程语言，它由 C 语言扩展而来，以其高性能和灵活性著称，常用于开发操作系统、游戏引擎、大型应用程序、嵌入式系统等领域。C++ 增加了类、模板、异常处理等特性，同时保留了 C 语言的强大底层控制能力，能够满足广泛的开发需求。

## 起源与发展
C++ 最初由 Bjarne Stroustrup 在 1979 年于贝尔实验室开发。它是在 C 语言的基础上进行扩展和改进的，最初命名为“带类的C”，后于1983 年更名为 C++。

## 主要特点
- 支持多种编程范式：它不仅支持过程化编程，还支持面向对象编程（如类、对象、继承、多态）和泛型编程。
- 高级与低级特性兼备：C++ 兼具高级语言的抽象能力和低级语言的硬件控制能力，被认为是一种中级语言。
- 高效性和灵活性：C++ 以其卓越的性能和高度的灵活性而闻名，适合对性能要求极高的应用。
- 静态类型和编译型：它在编译时进行类型检查，并需要将源代码编译为机器码才能执行。
跨平台性：C++ 可以在多种操作系统上运行，包括 Windows、macOS 和 Linux（Unix）。

## 典型应用场景
- 操作系统开发：许多操作系统，如 Windows，在很大程度上是用 C++ 编写的。
- 游戏开发：C++ 的高性能使其成为开发大型游戏引擎和游戏的理想选择。
- 嵌入式系统：其对硬件的直接控制能力适用于嵌入式系统的开发。
- 桌面应用程序：用于构建复杂的桌面应用程序。
- 服务器应用和后台系统：在构建高性能的服务器端应用和数据库方面也发挥着重要作用。

# HelloWorld
目录结构如下：
```bash
../../xcpp001helloword
├── build
│   └── helloword
└── src
    └── helloworld.cpp

3 directories, 2 files
```

代码：
```c++
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
```
编译：
```bash
g++ -std=c++11 helloworld.cpp -o ../build/helloword
```
执行：
```bash
../build/helloword
```

# 函数
## 调用函数
代码结构：
```bash
│       └── helloworld.cpp
└── xcpp002func
    ├── build
    │   └── main
    └── src
        ├── main.cpp
        └── welcome.cpp

7 directories, 5 files
```
main.cpp
```c++
#include <iostream> // for std::cout, std::cin and std::endl;
#include <unistd.h> // for pause()

// function declaration
void welcome();

// function definition
void greet() {
    std::cout << "please input your name: " << std::endl;
    std::string name;
    std::cin >> name;
    std::cout << "hello, " << name << std::endl;

    return;
}

/*
main function
*/
int main() {
    greet();

    welcome();
    // // keep the console window open in debug mode
    // // use two std::cin.get() to wait for the second enter key
    // std::cin.get();
    // std::cin.get();

    pause(); // ctrl + c to exit
    return 0;

}
```
welcome.cpp

```c++
#include <iostream>

void welcome() {
    std::cout << "please input your name: " << std::endl;
    std::string name;
    std::cin >> name;
    std::cout << "hello, " << name << std::endl;
    return;
}
```
编译代码
```bash
g++ -std=c++11 main.cpp welcome.cpp -o ../build/main
```
run
```c++
../build/main
```

# 变量
## 变量的声明和赋值
```c++
// 数据类型 变量名;
int a;
```
