#include <stdio.h>
#include <math.h>

double num = 0;

int bi[11] = {0,1,2,3,4,5,6,7,8,9,-10};

int cha(int b)
{
    for(int i = 0; i<10; i++)
    {
        if(bi[i] == b)
        {
            bi[i] = -10;
        }
    }
    for(int j = 0; j < 10; j++)
    return 1;
}

int re(int a)
{
    num = sqrt(a);
    while (1)
    {
        num = num*10;
        if(cha((int)num%10))
        {
            return 1;
        }
    }
    
}

int main(int argc, char const *argv[])
{
    for(int i = 1; i < 200; i++)
    {
        for(int j = 0; j < 10; j++)
        { bi[j] = j; }

    }
    return 0;
}