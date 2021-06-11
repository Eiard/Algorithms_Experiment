//
// Created by 30671 on 2021/3/21.
//

#ifndef ALGORITHMS_EXPERIMENT_TEST1_H
#define ALGORITHMS_EXPERIMENT_TEST1_H

#include "Base.h"

typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;  //LinkList常代表单链表的头指针  LNode常代表区块

Status ShowMeun1(void);  //菜单
Status Test1(void);  //测试
Status CreateList_LNode(LinkList &L, int n);    //创建链表
Status ListInsertPrior_LNode(LinkList &L, int i, ElemType e);   //前插操作
Status ListDelete_LNode(LinkList &L, int i, ElemType &e);   //删除结点
Status GetElem_LNode(LinkList L, int i, ElemType &e);  //通过下标得到某值
Status ListTraverse_LNode(LinkList &L);  //遍历链表
Status DeleteMin_LNode(LinkList &L, ElemType x);
int MaxXLength(LinkList L, int x);  //比x大的元素个数  重复只算一次

    Status ShowMeun1(void) {
    printf("1.初始化链表,并且添加元素(通过逆序载入)\n");
    printf("2.插入操作(按位序)\n");
    printf("3.删除操作(按位序)\n");
    printf("4.查找操作(按位序)\n");
    printf("5.遍历操作\n");
    printf("0.退出\n");
    return TRUE;
}

Status Test1(void) {
    int select;
    LinkList L;
    ShowMeun1();
    while (TRUE) {
        printf("操作序号-----> ");
        scanf("%d", &select);
        switch (select) {
            case 1: {
                int size = 0;
                printf("请输入你的链表规模size = ");
                scanf("%d", &size);
                printf("请输入你的链表元素\n");
                CreateList_LNode(L, size);
                break;
            }
            case 2: {
                int place;
                printf("请输入您需要插入元素的位序place = ");
                scanf("%d", &place);
                int Temp;
                printf("请再输入需要插入的值Temp = ");
                scanf("%d", &Temp);
                ListInsertPrior_LNode(L, place, Temp);
                break;
            }
            case 3: {
                int place;
                printf("请输入您需要删除元素的位序place = ");
                scanf("%d", &place);
                int Temp;
                ListDelete_LNode(L, place, Temp);
                printf("您删除的是第%d个元素,该值为%d\n", place, Temp);
                break;
            }
            case 4: {
                int place;
                printf("请输入您需要查找元素的位序place = ");
                scanf("%d", &place);
                int Temp;
                GetElem_LNode(L, place, Temp);
                printf("您第%d个元素值为%d\n", place, Temp);
                break;
            }
            case 5: {
                ListTraverse_LNode(L);
                break;
            }
            case 6: {
                int temp;
                printf("删除 值小于x并且使偶数(对于已经是升序排序的单链表而言)的结点 x = ");
                scanf("%d", &temp);
                DeleteMin_LNode(L, temp);
                break;
            }
            case 7: {
                int temp;
                printf("大于x的数的个数(重复仅计算一次) x = ");
                scanf("%d", &temp);
                printf("%d\n",MaxXLength(L,temp));
                break;
            }
            case 0: {
                exit(-1);
            }
            default:
                break;
        }
    }
    return TRUE;
}

Status CreateList_LNode(LinkList &L, int n) {
    L = (LinkList) malloc(sizeof(LNode));  //头结点地址(地址)
    if (L == nullptr) return ERROR;
    L->next = nullptr;
    for (int i = n; i > 0; --i) {
        LNode *p = (LNode *) malloc(sizeof(LNode));  //区块地址(指针)
        scanf("%d", &p->data);
        //插入到表头
        p->next = L->next;
        L->next = p;
    }
    return TRUE;
}

Status ListInsertPrior_LNode(LinkList &L, int i, ElemType e) {  //头插
    if (i < 1) {
        return ERROR;
    }
    LNode *p = L;  //指针p指向当前扫描到的节点(临时指针)  开头指头结点
    int j = 0;  //当前p指向的是第几个节点
    while (p != NULL && j < i - 1) {  //j<i-1: 先找第i-1个节点是否存在
        p = p->next;
        j++;
    }

    if (p == NULL) {  //如果第i-1个节点 p == NULL 则说明 i-1个节点不存在
        return ERROR;
    }
    //如果第i-1个节点存在 p! = NULL
    LNode *s = (LNode *) malloc(sizeof(LNode));  //创建新区块
    if (s == NULL) {  //内存分配失败
        return ERROR;
    }
    s->data = e;  //填入数据
    s->next = p->next;  //让此时新区块 指向 p原先的下一个区块地址
    p->next = s;  //让原先的p 指向 新区块
    return TRUE;
}

Status ListDelete_LNode(LinkList &L, int i, ElemType &e) {
    LNode *p = L;
    int j = 0;
    while (p->next && j < i - 1) {
        p = p->next;
        ++j;
    }
    if (!(p->next) || j > i - 1) return ERROR;
    LNode *q = p->next;
    p->next = q->next;
    e = q->data;
    free(q);
    return TRUE;
}

Status GetElem_LNode(LinkList L, int i, ElemType &e) {
    LNode *p = L->next;
    int j = 1;  //LNode是下一个区块地址
    while (p && j < i) {  //通过下标定位元素
        p = p->next;
        j++;
    }
    if (!p || j > i) return ERROR;
    e = p->data;
    return TRUE;
}

Status ListTraverse_LNode(LinkList &L) {
    if (L == nullptr)return ERROR;
    LinkList P = L->next;
    while (P) {
        printf_s("%d ", P->data);
        P = P->next;
    }
    printf("\n");
    return TRUE;
}

Status DeleteMin_LNode(LinkList &L, ElemType x) {  //对于已按升序排序的单链表
    LNode *p = L;
    LNode *q = p->next;
    while (q) {
        if (q->data < x && (q->data % 2 == 0)) { //偶数并且小于x
            p->next = q->next;
            free(q);
            q = p->next;
        } else {
            p = p->next;
            q = p->next;
        }
    }
    return TRUE;
}

int MaxXLength(LinkList L, int x) {  //比x大的元素个数  重复只算一次
    LNode *p = L->next;  //从第一个有效元素开始计算
    int length = 0;
    int rear = 0xc0c0c0c0;  //负无穷
    while (p) {
        if (p->data > x) {
            if (p->data != rear) {  //与上一个不相等
                rear = p->data;
                length++;
            }
        }
        p = p->next;
    }
    return length;
}

#endif //ALGORITHMS_EXPERIMENT_TEST1_H
