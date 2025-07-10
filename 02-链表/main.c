#include <stdio.h>
#include <stdlib.h>

//定义链表节点结构体
struct Node{
    int num1;// 节点存储的数据
    struct Node* next;  // 指向下一个节点的指针
};

//创建新的节点
struct Node* AddNode(int Num)//参数为新节点携带的数据
{
    struct Node* handle = (struct Node*)malloc(sizeof(struct Node));//申请一块和链表空间大小相同的内存，并将地址传递给handle
    printf("新申请链表节点地址为：%p\n",handle);
    handle->num1 = Num;
    handle->next = NULL;
    return handle;
}

//将节点插入链表尾部
void AddNodeEnd(struct Node** headRef, int data)//参数1为链表头地址 参数2为追加的数据
{
    struct Node* newNode = AddNode(data);//先申请节点 并用*newNode存储新节点的地址
    printf("传入新申请链表节点地址为：%p\n",newNode);
    printf("此时链表头地址为：%p\n",headRef);
    if(*headRef == NULL)//如果链表头为空，将新节点作为链表头赋值
    {
        *headRef = newNode;
        printf("修改后链表头地址为：%p\n",*headRef);
        return;
    }
    //接下来是链表头非空的情况
    struct Node* current = *headRef;//临时变量current存储链表头数据
    while(current->next != NULL)
    {
        current = current->next;//
    }
    current->next = newNode;//
}

void printfNode(struct Node* head)
{
    if(head == NULL)
    {
        printf("链表为空\n");
        return;
    }
    //接下来是链表头非空的情况
    struct Node* current = head;//临时变量current存储链表头数据
    while (current != NULL)
    {
        printf("节点地址: %p, 数据: %d, 下一个节点: %p\n", current, current->num1, current->next);
        current = current->next;
    }
}


int main(int argc, char const *argv[])
{
    struct Node* headRef = NULL;//Node为链表数据结构  headRef为链表头
    AddNodeEnd(&headRef,10);//参数1为链表头地址 参数2为追加的数据
    AddNodeEnd(&headRef,20);//参数1为链表头地址 参数2为追加的数据
    AddNodeEnd(&headRef,30);//参数1为链表头地址 参数2为追加的数据
    AddNodeEnd(&headRef,40);//参数1为链表头地址 参数2为追加的数据
    AddNodeEnd(&headRef,50);//参数1为链表头地址 参数2为追加的数据
    AddNodeEnd(&headRef,60);//参数1为链表头地址 参数2为追加的数据
    printf("链表头地址为：%p\n",headRef);
    printf("开始打印链表：\n");
    printfNode(headRef);
    return 0;
}
