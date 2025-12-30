#include <iostream>
using namespace std;

// 交换数组中的两个元素
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// 按照支点进行分区的函数
int partition(int arr[], int low, int high) {
    // 选取支点
    int pivot = arr[high];
    // 指定指向数组头尾元素的“指针”
    int i = low - 1;
    // 只要 left 与 right 不相遇，left 向右移动，right想左移动
    for (int j = low; j < high; ++j) {
        if (arr[j] <= pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    // 将支点元素放到正确的位置
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// 快速排序函数
void quickSort(int arr[], int low, int high) {
    /**
     * 递归实现数组快速排序
     */
    // 基准情况，首尾两个指针相等
    if (low >= high) {
        return;
    }
    // 支点
    int pivot = partition(arr, low, high);
    // 对支点左右部分进行递归调用
    quickSort(arr, low, pivot - 1);
    quickSort(arr, pivot + 1, high);
}

// 打印输出数组
void printArr(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << "\t";
    }
    cout << endl;
}

int main() {
    int arr[] = {23, 45, 18, 6, 11, 19, 22, 18, 123, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Original array: ";
    printArr(arr, size);

    quickSort(arr, 0, size - 1);
    cout << "Sorted array: ";
    printArr(arr, size);
}