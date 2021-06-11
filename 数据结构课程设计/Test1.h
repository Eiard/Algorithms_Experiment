#pragma once

/*
* ����11902�� ���˳� 201902849
* ��ͷ�ļ�������5��28��
*
* Test1.hͷ�ļ�:
*		��������������ĺ���
*		�����ֻ�ͨѶ¼��Ӧ��
*/

#include "Base.h"

typedef struct LNode {
    ElemType data;
    char name[20];
    struct LNode *next;
} LNode, *LinkList;  //LinkList�����������ͷָ��  LNode����������
//-----------------------------------------------------
Status ShowMeun1(void);  //�˵�
Status Test1(void);  //����
Status CreateList_LNode(LinkList &L, int n);    //��������
Status ListInsertPrior_LNode(LinkList &L, int i, ElemType e);   //ǰ�����
Status ListDelete_LNode(LinkList &L, int i, ElemType &e);   //ɾ�����
Status GetElem_LNode(LinkList L, int i, ElemType &e);  //ͨ���±�õ�ĳֵ
Status ListTraverse_LNode(LinkList &L);  //��������

//�ֻ�Ӧ��
Status Phone(void);
Status PhoneMeun(void);
Status PhoneCreateList_LNode(LinkList& L, int n);
Status PhoneListInsertPrior_LNode(LinkList& L, int i, ElemType e,char name[20]);
Status PhoneListDelete_LNode(LinkList& L, int i);   //ɾ�����
Status PhoneGetElem_LNode(LinkList L, char name[20]);
Status PhoneTraverse_LNode(LinkList &L);
//-----------------------------------------------------
Status ShowMeun1(void) {
    printf("**************������Ļ���������Ӧ��***************\n");
    printf("* 1  ����                                         *\n");
    printf("* 2  ����                                         *\n");
    printf("* 3  ɾ��                                         *\n");
    printf("* 4  ����                                         *\n");
    printf("* 5  ��ʾ                                         *\n");
    printf("* 6  ͨѶ¼��Ӧ�ã�         (��ʵ��)              *\n");
    printf("* 7  �˳�                                         *\n");
    printf("***************************************************\n");
    return OK;
}

Status Test1(void) {
    int select;
    LinkList L = nullptr;
	while (TRUE) {
        ShowMeun1();
        printf("��ѡ��");
        scanf("%d", &select);
        system("cls");
        switch (select) {
            case 1: {
                printf("--------����������---------\n");
                int size = 0;
                printf("��������������ģsize = ");
                scanf("%d", &size);
                printf("�÷�����ͷ�巨�ķ�ʽ����-���Թ��������˳��������˳���෴\n");
                printf("�������������Ԫ��\n");

                if (CreateList_LNode(L, size)) printf("�����ɹ�!\n");
                else printf("����ʧ��!\n");

                system("pause");
                system("cls");
                break;
            }
            case 2: {
                printf("--------����Ԫ��-------\n");
                int place;
                printf("����������Ҫ����Ԫ�ص�λ��place = ");
                scanf("%d", &place);
                int Temp;
                printf("����������Ҫ�����ֵTemp = ");
                scanf("%d", &Temp);

                if (ListInsertPrior_LNode(L, place, Temp)) printf("����ɹ�!\n");
                else printf("����ʧ��!\n");

                system("pause");
                system("cls");
                break;
            }
            case 3: {
                printf("--------ɾ��Ԫ��-------\n");
                int place;
                printf("����������Ҫɾ��Ԫ�ص�λ��place = ");
                scanf("%d", &place);
                int Temp;

				if (ListDelete_LNode(L, place, Temp)) printf("ɾ���ɹ�!\n");
				else printf("ɾ��ʧ��!\n");
                
                printf("��ɾ�����ǵ�%d��Ԫ��,��ֵΪ%d\n", place, Temp);
                system("pause");
                system("cls");
                break;
            }
            case 4: {
                printf("--------����Ԫ��-------\n");
                int place;
                printf("����������Ҫ����Ԫ�ص�λ��place = ");
                scanf("%d", &place);
                int Temp;
                if (GetElem_LNode(L, place, Temp)) { 
                    printf("��ѯ�ɹ�!\n");
                    printf("����%d��Ԫ��ֵΪ%d\n", place, Temp);
                }
                else printf("��ѯʧ��!\n");

                system("pause");
                system("cls");
                break;
            }
            case 5: {
                printf("--------��ʾ����-------\n");
                printf("��������������:\n");

                if (ListTraverse_LNode(L)) printf("�����ɹ�!\n");
                else printf("����ʧ��!\n");
                   
                system("pause");
                system("cls");
                break;
            }
            case 6: {
                //printf("--------ͨѶ¼---------\n");
                Phone();
                system("pause");
                system("cls");
                break;
            }
            case 7: {
                printf("�˳��ɹ�!\n");
                system("pause");
                system("cls");
                return OK;
            }
            default:
                printf("��������������������!\n");
                system("pause");
                system("cls");
                break;
        }
    }
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
    return OK;
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
    return OK;
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
    return OK;
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
    return OK;
}

Status ListTraverse_LNode(LinkList &L) {
    if (L == nullptr)return ERROR;
    LinkList P = L->next;
    while (P) {
        printf_s("%d ", P->data);
        P = P->next;
    }
    printf("\n");
    return OK;
}

