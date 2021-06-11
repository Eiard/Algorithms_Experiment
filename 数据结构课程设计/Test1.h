#pragma once

/*
* 物联11902班 张宜成 201902849
* 该头文件创建于5月28日
*
* Test1.h头文件:
*		包含操作单链表的函数
*		包含手机通讯录的应用
*/

#include "Base.h"

typedef struct LNode {
    ElemType data;
    char name[20];
    struct LNode *next;
} LNode, *LinkList;  //LinkList常代表单链表的头指针  LNode常代表区块
//-----------------------------------------------------
Status ShowMeun1(void);  //菜单
Status Test1(void);  //测试
Status CreateList_LNode(LinkList &L, int n);    //创建链表
Status ListInsertPrior_LNode(LinkList &L, int i, ElemType e);   //前插操作
Status ListDelete_LNode(LinkList &L, int i, ElemType &e);   //删除结点
Status GetElem_LNode(LinkList L, int i, ElemType &e);  //通过下标得到某值
Status ListTraverse_LNode(LinkList &L);  //遍历链表

//手机应用
Status Phone(void);
Status PhoneMeun(void);
Status PhoneCreateList_LNode(LinkList& L, int n);
Status PhoneListInsertPrior_LNode(LinkList& L, int i, ElemType e,char name[20]);
Status PhoneListDelete_LNode(LinkList& L, int i);   //删除结点
Status PhoneGetElem_LNode(LinkList L, char name[20]);
Status PhoneTraverse_LNode(LinkList &L);
//-----------------------------------------------------
Status ShowMeun1(void) {
    printf("**************单链表的基本操作及应用***************\n");
    printf("* 1  创建                                         *\n");
    printf("* 2  插入                                         *\n");
    printf("* 3  删除                                         *\n");
    printf("* 4  查找                                         *\n");
    printf("* 5  显示                                         *\n");
    printf("* 6  通讯录（应用）         (已实现)              *\n");
    printf("* 7  退出                                         *\n");
    printf("***************************************************\n");
    return OK;
}

