#pragma once

/*
* 物联11902班 张宜成 201902849
* 该头文件创建于5月28日
*
* Test2.h头文件:
*		包含操作栈的函数
*		包含表达式求解的应用
*/

#include "Base.h"

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

//7种运算符
char OP[7] = {'+', '-', '*', '/', '(', ')', '#'};
//优先级
char r[7][7] = {
        //+    -    *    /    (    )    #
        '>', '>', '<', '<', '<', '>', '>',

        '>', '>', '<', '<', '<', '>', '>',

        '>', '>', '>', '>', '<', '>', '>',

        '>', '>', '>', '>', '<', '>', '>',

        '<', '<', '<', '<', '<', '=', 0,

        '>', '>', '>', '>', 0, '>', '>',

        '<', '<', '<', '<', '<', 0, '=',
};

typedef struct {
    int *top;//栈顶指针
    int *base;
    int stacksize;//当前已分配的内存空间，以元素为单位
} SqStack;
//-----------------------------------------------------
Status ShowMeun2(void);
Status Test2(void);  //测试
Status InitStack(SqStack &S);  //初始化一个空栈
Status StackEmpty(SqStack S);  //栈是否为空
Status GetTop(SqStack S, int &e);  //返回栈顶元素
Status Push(SqStack &S, int e);  //压栈
Status Pop(SqStack &S, int &e);  //出栈
Status EvaluateExpression(void);  //计算器模拟
Status In(char c);  //是不是+ - * / ( ) # 中的一个运算符
char Precede(int, int);  //利用下标来找优先级的表
int Operrate(int a, char theta, int b);  //加减乘除
int GetTop(SqStack S);  //用于计算器模拟
//-----------------------------------------------------
Status ShowMeun2(void) {
    printf("****************栈的基本操作及应用*****************\n");
    printf("* 1  进栈                                         *\n");
    printf("* 2  出栈                                         *\n");
    printf("* 3  取栈顶元素                                   *\n");
    printf("* 4  表达式求解（应用）        (已实现)           *\n");
    printf("* 5  退出                                         *\n");
    printf("***************************************************\n");
    return TRUE;
}

Status Test2(void) {
    int select;
    SqStack S;
    InitStack(S);  //初始化空栈

    while (TRUE) {
        ShowMeun2();
        printf("请选择：");
        scanf("%d", &select);
        system("cls");
        switch (select) {
            case 1: {
                printf("--------进栈-------\n");
                int place;
                printf("请输入您想进栈的值\n");
                scanf("%d", &place);
				
                if (Push(S, place)) printf("进栈成功!\n");
                else printf("进栈失败!\n");

                system("pause");
                system("cls");
                break;
            }
            case 2: {
                printf("--------出栈-------\n");
                int place;
                
                if (Pop(S, place)) printf("出栈元素为%d\n", place);
                else printf("出栈失败!\n");
                
                system("pause");
                system("cls");
                break;
            }
            case 3: {
                printf("--------取栈顶元素-------\n");
                int place;

                if (Pop(S, place)) printf("栈顶元素为%d\n", place);
                else printf("无法找到栈顶元素\n");
                
                system("pause");
                system("cls");
                break;
            }
            case 4: {
                printf("--------表达式求值-------\n");

                if (EvaluateExpression()) printf("表达式求值成功!\n");
                else printf("表达式求值失败!\n");

                system("pause");
                system("cls");
                break;
            }
            case 5: {
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

Status InitStack(SqStack &S) {
    S.base = (int *) malloc(STACK_INIT_SIZE * sizeof(int));
    if (!S.base)exit(OVERFLOW);// 内存分配失败
    S.top = nullptr;
    S.top = S.base;
    S.stacksize = STACK_INIT_SIZE;
    return OK;
}

Status StackEmpty(SqStack S) {
    //判断栈顶与栈底是否相等
    if (S.top == S.base)
        return OK;
    else
        return ERROR;
}

Status GetTop(SqStack S, int &e) {
    //若栈不空，则用e返回s的栈顶元素，并返回OK，否则返回ERROR
    if (S.top == S.base)return ERROR;
    e = *(S.top - 1);//输出下一个数
    return OK;
}

Status Push(SqStack &S, int e) {
    //插入元素e
    //当栈满
    if (S.top - S.base >= S.stacksize) {
        //追加栈容量
        S.base = (int *) realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(int));
        if (!S.base)return ERROR;//存储分配失败
        S.top = S.base + S.stacksize;
        S.stacksize += STACKINCREMENT;
    }
    //当栈没满
    *S.top++ = e;
    return OK;
}

Status Pop(SqStack &S, int &e) {
    //若栈不空，则删除S的栈顶元素，用e返回其值，并返回Ok，否则返回ERROR
    if (S.top == S.base)return ERROR;
    e = *--S.top;
    return OK;
}

Status EvaluateExpression(void) {
    //OPTR栈存储运算符  OPND栈存储运算数
    SqStack OPTR, OPND;
    InitStack(OPTR);
    ElemType e;
    Push(OPTR, '#');
    InitStack(OPND);
    //清空输入缓存

    char c = getchar();
    while (c != '#' || GetTop(OPTR) != '#') {
        if (In(c) == -1) {  //c如果不是字符(c是数字)
            //ASCII码种1就是49
            Push(OPND, c - '0');
            c = getchar();
        } else {
            //利用引用提取数值
            //GetTop(OPTR, e);

            //利用返回值提取数值
            e = GetTop(OPTR);
            switch (Precede(In(e), In(c))) {
                case '<':
                    Push(OPTR, c);
                    c = getchar();
                    break;
                case '=':  //脱括号
                    int x;
                    Pop(OPTR, x);
                    c = getchar();
                    break;
                case '>':
                    int theta;
                    int b, a;  //把前一个优先级高的运算符先拿出来计算
                    Pop(OPTR, theta);
                    Pop(OPND, b);
                    Pop(OPND, a);
                    Push(OPND, Operrate(a, theta, b));
                    break;
            }
        }
    }
    //利用引用提取数值
    //GetTop(OPND, e);
    //printf("计算结果为 %d\n", e);

    //利用返回值提取数值
    printf("计算结果为 %d\n",GetTop(OPND));
    return OK;
}

//返回下标
//+ - * / ( ) #
//0 1 2 3 4 5 6
int In(char c) {
    int i = 0;
    while (OP[i] != c && (i < 7)) {
        i++;
    }
    if (i == 7) {  //未找到
        return -1;
    } else {  //找到了
        return i;
    }
}

//利用下标来找
char Precede(int p, int c) {
    return r[p][c];
}

int Operrate(int a, char theta, int b) {
    float r;
    switch (In(theta)) {
        case 0: {    //加法运算
            r = a + b;
            break;
        }
        case 1: {    //减法运算
            r = a - b;
            break;
        }
        case 2: {    //乘法运算
            r = a * b;
            break;
        }
        case 3: {    //除法运算
            r = a / b;
            break;
        }
    }
    return r;
}

int GetTop(SqStack S) {
    //若栈不空，则用e返回s的栈顶元素，并返回OK，否则返回ERROR
    if (S.top == S.base)return (OVERFLOW);
    return *(S.top - 1);
}