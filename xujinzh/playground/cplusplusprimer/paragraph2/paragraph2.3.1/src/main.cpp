#include <iostream>

int main()
{
    // exercise 2.15
    int ival = 1.01;
    // int &rval1 = 1.01; // initial value of reference to non-const must be an lvalue
    int &rval2 = ival;
    // int &rval3;     // reference variable "rval3" requires an initializer

    std::cout << ival << std::endl;
    std::cout << rval2 << std::endl;

    // exercise 2.16
    int i = 0, &r1 = i;
    double d = 0, &r2 = d;
    r2 = 3.14159;
    std::cout << "r2:" << r2 << std::endl;
    r2 = r1;
    std::cout << "r2:" << r2 << std::endl;
    i = r2;
    std::cout << "i:" << i << std::endl;
    r1 = d;
    std::cout << "r1:" << r1 << std::endl;

    // exercis 2.17
    {
        int i, &ri = i;
        i = 5;
        ri = 10;
        std::cout << i << " " << ri << std::endl;
    }
    return 0;
}