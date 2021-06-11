//
// Created by 30671 on 2021/3/19.
//

#ifndef TEST2_STACK_H
#define TEST2_STACK_H


#include "Base.h"

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

//7�������
char OP[7] = {'+', '-', '*', '/', '(', ')', '#'};
//���ȼ�
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
    int *top;//ջ��ָ��
    int *base;
    int stacksize;//��ǰ�ѷ�����ڴ�ռ䣬��Ԫ��Ϊ��λ
} SqStack;

Status ShowMeun2(void);

Status Test2(void);  //����
Status InitStack(SqStack &S);  //����һ����ջ
Status StackEmpty(SqStack S);  //ջ�Ƿ�Ϊ��
Status GetTop(SqStack S, int &e);  //����ջ��Ԫ��(����д��)
Status Push(SqStack &S, int e);  //ѹջ
Status Pop(SqStack &S, int &e);  //��ջ
Status Traverse(SqStack S);  //����ջ
Status BrackerMatch(void);  //����ƥ��
Status Transform(void);  //����ת��
Status EvaluateExpression(void);  //������ģ��
Status In(char c);  //�ǲ���+ - * / ( ) # �е�һ�������
char Precede(int, int);  //�����±��������ȼ��ı�
int Operrate(int a, char theta, int b);  //�Ӽ��˳�
int GetTop(SqStack S);  //���ڼ�����ģ��

Status ShowMeun2(void) {
    printf("1.�����ջ\n");
    printf("2.��ջ\n");
    printf("3.��ջ\n");
    printf("4.ȡջ��Ԫ��\n");
    printf("5.����ջԪ��\n");
    printf("6.����һ���ַ�������[]()�Ƿ�ƥ��\n");
    printf("7.������ת��\n");
    printf("8.������ģ��\n");
    printf("0.�˳�\n");
    return TRUE;
}

Status Test2(void) {
    int select;
    SqStack S;
    ShowMeun2();
    while (TRUE) {
        printf("�������----->");
        scanf("%d", &select);
        switch (select) {
            //����ջ
            case 1: {
                if (InitStack(S)) {
                    printf("����ɹ�!\n");
                } else {
                    printf("����ʧ��\n");
                }
                break;
            }
                //ѹջ
            case 2: {
                int place;
                printf("������������ջ��ֵ\n");
                scanf("%d", &place);
                if (Push(S, place)) {
                    printf("ѹջ�ɹ�!\n");
                } else {
                    printf("ѹջʧ��!\n");
                }
                break;
            }
                //��ջ
            case 3: {
                int place;
                if (Pop(S, place)) {
                    printf("��ջԪ��Ϊ%d\n", place);
                }
                break;
            }
                //��ȡջ����ֵ
            case 4: {
                int place;
                if (Pop(S, place)) {
                    printf("ջ��Ԫ��Ϊ%d\n", place);
                } else {
                    ("�޷��ҵ�ջ��Ԫ��printf");
                }
                break;
            }
                //����ջ
            case 5: {
                if (Traverse(S)) {
                    printf("�����ɹ�!\n");
                } else {
                    printf("����ʧ��!\n");
                }
                break;
            }
                //����һ���ַ�������[]()�Ƿ�ƥ��
            case 6: {
                BrackerMatch();
                break;
            }
                //������ת��
            case 7: {
                Transform();
                break;
            }
                //������ģ��
            case 8: {
                EvaluateExpression();
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
}

Status InitStack(SqStack &S) {
    S.base = (int *) malloc(STACK_INIT_SIZE * sizeof(int));
    if (!S.base)exit(OVERFLOW);// �ڴ����ʧ��
    S.top = nullptr;
    S.top = S.base;
    S.stacksize = STACK_INIT_SIZE;
    return OK;
}

Status StackEmpty(SqStack S) {
    //�ж�ջ����ջ���Ƿ����
    if (S.top == S.base)
        return OK;
    else
        return ERROR;
}

Status GetTop(SqStack S, int &e) {
    //��ջ���գ�����e����s��ջ��Ԫ�أ�������OK�����򷵻�ERROR
    if (S.top == S.base)return (OVERFLOW);
    e = *(S.top - 1);//�����һ����
    return OK;
}

Status Push(SqStack &S, int e) {
    //����Ԫ��e
    //��ջ��
    if (S.top - S.base >= S.stacksize) {
        //׷��ջ����
        S.base = (int *) realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(int));
        if (!S.base)exit(OVERFLOW);//�洢����ʧ��
        S.top = S.base + S.stacksize;
        S.stacksize += STACKINCREMENT;
    }
    //��ջû��
    *S.top++ = e;
    return OK;
}

Status Pop(SqStack &S, int &e) {
    //��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������Ok�����򷵻�ERROR
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
                    printf("��ƥ��!\n");
                    return TRUE;
                }
            } else {
                printf("��ƥ��!\n");
                return FALSE;
            }
        }
    }
    if (StackEmpty(S)) {
        printf("ƥ��\n");
        return TRUE;
    } else {
        printf("��ƥ��!\n");
        return FALSE;
    }
}

