#pragma once

/*
* 物联11902班 张宜成 201902849
* 该头文件创建于5月28日
*
* Test4.h头文件:
*		包含二叉树的相关函数
*		包含哈夫曼编码(未实现)
*/

#include "Base.h"

typedef int TElemType;
//链式二叉树
typedef struct BiTNode{
    TElemType data;
    struct BiTNode* lchild, * rchild;  //左右孩子
}BiTNode, * BiTree;
//-----------------------------------------------------
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
//-----------------------------------------------------
Status Test4(void) {
    int select;
    BiTree T = nullptr;
    
    while (TRUE) {
        ShowMeun4();
        printf("请选择：");
        scanf("%d", &select);
        system("cls");
        switch (select) {
        case 1: {  //通过先序序列构建二叉树
            printf("---------创建二叉树---------\n");

            if (InitTree(T)) printf("创建成功!\n");
            else printf("创建失败!\n");

            system("pause");
            system("cls");
            break;
        }
        case 2: {  //三种方式遍历二叉树
            printf("---------遍历二叉树---------\n");

            
            if (TreeTraverse(T)) printf("遍历成功!\n");
            else printf("遍历失败!\n");

            system("pause");
            system("cls");
            break;
        }
        case 3: {  //树的长度
            printf("---------计算树的深度---------\n");

            if (printf("树的深度(长度)为 %d \n", TreeDepth(T))) printf("计算成功!\n");
            else printf("计算失败!\n");

            system("pause");
            system("cls");
            break;
        }
        case 4: {  //叶子节点的个数
            printf("---------计算叶子结点个数-------\n");

            int num = 0;
            CountLeaf(T, num);
			if (printf("叶子节点个数num = %d \n", num)) printf("计算成功!\n");
            else printf("计算失败!\n");           

            system("pause");
            system("cls");
            break;
        }
        case 5: {  //显示值为Temp的节点的双亲节点
            printf("---------查找双亲---------\n");

            int Temp;
            printf("请输入您要查询的节点数值Temp:");
            scanf("%d", &Temp);
            TreeParentX(T, Temp);

            system("pause");
            system("cls");
            break;
        }
        case 6: {  //显示值为Temp的节点的双亲节点
            printf("---------查找兄弟---------\n");

            int Temp;
            printf("请输入您要查询的节点数值Temp:");
            scanf("%d", &Temp);
            TreeBrother(T, Temp);

            system("pause");
            system("cls");
            break;
        }
        case 7: {
            printf("---------Huffman编码---------\n");

            printf("未实现\n");
            
            system("pause");
            system("cls");
            break;
        }
        case 8: {
            printf("退出成功!\n");

            system("pause");
            system("cls");
            return OK;
        }
        default:
            printf("您输入有误请重新输入!\n");

            system("pause");
            system("cls");
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
    printf("**************二叉树的基本操作及应用***************\n");
    printf("*  假设每个节点的值均为正整数 值为-1的节点不存在  *\n");
    printf("* 1  创建二叉树                                   *\n");
    printf("* 2  遍历二叉树（先/中/后）                       *\n");
    printf("* 3  计算树的深度                                 *\n");
    printf("* 4  计算叶子结点个数                             *\n");
    printf("* 5  查找双亲                                     *\n");
    printf("* 6  查找兄弟                                     *\n");
    printf("* 7  Huffman编码（应用）    (未实现)              *\n");
    printf("* 8  退出                                         *\n");
    printf("***************************************************\n");
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
