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
    int mu, nu, tu;  //矩阵的行数,列数和非零元个数
}TSMatrix;

Status InitMatrix(TSMatrix &M);  //三元表初始化,并且输入元素
Status TransposeSMatrix(TSMatrix M, TSMatrix& T);
Status FastTransposeSMatrix(TSMatrix M, TSMatrix& T);
Status ShowMeun3(void);  //菜单函数
Status Test3(void);






Status InitMatrix(TSMatrix &M) {
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
    for (int i = 0; i < r*l;i++) {
        scanf("%d", &temp);
        a.push_back(temp);  //将值压入数组
    }
    for (int i = 0; i < r * l; i++) {
        if (a[i] != 0) {
            M.data[M.tu].i = i / l;
			M.data[M.tu].j = i % l;
            M.data[M.tu].e = a[i];
            M.tu++;
        }
    }
    printf("压缩后的三元组\n");
    printf("i(行号)  j(列号) 值\n");
    for (int i = 0; i < M.tu; i++) {
        printf("%d        %d       %d\n",  M.data[i].i, M.data[i].j,M.data[i].e);
    }

    return TRUE;
}
Status TransposeSMatrix(TSMatrix M, TSMatrix& T) {
    //采用三元组表存储表示,求稀疏矩阵M的转置矩阵
    T.mu = M.nu;  //M的行数 赋值给 T的列数
    T.nu = M.mu;  //M的列数 赋值给 T的行数
    T.tu = M.tu;  //有效元素个数
    if (T.tu) {  //矩阵不为0
        int q = 0;
        for (int col = 0; col < M.nu; ++col) {
            for (int p = 0; p < M.tu; ++p) {
                if (M.data[p].j == col) {  //找到行对应的列
                    T.data[q].i = M.data[p].j;
                    T.data[q].j = M.data[p].i;
                    T.data[q].e = M.data[p].e;
                    ++q;
                }
            }
        }
    }
    printf("转置后的三元组\n");
    printf("i(行号)  j(列号) 值\n");
    for (int i = 0; i < T.tu; i++) {
        printf("%d        %d       %d\n", T.data[i].i, T.data[i].j, T.data[i].e);
    }

    return TRUE;
}
Status FastTransposeSMatrix(TSMatrix M, TSMatrix& T) {

    //采用三元组表存储表示,求稀疏矩阵M的转置矩阵
    //快速转置算法
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
            ++cpot[col];//此列下一个三元组的位置
        }
    }
    printf("转置后的三元组\n");
    printf("i(行号)  j(列号) 值\n");
    for (int i = 0; i < T.tu; i++) {
        printf("%d        %d       %d\n", T.data[i].i, T.data[i].j, T.data[i].e);
    }

    return TRUE;
}
Status ShowMeun3(void) {
    printf("1.编写程序任意输入一个稀疏矩阵，用三元组顺序表压缩存储稀疏矩阵\n");
    printf("2.对稀疏矩阵进行转置，输出转置后的矩阵 和 运算时间\n");
    printf("3.对稀疏矩阵进行快速转置转置，输出转置后的矩阵 和 运算时间\n");
    printf("0.退出\n");
    return TRUE;
}
Status Test3(void){
    time(nullptr);
    DWORD T1 = NULL;
    DWORD T2 = NULL;
    int select;
	TSMatrix T;
    T.tu = 0;  //有效元素个数
    ShowMeun3();
    while (TRUE) {
        printf("操作序号----->");
        scanf("%d", &select);
        switch (select) {
			//稀疏矩阵压缩并且输出
        case 1: {
            if (InitMatrix(T)) {
                printf("压缩成功!\n");
            }
            else {
                printf("压缩失败\n");
            }
            break;
		}
              //压缩矩阵转置并且输出
        case 2: {
            T1 = GetTickCount64();
            TSMatrix Temp;
            if (T.tu !=0) {
                TransposeSMatrix(T, Temp);
            }
            T2 = GetTickCount64();
            printf("算法所消耗时间为 %dms \n", T2 - T1);
            break;
		}
        case 3: {
            T1 = GetTickCount64();
            TSMatrix Temp;
            if (T.tu != 0) {
                FastTransposeSMatrix(T, Temp);
            }
            T2 = GetTickCount64();
            printf("算法所消耗时间为 %dms \n", T2 - T1);
            system("pause");
        }     
        case 0: {  //退出
            exit(-1);
        }
        default:
            break;
        }
    }
    return TRUE;
}





#endif //ALGORITHMS_EXPERIMENT_TEST3_H
