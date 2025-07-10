#include <stdio.h>
#include <stdlib.h>

//定义链表节点结构体
struct Node{
    int num1;// 节点存储的数据
    struct Node* next;  // 指向下一个节点的指针
};

int main(int argc, char const *argv[])
{
    struct Node No = {0};
    No.num1 = 100;
    No.next = &No;
    printf("链表携带数据为：%d\n",No.num1);
    printf("链表携带地址为：%p\n",No);
    return 0;
}
