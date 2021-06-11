//
// Created by 30671 on 2021/3/22.
//

#ifndef ALGORITHMS_EXPERIMENT_TEST3_H
#define ALGORITHMS_EXPERIMENT_TEST3_H

#include "Base.h"
#include<vector>

#define MAXSIZE 100

typedef struct {
    int i, j;
    ElemType e;
   
}Triple;

typedef struct {
    Triple data[MAXSIZE + 1];
    int mu, nu, tu;  //���������,�����ͷ���Ԫ����
}TSMatrix;

Status InitMatrix(TSMatrix &M);  //��Ԫ���ʼ��,��������Ԫ��
Status TransposeSMatrix(TSMatrix M, TSMatrix& T);
Status FastTransposeSMatrix(TSMatrix M, TSMatrix& T);
Status ShowMeun3(void);  //�˵�����
Status Test3(void);






Status InitMatrix(TSMatrix &M) {
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
    for (int i = 0; i < r*l;i++) {
        scanf("%d", &temp);
        a.push_back(temp);  //��ֵѹ������
    }
    for (int i = 0; i < r * l; i++) {
        if (a[i] != 0) {
            M.data[M.tu].i = i / l;
			M.data[M.tu].j = i % l;
            M.data[M.tu].e = a[i];
            M.tu++;
        }
    }
    printf("ѹ�������Ԫ��\n");
    printf("i(�к�)  j(�к�) ֵ\n");
    for (int i = 0; i < M.tu; i++) {
        printf("%d        %d       %d\n",  M.data[i].i, M.data[i].j,M.data[i].e);
    }

    return TRUE;
}
Status TransposeSMatrix(TSMatrix M, TSMatrix& T) {
    //������Ԫ���洢��ʾ,��ϡ�����M��ת�þ���
    T.mu = M.nu;  //M������ ��ֵ�� T������
    T.nu = M.mu;  //M������ ��ֵ�� T������
    T.tu = M.tu;  //��ЧԪ�ظ���
    if (T.tu) {  //����Ϊ0
        int q = 0;
        for (int col = 0; col < M.nu; ++col) {
            for (int p = 0; p < M.tu; ++p) {
                if (M.data[p].j == col) {  //�ҵ��ж�Ӧ����
                    T.data[q].i = M.data[p].j;
                    T.data[q].j = M.data[p].i;
                    T.data[q].e = M.data[p].e;
                    ++q;
                }
            }
        }
    }
    printf("ת�ú����Ԫ��\n");
    printf("i(�к�)  j(�к�) ֵ\n");
    for (int i = 0; i < T.tu; i++) {
        printf("%d        %d       %d\n", T.data[i].i, T.data[i].j, T.data[i].e);
    }

    return TRUE;
}
Status FastTransposeSMatrix(TSMatrix M, TSMatrix& T) {

    //������Ԫ���洢��ʾ,��ϡ�����M��ת�þ���
    //����ת���㷨
    T.mu = M.mu; T.nu = M.nu; T.tu = M.tu;
    int col;
    int num[20];
	int cpot[20];
    if (T.tu)
    {
        for (col = 0; col < M.nu; ++col) num[col] = 0;
        for (int t = 0; t < M.tu; ++t) ++num[M.data[t].j];
        cpot[0] = 0;
        for (col = 1; col < M.nu; ++col) cpot[col] = cpot[col - 1] + num[col - 1];
        for (int p = 0; p < M.tu; ++p)
        {
            col = M.data[p].j;
            int q = cpot[col];
            T.data[q].i = M.data[p].j;
            T.data[q].j = M.data[p].i;
            T.data[q].e = M.data[p].e;
            ++cpot[col];//������һ����Ԫ���λ��
        }
    }
    printf("ת�ú����Ԫ��\n");
    printf("i(�к�)  j(�к�) ֵ\n");
    for (int i = 0; i < T.tu; i++) {
        printf("%d        %d       %d\n", T.data[i].i, T.data[i].j, T.data[i].e);
    }

    return TRUE;
}
Status ShowMeun3(void) {
    printf("1.��д������������һ��ϡ���������Ԫ��˳���ѹ���洢ϡ�����\n");
    printf("2.��ϡ��������ת�ã����ת�ú�ľ��� �� ����ʱ��\n");
    printf("3.��ϡ�������п���ת��ת�ã����ת�ú�ľ��� �� ����ʱ��\n");
    printf("0.�˳�\n");
    return TRUE;
}
Status Test3(void){
    time(nullptr);
    DWORD T1 = NULL;
    DWORD T2 = NULL;
    int select;
	TSMatrix T;
    T.tu = 0;  //��ЧԪ�ظ���
    ShowMeun3();
    while (TRUE) {
        printf("�������----->");
        scanf("%d", &select);
        switch (select) {
			//ϡ�����ѹ���������
        case 1: {
            if (InitMatrix(T)) {
                printf("ѹ���ɹ�!\n");
            }
            else {
                printf("ѹ��ʧ��\n");
            }
            break;
		}
              //ѹ������ת�ò������
        case 2: {
            T1 = GetTickCount64();
            TSMatrix Temp;
            if (T.tu !=0) {
                TransposeSMatrix(T, Temp);
            }
            T2 = GetTickCount64();
            printf("�㷨������ʱ��Ϊ %dms \n", T2 - T1);
            break;
		}
        case 3: {
            T1 = GetTickCount64();
            TSMatrix Temp;
            if (T.tu != 0) {
                FastTransposeSMatrix(T, Temp);
            }
            T2 = GetTickCount64();
            printf("�㷨������ʱ��Ϊ %dms \n", T2 - T1);
            system("pause");
        }     
        case 0: {  //�˳�
            exit(-1);
        }
        default:
            break;
        }
    }
    return TRUE;
}





#endif //ALGORITHMS_EXPERIMENT_TEST3_H
