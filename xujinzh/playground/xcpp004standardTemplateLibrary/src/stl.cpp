#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <typeinfo>
#include <boost/type_index.hpp> // 需要先安装该库
/**
 * 安装方法
 * 1. 下载：wget https://archives.boost.io/release/1.90.0/source/boost_1_90_0.tar.gz, 访问官网获取最新地址：https://www.boost.org/releases/latest/
 * 2. 解压：tar -xzvf boost_1_90_0.tar.gz
 * 3. 配置：cd boost_1_90_0 && ./bootstrap.sh
 * 4. 编译：./b2 -j10
 * 5. 安装：sudo ./b2 install
 *
 * 默认安装在 /usr/local/include/boost
 * 使用
 *
    #include <iostream>
    #include <boost/algorithm/string.hpp>

    int main() {
        std::string str = "Hello, World!";
        boost::to_upper(str);
        std::cout << str << std::endl;
        return 0;
    }
 */

using namespace std;

void printVector(vector<int> &vec)
{
    for (auto &v : vec)
    {
        cout << v << "\t";
    }
    cout << endl;
}

int main()
{
    cout << "\033[32m======================================================================\033[0m" << endl;

    // 定义一个固定大小的整数数组
    int ia[6] = {27, 210, 12, 47, 109, 83};

    // 使用vector容器来存储数组元素
    vector<int, allocator<int>> vi(ia, ia + 6);

    // 打印输出字符串，表示代码的开始
    cout << "\033[31mbegin:\033[0m" << endl;

    printVector(vi);

    // 使用count_if算法计算vector中大于等于40的元素数量
    cout << count_if(vi.begin(), vi.end(), not1(bind2nd(less<int>(), 40))) << endl;

    // 打印输出字符串，表示代码的结束
    cout << "\033[1;34mend.\033[0m" << endl;

    cout << "Type of vi.begin(): " << typeid(vi.begin()).name() << endl;
    cout << "Type of vi.begin(): " << boost::typeindex::type_id_with_cvr<decltype(vi.begin())>().pretty_name() << endl;
    cout << "Type of vi.end(): " << typeid(vi.end()).name() << endl;
    cout << "Type of vi.end(): " << boost::typeindex::type_id_with_cvr<decltype(vi.end())>().pretty_name() << endl;

    int a = 3;
    cout << "Type of a: " << boost::typeindex::type_id_with_cvr<decltype(a)>().pretty_name() << endl;
    double b = 3.14;
    cout << "Type of b: " << boost::typeindex::type_id_with_cvr<decltype(b)>().pretty_name() << endl;

    vector<int>::iterator ite;
    for (ite = vi.begin(); ite != vi.end(); ++ite)
    {
        cout << *(ite) << "\t";
    }
    cout << endl;

    auto iteP = ::find(vi.begin(), vi.end(), 12);
    cout << *iteP << endl;

    cout << "\033[32m======================================================================\033[0m" << endl;
    return 0;
}