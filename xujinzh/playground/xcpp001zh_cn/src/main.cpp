#include <iostream>
#include <cwchar>
#include <locale>

int main()
{
    std::locale::global(std::locale(""));
    std::wcout.imbue(std::locale(""));
    std::wcout << L"你好" << std::endl;
    std::wcout << L"hello, world" << std::endl;

    wchar_t ch = L'C';
    std::wcout << L"这是一个宽字符: " << ch << std::endl;
    return 0;
}