Status Test1(void) {
    int select;
    LinkList L = nullptr;
	while (TRUE) {
        ShowMeun1();
        printf("请选择：");
        scanf("%d", &select);
        system("cls");
        switch (select) {
            case 1: {
                printf("--------创建单链表---------\n");
                int size = 0;
                printf("请输入你的链表规模size = ");
                scanf("%d", &size);
                printf("该方法以头插法的方式建立-所以构造的链表顺序与输入顺序相反\n");
                printf("请输入你的链表元素\n");

                if (CreateList_LNode(L, size)) printf("创建成功!\n");
                else printf("创建失败!\n");

                system("pause");
                system("cls");
                break;
            }
            case 2: {
                printf("--------插入元素-------\n");
                int place;
                printf("请输入您需要插入元素的位序place = ");
                scanf("%d", &place);
                int Temp;
                printf("请再输入需要插入的值Temp = ");
                scanf("%d", &Temp);

                if (ListInsertPrior_LNode(L, place, Temp)) printf("插入成功!\n");
                else printf("插入失败!\n");

                system("pause");
                system("cls");
                break;
            }
            case 3: {
                printf("--------删除元素-------\n");
                int place;
                printf("请输入您需要删除元素的位序place = ");
                scanf("%d", &place);
                int Temp;

				if (ListDelete_LNode(L, place, Temp)) printf("删除成功!\n");
				else printf("删除失败!\n");
                
                printf("您删除的是第%d个元素,该值为%d\n", place, Temp);
                system("pause");
                system("cls");
                break;
            }
            case 4: {
                printf("--------查找元素-------\n");
                int place;
                printf("请输入您需要查找元素的位序place = ");
                scanf("%d", &place);
                int Temp;
                if (GetElem_LNode(L, place, Temp)) { 
                    printf("查询成功!\n");
                    printf("您第%d个元素值为%d\n", place, Temp);
                }
                else printf("查询失败!\n");

                system("pause");
                system("cls");
                break;
            }
            case 5: {
                printf("--------显示链表-------\n");
                printf("链表遍历结果如下:\n");

                if (ListTraverse_LNode(L)) printf("遍历成功!\n");
                else printf("遍历失败!\n");
                   
                system("pause");
                system("cls");
                break;
            }
            case 6: {
                //printf("--------通讯录---------\n");
                Phone();
                system("pause");
                system("cls");
                break;
            }
            case 7: {
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
    return OK;
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
    int j = 1;  //LNode是下一个区块地址
    while (p && j < i) {  //通过下标定位元素
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

//手机应用部分
Status Phone() {
    int select;
    LinkList L;

    while (TRUE) {
        PhoneMeun();
        printf("请选择：");
        scanf("%d", &select);
        system("cls");
        switch (select) {
        case 1: {
            printf("--------创建通讯录---------\n");
            int size = 0;
            printf("请输入你的通讯录个数size = ");
            scanf("%d", &size);
            printf("请输入你的联系人信息\n");

            if (PhoneCreateList_LNode(L, size)) printf("创建成功!\n");
            else printf("创建失败!\n");

            system("pause");
            system("cls");
            break;
        }
        case 2: {
            printf("--------添加联系人---------\n");
            
            char b[20];
			printf("请输入名字:");
            scanf("%s", b);

            int Temp;
            printf("联系人电话号: ");
            scanf("%d", &Temp);

            if (PhoneListInsertPrior_LNode(L, 1, Temp,b)) printf("添加联系人成功!\n");
            else printf("添加联系人失败!\n");

            system("pause");
            system("cls");
            break;
        }
        case 3: {
            printf("--------删除联系人---------\n");

            int place;
            printf("请输入您要删除联系人的位序:");
            scanf("%d", &place);

			if (PhoneListDelete_LNode(L, place)) printf("删除成功!\n");
            else printf("删除失败!\n");

            system("pause");
            system("cls");
            break;
        }
        case 4: {
            printf("--------查询联系人---------\n");

            char name[20];
            printf("请输入您需要查找的联系人姓名:");
            scanf("%s", name);
            if (PhoneGetElem_LNode(L, name)) printf("查询成功!\n");
            else printf("查询失败!\n");


            system("pause");
            system("cls");
            break;
        }
        case 5: {
            printf("--------显示所有联系人---------\n");
            if (PhoneTraverse_LNode(L)) printf("显示所有联系人成功!\n");
            else printf("显示所有联系人失败!\n");
            system("pause");
            system("cls");
            break;
        }
        case 6: {
            printf("退出成功!\n");
            return OK;
        }
        default:
            printf("您输入有误请重新输入!\n");
            system("pause");
            system("cls");
            break;
        }
    }

    return OK;
}

Status PhoneMeun(void) {
    printf("**********************Phone************************\n");
    printf("* 1  创建通讯录                                   *\n");
    printf("* 2  添加联系人                                   *\n");
    printf("* 3  删除联系人                                   *\n");
    printf("* 4  查找联系人                                   *\n");
    printf("* 5  显示所有联系人                               *\n");
    printf("* 6  退出                                         *\n");
    printf("***************************************************\n");
    return OK;
}

Status PhoneCreateList_LNode(LinkList& L, int n) {
    L = (LinkList)malloc(sizeof(LNode));  //头结点地址(地址)
    if (L == nullptr) return ERROR;
    L->next = nullptr;
    for (int i = n; i > 0; --i) {
        LNode* p = (LNode*)malloc(sizeof(LNode));  //区块地址(指针)
        printf("姓名:");
        scanf("%s", p->name);

        printf("电话号码:");
        scanf("%d", &p->data);

        //插入到表头
        p->next = L->next;
        L->next = p;
    }
    return OK;
}

Status PhoneListInsertPrior_LNode(LinkList& L, int i, ElemType e,char name[20]) {  //头插
    if (i < 1) {
        return ERROR;
    }
    LNode* p = L;  //指针p指向当前扫描到的节点(临时指针)  开头指头结点
    int j = 0;  //当前p指向的是第几个节点
    while (p != NULL && j < i - 1) {  //j<i-1: 先找第i-1个节点是否存在
        p = p->next;
        j++;
    }

    if (p == NULL) {  //如果第i-1个节点 p == NULL 则说明 i-1个节点不存在
        return ERROR;
    }
    //如果第i-1个节点存在 p! = NULL
    LNode* s = (LNode*)malloc(sizeof(LNode));  //创建新区块
    if (s == NULL) {  //内存分配失败
        return ERROR;
    }
    s->data = e;  //填入数据
    strcpy(s->name, name);

    s->next = p->next;  //让此时新区块 指向 p原先的下一个区块地址
    p->next = s;  //让原先的p 指向 新区块
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

	printf("您删除的是第%d个联系人,该名字:%s 电话:%d\n", i, q->name, q->data);

    free(q);
    return OK;
}

Status PhoneGetElem_LNode(LinkList L, char name[20]) {
    LNode* p = L->next;
	while (p && abs(strcmp(name, p->name))) {
        p = p->next;
    }
    if (!p) return ERROR;
	printf("名字:%s 电话:%d\n", p->name, p->data);
    return OK;
}

Status PhoneTraverse_LNode(LinkList& L) {
    if (L->next == nullptr)return ERROR;
    printf("姓名   电话号码\n");
    LinkList P = L->next;
    while (P) {
        printf("%s      %d\n", P->name, P->data);
        P = P->next;
    }
    printf("\n");
    return OK;
}

