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
计算机中所有数据都是以二进制 0，1 来表示的，每个叫做一位 bit，而计算机可寻址的内存最小单元是 8 位，即一个字节 byte。

C++ 定义了多种整数类型，包括 char, short, int, long, C++11 新增了 long long 类型，此外，特殊的布尔类型  bool 本质上也是整型。

|类型|含义|最小尺寸（具体依据操作系统）|
|--|--|--|
|bool|布尔类型|未定义|
|char|字符|8位，1个字节|
|short|短整型|16位，最小2字节|
|int|整型|16位，最小2字节，不能比short短|
|long|长整型|32位，最小4字节，不能比int短|
|long long | 长整型|64位，至少8字节，不能比long 短|

C++ 中对不同整型类型占据的长度定义比较灵活，这样不同的计算机平台就可以有自己的实现（这根C是一样的）。

现在一般系统中，short和long 都选择最小长度，也就是short占2个字节， long占4个字节， long long 占8个字节。但是 int 则有不同的选择，一般使用的电脑操作系统（windows7, windows10, macos等）的实现中，int都是4字节的。

short 表示的数有 $2^{16}=65536$个，考虑正负，范围是 -32768 $\sim$ 32768; 而 int 能表示的数范围则为 $-2^{31} \sim 2^{31} - 1$，大概是20亿。

### 无符号整型
整型默认是可正可负的，如果只想表示正数和0，那么所能表示的范围就会增大一倍。如 16 位的 short 类型，不考虑负数，表示范围是 0 $\sim$ 65535。C++ 中，short, int, long, long long 都有各自的无符号版本。只需要在定义类型时前面增加上 unsigned

需要注意，当数值超出了整型表示的范围，程序本身并不会报错，而是会让数值回到能表示的最小值，这种情况叫做“数据溢出”或者“算术溢出”。

由于整型的类型太多，在实际应用中使用整型可以只考虑三个原则：
- 一般的整数计算，全部用 int；
- 如果数值超出了 int 的表示范围，用 long long;
- 确定数值不可能为负时，用无符号类型（如统计人数、销售额等）

```c++
#include <iostream>

int main() {
    short a = 10;
    std::cout << "a = " << a << std::endl;
    std::cout << "sizeof(a) = " << sizeof(a) << std::endl;
    std::cout << "sizeof a = " << sizeof a << std::endl;
    std::cout << "sizeof(short) = " << sizeof(short) << std::endl;
 
    int a2 = 10;
    std::cout << "a2 = " << a2 << std::endl;
    std::cout << "sizeof(a2) = " << sizeof(a2) << std::endl;
    std::cout << "sizeof a2 = " << sizeof a2 << std::endl;
    std::cout << "sizeof(int) = " << sizeof(int) << std::endl;

    long long a3 = 10;
    std::cout << "a3 = " << a3 << std::endl;
    std::cout << "sizeof(a3) = " << sizeof(a3) << std::endl;
    std::cout << "sizeof a3 = " << sizeof a3 << std::endl;
    std::cout << "sizeof(long long) = " << sizeof(long long) << std::endl;

    unsigned short a4 = 32768;
    std::cout << "a4 = " << a4 << std::endl;
    std::cout << "sizeof(a4) = " << sizeof(a4) << std::endl;
    std::cout << "sizeof a4 = " << sizeof a4 << std::endl;
    std::cout << "sizeof(unsigned short) = " << sizeof(unsigned short) << std::endl;
    
    return 0;
}
```

### char 类型
如果我们只需要处理很小的整数，也可以用另外一种特殊的整型类型 char，它通常只占一个字节。不过 char 类型一般并不用在整数计算，它更重要的用途是表示字符。

计算机底层的数据都是二进制位表示的，这用来表示一个整数当然没有问题，怎么表示字母呢，这就需要将字母、以及一些特殊符号对应到一个个的数字上，然后保存下来，这就是“编码”的过程。

最常用的字符编码集就是 ASCII 码，它用 0 $\sim$ 127 表示了128个字符，这包括了所有的大小写字母、数字、标点符号、特殊符号以及一些计算机的控制符。比如字母"A"的编码是65，数字字符"0"的编码是48.

在程序中如果使用 char 类型的变量，我们会发现，打印出来就是一个字符，而它的底层是一个整数，也可以做整数计算。

char 类型用来表示整数时，到底是有符号还是无符号呢，之前所有的整型，默认都是有符号的，而 char 并没有默认类型，而是需要 C++ 编译器根据需要自己决定。

所以把 char 当做小整数时，有两种显式的定义方式：signed char 和 unsigned char; 至于 char 定义出来的到底带不带符号，就看编译器的具体实现了。

另外，C++ 还对字符类型进行了“扩容”，提供了一种“宽字符”类型 wchar_t，其会在底层对应另一种类型（比如short或者int），具体占几个字节要看系统中的实现。

wchar_t 会随着具体实现而变化，不够稳定；所以在 C++11 新标准中，还为 Unicode 字符集提供了专门的扩展字符类型：char16_t 和 char32_t，分别长 16 位和 32 位。

|类型|字符 |位数|
|--|--|--|
|char|字符|8位|
|wchar_t|宽字符|16位|
|char16_t|Unicode字符|16位|
|char32_t|Unicode字符|32位|

```c++
#include <iostream>

int main() {
    char a = 65;
    char b = 'A';
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;

    std::cout << "b + 1: " << (b + 1) << std::endl;
    char c = b + 1;
    std::cout << "c: " << c << std::endl;
    return 0;
}
```

### bool 类型
在程序中，往往需要针对某个条件做判断，结果只有两种：“成立”和“不成立”；如果用逻辑语言来描述，就是“真”和“假”。真值判断是二元的，所以在 C 语言中，可以很简单地用“1”表示“真”，用“0”表示“假”。

