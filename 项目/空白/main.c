#include<stdio.h>
#include<string.h>  // 需要添加这个头文件

int main()
{
    char text[255] = {0};
    int num = 0;
    //printf("请输入文本: ");
    fgets(text, sizeof(text), stdin);
    for(int i = 0; i < strlen(text); i++)
    {
        if(text[i] >= '0' && text[i] <= '9' )
        {
            num++;
        }
    }
    printf("%d\n",num);
    return 0;
}