#include <stdio.h>
#include <math.h>

//有三个容积分别是3升、5升和8升的水桶，其中容积为8升的水桶中装满了水，容积为3升和容积为5升的水桶是空的。
//三个水桶都没有体积刻度，现在需要将大 水桶中的8升水等分成两份，每份都是4升水。
//附加条件是只能使用另外两个空水桶，不能借助其他辅助容器。 

// 二叉树节点结构
typedef struct TreeNode {
    int data[3];           //数据域
    struct TreeNode* left; //左子节点指针
    struct TreeNode* right;//右子节点指针
} TreeNode;


int main(int argc, char const *argv[])
{
    printf("aaa");
    return 0;
}