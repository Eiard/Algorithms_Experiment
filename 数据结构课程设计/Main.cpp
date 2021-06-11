#include"Base.h"
#include"Test1.h"  //单链表的基本操作及应用
#include"Test2.h"
#include"Test3.h"
#include"Test4.h"
#include"Test5.h"

Status ShowMainMenu(void);  //主页菜单函数

int main(void) {
	int Select;
	while (TRUE) {
		ShowMainMenu();
		printf("请选择：");
		scanf("%d", &Select);
		system("cls");
		switch (Select) {
			case 1: {
				Test1();
				break;
			}
			case 2: {
				Test2();
				break;
			}
			case 3: {
				Test3();
				break;
			}
			case 4: {
				Test4();
				break;
			}
			case 5: {
				Test5();
				break;
			}
			case 6: {
				printf("退出成功!\n");
				system("pause");
				return 0;
			}
			default:
				printf("您输入有误请重新输入!\n");
				system("pause");
				system("cls");
				break;
		}
	}
	return 0;
}

Status ShowMainMenu(void) {
	printf("*******************算法与数据结构******************\n");
	printf("* 1  单链表的基本操作及应用                       *\n");
	printf("* 2  栈的基本操作及应用                           *\n");
	printf("* 3  稀疏矩阵的压缩存储及应用                     *\n");
	printf("* 4  树的基本操作及应用                           *\n");
	printf("* 5  图的基本操作及应用                           *\n");
	printf("* 6  退出                                         *\n");
	printf("***************************************************\n");
	return OK;
}