#include <stdio.h>

int ou[] = {0, 32, 15, 19, 4, 21, 2, 25, 17, 34, 6, 27, 13, 36, 11, 30, 8, 23, 10, 5, 24, 16, 33, 1, 20, 14, 31, 9, 22, 18, 29, 7, 28, 12, 35, 3, 26};
int mei[] = {0, 28, 9, 26, 30, 11, 7, 20, 32, 17, 5, 22, 34, 15, 3, 24, 36, 13, 1, 00, 27, 10, 25, 29, 12, 8, 19, 31, 18, 6, 21, 33, 16, 4, 23, 35, 14, 2};

int di(int x, int y)
{
    if(x < y)
    {
        return x;
    } else
    {
        x = x -y;
        di(x,y);
    }
}

int ou_max = 0, mei_max = 0, linshi = 0, yin = 0;

int ou_mei_max(int n)
{
    for(int i = 0; i < 37; i++)
    {
        linshi = 0;
        for(int j = 0; j < n; j++)
        {
            yin = di(i+j,37);
            linshi += ou[yin];
        }
        if(linshi > ou_max)
        {
            ou_max = linshi;
        }
    }
    for(int i = 0; i < 38; i++)
    {
        linshi = 0;
        for(int j = 0; j < n; j++)
        {
            yin = di(i+j,38);
            linshi += mei[yin];
        }
        if(linshi > mei_max)
        {
            mei_max = linshi;
        }
    }
    if(ou_max < mei_max)
    {
        return 0;
    } else
    {
        return 1;
    }
}

int main(int argc, char const *argv[])
{
    int ok = 0;
    for(int i = 2; i < 36; i++)
    {
        if(ou_mei_max(i) == 0)
        {
            ok++;
        }
    }
    printf("ok:%d",ok);
    return 0;
}