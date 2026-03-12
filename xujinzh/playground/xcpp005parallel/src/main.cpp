/*并行累加*/
// 利用thread库实现多线程并行计算，更高效地处理大量数据（如本代码中10000个元素的累加）
// 核心目标：将一个容器（如vector）中的所有元素累加，通过多线程并行处理拆分后的元素块
// 最终汇总所有线程的计算结果，得到总累加值，同时自动匹配硬件支持的线程数

#include <iostream>
#include <vector>
#include <thread>
#include <algorithm>
#include <numeric>

// 用于并行累加操作
template <typename Iterator, typename T>
struct accumulate_block
{
    void operator()(Iterator first, Iterator last, T &result)
    {
        // 使用标准库中的accumulate函数，对迭代器范围内的元素进行累加，并将结果存储在
        result = std::accumulate(first, last, result);
    }
};

// 用于并行累加操作
template <typename Iterator, typename T>
T parallel_accumulate(Iterator first, Iterator last, T init)
{
    // 计算元素个数
    unsigned long const length = std::distance(first, last);
    // 如果元素个数为0，则直接返回初始值
    if (!length)
    {
        return init;
    }
    // 定义每个线程处理元素的最小数量
    unsigned long const min_per_thread = 25;
    // 计算最大线程数，保证每个线程最少处理 min_per_thread 个元素
    unsigned long const max_threads = (length + min_per_thread - 1) / min_per_thread;
    // 获取硬件支持的并发线程数
    unsigned long const hardware_threads = std::thread::hardware_concurrency();
    // 根据硬件线程数和最大线程数，确定实际使用的线程数
    unsigned long const num_threads = std::min(hardware_threads != 0 ? hardware_threads : 2, max_threads);
    // 计算每个线程处理的元素块
    unsigned long const block_size = length / num_threads;
    // 创建一个容器，用于存储每个线程累加的结果
    std::vector<T> results(num_threads);
    // 创建一个容器，用于管理创建的线程，-1 表示不管理主线程
    std::vector<std::thread> threads(num_threads - 1);
    // 初始化块起始迭代器为范围的起始迭代器
    Iterator block_start = first;
    // 遍历并创建线程，每个线程处理一个元素块
    for (unsigned long i = 0; i < (num_threads - 1); ++i)
    {
        // 计算块结束迭代器
        Iterator block_end = block_start;
        std::advance(block_end, block_size);
        // 创建线程，执行 accumulate_block 结构中的累加操作
        threads[i] = std::thread(accumulate_block<Iterator, T>(), block_start, block_end, std::ref(results[i]));
        // 更新块起始迭代器为下一个块的起始位置
        block_start = block_end;
    }
    // 在当前线程处理剩余的最后一个元素块（因为可能不是整数倍的线程数）
    accumulate_block<Iterator, T>()(block_start, last, results[num_threads - 1]);
    // 等待所有线程完成
    for (auto &t : threads)
    {
        t.join();
    }
    // 将所有线程的结果进行累加，并返回最终结果
    std::cout << "线程数为 " << num_threads << std::endl;
    return std::accumulate(results.begin(), results.end(), init);
}

int main(int argc, char *argv[])
{
    // 准备数据
    if (argc != 3)
    {
        std::cout << "传入参数个数不对，应该传入2个整数，" << "你传入参数个数是：" << argc << std::endl;
        return -1;
    }
    std::vector<unsigned long> numbers(std::stoul(argv[1]), std::stoul(argv[2]));
    // 调用平行累加求和
    unsigned long init = 0;
    // 这里不要直接传0而不是传明确类型的init，否则默认是int，求值范围会有限制
    unsigned long sum = parallel_accumulate(numbers.begin(), numbers.end(), init);

    // 输出结果
    std::cout << "累加结果为 " << sum << std::endl;

    // 获取unsigned long类型最大值
    std::cout << "能处理的最大值为 " << std::numeric_limits<unsigned long>::max() << std::endl;
    return 0;
}