#include"sort.h"

// 交换两个整数的值
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Selectioninsertion_sort(int arr[], int n)//插入排序
{
    // 从第二个元素开始（索引1），因为第一个元素默认已排序
    for (int i = 1; i < n; i++)//i为当前要排序的数字
    {
        int key = arr[i];  // 当前需要插入的元素
        int j = i - 1;    // 已排序部分的最后一个索引
        // 将大于key的元素向后移动
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];  // 元素后移
            j--;
        }
        // 找到正确位置，插入key
        arr[j + 1] = key;
    }
}

void selection_sort(int arr[], int n)//选择排序
{
    for(int i = 0; i < n-1; i++)
    {
        int min = i;//未排序元素最小元素的索引
        for(int j = i+1; j < n; j++)//j为已排序元素
        {
            if(arr[min] > arr[j])
            {
                min = j;
            }
        }
        //将找到的最小元素与当前位置交换
        if(min != i)
        {
            int num = arr[i];//当前元素保存
            arr[i] = arr[min];//最小元素赋值给当前元素
            arr[min] = num;//当前元素赋值给原最小元素的位置
        }
    }
}

void bubble_sort(int arr[], int n)//冒泡排序
{
    int flag = n;//未排序部分
    for(int j = 0; j < n; j++)
    {
        for(int i = 0; i < flag-1; i++)//每次只排序未排序部分
        {
            if(arr[i] > arr[i+1])//如果左元素大于右元素则交换
            {
                int num = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = num;
            }
        }
        flag--;//未排序部分-1
    }
}


// // 快速排序分区函数
// int partition(int *left, int *right)
// {
//     int pivot = *left;      // 选择最左边的元素作为基准
//     int *i = left + 1;     // 左指针从基准的下一个开始
//     int *j = right;         // 右指针从最右边开始
//     while (1)
//     {
//         // 左指针向右移动，直到找到大于等于基准的元素
//         while (i <= j && *i < pivot) i++;
//         {
//             // 右指针向左移动，直到找到小于等于基准的元素
//             while (i <= j && *j > pivot) j--;
//             {
//                 if (i >= j) 
//                 {
//                     break; // 指针相遇时退出
//                 }
//             }
//         }
//         swap(i, j);         // 交换左右指针指向的元素
//         i++;
//         j--;
//     }
//     swap(left, j);          // 将基准元素放到正确位置
//     return j - left;        // 返回基准元素的索引
// }

// // 快速排序递归函数
// void quick_sort(int *arr, int size)
// {
//     if (size <= 1)
//     {
//         return;
//     }
//     int pi = partition(arr, arr + size - 1); // 分区操作
//     quick_sort(arr, pi);                     // 递归排序左半部分
//     quick_sort(arr + pi + 1, size - pi - 1); // 递归排序右半部分
// }


// 随机选择基准并分区（避免最坏情况）
int partition(int arr[], int low, int high)//
{
    srand(time(NULL));
    // 随机选择基准（避免最坏时间复杂度）
    int random_idx = low + rand() % (high - low + 1);//让基准在低元素和高元素之间随机生成
    //random_idx 基准
    //low 低元素
    //high 高元素
    swap(&arr[random_idx], &arr[high]);//交换基准和高元素
    int pivot = arr[high];  // 基准值
    int i = low - 1;        // 小于基准的边界指针
    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)//小于基准值的
        {
            i++;
            swap(&arr[i], &arr[j]);//和基准值交换
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;  //返回基准最终位置
}

// 快速排序主函数
void quickSort(int arr[], int low, int high)
{
    if (low < high)//只高元素大于低元素就执行排序
    {
        // 获取基准位置
        int pi = partition(arr, low, high);//
        // 递归排序子数组
        quickSort(arr, low, pi - 1);  // 左半部分小于基准
        quickSort(arr, pi + 1, high); // 右半部分大于基准
    }
}
