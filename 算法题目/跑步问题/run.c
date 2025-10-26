#include<stdio.h>

int OK = 0;
int r[5] = {0};

void clear()
{
    r[0] = 0;
    r[1] = 0;
    r[2] = 0;
    r[3] = 0;
    r[4] = 0;
}

void fen(int a, int b, int c)//已经跑了几次 当前最大圈数 还剩多少
{
    if()
    {
        
    }
    fen(a+c,20,c+1);
}

int main()
{
    fen(1,20,1);
    printf("OK:%d",OK);
    return 0;
}

