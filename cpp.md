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

# 变量和数据类型
## 变量声明

变量的声明和赋值
```c++
// 数据类型 变量名;
int a;
```

## 标识符
标识符由字母、数字和下划线组成，但是不能以数字开头，标识符是大小写敏感的，长度不限。

C++ 中对变量命名有一些要求和约定俗成的规范：
1. 不能使用C++关键字
2. 不能用连续两个下划线开头，也不能以下划线加大写字母开头，这些被C++保留给标准库使用
3. 函数体外的标识符，不能以下划线开头
4. 要尽量有实际意义
5. 变量名一般使用小写字母
6. 自定义类名一般以大写字母开头
7. 如果包含多个单词，一般用下划线分隔，或者将后面的单词首字母大写

C++关键字：
|关键字|关键字|关键字|关键字|关键字|
|--|--|--|--|--|
|alignas|continue|friend|register|true|
|alignof|decltype|goto|reinterpret_cast|try|
|asm|default|if|return|typedef|
|auto|delete|inline|short|typeid|
|bool|do|int|signed|typename|
|break|double|long|sizeof|union|
|case|dynamic_cast|mutable|static|unsigned|
|catch|else|namespace|static_assert|using|
|char|enum|new|static_cast|virtual|
|char16_t|explicit|noexcept|struct|void|
|char32_t|export|nullptr|switch|volatile|
|class|extern|operator|template|wchar_t|
|const|false|private|this|while|
|constexpr|float|protected|thread_local|throw|
|const_cast|for|public|||

C++ 中使用的一些运算操作符的替代名：
|运算符|运算符|运算符|运算符|运算符|运算符|
|--|--|--|--|--|--|
|and|bitand|compl|not_eq|or_eq|xor_eq|
|and_eq|bitor|not|or|xor||

## 作用域
C++ 中全局变量在所有函数外部声明，作用域覆盖整个程序，生命周期从程序开始到结束，存储在全局存储区；局部变量在函数或代码块内部声明，作用域仅限于其定义的{}内，生命周期仅限于其作用域内，存储在栈区。两者主要区别在于作用域、生命周期和存储位置
```c++
#include <iostream>

// 全局变量声明时可以不用初始化，使用默认值
int number; // 全局变量

int main() {
    // variable declaration
    int a = 1, b;
    std::cout << "a = " << a << std::endl;
    b = 10;
    std::cout << "b = " << b << std::endl;
    b = 25;
    std::cout << "b = " << b << std::endl;
    
    // 定义局部变量；局部变量声明时，或者后面必须初始化；
    // 否则使用未初始化的局部变量会导致不可预期的结果
    int number;
    number = 20;
    std::cout << "number = " << number << std::endl;
    std::cout << "global number = " << ::number << std::endl; // 访问全局变量

}
```

## 常量
保存的数据不能更改，这种特殊的变量被叫做“常量”，C++中有两种方式可以定义常量：
1. 使用符号常量
这种方式是在文件头用#define来定义常量，也叫作“宏定义”
```c++
// 没有数据类型的定义
// 宏定义常量约定用全大写
#define ZERO 0
```
跟 #include 一样，“#”号开头的语句都是“预处理语句”，在编译之前，预处理器会查找程序中所有的“ZERO”，并把它替换成0，这种宏定义的方式是保留的C语言特性，在C++中一般不推荐。
2. 使用const限定符
这种方式跟定义一个变量是一样的，只需要在变量的数据类型前再加上一个 const 关键字，这被称为"限定符"
```c++
// 定义常量；声明时必须初始化
// 约定首字母大写
const int Zero = 0;

// 不能修改常量值
Zero = 10; // error
```

## 基本数据类型
C++支持丰富的数据类型，它内置了一套基本数据类型，也为我们提供了自定义类型的机制。

基本数据类型主要包括算术类型和空类型（void）。算术类型包含整型和浮点型，空类型不对应具体的值，只用在一些特定的场合，比如一个函数如果不返回任何只，可以用 void 作为它的返回类型。

### 整型
