#include<iostream>
#include<fstream>
#include<string>

int main() {
    // 1. 按照单词逐个读取
    std::ifstream input("../resource/input.txt"); // 读
    std::ofstream output("../resource/output.txt"); // 写
    std::string word;
    while (input >> word) {
        std::cout << word << std::endl;
        output << word;
    }
    std::cout << "======" << std::endl;
    
    // 2. 逐行读取
    std::ifstream input2("../resource/input.txt");
    std::ofstream output2("../resource/output2.txt");
    std::string line;
    while (getline(input2, line)) {
        std::cout << line << std::endl;
        output2 << line << "\n";
    }
    std::cout << "======" << std::endl;
    
    // 3. 逐字符读取
    std::ifstream input3("../resource/input.txt");
    std::ofstream output3("../resource/output3.txt");
    char ch;
    while (input3.get(ch)) {
        std::cout << ch << std::endl;
        output3 << ch;
    }
    std::cout << "======" << std::endl;
}