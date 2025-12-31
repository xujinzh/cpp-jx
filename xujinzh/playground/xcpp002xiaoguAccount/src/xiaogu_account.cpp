#include "../include/common.h"
#include "../include/account_item.h"

int main()
{
    // 1. 加载文件中的账目数据
    vector<AccountItem> items;

    loadDataFromFile(items);

    bool quit = false;
    while (!quit)
    {
        // 2. 显示主菜单
        showMainMenu();
        // 3. 读取键盘选择，并做合法性检验
        char key = readMenuSelection(3);
        
        switch (key)
        {
        case '1':
            /* 记账 */
            showAccountingMenu();
            accounting(items); // 可能会改变 items
            break;
        case '2':
            /* 查询 */
            showQueryMenu();
            query(items); // 不会改变items
            break;
        case '3':
            cout << "\n是否确认退出？（Y/N）: ";
            if (readQuitConfirm() == 'Y')
            {
                quit = true;
            }

        default:
            break;
        }
        cout << endl;
    }
}