#pragma once

#include"Base.h"

#pragma once
/**
* 算法导论排序算法的总结
* name:排序算法测试汇总
* time:2021/1/3 12:46
* Operating System: Windows 64-bit (10.0, Build 18363)
* ----QQ3067132996 Eiard
*/
//                                                        时间复杂度:     顺序情况      逆序情况
/*           数据对象    稳定性   空间复杂度   排序方式      平均         最好          最坏

冒泡排序     数组         稳定        O(1)     In-place      O(n^2)       O(n)          O(n^2)
选择排序     数组 链表    不稳定      O(1)     In-place      O(n^2)       O(n^2)        O(n^2)
插入排序     数组 链表    稳定        O(1)     In-place      O(n^2)       O(n)          O(n^2)
希尔排序     数组         不稳定      O(1)     In-place      O(nlog n)    O(nlog^2 n)   O(nlog^2 n)
归并排序     数组 链表    稳定        O(n)     out-place     O(nlog n)    O(nlog n)     O(nlog n)
快速排序     数组         不稳定      O(log n) In-place      O(nlog n)    O(nlog n)     O(n^2)
堆排序       数组         不稳定      O(1)     In-place      O(nlog n)    O(nlog n)     O(nlog n)
计数排序     数组 链表    稳定        O(k)     Out-place     O(n+k)       O(n+k)        O(n+k)
桶排序       数组 链表    稳定        O(n+k)   Out-place     O(n+k)       O(n+k)        O(n^2)
基数排序     数组 链表    稳定        O(n+k)   Out-place     O(n*k)       O(n*k)        O(n*k)
*/

#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<iomanip>
#include <windows.h>

//Sequence Containers  连续式容器
//#include<array>  //STL容器:Array数组(定义后长度无法更改)
#include<vector>  //STL容器:Vector数组(可以自动释放内存)
//#include<deque>  //STL容器:Deque数组(两端都可以进出,前后都可以扩充)
//#include<list>  //STL容器:双向链表(位置不连续,关系上连续)
//#include<forward_list>  ///STL容器:单向链表(位置不连续,关系上连续)
//#include<stack>  //STL容器:栈(先进后出)
//#include<queue>  //STL容器:队列(先进先出)

//Associative Containers  关联式容器
//#include<Set>  //STL容器:集合
//#include<map>  //STL容器:图
//#include<hash_map>  //STL容器:哈希表

//#include<algorithm>  //STL算法
//#include<functional>  //STL仿函数
void Test6();
void Menu();  //窗口函数

using namespace std;
class Sort_Algorithms {
public:
	vector<int, allocator<int>> Vec;//随机创建未知数数组用于测试算法  原先数组
	vector<int, allocator<int>> Temp;//随机创建未知数数组用于测试算法  排序后数组
public:
	void Build_Vector(int, int);  //创建随机数数组
	void Build_TVector(int);  //输入有限个数
	void TraverseVector1();  //利用迭代器遍历原vector
	void TraverseVector2();  //利用迭代器遍历排序后vector
	bool Search(int);   //查询


	//一.简单排序
	void Bubble_Sort();  //冒泡排序

	void Selection_Sort();  //选择排序(可以看作改良后的冒泡排序)
	void Selection_Sort(vector<int>&);  //用于桶排序的选择排序

	void Insertion_Sort();  //插入排序
	void Insertion_Sort(vector<int>&);  //用于桶排序的插入排序

	//二.高级排序
	void Shell_Sort();  //希尔排序(可以看作分块的插入排序)

	void Merge_Sort(int, int);  //归并排序第一步:利用递归进行分块
	void Merge_Sort(int, int, int);  //归并排序第二步:排序整合

	void Quick_Sort(int, int);  //快速排序

	void Heap_Sort(int);  //堆排序
	void Heap_Sort(int, int);

	void Count_Sort();  //计数排序

	void Bucket_Sort();  //桶排序

	int Max_Bit(vector<int>&);   //基数排序
	void Radix_Sort();
};