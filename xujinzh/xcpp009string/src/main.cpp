#include <iostream>
#include <string>

int main()
{
    std::string str;
    std::string str2 = "hello world";
    std::cout << str2 << std::endl;
    std::cout << "==========" << std::endl;
    
    std::cin >> str; // 读一个单词，遇到空格结束
    std::cout << str << std::endl;
    std::cout << "==========" << std::endl;
    
    std::string str3;
    getline(std::cin, str3); // 读取一行，遇到回车结束
    std::cout << str3 << std::endl;
    std::cout << "==========" << std::endl;
    
    char c;
    c = std::cin.get(); // 读取一个字符
    std::cout << c << std::endl;
    std::cout << "==========" << std::endl;
}

