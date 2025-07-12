#include "main.h"

int main(int argc, char const *argv[])
{
    int num[100] = {0};
    make_num(&num[0], 100, 100);
    printf("未排序：");
    printf_num(&num[0],10);
    printf("\n已排序：");
    bubble_sort(&num[0],10);
    printf_num(&num[0],10);
    return 0;
}