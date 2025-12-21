#include <iostream>

int main()
{
    double d = 3.14;
    const int &cref = d;

    // 因为引用到不同数据类型的变量，需要先进行类型转换
    // 此时，引用和原变量不再是同地址、可能值也不同
    std::cout << "d addr: " << &d << std::endl;
    std::cout << "cref addr: " << &cref << std::endl;
    std::cout << "d = " << d << std::endl;
    std::cout << "cref = " << cref << std::endl;

    int n = 8;
    int arr[n];

    std::cout << "arr = " << arr << std::endl;
    std::cout << "&arr[0] = " << &arr[0] << std::endl;

    return 0;
}