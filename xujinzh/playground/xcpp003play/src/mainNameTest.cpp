#include <iostream>
#include "../include/add.h"

using namespace std;

int main()
{
    bool flag = 0;
    cout << boolalpha << flag << endl;
    cout << 7.0127 / 2 << endl;
    char c = 67;
    cout << c << endl;
    cout << add(3, 5) << endl;

    cout << __cplusplus << endl; // 输出当前C++标准版本
    return 0;
} 