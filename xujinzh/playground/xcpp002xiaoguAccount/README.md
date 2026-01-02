# C++ 实现命令行小谷记账簿

- src: 所有源码(*.cpp)文件
- include: 公共头文件(*.h)
- bin: 生成的可执行文件
- resources: 资源文件

# 编译
```c++
// 建议这种
cd xcpp002xiaoguAccount/bin

g++ -std=c++17 -O3 -march=native -pthread -Wall -o ../bin/xiaogu_account -I ../include *cpp

// 或者

cd xcpp002xiaoguAccount

g++ -std=c++17 -O3 -march=native -pthread -Wall -o ./bin/xiaogu_account -I include ./src/*cpp
```

# 执行
```bash
# 建议这种
cd xcpp002xiaoguAccount/bin
./xiaogu_account

# 如果使用下面的执行命令，那么需要在 include/common.h 中修改 #define FILENAME "../resources/XiaoGuAccountBook.txt" 为 #define FILENAME "./resources/XiaoGuAccountBook.txt"
cd xcpp002xiaoguAccount
./bin/xiaogu_account

# 如果两种执行命令都需要，那么定义宏  #define FILENAME "/disk0/xcpp002xiaoguAccount/resources/XiaoGuAccountBook.txt" 为绝对路径
```
