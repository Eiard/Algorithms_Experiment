#pragma once

/*
* ����11902�� ���˳� 201902849
* ��ͷ�ļ�������5��28��
*
* Test3.hͷ�ļ�:
*		����ϡ��������غ���
*		��������˷�
*/

#include "Base.h"

#define MAXSIZE 100

typedef struct {
    int i, j;
    ElemType e;   
}Triple;

typedef struct {
    Triple data[MAXSIZE + 1];
    int mu, nu, tu;  //���������,�����ͷ���Ԫ����
}TSMatrix;
//-----------------------------------------------------
Status ShowMeun3(void);
Status Test3(void);
Status InitMatrix(TSMatrix &M);
Status ShowMatrix(TSMatrix &M);
Status MultiplyMatrix(void);
//-----------------------------------------------------
Status ShowMeun3(void) {
    printf("*************ϡ������ѹ���洢��Ӧ��**************\n");
    printf("* 1  ����                                         *\n");
    printf("* 2  ��ʾ                                         *\n");
    printf("* 3  ����˷���Ӧ�ã�         (��ʵ��)            *\n");
    printf("* 4  �˳�                                         *\n");
    printf("***************************************************\n");
    return OK;
}

Status Test3(void){
    int select;
	TSMatrix T;
    T.tu = 0;  //��ЧԪ�ظ���

    while (TRUE) {
        ShowMeun3();
        printf("��ѡ��");
        scanf("%d", &select);
        system("cls");
        switch (select) {
            case 1: {
                printf("---------����-------\n");

                if (InitMatrix(T)) printf("ѹ���ɹ�!\n");
                else printf("ѹ��ʧ��\n");
                
                system("pause");
                system("cls");
                break;
            }
            case 2: {
                printf("---------��ʾ-------\n");

                if (ShowMatrix(T)) printf("��ʾ�ɹ�!\n");
                else printf("��ʾʧ��\n");

                system("pause");
                system("cls");
                break;
            }
            case 3: {
                printf("---------����˷�-------\n");

                if (MultiplyMatrix()) printf("��ʾ�ɹ�!\n");
                else printf("��ʾʧ��\n");

                system("pause");
                system("cls");
                break;
            }
            case 4: {
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

Status InitMatrix(TSMatrix& M) {
    int r;
    printf("����������������� r = ");
    scanf("%d", &r);
    int l;
    printf("����������������� l = ");
    scanf("%d", &l);

    M.tu = 0;  //��ЧԪ�ظ���
    M.mu = r;  //�������
    M.nu = l;  //�������

    printf("����������Ҫѹ���ľ���\n");
    std::vector<int> a;
    int temp;

    for (int i = 0; i < r * l; i++) {  //��ʱ�洢
        scanf("%d", &temp);
        a.push_back(temp);
    }
    for (int i = 0; i < r * l; i++) {  //ת��Ϊ��Ԫ��洢
        if (a[i] != 0) {
            M.data[M.tu].i = i / l;
            M.data[M.tu].j = i % l;
            M.data[M.tu].e = a[i];
            M.tu++;
        }
    }
    return OK;
}

Status ShowMatrix(TSMatrix& M) {
    if (M.nu <= 0) return ERROR;

    printf("ѹ�������Ԫ��(i��j����1��ʼ)\n");
    printf("i(�к�)  j(�к�) ֵ\n");
    for (int i = 0; i < M.tu; i++) {
        printf("%d        %d       %d\n", M.data[i].i + 1, M.data[i].j + 1, M.data[i].e);
    }

    printf("ԭϡ���������:\n");
    int i = 0;
    for (int j = 0; j < M.mu; j++) {  //��
        for (int k = 0; k < M.nu; k++) {  //��
            if (M.data[i].i == j && M.data[i].j == k) {
                printf(" %d ", M.data[i].e); i++;
            }
            else printf(" 0 ");
        }
        printf("\n");
    }

    return OK;
}

Status MultiplyMatrix(void) {
    TSMatrix M, N;
    M.tu = 0;
    N.tu = 0;

	int a[10][10], b[10][10], c[10][10];

    printf("����Mϡ�����:\n");
    InitMatrix(M);

    printf("����ϡ�����N\n");
    InitMatrix(N);

    if (M.nu != N.nu) printf("�������޷����г˷�����\n");
    else {
        int i = 0;
        //��Mת��Ϊϡ�����
        for (int j = 0; j < M.mu; j++) {  //��
            for (int k = 0; k < M.nu; k++) {  //��
                if (M.data[i].i == j && M.data[i].j == k) {
                    a[j][k] = M.data[i].e; i++;
                }
                else a[j][k] = 0;
            }
        }
        i = 0;
        //��Nת��Ϊϡ�����
        for (int j = 0; j < N.mu; j++) {  //��
            for (int k = 0; k < N.nu; k++) {  //��
                if (N.data[i].i == j && N.data[i].j == k) {
                    b[j][k] = N.data[i].e; i++;
                }
                else b[j][k] = 0;
            }
        }

        //����˷�
        for (int i = 0; i < M.mu; ++i) {
            for (int j = 0; j < N.nu; ++j) {
                c[i][j] = 0;
                for (int k = 0; k < N.mu; ++k) {
					c[i][j] += a[i][k] * b[k][j];
                }
            }
        }

        printf("���֮��ľ�������:\n");
        for (int p = 0; p < M.nu; p++) {
            for (int r = 0; r < M.mu; r++) {
                printf("%d ", c[p][r]);
            }
            printf("\n");
		}
    }

    return OK;
}