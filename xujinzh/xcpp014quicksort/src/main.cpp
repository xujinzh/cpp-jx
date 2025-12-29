#include <iostream>

using namespace std;

void swap(int (&)[10], int, int);
int partition(int (&)[10], int, int);
void quickSort(int (&)[10], int, int);
void printArr(const int (&)[10]);

int main()
{
    int arr[10] = {23, 45, 18, 6, 11, 19, 22, 18, 123, 9};
    printArr(arr);

    int size = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, size - 1);
    printArr(arr);
}

// 交换数组中的两个元素
void swap(int (&arr)[10], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// 按照支点进行分区的函数
int partition(int (&arr)[10], int start, int end)
{
    // 选取支点
    int pivot = arr[start];
    // 指定指向数组头尾元素的“指针”
    int left = start, right = end;
    // 只要 left 与 right 不相遇，left 向右移动，right想左移动
    while (left < right)
    {
        // 左指针不停右移，找到一个比支点大的值
        while (arr[left] <= pivot && left < right)
        {
            ++left;
        }
        // 右指针不停左移，找到一个比支点小的值
        while (arr[right] >= pivot && left < right)
        {
            --right;
        }
        // 左右互换
        swap(arr, left, right);
    }

    // 判断指针相遇位置的值，跟支点值的大小关系
    if (arr[left] <= pivot)
    {
        // 比支点值小，就直接换到数组的头位置
        swap(arr, start, left);
        return left;
    }
    else
    {
        // 比支点值大，就将前一个位置的元素直接换到数组的头位置
        swap(arr, start, left - 1);
        return left - 1;
    }
}

// 快速排序函数
void quickSort(int (&arr)[10], int start, int end)
{
    /**
     * 递归实现数组快速排序
     */
    // 基准情况，首尾两个指针相等
    if (start >= end)
    {
        return;
    }
    // 支点
    int pivot = partition(arr, start, end);
    // 对支点左右部分进行递归调用
    quickSort(arr, start, pivot - 1);
    quickSort(arr, pivot + 1, end);
}

// 打印输出数组
void printArr(const int (&arr)[10])
{
    for (int num : arr)
    {
        cout << num << "\t";
    }
    cout << endl;
}