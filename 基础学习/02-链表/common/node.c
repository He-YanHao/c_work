#include "node.h"

//创建新的节点
struct Node* AddNode(int Num)//参数为新节点携带的数据
{
    Node* handle = malloc(sizeof(Node));//申请一块和链表空间大小相同的内存，并将地址传递给handle
    //printf("新申请链表节点地址为：%p\n",handle);
    handle->num1 = Num;
    handle->next = NULL;
    return handle;
}

//将节点插入链表尾部
void AddNodeEnd(Node** headRef, int data)//参数1为链表头地址 参数2为追加的数据
{
    Node* newNode = AddNode(data);//先申请节点 并用*newNode存储新节点的地址
    //printf("传入新申请链表节点地址为：%p\n",newNode);
    //printf("此时链表头地址为：%p\n",headRef);
    if(*headRef == NULL)//如果链表头为空，将新节点作为链表头赋值
    {
        *headRef = newNode;
        //printf("修改后链表头地址为：%p\n",*headRef);
        return;
    }
    //接下来是链表头非空的情况
    Node* current = *headRef;//临时变量current存储链表头数据
    while(current->next != NULL)
    {
        current = current->next;//
    }
    current->next = newNode;//
}

//删除链表特定节点
void DeleteNode(Node** headRef, int data)
{
    if(*headRef == NULL)//如果链表头为空退出
    {
        printf("链表头为空\n");
        return;
    }

    Node* current = *headRef;//保存链表头地址或上一个地址
    Node* prev = NULL;//保存下一个地址

    //要删除的是第一个是链表头
    if(current->num1 == data)
    {
        *headRef = current->next;
        free(current);
        return;
    }
    
    //遍历
    while(current->num1 != data)
    {
        prev = current;//保存链表头地址
        current = current->next;//下一个地址赋予上一个地址
    }
    //删除中间/尾部节点
    prev->next = current->next;
    free(current);
}

void DeleteNodeAll(Node** headRef, int data)
{
    if(*headRef == NULL)//如果链表头为空退出
    {
        printf("链表头为空\n");
        return;
    }

    Node* current1 = *headRef;//保存链表头地址或上一个地址

    if(current1->num1 == data)
    {
        *headRef = current1->next;
        free(headRef);
    }

    Node* current2 = current1->next;//保存下一个地址

    while(current2->next != NULL)//一直循环到链表最后最后一个节点
    {
        if(current1->num1 == data)//如果数据符合
        {
            current2 = current2;//
        }
    }
}

//更改链表特定节点
void ChengeNode()
{

}

//输出所有链表数据
void printfNode(struct Node* head)
{
    if(head == NULL)
    {
        printf("链表为空\n");
        return;
    }
    //接下来是链表头非空的情况
    Node* current = head;//临时变量current存储链表头数据
    while (current != NULL)
    {
        printf("节点地址: %p, 数据: %d, 下一个节点: %p\n", current, current->num1, current->next);
        current = current->next;
    }
}