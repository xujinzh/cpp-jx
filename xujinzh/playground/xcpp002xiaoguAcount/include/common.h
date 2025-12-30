#pragma once

// 导入包
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// 宏定义常量
#define INCOME "收入"
#define EXPAND "支出"
// #define FILENAME "../resources/XiaoGuAccountBook.txt"
#define FILENAME "/home/jinzhongxu/disk0/codes/cpp/cpp-jx/xujinzh/playground/xcpp002xiaoguAcount/resources/XiaoGuAccountBook.txt"

// 使用命名空间 std
using namespace std;

// 通用功能性函数声明


// 绘制菜单的函数
void showMainMenu();
void showAccountingMenu();
void showQueryMenu();

// 读取键盘输入并进行合法性校验的函数
char readMenuSelection(int options);
char readQuitConfirm();
int readAmount();
