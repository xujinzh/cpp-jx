#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <filesystem>
#include <thread>
#include <chrono>

/*
g++ -std=c++17 mainBinary.cpp -O3 -march=native -pthread -o ../bin/macMainBinary
*/

std::vector<std::string> getAllFilesRecursively(const std::string &directoryPath)
{
    /*
    get all files in the directory and its subdirectories recursively
    */
    std::vector<std::string> filesPath;
    try
    {
        for (const auto &entry : std::filesystem::recursive_directory_iterator(directoryPath))
        {
            if (entry.is_regular_file())
            {
                filesPath.push_back(entry.path().string());
            }
        }
    }
    catch (const std::filesystem::filesystem_error &e)
    {
        std::cerr << "filesystem error: " << e.what() << std::endl;
    }
    return filesPath;
}

std::vector<u_char> accSumCal(std::vector<u_char> data)
{
    /*
    calculate the accumulated sum of the input data
    */
    if ((data.size() % 4) != 0)
    {
        std::cerr << "data size if not multiple of 4" << std::endl;
        return std::vector<u_char>(4, 0);
    }
    int acc = 0;
    int count = 0;
    for (int val : data)
    {
        acc += (val << (4 - count - 1) * 8);
        acc &= 0xFFFFFFFF;
        count = ((count + 1) % 4);
    }
    // for (int val : data) {
    //     std::cout << std::hex << std::setw(2) << std::setfill('0') << (int)val;
    // }
    // std::cout << std::endl;
    // std::cout << "calculated acc sum: " << std::hex << std::setw(8) << std::setfill('0') << acc << std::dec << std::endl;
    std::vector<u_char> result(4);
    for (int i = 0; i < 4; ++i)
    {
        result[3 - i] = ((acc >> (i * 8)) & 0xFF);
    }
    return result;
}

int update33033File(const std::string &filePath)
{
    // std::string filePath = "/Volumes/MyPassport/work/data/csst/xt/duanbo-FUZHU_1.dat.noFDFDandFBFB.dat.33033-taskNum15.dat";
    std::ifstream inputFile(filePath, std::ios::in | std::ios::binary);
    if (!inputFile)
    {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    std::ofstream outputFile(filePath + ".updated.bin", std::ios::out | std::ios::binary);
    if (!outputFile)
    {
        std::cerr << "Error creating output file." << std::endl;
        return 1;
    }

    // read data block
    int blockSize = 33033;
    std::vector<u_char> dataBlock(blockSize);

    int count33033 = 0;

    while (inputFile.read(reinterpret_cast<char *>(dataBlock.data()), dataBlock.size() * sizeof(u_char)))
    // while (inputFile.read(reinterpret_cast<char *>(dataBlock.data()), blockSize))
    {
        count33033++;

        // upate packet count
        std::swap(dataBlock[12], dataBlock[14]);
        std::swap(dataBlock[13], dataBlock[15]);

        // update accumulated sum
        std::vector<u_char> accSumCaled = accSumCal(std::vector<u_char>(dataBlock.begin() + 4, dataBlock.begin() + dataBlock.size() - 233 - 4));
        std::swap(dataBlock[dataBlock.size() - 233 - 4], accSumCaled[0]);
        std::swap(dataBlock[dataBlock.size() - 233 - 3], accSumCaled[1]);
        std::swap(dataBlock[dataBlock.size() - 233 - 2], accSumCaled[2]);
        std::swap(dataBlock[dataBlock.size() - 233 - 1], accSumCaled[3]);

        // write new data block to output file
        outputFile.write(reinterpret_cast<char *>(dataBlock.data()), dataBlock.size() * sizeof(u_char));
    }
    inputFile.close();
    outputFile.close();

    std::cout << "total 33033 blocks: " << std::dec << count33033 << std::endl;
    return 0;
}

void update33033FileWithThreadPool(const std::vector<std::string> &files)
{
    /*
    update multiple 33033 files using thread pool
    */
    auto start = std::chrono::high_resolution_clock::now();
    std::vector<std::thread> threads;

    for (const auto &filePath : files)
    {
        threads.emplace_back(update33033File, filePath);
    }
    // wait for all threads to finish
    for (auto &thread : threads)
    {
        thread.join();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Total time taken: " << duration.count() << " ms" << std::endl;
}

int main(int argc, char *argv[])
{
    /*
    更新33033文件中每一包的数据包计数，并更新累加和
    第一个参数表示代码
    第二个参数表示33033文件路径
    */

    // update 33033 file
    // update33033File(argv[1]);
    // 使用示例：../bin/macMainBinary /Volumes/MyPassport/work/data/csst

    // get all files recursively
    std::vector<std::string> files = getAllFilesRecursively(argv[1]);

    // filter .dat files
    std::vector<std::string> datFiles;
    for (const auto &filePath : files)
    {   
        // 以 .dat 结尾且文件名不以 . 开头（Linux系统）
        if ((std::filesystem::path(filePath).extension() == ".dat") && (std::filesystem::path(filePath).filename().string().rfind(".", 0) != 0))
        {
            datFiles.push_back(filePath);
        }
    }

    // print all dat files
    for (const auto &filePath : datFiles)
    {
        std::cout << "dat files: " << filePath << std::endl;
    }

    update33033FileWithThreadPool(datFiles);
    return 0;
}