#include "../include/common.h"

// 读取键盘输入的菜单选项，并进行合法性校验
char readMenuSelection(int options)
{
    /**
     *
     * 把用户从命令行输入的字符读取，并检验是否输入的字符是 '1' - options（如 '3'） 范围
     */

    string str;

    while (true)
    {
        // 从命令行读取用户输入放到字符串 str
        getline(cin, str);
        // 进行合法性校验
        if (str.size() != 1 || str[0] - '0' <= 0 || str[0] - '0' > options)
        {
            cout << "输入错误，请重新选择：";
        }
        else
        {
            break;
        }
    }
    // 输入合法
    return str[0];
}

// 读取确认退出信息，并进行合法性校验
char readQuitConfirm()
{
    /**
     *
     * 从命令行读取用户退出信息
     * 如果用户输入Y，那么表示退出；
     * 如果用户输入N，那么表示不退出；
     * 如果用户输入其他字符，那么输入不正确，需要重新输入
     */

    //  定义变量，存储用户输入信息
    string str;
    while (true)
    {
        getline(cin, str);
        // 进行合法性校验
        // 逻辑与&&运算优先级高于逻辑或||，这里表示，先与运算，再或运算
        if (str.size() != 1 || (toupper(str[0]) != 'Y' && toupper(str[0]) != 'N'))
        {
            cout << "输入错误，请重新输入（Y/N）：";
        }
        else
        {
            break;
        }
    }
    // 输入合法
    return toupper(str[0]);
}

// 录入键盘金额
int readAmount()
{
    /**
     * 读取用户在命令行输入的金额
     * 简单起见，只输入整数
     * 进行合法性校验
     */
    int amount;

    string str;
    while (true)
    {
        getline(cin, str);
        // 进行合法性校验
        try
        {
            amount = stoi(str);
            break;
        }
        catch (invalid_argument e)
        {
            cout << "输入错误，请正确输入数字：";
        }
    }
    // 输入合法
    return amount;
}