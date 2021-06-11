#pragma once
#include "Base.h"
#include<iostream>
typedef int TElemType;

//链式二叉树
typedef struct BiTNode
{
    TElemType data;
    struct BiTNode* lchild, * rchild;  //左右孩子
}BiTNode, * BiTree;

Status Test4(void);
Status InitTree(BiTree& root);  //链式二叉树的初始化(通过输入的先序遍历顺序初始化)
Status ShowMeun4(void);
Status PreOrderTraverse(BiTree& root);
Status InOrderTraverse(BiTree& root);
Status BehOrderTraverse(BiTree& root);
Status TreeTraverse(BiTree& root);
int TreeDepth(BiTree T);
void CountLeaf(BiTNode* T, int& num);
void TreeChildX(BiTree T, TElemType e);
void TreeParentX(BiTree T, TElemType x);
void TreeBrother(BiTree T, TElemType x);
Status Test4(void) {
    int select;
    BiTree T = nullptr;
    ShowMeun4();
    while (TRUE) {
        printf("操作序号----->");
        scanf("%d", &select);
        switch (select) {
        case 1: {  //通过先序序列构建二叉树
            InitTree(T);
            break;
        }
        case 2: {  //三种方式遍历二叉树
            TreeTraverse(T);
            break;
        }
        case 3: {  //树的长度
            printf("树的深度(长度)为 %d \n", TreeDepth(T));
            break;
        }
        case 4: {  //叶子节点的个数
            int num = 0;
            CountLeaf(T, num);
            printf("叶子节点个数num = %d \n", num);
            break;
        }
        case 5: {  //显示值为Temp的节点的左右孩子
            int Temp;
            printf("请输入您要查询的节点数值Temp:");
            scanf("%d", &Temp);
            TreeChildX(T, Temp);
            break;
		}
        case 6: {  //显示值为Temp的节点的双亲节点
            int Temp;
            printf("请输入您要查询的节点数值Temp:");
            scanf("%d", &Temp);
            TreeParentX(T, Temp);
            break;
        }
        case 7: {  //显示值为Temp的节点的双亲节点
            int Temp;
            printf("请输入您要查询的节点数值Temp:");
            scanf("%d", &Temp);
            TreeBrother(T, Temp);
            break;
        }
        //退出
        case 0: {
            exit(-1);
        }
        default:
            break;
        }
    }
	return TRUE;
}
Status InitTree(BiTree& root){   //把树根传入
    //定义每个节点的值都为正整数
    //每个节点的值
    int temp;
    scanf("%d", &temp);
    
    if (temp == -1) {  //如果是   -1该节点不存在
        root = NULL;
    }  //该节点存在
    else {
        root = (BiTNode*)malloc(sizeof(BiTNode));  //创建该节点
        root->data = temp;  //将数值存入根节点

        //递归
        //左子树
        InitTree(root->lchild);
        //右子树
        InitTree(root->rchild);
    }
    return TRUE;
}
Status ShowMeun4(void) {
    printf("假设每个节点的值均为正整数 值为-1的节点不存在\n");
    printf("1.根据用户输入的扩展的先序遍历序列创建二叉树的二叉链表存储结构\n");
    printf("2.编写二叉树的先序遍历、后序遍历、中序遍历算法\n");
    printf("3.编写函数，求二叉树高度\n");
    printf("4.编写函数，求二叉树中叶子节点的个数。\n");
    printf("5.写一个函数LeftChild(T,e)或RightChild(T,e)，实现求二叉树T中某个非叶子结点e的左孩子或右孩子，若e无左孩子或右孩，则返回空\n");
    printf("6.写一个函数Parent(T,e)，实现求二叉树T中某个非根结点e的双亲，若e无双亲，则返回空 \n");
    printf("7.写一个函数LeftSibling(T,e)或RightSibling(T,e)，实现求二叉树T中某个结点e的左兄弟或右兄弟 \n");
    printf("0.退出\n");
    return TRUE;
}
Status PreOrderTraverse(BiTree& root) {
    if (root) {  //树根是否存在
        //根
        printf("%d ", root->data);
        //左
        if (root->lchild) PreOrderTraverse(root->lchild);
        //右
        if (root->rchild) PreOrderTraverse(root->rchild);
    }
    return OK;
}
Status InOrderTraverse(BiTree& root) {
    if (root) {  //树根是否存在
        //左
        if (root->lchild) InOrderTraverse(root->lchild);
        //根
        printf("%d ", root->data);
        //右
		if (root->rchild) InOrderTraverse(root->rchild);
    }
    return OK;
}
Status BehOrderTraverse(BiTree& root) {
    if (root) {  //树根是否存在
        //左
        if (root->lchild) BehOrderTraverse(root->lchild);
        //右
        if (root->rchild) BehOrderTraverse(root->rchild);
        //根
        printf("%d ", root->data);
    }
    return OK;
}
Status TreeTraverse(BiTree& root) {
    printf("先序排序:");
    PreOrderTraverse(root);
    printf("\n");

    printf("中序排序:");
    InOrderTraverse(root);
    printf("\n");
    
    printf("后序排序:");
    BehOrderTraverse(root);
    printf("\n");

    return TRUE;
}
int TreeDepth(BiTree T) {
    int depth;
    if (!T)  //树不存在
    {
		depth = 0;
    }
    else if ((!T->lchild) && (!T->rchild)) depth = 1;
    else {
       int  Left = TreeDepth(T->lchild);
       int  Right = TreeDepth(T->rchild);
        depth = 1 + (Left > Right ? Left : Right);
    }
    return depth;
}
void CountLeaf(BiTNode* T, int &num){
    if (T){
        //如果没有左右孩子(叶子节点)
        if (!T->lchild && !T->rchild) num++;
        CountLeaf(T->lchild, num);
        CountLeaf(T->rchild, num);
    }
}
void TreeChildX(BiTree T, TElemType e){
    if (T){
        if (T->data == e) {
            if (!T->lchild) std::cout << e << "无左孩子" << std::endl;
            if (T->lchild) std::cout << e << "的左孩子为" << T->lchild->data << std::endl;
            if (!T->rchild) std::cout << e << "无右孩子" << std::endl;
            if (T->rchild) std::cout << e << "的右孩子为" << T->rchild->data << std::endl;
            return;
        }
        TreeChildX(T->lchild, e);
        TreeChildX(T->rchild, e);
    }
}
void TreeParentX(BiTree T, TElemType x) {
    if (T){
        //如果存在左孩子或右孩子值等于Temp
        if ((T->lchild && T->lchild->data == x) ||
            (T->rchild && T->rchild->data == x)){
            std::cout << x << "的双亲为" << T->data << std::endl; return;
        }
        TreeParentX(T->lchild, x);
        TreeParentX(T->rchild, x);
    }
}
void TreeBrother(BiTree T, TElemType x) {
    if (T) {
        //如果存在左孩子或右孩子值等于Temp
		if (T->lchild && x == T->lchild->data) {
            if (T->rchild) {
                std::cout << x << "的兄弟为" << T->rchild->data << std::endl; return;
            }
        }
        if (T->rchild && x == T->rchild->data) {
            if (T->lchild) {
                std::cout << x << "的兄弟为" << T->lchild->data << std::endl; return;
            }
        }
        TreeBrother(T->lchild, x);
        TreeBrother(T->rchild, x);
    }
}
