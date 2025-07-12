#include"sort.h"

void num_move(int *data,int quantity)
{
    for(int i = quantity-2; i != -1; i--)
    {
        data[i+1] = data[i];
    }
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