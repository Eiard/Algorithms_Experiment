//
// Created by 30671 on 2021/3/19.
//

#ifndef TEST2_STACK_H
#define TEST2_STACK_H


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

Status ShowMeun2(void);

Status Test2(void);  //测试
Status InitStack(SqStack &S);  //构造一个空栈
Status StackEmpty(SqStack S);  //栈是否为空
Status GetTop(SqStack S, int &e);  //返回栈顶元素(书上写法)
Status Push(SqStack &S, int e);  //压栈
Status Pop(SqStack &S, int &e);  //出栈
Status Traverse(SqStack S);  //遍历栈
Status BrackerMatch(void);  //括号匹配
Status Transform(void);  //进制转换
Status EvaluateExpression(void);  //计算器模拟
Status In(char c);  //是不是+ - * / ( ) # 中的一个运算符
char Precede(int, int);  //利用下标来找优先级的表
int Operrate(int a, char theta, int b);  //加减乘除
int GetTop(SqStack S);  //用于计算器模拟

Status ShowMeun2(void) {
    printf("1.构造空栈\n");
    printf("2.入栈\n");
    printf("3.出栈\n");
    printf("4.取栈顶元素\n");
    printf("5.遍历栈元素\n");
    printf("6.输入一段字符串包含[]()是否匹配\n");
    printf("7.进制数转化\n");
    printf("8.计算器模拟\n");
    printf("0.退出\n");
    return TRUE;
}

Status Test2(void) {
    int select;
    SqStack S;
    ShowMeun2();
    while (TRUE) {
        printf("操作序号----->");
        scanf("%d", &select);
        switch (select) {
            //构造栈
            case 1: {
                if (InitStack(S)) {
                    printf("构造成功!\n");
                } else {
                    printf("构造失败\n");
                }
                break;
            }
                //压栈
            case 2: {
                int place;
                printf("请输入您想入栈的值\n");
                scanf("%d", &place);
                if (Push(S, place)) {
                    printf("压栈成功!\n");
                } else {
                    printf("压栈失败!\n");
                }
                break;
            }
                //出栈
            case 3: {
                int place;
                if (Pop(S, place)) {
                    printf("出栈元素为%d\n", place);
                }
                break;
            }
                //提取栈顶的值
            case 4: {
                int place;
                if (Pop(S, place)) {
                    printf("栈顶元素为%d\n", place);
                } else {
                    ("无法找到栈顶元素printf");
                }
                break;
            }
                //遍历栈
            case 5: {
                if (Traverse(S)) {
                    printf("遍历成功!\n");
                } else {
                    printf("遍历失败!\n");
                }
                break;
            }
                //输入一段字符串包含[]()是否匹配
            case 6: {
                BrackerMatch();
                break;
            }
                //进制数转化
            case 7: {
                Transform();
                break;
            }
                //计算器模拟
            case 8: {
                EvaluateExpression();
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
    if (S.top == S.base)return (OVERFLOW);
    e = *(S.top - 1);//输出下一个数
    return OK;
}

Status Push(SqStack &S, int e) {
    //插入元素e
    //当栈满
    if (S.top - S.base >= S.stacksize) {
        //追加栈容量
        S.base = (int *) realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(int));
        if (!S.base)exit(OVERFLOW);//存储分配失败
        S.top = S.base + S.stacksize;
        S.stacksize += STACKINCREMENT;
    }
    //当栈没满
    *S.top++ = e;
    return OK;
}

Status Pop(SqStack &S, int &e) {
    //若栈不空，则删除S的栈顶元素，用e返回其值，并返回Ok，否则返回ERROR
    if (S.top == S.base)exit(OVERFLOW);
    e = *--S.top;
    return OK;
}

Status Traverse(SqStack S) {
    if (StackEmpty(S)) {
        return FALSE;
    }
    int *Temp = S.top - 1;
    while (Temp != (S.base - 1)) {
        printf(" %d", *Temp);
        Temp--;
    }
    printf("\n");
    return TRUE;
}

Status BrackerMatch(void) {
    SqStack S;
    InitStack(S);
    char c[30];
    scanf("%s", c);
    int i = 0;
    while ((c[i] != '\0')) {
        if ((c[i] == '[' || c[i] == '(')) {
            Push(S, c[i]);
            i++;
        } else if (c[i] == ']' || c[i] == ')') {
            int e;
            if (!StackEmpty(S)) {
                Pop(S, e);
                if ((c[i] == ']' && e == '[') || (c[i] == ')' && e == '(')) {
                    i++;
                } else {
                    printf("不匹配!\n");
                    return TRUE;
                }
            } else {
                printf("不匹配!\n");
                return FALSE;
            }
        }
    }
    if (StackEmpty(S)) {
        printf("匹配\n");
        return TRUE;
    } else {
        printf("不匹配!\n");
        return FALSE;
    }
}

Status Transform(void) {
    SqStack S;
    InitStack(S);
    int size;
    printf("您需要转化为多少进制的数 =");
    scanf("%d", &size);
    int Num;
    printf("请输入您需要转换的数 =");
    scanf("%d", &Num);
    while (Num) {
        Push(S, Num % size);  //取余
        Num = Num / size;
    }
	int e;
    while (!StackEmpty(S)) {
        Pop(S, e);
        printf("%d ", e);
    }
    printf("\n");
    return TRUE;
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
    return TRUE;
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

#endif //TEST2_STACK_H
