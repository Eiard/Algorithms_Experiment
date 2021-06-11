//
// Created by 30671 on 2021/3/21.
//

#ifndef ALGORITHMS_EXPERIMENT_TEST1_H
#define ALGORITHMS_EXPERIMENT_TEST1_H

#include "Base.h"

typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;  //LinkList�����������ͷָ��  LNode����������

Status ShowMeun1(void);  //�˵�
Status Test1(void);  //����
Status CreateList_LNode(LinkList &L, int n);    //��������
Status ListInsertPrior_LNode(LinkList &L, int i, ElemType e);   //ǰ�����
Status ListDelete_LNode(LinkList &L, int i, ElemType &e);   //ɾ�����
Status GetElem_LNode(LinkList L, int i, ElemType &e);  //ͨ���±�õ�ĳֵ
Status ListTraverse_LNode(LinkList &L);  //��������
Status DeleteMin_LNode(LinkList &L, ElemType x);
int MaxXLength(LinkList L, int x);  //��x���Ԫ�ظ���  �ظ�ֻ��һ��

    Status ShowMeun1(void) {
    printf("1.��ʼ������,�������Ԫ��(ͨ����������)\n");
    printf("2.�������(��λ��)\n");
    printf("3.ɾ������(��λ��)\n");
    printf("4.���Ҳ���(��λ��)\n");
    printf("5.��������\n");
    printf("0.�˳�\n");
    return TRUE;
}

Status Test1(void) {
    int select;
    LinkList L;
    ShowMeun1();
    while (TRUE) {
        printf("�������-----> ");
        scanf("%d", &select);
        switch (select) {
            case 1: {
                int size = 0;
                printf("��������������ģsize = ");
                scanf("%d", &size);
                printf("�������������Ԫ��\n");
                CreateList_LNode(L, size);
                break;
            }
            case 2: {
                int place;
                printf("����������Ҫ����Ԫ�ص�λ��place = ");
                scanf("%d", &place);
                int Temp;
                printf("����������Ҫ�����ֵTemp = ");
                scanf("%d", &Temp);
                ListInsertPrior_LNode(L, place, Temp);
                break;
            }
            case 3: {
                int place;
                printf("����������Ҫɾ��Ԫ�ص�λ��place = ");
                scanf("%d", &place);
                int Temp;
                ListDelete_LNode(L, place, Temp);
                printf("��ɾ�����ǵ�%d��Ԫ��,��ֵΪ%d\n", place, Temp);
                break;
            }
            case 4: {
                int place;
                printf("����������Ҫ����Ԫ�ص�λ��place = ");
                scanf("%d", &place);
                int Temp;
                GetElem_LNode(L, place, Temp);
                printf("����%d��Ԫ��ֵΪ%d\n", place, Temp);
                break;
            }
            case 5: {
                ListTraverse_LNode(L);
                break;
            }
            case 6: {
                int temp;
                printf("ɾ�� ֵС��x����ʹż��(�����Ѿ�����������ĵ��������)�Ľ�� x = ");
                scanf("%d", &temp);
                DeleteMin_LNode(L, temp);
                break;
            }
            case 7: {
                int temp;
                printf("����x�����ĸ���(�ظ�������һ��) x = ");
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
    L = (LinkList) malloc(sizeof(LNode));  //ͷ����ַ(��ַ)
    if (L == nullptr) return ERROR;
    L->next = nullptr;
    for (int i = n; i > 0; --i) {
        LNode *p = (LNode *) malloc(sizeof(LNode));  //�����ַ(ָ��)
        scanf("%d", &p->data);
        //���뵽��ͷ
        p->next = L->next;
        L->next = p;
    }
    return TRUE;
}

Status ListInsertPrior_LNode(LinkList &L, int i, ElemType e) {  //ͷ��
    if (i < 1) {
        return ERROR;
    }
    LNode *p = L;  //ָ��pָ��ǰɨ�赽�Ľڵ�(��ʱָ��)  ��ͷָͷ���
    int j = 0;  //��ǰpָ����ǵڼ����ڵ�
    while (p != NULL && j < i - 1) {  //j<i-1: ���ҵ�i-1���ڵ��Ƿ����
        p = p->next;
        j++;
    }

    if (p == NULL) {  //�����i-1���ڵ� p == NULL ��˵�� i-1���ڵ㲻����
        return ERROR;
    }
    //�����i-1���ڵ���� p! = NULL
    LNode *s = (LNode *) malloc(sizeof(LNode));  //����������
    if (s == NULL) {  //�ڴ����ʧ��
        return ERROR;
    }
    s->data = e;  //��������
    s->next = p->next;  //�ô�ʱ������ ָ�� pԭ�ȵ���һ�������ַ
    p->next = s;  //��ԭ�ȵ�p ָ�� ������
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
    int j = 1;  //LNode����һ�������ַ
    while (p && j < i) {  //ͨ���±궨λԪ��
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

Status DeleteMin_LNode(LinkList &L, ElemType x) {  //�����Ѱ���������ĵ�����
    LNode *p = L;
    LNode *q = p->next;
    while (q) {
        if (q->data < x && (q->data % 2 == 0)) { //ż������С��x
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

int MaxXLength(LinkList L, int x) {  //��x���Ԫ�ظ���  �ظ�ֻ��һ��
    LNode *p = L->next;  //�ӵ�һ����ЧԪ�ؿ�ʼ����
    int length = 0;
    int rear = 0xc0c0c0c0;  //������
    while (p) {
        if (p->data > x) {
            if (p->data != rear) {  //����һ�������
                rear = p->data;
                length++;
            }
        }
        p = p->next;
    }
    return length;
}

#endif //ALGORITHMS_EXPERIMENT_TEST1_H
