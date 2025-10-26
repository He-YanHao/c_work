#ifndef __NODE_H
#define __NODE_H

#include <stdio.h>
#include <stdlib.h>

//定义链表节点结构体
typedef struct Node{
    int num1;// 节点存储的数据
    struct Node* next;  // 指向下一个节点的指针
}Node;

Node* AddNode(int Num);//新增节点
void AddNodeEnd(Node** headRef, int data);//链表结尾新增一个节点
void DeleteNode(Node** headRef, int data);//删除链表特定节点
void DeleteNodeAll(Node** headRef, int data);//删除链表特定节点
//void ChengeNode();//更改链表特定节点
void printfNode(Node* head);//打印链表

#endif