Status Transform(void) {
    SqStack S;
    InitStack(S);
    int size;
    printf("����Ҫת��Ϊ���ٽ��Ƶ��� =");
    scanf("%d", &size);
    int Num;
    printf("����������Ҫת������ =");
    scanf("%d", &Num);
    while (Num) {
        Push(S, Num % size);  //ȡ��
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
    //OPTRջ�洢�����  OPNDջ�洢������
    SqStack OPTR, OPND;
    InitStack(OPTR);
    ElemType e;
    Push(OPTR, '#');
    InitStack(OPND);
    //������뻺��

    char c = getchar();
    while (c != '#' || GetTop(OPTR) != '#') {
        if (In(c) == -1) {  //c��������ַ�(c������)
            //ASCII����1����49
            Push(OPND, c - '0');
            c = getchar();
        } else {
            //����������ȡ��ֵ
            //GetTop(OPTR, e);

            //���÷���ֵ��ȡ��ֵ
            e = GetTop(OPTR);
            switch (Precede(In(e), In(c))) {
                case '<':
                    Push(OPTR, c);
                    c = getchar();
                    break;
                case '=':  //������
                    int x;
                    Pop(OPTR, x);
                    c = getchar();
                    break;
                case '>':
                    int theta;
                    int b, a;  //��ǰһ�����ȼ��ߵ���������ó�������
                    Pop(OPTR, theta);
                    Pop(OPND, b);
                    Pop(OPND, a);
                    Push(OPND, Operrate(a, theta, b));
                    break;
            }
        }
    }
    //����������ȡ��ֵ
    //GetTop(OPND, e);
    //printf("������Ϊ %d\n", e);

    //���÷���ֵ��ȡ��ֵ
    printf("������Ϊ %d\n",GetTop(OPND));
    return TRUE;
}

//�����±�
//+ - * / ( ) #
//0 1 2 3 4 5 6
int In(char c) {
    int i = 0;
    while (OP[i] != c && (i < 7)) {
        i++;
    }
    if (i == 7) {  //δ�ҵ�
        return -1;
    } else {  //�ҵ���
        return i;
    }
}

//�����±�����
char Precede(int p, int c) {
    return r[p][c];
}

int Operrate(int a, char theta, int b) {
    float r;
    switch (In(theta)) {
        case 0: {    //�ӷ�����
            r = a + b;
            break;
        }
        case 1: {    //��������
            r = a - b;
            break;
        }
        case 2: {    //�˷�����
            r = a * b;
            break;
        }
        case 3: {    //��������
            r = a / b;
            break;
        }
    }
    return r;
}

int GetTop(SqStack S) {
    //��ջ���գ�����e����s��ջ��Ԫ�أ�������OK�����򷵻�ERROR
    if (S.top == S.base)return (OVERFLOW);
    return *(S.top - 1);
}

#endif //TEST2_STACK_H
