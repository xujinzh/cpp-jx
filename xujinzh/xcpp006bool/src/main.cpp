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