//�ֻ�Ӧ�ò���
Status Phone() {
    int select;
    LinkList L;

    while (TRUE) {
        PhoneMeun();
        printf("��ѡ��");
        scanf("%d", &select);
        system("cls");
        switch (select) {
        case 1: {
            printf("--------����ͨѶ¼---------\n");
            int size = 0;
            printf("���������ͨѶ¼����size = ");
            scanf("%d", &size);
            printf("�����������ϵ����Ϣ\n");

            if (PhoneCreateList_LNode(L, size)) printf("�����ɹ�!\n");
            else printf("����ʧ��!\n");

            system("pause");
            system("cls");
            break;
        }
        case 2: {
            printf("--------�����ϵ��---------\n");
            
            char b[20];
			printf("����������:");
            scanf("%s", b);

            int Temp;
            printf("��ϵ�˵绰��: ");
            scanf("%d", &Temp);

            if (PhoneListInsertPrior_LNode(L, 1, Temp,b)) printf("�����ϵ�˳ɹ�!\n");
            else printf("�����ϵ��ʧ��!\n");

            system("pause");
            system("cls");
            break;
        }
        case 3: {
            printf("--------ɾ����ϵ��---------\n");

            int place;
            printf("��������Ҫɾ����ϵ�˵�λ��:");
            scanf("%d", &place);

			if (PhoneListDelete_LNode(L, place)) printf("ɾ���ɹ�!\n");
            else printf("ɾ��ʧ��!\n");

            system("pause");
            system("cls");
            break;
        }
        case 4: {
            printf("--------��ѯ��ϵ��---------\n");

            char name[20];
            printf("����������Ҫ���ҵ���ϵ������:");
            scanf("%s", name);
            if (PhoneGetElem_LNode(L, name)) printf("��ѯ�ɹ�!\n");
            else printf("��ѯʧ��!\n");


            system("pause");
            system("cls");
            break;
        }
        case 5: {
            printf("--------��ʾ������ϵ��---------\n");
            if (PhoneTraverse_LNode(L)) printf("��ʾ������ϵ�˳ɹ�!\n");
            else printf("��ʾ������ϵ��ʧ��!\n");
            system("pause");
            system("cls");
            break;
        }
        case 6: {
            printf("�˳��ɹ�!\n");
            return OK;
        }
        default:
            printf("��������������������!\n");
            system("pause");
            system("cls");
            break;
        }
    }

    return OK;
}

Status PhoneMeun(void) {
    printf("**********************Phone************************\n");
    printf("* 1  ����ͨѶ¼                                   *\n");
    printf("* 2  �����ϵ��                                   *\n");
    printf("* 3  ɾ����ϵ��                                   *\n");
    printf("* 4  ������ϵ��                                   *\n");
    printf("* 5  ��ʾ������ϵ��                               *\n");
    printf("* 6  �˳�                                         *\n");
    printf("***************************************************\n");
    return OK;
}

Status PhoneCreateList_LNode(LinkList& L, int n) {
    L = (LinkList)malloc(sizeof(LNode));  //ͷ����ַ(��ַ)
    if (L == nullptr) return ERROR;
    L->next = nullptr;
    for (int i = n; i > 0; --i) {
        LNode* p = (LNode*)malloc(sizeof(LNode));  //�����ַ(ָ��)
        printf("����:");
        scanf("%s", p->name);

        printf("�绰����:");
        scanf("%d", &p->data);

        //���뵽��ͷ
        p->next = L->next;
        L->next = p;
    }
    return OK;
}

Status PhoneListInsertPrior_LNode(LinkList& L, int i, ElemType e,char name[20]) {  //ͷ��
    if (i < 1) {
        return ERROR;
    }
    LNode* p = L;  //ָ��pָ��ǰɨ�赽�Ľڵ�(��ʱָ��)  ��ͷָͷ���
    int j = 0;  //��ǰpָ����ǵڼ����ڵ�
    while (p != NULL && j < i - 1) {  //j<i-1: ���ҵ�i-1���ڵ��Ƿ����
        p = p->next;
        j++;
    }

    if (p == NULL) {  //�����i-1���ڵ� p == NULL ��˵�� i-1���ڵ㲻����
        return ERROR;
    }
    //�����i-1���ڵ���� p! = NULL
    LNode* s = (LNode*)malloc(sizeof(LNode));  //����������
    if (s == NULL) {  //�ڴ����ʧ��
        return ERROR;
    }
    s->data = e;  //��������
    strcpy(s->name, name);

    s->next = p->next;  //�ô�ʱ������ ָ�� pԭ�ȵ���һ�������ַ
    p->next = s;  //��ԭ�ȵ�p ָ�� ������
    return OK;
}

Status PhoneListDelete_LNode(LinkList& L, int i) {
    LNode* p = L;
    int j = 0;
    while (p->next && j < i - 1) {
        p = p->next;
        ++j;
    }
    if (!(p->next) || j > i - 1) return ERROR;
    LNode* q = p->next;
    p->next = q->next;

	printf("��ɾ�����ǵ�%d����ϵ��,������:%s �绰:%d\n", i, q->name, q->data);

    free(q);
    return OK;
}

Status PhoneGetElem_LNode(LinkList L, char name[20]) {
    LNode* p = L->next;
	while (p && abs(strcmp(name, p->name))) {
        p = p->next;
    }
    if (!p) return ERROR;
	printf("����:%s �绰:%d\n", p->name, p->data);
    return OK;
}

Status PhoneTraverse_LNode(LinkList& L) {
    if (L->next == nullptr)return ERROR;
    printf("����   �绰����\n");
    LinkList P = L->next;
    while (P) {
        printf("%s      %d\n", P->name, P->data);
        P = P->next;
    }
    printf("\n");
    return OK;
}