C++ 支持 C 语言中的这种定义，同时为了让代码更容易理解，引入了一种新的数据类型，布尔类型 bool（来自英国数学家布尔）。该类型只有两个取值：true 和 false，这样就可以非常明确地表示逻辑真假了。bool 类型通常占用 8 位。

```c++
#include <iostream>

int main() {
    bool b1 = true;
    bool b2 = false;
    std::cout << "b1: " << b1 << std::endl;
    std::cout << "b2: " << b2 << std::endl;

    std::cout << std::boolalpha; // Enable boolalpha to print bool as true/false
    std::cout << "b1 (boolalpha): " << b1 << std::endl;
    std::cout << "b2 (boolalpha): " << b2 << std::endl;

    std::cout << std::noboolalpha; // Disable boolalpah
    std::cout << "bool len: " << sizeof(bool) << std::endl;
    
    return 0;

}
```

可以看到，true 和 false 可以直接赋值给 bool 类型的变量，打印输出的时候，true 就是 1，false 就是 0，这跟 C 语言里的表示其实是一样的。

### 浮点类型
浮点类型用来表示小数，主要有单精度 float 和双精度 double 两种类型，double 的长度不会小于 float。通常，float 会占用 4 个字节（32位），而 double 会占用 8 个字节（64位）。此外，C++ 还提供了一种扩展的高精度类型 long double，一般会占 12 或 16 个字节。

除了一般的小数，在 C++ 中，还提供了另外一种浮点数的表示法，那就是科学计数法，也叫作“E表示法”。比如：5.98E24表示5.98 $\times 10^{24}$，9.11e-31 表示 $9.11\times 10^{-31}$.


### 字面值常量
给变量赋值的整数、小数等数据，就是显示定义的常量值，叫做“字面值常量”，literal。每个字面值常量需要计算机进行保存和处理，因此也有数据类型。字面值常量的写法形式和具体值，决定了他的类型。

#### 整型字面值常量
整型字面值常量是一个整数，比如 30，这里是十进制，但在计算机底层是二进制的。除了十进制，还支持协程八进制和十六进制的形式。以 0 开头的整数表示八进制数，以 0x 或 0X 开头的表示十六进制数，以 0b 或 0B 开头的表示二进制数，如

- 30，十进制数
- 0b1101，二进制数
- 0B1100，二进制数
- 036，八进制数（1 个位表示 3 个二进制 0,1）
- 0x1E，十六进制数（1 个位表示 4 个二进制 0,1）
- 0X1e，十六进制数

这几个数本质上都是十进制的30，在计算机底层都是一样的。

在 C++ 中，一个整型字面值，默认就是 int 类型，前提是数值在 int 能表示的范围。如果超出 int 范围，那就需要选择能够表示这个数的长度最小的那个类型。

具体来说，对于十进制的整型字面值常量，如果 int 不够那么选择 long；还不够，就选择  long long （不考虑无符号类型）；而八进制和十六进制字面值，则优先用无符号类型 unsigned int，不够的话选择 long，之后依次是 unsigned long, long long 和 unsigned long long.

一般在定义整型字面值常量时，会给它加上一个后缀，明确告诉计算机这个字面值是什么类型。

- 默认什么都不加，是 int 类型
- l 或 L，表示 long 类型
- ll 或 LL，表示 long long 类型
- u 或者 U，表示 unsigned 无符号类型

对于 l 和 L，一般用 L，避免跟数字 1 混淆；而 u 可以和 L, LL 组合。如 036L, 0x1EULL

#### 浮点型字面值常量
用小数或科学计数法表示的数给浮点类型变量赋值，这样的数就是浮点型字面值常量。浮点型字面值默认类型是 double，如果想要明确指定类型，也可以加上相应的后缀：

- f 或 F，表示 float 类型
- l 或 L，表示 long double 类型

因为浮点型字面值本身是小数或科学计数法，所以 L 不会跟整型的 long 类型混淆。

示例：3.14f, 1.25L, 3.79E-23

#### 字符字面值常量
字符就是常说的字母、单个数字、符号等，字面值用单引号括起来表示。字符字面值默认类型是 char，底层存储是整型。

示例：','，'A'，'2'

**转义字符**
有一类比较特殊的字符字面值，不能直接使用。在 ASCII 码中，除了字母、数字外还有很多符号，其中有一些本身在 C++ 语法中被用于特殊的用途，比如单引号、双引号、一些控制字符等，如果想要使用它们，就需要进行转义，这就是转义字符。

C++ 中规定的转义字符有：

|符号名称|符号|符号名称|符号|符号名称|符号|
|--|--|--|--|--|--|
|换行符| \n | 横向制表符| \t |报警（响铃）符| \a |
|纵向制表符| \v |退格符| \b |双引号| \\" |
|反斜线| \ |问号| \\? |单引号| \\' |
|回车符| \r |进纸符| \f |

注意：在 C++ 中，\n 是换行符（Line Feed），它只将光标移动到下一行的开头；而 \r 是回车符（Carriage Return），它将光标移动到当前行的行首。 它们在不同操作系统中有不同的行为：Windows 系统通常使用 \r\n（回车+换行）组合来表示换行，而Unix/Linux 系统和macOS 则分别使用 \n（换行）和 \r（回车）。 

#### 字符串字面值常量
多个字符组合在一起，就构成了字符串，字符串字面值就是一串字符，用双引号引起了表示。

字符串是字符的组合，所以字符串字面值本质上是 char 类型构成的数组（array）

示例："ABCDE"，"C++"

#### 布尔字面值
布尔字面值非常简单，只有两个：true 和 false.
