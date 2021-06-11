#pragma once
#include "Base.h"
#include<iostream>
typedef int TElemType;

//��ʽ������
typedef struct BiTNode
{
    TElemType data;
    struct BiTNode* lchild, * rchild;  //���Һ���
}BiTNode, * BiTree;

Status Test4(void);
Status InitTree(BiTree& root);  //��ʽ�������ĳ�ʼ��(ͨ��������������˳���ʼ��)
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
        printf("�������----->");
        scanf("%d", &select);
        switch (select) {
        case 1: {  //ͨ���������й���������
            InitTree(T);
            break;
        }
        case 2: {  //���ַ�ʽ����������
            TreeTraverse(T);
            break;
        }
        case 3: {  //���ĳ���
            printf("�������(����)Ϊ %d \n", TreeDepth(T));
            break;
        }
        case 4: {  //Ҷ�ӽڵ�ĸ���
            int num = 0;
            CountLeaf(T, num);
            printf("Ҷ�ӽڵ����num = %d \n", num);
            break;
        }
        case 5: {  //��ʾֵΪTemp�Ľڵ�����Һ���
            int Temp;
            printf("��������Ҫ��ѯ�Ľڵ���ֵTemp:");
            scanf("%d", &Temp);
            TreeChildX(T, Temp);
            break;
		}
        case 6: {  //��ʾֵΪTemp�Ľڵ��˫�׽ڵ�
            int Temp;
            printf("��������Ҫ��ѯ�Ľڵ���ֵTemp:");
            scanf("%d", &Temp);
            TreeParentX(T, Temp);
            break;
        }
        case 7: {  //��ʾֵΪTemp�Ľڵ��˫�׽ڵ�
            int Temp;
            printf("��������Ҫ��ѯ�Ľڵ���ֵTemp:");
            scanf("%d", &Temp);
            TreeBrother(T, Temp);
            break;
        }
        //�˳�
        case 0: {
            exit(-1);
        }
        default:
            break;
        }
    }
	return TRUE;
}
Status InitTree(BiTree& root){   //����������
    //����ÿ���ڵ��ֵ��Ϊ������
    //ÿ���ڵ��ֵ
    int temp;
    scanf("%d", &temp);
    
    if (temp == -1) {  //�����   -1�ýڵ㲻����
        root = NULL;
    }  //�ýڵ����
    else {
        root = (BiTNode*)malloc(sizeof(BiTNode));  //�����ýڵ�
        root->data = temp;  //����ֵ������ڵ�

        //�ݹ�
        //������
        InitTree(root->lchild);
        //������
        InitTree(root->rchild);
    }
    return TRUE;
}
Status ShowMeun4(void) {
    printf("����ÿ���ڵ��ֵ��Ϊ������ ֵΪ-1�Ľڵ㲻����\n");
    printf("1.�����û��������չ������������д����������Ķ�������洢�ṹ\n");
    printf("2.��д����������������������������������㷨\n");
    printf("3.��д��������������߶�\n");
    printf("4.��д���������������Ҷ�ӽڵ�ĸ�����\n");
    printf("5.дһ������LeftChild(T,e)��RightChild(T,e)��ʵ���������T��ĳ����Ҷ�ӽ��e�����ӻ��Һ��ӣ���e�����ӻ��Һ����򷵻ؿ�\n");
    printf("6.дһ������Parent(T,e)��ʵ���������T��ĳ���Ǹ����e��˫�ף���e��˫�ף��򷵻ؿ� \n");
    printf("7.дһ������LeftSibling(T,e)��RightSibling(T,e)��ʵ���������T��ĳ�����e�����ֵܻ����ֵ� \n");
    printf("0.�˳�\n");
    return TRUE;
}
Status PreOrderTraverse(BiTree& root) {
    if (root) {  //�����Ƿ����
        //��
        printf("%d ", root->data);
        //��
        if (root->lchild) PreOrderTraverse(root->lchild);
        //��
        if (root->rchild) PreOrderTraverse(root->rchild);
    }
    return OK;
}
Status InOrderTraverse(BiTree& root) {
    if (root) {  //�����Ƿ����
        //��
        if (root->lchild) InOrderTraverse(root->lchild);
        //��
        printf("%d ", root->data);
        //��
		if (root->rchild) InOrderTraverse(root->rchild);
    }
    return OK;
}
Status BehOrderTraverse(BiTree& root) {
    if (root) {  //�����Ƿ����
        //��
        if (root->lchild) BehOrderTraverse(root->lchild);
        //��
        if (root->rchild) BehOrderTraverse(root->rchild);
        //��
        printf("%d ", root->data);
    }
    return OK;
}
Status TreeTraverse(BiTree& root) {
    printf("��������:");
    PreOrderTraverse(root);
    printf("\n");

    printf("��������:");
    InOrderTraverse(root);
    printf("\n");
    
    printf("��������:");
    BehOrderTraverse(root);
    printf("\n");

    return TRUE;
}
int TreeDepth(BiTree T) {
    int depth;
    if (!T)  //��������
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
        //���û�����Һ���(Ҷ�ӽڵ�)
        if (!T->lchild && !T->rchild) num++;
        CountLeaf(T->lchild, num);
        CountLeaf(T->rchild, num);
    }
}
void TreeChildX(BiTree T, TElemType e){
    if (T){
        if (T->data == e) {
            if (!T->lchild) std::cout << e << "������" << std::endl;
            if (T->lchild) std::cout << e << "������Ϊ" << T->lchild->data << std::endl;
            if (!T->rchild) std::cout << e << "���Һ���" << std::endl;
            if (T->rchild) std::cout << e << "���Һ���Ϊ" << T->rchild->data << std::endl;
            return;
        }
        TreeChildX(T->lchild, e);
        TreeChildX(T->rchild, e);
    }
}
void TreeParentX(BiTree T, TElemType x) {
    if (T){
        //����������ӻ��Һ���ֵ����Temp
        if ((T->lchild && T->lchild->data == x) ||
            (T->rchild && T->rchild->data == x)){
            std::cout << x << "��˫��Ϊ" << T->data << std::endl; return;
        }
        TreeParentX(T->lchild, x);
        TreeParentX(T->rchild, x);
    }
}
void TreeBrother(BiTree T, TElemType x) {
    if (T) {
        //����������ӻ��Һ���ֵ����Temp
		if (T->lchild && x == T->lchild->data) {
            if (T->rchild) {
                std::cout << x << "���ֵ�Ϊ" << T->rchild->data << std::endl; return;
            }
        }
        if (T->rchild && x == T->rchild->data) {
            if (T->lchild) {
                std::cout << x << "���ֵ�Ϊ" << T->lchild->data << std::endl; return;
            }
        }
        TreeBrother(T->lchild, x);
        TreeBrother(T->rchild, x);
    }
}
