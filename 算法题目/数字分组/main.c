#include <stdio.h>

int check_digits(int a, int b, int c) {
    int digits[10] = {0}; // 索引0-9，记录每个数字出现的次数
    // 分解a的各位数字
    while(a > 0) {
        digits[a % 10]++;
        a /= 10;
    }
    // 分解b的各位数字
    while(b > 0) {
        digits[b % 10]++;
        b /= 10;
    }
    // 分解c的各位数字
    while(c > 0) {
        digits[c % 10]++;
        c /= 10;
    }
    
    // 检查1-9是否都出现了一次，且0没有出现
    if(digits[0] != 0)// 不能有0
    {
        return 0; 
    }
    
    for(int i = 1; i <= 9; i++)
    {
        if(digits[i] != 1)// 每个数字1-9必须恰好出现一次
        {
            return 0;
        }
    }
    return 1; // 满足条件
}

int main()
{
    for(int a = 123; a <= 329; a++)
    {
        if(check_digits(a, 2*a, 3*a)) {
            printf("%d : %d : %d \n", a, 2*a, 3*a);
        }
    }
    return 0;
}