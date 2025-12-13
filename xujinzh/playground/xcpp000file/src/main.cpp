#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::ifstream f("../resource/input.txt", std::ios::in);

    if (!f.is_open())
    {
        std::cerr << "read file error!" << std::endl;
        return -1;
    }
    // char buf[1024] = {0};
    std::string word;
    while (f >> word)
    {
        // std::cout << buf << std::endl;
        std::cout << word << std::endl;
    }
    // std::getchar();
    f.close();
    return 0;
}