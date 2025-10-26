#include <stdio.h>
#include <limits.h>

unsigned long long fei[100] = {1,1};

int wei_long(unsigned long long num)
{
    if(num == 0) return 0;  // 处理0的情况
    int wei = 0;
    while(num != 0)
    {
        wei += num%10;
        num = num / 10;
    }
    return wei;
}

int main(int argc, char const *argv[])
{
    for(int i = 2; i < 100; i++)
    {
        fei[i] = fei[i-1] + fei[i-2];
        if(fei[i]%wei_long(fei[i]) == 0)
        {
            printf("%u\n",ULLONG_MAX - fei[i]);
            printf("第%d个数字%d符合条件，各位数上的和为%d:\n",i,fei[i],wei_long(fei[i]));
        }
    }
    return 0;
}