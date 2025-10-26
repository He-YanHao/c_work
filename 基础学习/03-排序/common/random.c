#include"random.h"

void make_num(int *data,int quantity,int size)//quantity 数字数量 size 数字大小
{
    srand(time(NULL));
    for(int i = 0; i < quantity; i++)
    {
       data[i] = rand() % size;
    }
}

void printf_num(int *num, int quantity)
{
    for(int i = 0; i < quantity; i++)
    {
        if(i%10 == 0)
        {
            printf("\n");
        }
        printf("%d  ",num[i]);
    }
}

