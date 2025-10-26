#include "main.h"

#define LEN 256

int main(int argc, char const *argv[])
{
    int num[LEN] = {0};
    for(int i = 0; i < LEN; i++)//初始化
    {
        num[i] = i;
    }
    int cha = 73;//查找的数字
    int jie = 0;//所在的位置
    int da = LEN-1;
    int xiao = 0;
    while(xiao <= da)
    {
        jie = xiao + (da - xiao)/2;
        if(cha == num[jie])
        {
            break;
        }
        else if(cha > num[jie])
        {
            xiao = jie + 1;
        } else
        {
            da = jie - 1;
        }
    }
    printf("%d",num[jie]);
    return 0;
}