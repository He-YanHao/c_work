#include<stdio.h>

int main()
{
    int OK = 0;
    for (int i1 = 1; i1 < 20; i1++)
    {
        for (int i2 = 2; i2 < 20; i2++)
        {
            if((i1 + i2) == 20)
            {
                if(i1 < i2)
                {
                    printf("%d,%d\n",i1,i2);
                    OK++;
                }
            }
        }
    }
    for (int i1 = 1; i1 < 20; i1++)
    {
        for (int i2 = 2; i2 < 20; i2++)
        {
            for (int i3 = 3; i3 < 20; i3++)
            {
                if((i1 + i2 +i3) == 20)
                {
                    if((i1 < i2) && (i2 < i3))
                    {
                        printf("%d,%d,%d\n",i1,i2,i3);
                        OK++;
                    }
                }
            }
        }
    }
    for (int i1 = 1; i1 < 20; i1++)
    {
        for (int i2 = 2; i2 < 20; i2++)
        {
            for (int i3 = 3; i3 < 20; i3++)
            {
                for (int i4 = 4; i4 < 20; i4++)
                {
                    if((i1 + i2 +i3 + i4) == 20)
                    {
                        if((i1 < i2) && (i2 < i3) && (i3 < i4))
                        {
                            printf("%d,%d,%d,%d\n",i1,i2,i3,i4);
                            OK++;
                        }
                    }
                }
            }
        }
    }
    for (int i1 = 1; i1 < 20; i1++)
    {
        for (int i2 = 2; i2 < 20; i2++)
        {
            for (int i3 = 3; i3 < 20; i3++)
            {
                for (int i4 = 4; i4 < 20; i4++)
                {
                    for (int i5 = 5; i5 < 20; i5++)
                    {
                        if((i1 + i2 +i3 + i4 + i5) == 20)
                        {
                            if((i1 < i2) && (i2 < i3) && (i3 < i4) && (i4 < i5))
                            {
                                printf("%d,%d,%d,%d,%d\n",i1,i2,i3,i4,i5);
                                OK++;
                            }
                        }
                    }
                }
            }
        }
    }
    printf("OK:%d",OK);
    return 0;
}
