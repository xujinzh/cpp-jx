#include "../include/add.h"
#include <iostream>

int add(int x, int y)
{
    return x + y;
}

int main()
{
    int x = 1;
    int y = 2;
    int z = add(x, y);
    std::cout << z << std::endl;
    return 0;
}
