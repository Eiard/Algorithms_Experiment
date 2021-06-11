#pragma once

#include"Base.h"

#pragma once
/**
* �㷨���������㷨���ܽ�
* name:�����㷨���Ի���
* time:2021/1/3 12:46
* Operating System: Windows 64-bit (10.0, Build 18363)
* ----QQ3067132996 Eiard
*/
//                                                        ʱ�临�Ӷ�:     ˳�����      �������
/*           ���ݶ���    �ȶ���   �ռ临�Ӷ�   ����ʽ      ƽ��         ���          �

ð������     ����         �ȶ�        O(1)     In-place      O(n^2)       O(n)          O(n^2)
ѡ������     ���� ����    ���ȶ�      O(1)     In-place      O(n^2)       O(n^2)        O(n^2)
��������     ���� ����    �ȶ�        O(1)     In-place      O(n^2)       O(n)          O(n^2)
ϣ������     ����         ���ȶ�      O(1)     In-place      O(nlog n)    O(nlog^2 n)   O(nlog^2 n)
�鲢����     ���� ����    �ȶ�        O(n)     out-place     O(nlog n)    O(nlog n)     O(nlog n)
��������     ����         ���ȶ�      O(log n) In-place      O(nlog n)    O(nlog n)     O(n^2)
������       ����         ���ȶ�      O(1)     In-place      O(nlog n)    O(nlog n)     O(nlog n)
��������     ���� ����    �ȶ�        O(k)     Out-place     O(n+k)       O(n+k)        O(n+k)
Ͱ����       ���� ����    �ȶ�        O(n+k)   Out-place     O(n+k)       O(n+k)        O(n^2)
��������     ���� ����    �ȶ�        O(n+k)   Out-place     O(n*k)       O(n*k)        O(n*k)
*/

#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<iomanip>
#include <windows.h>

//Sequence Containers  ����ʽ����
//#include<array>  //STL����:Array����(����󳤶��޷�����)
#include<vector>  //STL����:Vector����(�����Զ��ͷ��ڴ�)
//#include<deque>  //STL����:Deque����(���˶����Խ���,ǰ�󶼿�������)
//#include<list>  //STL����:˫������(λ�ò�����,��ϵ������)
//#include<forward_list>  ///STL����:��������(λ�ò�����,��ϵ������)
//#include<stack>  //STL����:ջ(�Ƚ����)
//#include<queue>  //STL����:����(�Ƚ��ȳ�)

//Associative Containers  ����ʽ����
//#include<Set>  //STL����:����
//#include<map>  //STL����:ͼ
//#include<hash_map>  //STL����:��ϣ��

//#include<algorithm>  //STL�㷨
//#include<functional>  //STL�º���
void Test6();
void Menu();  //���ں���

using namespace std;
class Sort_Algorithms {
public:
	vector<int, allocator<int>> Vec;//�������δ֪���������ڲ����㷨  ԭ������
	vector<int, allocator<int>> Temp;//�������δ֪���������ڲ����㷨  ���������
public:
	void Build_Vector(int, int);  //�������������
	void Build_TVector(int);  //�������޸���
	void TraverseVector1();  //���õ���������ԭvector
	void TraverseVector2();  //���õ��������������vector
	bool Search(int);   //��ѯ


	//һ.������
	void Bubble_Sort();  //ð������

	void Selection_Sort();  //ѡ������(���Կ����������ð������)
	void Selection_Sort(vector<int>&);  //����Ͱ�����ѡ������

	void Insertion_Sort();  //��������
	void Insertion_Sort(vector<int>&);  //����Ͱ����Ĳ�������

	//��.�߼�����
	void Shell_Sort();  //ϣ������(���Կ����ֿ�Ĳ�������)

	void Merge_Sort(int, int);  //�鲢�����һ��:���õݹ���зֿ�
	void Merge_Sort(int, int, int);  //�鲢����ڶ���:��������

	void Quick_Sort(int, int);  //��������

	void Heap_Sort(int);  //������
	void Heap_Sort(int, int);

	void Count_Sort();  //��������

	void Bucket_Sort();  //Ͱ����

	int Max_Bit(vector<int>&);   //��������
	void Radix_Sort();
};