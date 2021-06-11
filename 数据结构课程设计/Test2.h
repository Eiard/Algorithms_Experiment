#pragma once

/*
* ����11902�� ���˳� 201902849
* ��ͷ�ļ�������5��28��
*
* Test2.hͷ�ļ�:
*		��������ջ�ĺ���
*		�������ʽ����Ӧ��
*/

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
//-----------------------------------------------------
Status ShowMeun2(void);
Status Test2(void);  //����
Status InitStack(SqStack &S);  //��ʼ��һ����ջ
Status StackEmpty(SqStack S);  //ջ�Ƿ�Ϊ��
Status GetTop(SqStack S, int &e);  //����ջ��Ԫ��
Status Push(SqStack &S, int e);  //ѹջ
Status Pop(SqStack &S, int &e);  //��ջ
Status EvaluateExpression(void);  //������ģ��
Status In(char c);  //�ǲ���+ - * / ( ) # �е�һ�������
char Precede(int, int);  //�����±��������ȼ��ı�
int Operrate(int a, char theta, int b);  //�Ӽ��˳�
int GetTop(SqStack S);  //���ڼ�����ģ��
//-----------------------------------------------------
Status ShowMeun2(void) {
    printf("****************ջ�Ļ���������Ӧ��*****************\n");
    printf("* 1  ��ջ                                         *\n");
    printf("* 2  ��ջ                                         *\n");
    printf("* 3  ȡջ��Ԫ��                                   *\n");
    printf("* 4  ���ʽ��⣨Ӧ�ã�        (��ʵ��)           *\n");
    printf("* 5  �˳�                                         *\n");
    printf("***************************************************\n");
    return TRUE;
}

Status Test2(void) {
    int select;
    SqStack S;
    InitStack(S);  //��ʼ����ջ

    while (TRUE) {
        ShowMeun2();
        printf("��ѡ��");
        scanf("%d", &select);
        system("cls");
        switch (select) {
            case 1: {
                printf("--------��ջ-------\n");
                int place;
                printf("�����������ջ��ֵ\n");
                scanf("%d", &place);
				
                if (Push(S, place)) printf("��ջ�ɹ�!\n");
                else printf("��ջʧ��!\n");

                system("pause");
                system("cls");
                break;
            }
            case 2: {
                printf("--------��ջ-------\n");
                int place;
                
                if (Pop(S, place)) printf("��ջԪ��Ϊ%d\n", place);
                else printf("��ջʧ��!\n");
                
                system("pause");
                system("cls");
                break;
            }
            case 3: {
                printf("--------ȡջ��Ԫ��-------\n");
                int place;

                if (Pop(S, place)) printf("ջ��Ԫ��Ϊ%d\n", place);
                else printf("�޷��ҵ�ջ��Ԫ��\n");
                
                system("pause");
                system("cls");
                break;
            }
            case 4: {
                printf("--------���ʽ��ֵ-------\n");

                if (EvaluateExpression()) printf("���ʽ��ֵ�ɹ�!\n");
                else printf("���ʽ��ֵʧ��!\n");

                system("pause");
                system("cls");
                break;
            }
            case 5: {
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
    if (S.top == S.base)return ERROR;
    e = *(S.top - 1);//�����һ����
    return OK;
}

Status Push(SqStack &S, int e) {
    //����Ԫ��e
    //��ջ��
    if (S.top - S.base >= S.stacksize) {
        //׷��ջ����
        S.base = (int *) realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(int));
        if (!S.base)return ERROR;//�洢����ʧ��
        S.top = S.base + S.stacksize;
        S.stacksize += STACKINCREMENT;
    }
    //��ջû��
    *S.top++ = e;
    return OK;
}

Status Pop(SqStack &S, int &e) {
    //��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������Ok�����򷵻�ERROR
    if (S.top == S.base)return ERROR;
    e = *--S.top;
    return OK;
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
    return OK;
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