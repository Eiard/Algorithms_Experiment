#include"Base.h"
#include"Test1.h"  //������Ļ���������Ӧ��
#include"Test2.h"
#include"Test3.h"
#include"Test4.h"
#include"Test5.h"

Status ShowMainMenu(void);  //��ҳ�˵�����

int main(void) {
	int Select;
	while (TRUE) {
		ShowMainMenu();
		printf("��ѡ��");
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
				printf("�˳��ɹ�!\n");
				system("pause");
				return 0;
			}
			default:
				printf("��������������������!\n");
				system("pause");
				system("cls");
				break;
		}
	}
	return 0;
}

Status ShowMainMenu(void) {
	printf("*******************�㷨�����ݽṹ******************\n");
	printf("* 1  ������Ļ���������Ӧ��                       *\n");
	printf("* 2  ջ�Ļ���������Ӧ��                           *\n");
	printf("* 3  ϡ������ѹ���洢��Ӧ��                     *\n");
	printf("* 4  ���Ļ���������Ӧ��                           *\n");
	printf("* 5  ͼ�Ļ���������Ӧ��                           *\n");
	printf("* 6  �˳�                                         *\n");
	printf("***************************************************\n");
	return OK;
}