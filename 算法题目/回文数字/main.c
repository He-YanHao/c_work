#include<stdio.h>
#include<string.h>

char str1[100] = {0};
char str2[100] = {0};

int num_long(int num,int len)
{
    int chang = 0;
    while(num != 0)
    {
        chang++;
        num = num/len;
    }
    return chang;
}

void change(int num, int len)
{
    int chang = num_long(num,len);
    int chang2 = chang, num2 = num;
    str1[chang] = 0;
    str2[chang] = 0;
    while(chang)
    {
        str1[chang-1] = num%len + '0';
        num = num/len;
        chang--;
    }
    while(chang2 != chang)
    {
        str2[chang] = num2%len + '0';
        num2 = num2/len;
        chang++;
    }
}

int bi(int num)
{
    change(num, 2);
    if(strcmp(str1,str2)==0)
    {
        change(num,8);
        if(strcmp(str1,str2)==0)
        {
            change(num,10);
            if(strcmp(str1,str2)==0)
            {return 0;}else{return 1;}
        }
    }
}

int main()
{
    int num = 11;
    while(bi(num))
    {num = num + 2;}
    printf("%s  %s\n",str1,str2);
}

/*
#include<stdio.h>
#include<string.h>

char str1[100] = {0};
char str2[100] = {0};

// 计算数字在指定进制下的位数
int num_long(int num, int len)
{
    if(num == 0) return 1;  // 处理0的情况
    
    int chang = 0;
    while(num != 0)
    {
        chang++;
        num = num / len;
    }
    return chang;
}

// 将数字转换为字符串（正序和逆序）
void change(int num, int len)
{
    int chang = num_long(num, len);
    int temp = num;
    
    // 生成正序字符串
    for(int i = chang - 1; i >= 0; i--)
    {
        str1[i] = temp % len + '0';
        temp = temp / len;
    }
    str1[chang] = '\0';
    
    // 生成逆序字符串
    temp = num;
    for(int i = 0; i < chang; i++)
    {
        str2[chang - 1 - i] = temp % len + '0';
        temp = temp / len;
    }
    str2[chang] = '\0';
}

// 检查是否为多进制回文数
int is_multi_base_palindrome(int num)
{
    change(num, 2);
    if(strcmp(str1, str2) != 0) return 1;  // 二进制不是回文
    
    change(num, 8);
    if(strcmp(str1, str2) != 0) return 1;  // 八进制不是回文
    
    change(num, 10);
    if(strcmp(str1, str2) != 0) return 1;  // 十进制不是回文
    
    return 0;  // 所有进制都是回文
}

int main()
{
    int num = 11;
    while(is_multi_base_palindrome(num))
    {
        num = num + 2;
    }
    
    printf("找到的数字: %d\n", num);
    printf("二进制: ");
    change(num, 2);
    printf("%s (正序) = %s (逆序)\n", str1, str2);
    
    printf("八进制: ");
    change(num, 8);
    printf("%s (正序) = %s (逆序)\n", str1, str2);
    
    printf("十进制: ");
    change(num, 10);
    printf("%s (正序) = %s (逆序)\n", str1, str2);
    
    return 0;
}
*/