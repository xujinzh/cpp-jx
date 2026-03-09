#include <iostream>

/*
当一个算术表达式中既有无符号数又有 int 值时,那个 int 值就会转换成无符号
数。把int 转换成无符号数的过程和把int 直接赋给无符号变量一样
*/

/*
编译
g++ -std=c++17 -O3 -march=native -pthread -o ./bin/main ./src/main.cpp

运行
./bin/main
*/

std::string global_str;
int global_int;

int main()
{
    // unsigned 是 unsigned int 简写
    unsigned u = 10, u2 = 42;
    std::cout << u2 - u << std::endl; // 结果为正，直接相减得结果
    std::cout << u - u2 << std::endl; // 结果为负，相减的结果自动转为无符号整数输出

    int i = 10, i2 = 42;
    std::cout << i2 - i << std::endl; // 有符号数，直接相减得结果
    std::cout << i - i2 << std::endl; // 有符号数，直接相减得结果

    std::cout << i - u << std::endl; // 先把有符号数i转为无符号数，再相减
    std::cout << u - i << std::endl; // 先把有符号数i转为无符号数，再相减

    // 分多行书写的字符串字面值
    std::cout << "a really, really long string literal "
                 "that spans two lines"
              << std::endl;

    std::cout << '\n';
    std::cout << "\tHi!\n";

    std::cout << '\12'; // 返回的转义序列，这里表示换行符
    // 输出 Hi MOM!，转到新一行. \115表示字符M
    std::cout << "Hi \x4dO\115!\n";

    std::cout << L'a';    // 宽字符型字面值，类型是 wchar_t
    std::cout << u8"hi!"; // utf-8字符串字面值（utf-8用8位编码一个Unicode字符）
    std::cout << 42ULL;   // 无符号整型字面值，类型是 unsigned long long
    std::cout << 1E-3F;   // 单精度浮点型字面值，类型是 float
    // 当使用一个长整型字面值时，请使用大写字母L来标记，因为小写字母l和数字1太容易混淆了
    std::cout << 3.14159L; // 扩展精度浮点型字面值，类型是 long double

    std::cout << std::endl;
    std::cout << 'a' << std::endl;
    std::cout << L'a' << std::endl;
    std::cout << "a" << std::endl;
    std::cout << L"a" << std::endl;

    int month = 9, day = 7;
    std::cout << month << " " << day << std::endl;

    int month1 = 0x9, day1 = 07;
    std::cout << month1 << " " << day1 << std::endl;

    // 以下4条语句都可以对int变量初始化为0
    int units_sold = 0;
    int units_sold_1 = {0};
    int units_sold_2{0};
    int units_sold_3(0);

    // price先被定义并赋值，随后被用于初始化discount
    double price = 109.99, discount = price * 0.16;

    /*
    使用 long double 的值初始化 int 变量时可能丢失数据,所以编译器拒绝了a和b的初
    始化请求。其中,至少1d的小数部分会丢失掉,而且int 也可能存不下1d的整数部分。
    */
    long double ld = 3.14159265358;

    int a{ld}, b = {ld}; // 编译时会发出警告，因为存在丢失信息的危险
    int c(ld), d = ld;   // 编译时不会发出警告，且确实丢失了部分值
    std::cout << a << b << c << d << std::endl;

    // std::cin >> int input_value; // type name is not allowed
    // int iii = {3.14}; // from double to int error
    // double salary = wage = 9999.99; // identifier "wage" is undefined
    int ii = 3.14;
    std::cout << ii << std::endl;

    // 变量未初始化
    int local_int;
    std::string local_str;

    std::cout << global_str << std::endl;
    std::cout << global_int << std::endl;
    std::cout << local_str << std::endl;
    std::cout << local_int << std::endl;

    /*
    为了允许把程序拆分成多个逻辑部分来编写,C++语言支持分离式编译(separate
    compilation)机制,该机制允许将程序分割为若干个文件,每个文件可被独立编译。
    */

    {

        extern int i1; // 声明i而非定义i
        int j;         // 声明并定义j

        // 给由 extern 关键字标记的变量赋一个初始值,但是这么做也就抵消了 extern 的作用。
        // extern 语句如果包含初始值就不再是声明,而变成定义了
        // 在函数体内部,如果试图初始化一个由 extern 关键字标记的变量,将引发错误。
        // extern double pi = 3.14159; // 定义

        /*
        C++也为标准库保留了一些名字。用户自定义的标识符中不能连续出现两个下
        画线,也不能以下画线紧连大写字母开头。此外,定义在函数体外的标识符不能以下画线
        开头。
        */

        // int double = 3.14; // invalid combination of type specifiers
        int _;
        // int catch - 22; // expected an identifier
        // int 1_or_2 = 1; // expected an identifier
        double Double = 3.14;
        std::cout << _ << std::endl;
        std::cout << Double << std::endl;
        int i;
        std::cout << i << std::endl;
    }

    {
    }
}