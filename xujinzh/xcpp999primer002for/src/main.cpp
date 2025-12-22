#include <iostream>

/*

当从键盘向程序输入数据时,对于如何指出文件结束,不同操作系统有不同的约定。
在 Windows系统中,输入文件结束符的方法是敲 Ctrl+Z(按住Ctrl键的同时按Z键),
然后按 Enter 或 Return 键。在UNIX 系统中,包括 Mac OS X 系统中,文件结束符输入
是用 Ctrl+D

*/
int main() {
    int sum = 0, value = 0;
    // 读取数据直到遇到文件尾，计算所有读入的值的和
    while (std::cin >> value) {
        sum += value; // 等价于 sum = sum + value
    }
    std::cout << std::endl;

    std::cout << "Sum is: " << sum << std::endl;
    return 0;
}