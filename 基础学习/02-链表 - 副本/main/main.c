#include "main.h"

int main(int argc, char const *argv[])
{
    struct Node* headRef = NULL;//Node为链表数据结构  headRef为链表头
    AddNodeEnd(&headRef,10);//参数1为链表头地址 参数2为追加的数据
    AddNodeEnd(&headRef,20);//参数1为链表头地址 参数2为追加的数据
    AddNodeEnd(&headRef,30);//参数1为链表头地址 参数2为追加的数据
    AddNodeEnd(&headRef,20);//参数1为链表头地址 参数2为追加的数据
    DeleteNodeAll(&headRef,20);
    printf("开始打印链表：\n");
    printfNode(headRef);
    return 0;
}