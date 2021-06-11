#pragma once

/*
* 物联11902班 张宜成 201902849
* 该头文件创建于5月28日
*
* Test3.h头文件:
*		包含稀疏矩阵的相关函数
*		包含矩阵乘法
*/

#include "Base.h"

#define MAXSIZE 100

typedef struct {
    int i, j;
    ElemType e;   
}Triple;

typedef struct {
    Triple data[MAXSIZE + 1];
    int mu, nu, tu;  //矩阵的行数,列数和非零元个数
}TSMatrix;
//-----------------------------------------------------
Status ShowMeun3(void);
Status Test3(void);
Status InitMatrix(TSMatrix &M);
Status ShowMatrix(TSMatrix &M);
Status MultiplyMatrix(void);
//-----------------------------------------------------
Status ShowMeun3(void) {
    printf("*************稀疏矩阵的压缩存储及应用**************\n");
    printf("* 1  创建                                         *\n");
    printf("* 2  显示                                         *\n");
    printf("* 3  矩阵乘法（应用）         (已实现)            *\n");
    printf("* 4  退出                                         *\n");
    printf("***************************************************\n");
    return OK;
}

Status Test3(void){
    int select;
	TSMatrix T;
    T.tu = 0;  //有效元素个数

    while (TRUE) {
        ShowMeun3();
        printf("请选择：");
        scanf("%d", &select);
        system("cls");
        switch (select) {
            case 1: {
                printf("---------创建-------\n");

                if (InitMatrix(T)) printf("压缩成功!\n");
                else printf("压缩失败\n");
                
                system("pause");
                system("cls");
                break;
            }
            case 2: {
                printf("---------显示-------\n");

                if (ShowMatrix(T)) printf("显示成功!\n");
                else printf("显示失败\n");

                system("pause");
                system("cls");
                break;
            }
            case 3: {
                printf("---------矩阵乘法-------\n");

                if (MultiplyMatrix()) printf("显示成功!\n");
                else printf("显示失败\n");

                system("pause");
                system("cls");
                break;
            }
            case 4: {
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

Status InitMatrix(TSMatrix& M) {
    int r;
    printf("请输入你的数组行数 r = ");
    scanf("%d", &r);
    int l;
    printf("请输入你的数组列数 l = ");
    scanf("%d", &l);

    M.tu = 0;  //有效元素个数
    M.mu = r;  //最大行数
    M.nu = l;  //最大列数

    printf("请输入您需要压缩的矩阵\n");
    std::vector<int> a;
    int temp;

    for (int i = 0; i < r * l; i++) {  //临时存储
        scanf("%d", &temp);
        a.push_back(temp);
    }
    for (int i = 0; i < r * l; i++) {  //转化为三元表存储
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

    printf("压缩后的三元组(i和j均从1开始)\n");
    printf("i(行号)  j(列号) 值\n");
    for (int i = 0; i < M.tu; i++) {
        printf("%d        %d       %d\n", M.data[i].i + 1, M.data[i].j + 1, M.data[i].e);
    }

    printf("原稀疏矩阵如下:\n");
    int i = 0;
    for (int j = 0; j < M.mu; j++) {  //行
        for (int k = 0; k < M.nu; k++) {  //列
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

    printf("创建M稀疏矩阵:\n");
    InitMatrix(M);

    printf("创建稀疏矩阵N\n");
    InitMatrix(N);

    if (M.nu != N.nu) printf("两矩阵无法进行乘法运算\n");
    else {
        int i = 0;
        //将M转化为稀疏矩阵
        for (int j = 0; j < M.mu; j++) {  //行
            for (int k = 0; k < M.nu; k++) {  //列
                if (M.data[i].i == j && M.data[i].j == k) {
                    a[j][k] = M.data[i].e; i++;
                }
                else a[j][k] = 0;
            }
        }
        i = 0;
        //将N转化为稀疏矩阵
        for (int j = 0; j < N.mu; j++) {  //行
            for (int k = 0; k < N.nu; k++) {  //列
                if (N.data[i].i == j && N.data[i].j == k) {
                    b[j][k] = N.data[i].e; i++;
                }
                else b[j][k] = 0;
            }
        }

        //矩阵乘法
        for (int i = 0; i < M.mu; ++i) {
            for (int j = 0; j < N.nu; ++j) {
                c[i][j] = 0;
                for (int k = 0; k < N.mu; ++k) {
					c[i][j] += a[i][k] * b[k][j];
                }
            }
        }

        printf("相乘之后的矩阵如下:\n");
        for (int p = 0; p < M.nu; p++) {
            for (int r = 0; r < M.mu; r++) {
                printf("%d ", c[p][r]);
            }
            printf("\n");
		}
    }

    return OK;
}