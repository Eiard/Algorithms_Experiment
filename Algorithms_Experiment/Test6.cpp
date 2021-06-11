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



//Sort-Algorithms.h功能实例化
#include"Test6.h"




//创建Vector数组
void Sort_Algorithms::Build_Vector(int n, int Size) {
	Vec.clear();  //清空数组
	//创建随机数数组
	for (int i = 0; i < n; i++) {
		Vec.push_back(rand() % Size);
	}
	Temp.assign(Vec.begin(), Vec.end());  //assign自带功能清空Temp原vector
	system("pause");
	system("cls");
}

//创建有限个数的Vector数组
void Sort_Algorithms::Build_TVector(int n) {
	Vec.clear();  //清空Vector数组
	int UTemp;
	cout << "请按此格式[1 2]一次输入您要输入的" << n << "个数" << endl;
	for (int i = 0; i < n; i++) {
		cin >> UTemp;
		Vec.push_back(UTemp);  //压入数组中
	}
	Temp.assign(Vec.begin(), Vec.end());  //assign自带功能清空Temp原vector  这里的Temp是public的对象
	system("pause");
	system("cls");
}

//遍历原先Vector
void Sort_Algorithms::TraverseVector1() {  //利用迭代器遍历原Vector
	int num = 1;

	vector<int>::iterator it = Vec.begin();  //迭代器iterator可以看作泛型指针
	for (; it != Vec.end(); ++it, num++) {
		cout << setw(7) << (*it);
		if (num == 17) {
			cout << endl;
			num = num - 17;
		}
	}
	//for (auto elem : Vec) {  //自动提取出Vec.Begin和Vec.end  (auto适度使用)
	//	cout << setw(7) << elem;
	//	if (num == 17) {
	//		cout << endl;
	//		num = num - 17;
	//	}
	//	num++;
	//}
	cout << endl;
	system("pause");
	system("cls");
}
//遍历排序后的Vector
void Sort_Algorithms::TraverseVector2() {  //利用迭代器遍历排序后Vector
	vector<int>::iterator it = Temp.begin();
	int num = 1;
	for (; it != Temp.end(); ++it, num++) {
		cout << setw(7) << (*it);
		if (num == 17) {
			cout << endl;
			num = num - 17;
		}
	}
	cout << endl;
	system("pause");
	system("cls");
}

//1.1冒泡排序
void Sort_Algorithms::Bubble_Sort() {
	Temp.assign(Vec.begin(), Vec.end());  //每次排序完还原
	int i, j;
	for (i = 0; i < Temp.size(); i++)
		for (j = 0; j < Temp.size() - 1 - i; j++)
			if (Temp[j] > Temp[j + 1]) {  //  >对应升序  <对应降序
				swap(Temp[j], Temp[j + 1]);
			}
}

//1.2选择排序(可以看作改良后的冒泡排序)
void Sort_Algorithms::Selection_Sort() {
	for (int i = 0; i < Temp.size() - 1; i++) {
		int min = i;
		for (int j = i + 1; j < Temp.size(); j++)
			if (Temp[j] < Temp[min])  //  >对应降序  <对应升序
				min = j;
		swap(Temp[i], Temp[min]);
	}
}
void Sort_Algorithms::Selection_Sort(vector<int>& vec) {  //用于桶排序的选择排序
	int minPos = -1;
	int len = vec.size();
	for (size_t i = 0; i < len - 1; i++)
	{
		minPos = i;
		for (size_t j = i + 1; j < len; j++)	// 待排序区
		{
			if (vec[minPos] > vec[j])
			{
				minPos = j;
			}
		}

		if (minPos != i)
		{
			swap(vec[minPos], vec[i]);
		}
	}
}

//1.3插入排序
void Sort_Algorithms::Insertion_Sort() {
	for (int j = 1; j < Temp.size(); j++) {
		int key = Temp[j];
		int i = j - 1;
		while (i >= 0 && Temp[i] > key) {  //Temp[i]>key则升序  Temp[i]<key则降序
			Temp[i + 1] = Temp[i];
			i = i - 1;
		}
		Temp[i + 1] = key;
	}
}
void Sort_Algorithms::Insertion_Sort(vector<int>& vec)  //用于实现桶排序所用的插入排序
{
	int len = vec.size();
	// 从下标为1的元素选择合适位置，因为下标为0的元素只有一个，默认有序
	for (size_t i = 1; i < len; i++)
	{
		int temp = vec[i];
		int j = i;
		// 从已排序的右边开始比较，找到比其小的数
		while (j > 0 && temp < vec[j - 1])
		{
			vec[j] = vec[j - 1];
			j--;
		}

		if (i != j)
		{
			vec[j] = temp;
		}
	}
}

//1.4希尔排序(可以看作改良后的插入排序(对于每个小分组进行插入排序))
void Sort_Algorithms::Shell_Sort() {
	//1.根据数组a的长度，确定增长量h的初始值；
	int h = 1;
	while (h < Temp.size() / 2) {
		h = 2 * h + 1;  //先找到最大分组
	}
	//2.希尔排序
	while (h >= 1) {
		//排序
		//2.1.找到待插入的元素
		for (int i = h; i < Temp.size(); i++) {  //此时h+1个元素组成一组
			//2.2把待插入的元素插入到有序数列中
			for (int j = i; j >= h; j -= h) {
				//待插入的元素是a[j],比较a[j]和a[j-h]
				if (Temp[j - h] > Temp[j]) {  //>对应升序  <对应降序
					//小分组的头和尾进行比较
					//交换元素
					swap(Temp[j - h], Temp[j]);
				}
				else {
					//待插入元素已经找到了合适的位置，结束循环；
					break;
				}
			}
		}
		//减小h的值
		h = h / 2;
	}
}

//1.5归并排序
void Sort_Algorithms::Merge_Sort(int low, int mid, int high) {
	int i, k;
	int* tmp = (int*)malloc((high - low + 1) * sizeof(int));
	//high-low+1就是还没分之前的元素总个数
	//申请空间，使其大小为两个
	//左边一块 上下限
	int left_low = low;
	int left_high = mid;
	//右边一块 上下限
	int right_low = mid + 1;
	int right_high = high;
	for (k = 0; left_low <= left_high && right_low <= right_high; k++) {  // 比较两个指针所指向的元素
		if (Temp[left_low] <= Temp[right_low]) {
			tmp[k] = Temp[left_low++];
		}
		/* 假设分为两段
		*  1 3 2 9 5 7
		*  2 7 3 5 1 6
		*  先比较1和2,然后把1储存在临时数组temp中,再第二趟2和3比较,将2再储存到临时数组temp中
		*  数组里面是后置++,说明在循环直接结束后必有left_low大于left_high或者right_low大于right_high
		*/
		else {
			tmp[k] = Temp[right_low++];
		}
	}
	//当有一边提前提取完
	//另一边则直接加到临时数组temp后面
	if (left_low <= left_high) {  //若第一个序列有剩余，直接复制出来粘到合并序列尾
	//memcpy(tmp+k, Temp+left_low, (left_high-left_low+l)*sizeof(int));
		for (i = left_low; i <= left_high; i++)
			tmp[k++] = Temp[i];
	}
	if (right_low <= right_high) {
		//若第二个序列有剩余，直接复制出来粘到合并序列尾
		//memcpy(tmp+k, Temp+right_low, (right_high-right_low+1)*sizeof(int));
		for (i = right_low; i <= right_high; i++)
			tmp[k++] = Temp[i];
	}
	for (i = 0; i < high - low + 1; i++)
		Temp[low + i] = tmp[i];  //将临时数组里的元素排序好后
	free(tmp);
}
void Sort_Algorithms::Merge_Sort(int first, int last) {
	int mid = 0;
	if (first < last) {
		//每次对半分进行处理
		mid = (first + last) / 2; /* 注意防止溢出 */
		/*mid = first/2 + last/2;*/
		//mid = (first & last) + ((first ^ last) >> 1);
		//利用递归将数组分为二叉树
		Merge_Sort(first, mid);
		Merge_Sort(mid + 1, last);
		Merge_Sort(first, mid, last);  //归并
	}
}

//1.6快速排序
void Sort_Algorithms::Quick_Sort(int start, int end) {
	if (start >= end)  //如果只有一个元素
		return;
	int mid = Temp[end];  //将尾部元素当成中间值
	int left = start, right = end - 1;  //除去中间值以外的
	while (left < right) { //在整个范围内搜寻比枢纽元值小或大的元素，然后将左侧元素与右侧元素交换
		while (Temp[left] < mid && left < right) //试图在左侧找到一个比枢纽元更大的元素
			//比中间值小left就右移
			left++;
		while (Temp[right] >= mid && left < right) //试图在右侧找到一个比枢纽元更小的元素
			//比中间值大right就左移
			right--;
		swap(Temp[left], Temp[right]); //交换元素
	}
	if (Temp[left] >= Temp[end])
		swap(Temp[left], Temp[end]);
	else
		left++;
	//递归
	Quick_Sort(start, left - 1);
	Quick_Sort(left + 1, end);
}

//1.7堆排序
void Sort_Algorithms::Heap_Sort(int start, int end) {
	// 建立父类指标和子类指标
	int dad = start;
	int son = dad * 2 + 1;
	while (son <= end) { //若子类点指标在范围内才做比较
		if (son + 1 <= end && Temp[son] < Temp[son + 1]) //先比较两个子类大小,选择最大的
			son++;
		if (Temp[dad] > Temp[son]) //如果父类大于子类则直接跳出函数
			return;
		else { // 否则交换父子内容再惊醒子类点数和孙类比较
			swap(Temp[dad], Temp[son]);
			dad = son;
			son = dad * 2 + 1;
		}
	}
}
void Sort_Algorithms::Heap_Sort(int len) {
	// 初始化，i从最后一个父类点开始调整
	for (int i = len / 2 - 1; i >= 0; i--)
		Heap_Sort(i, len - 1);
	// 先将第一个元素和已经排好的元素前一位做交换，再重新调整(刚调整的元素之前的元素)，直到排序完成
	for (int i = len - 1; i > 0; i--) {
		swap(Temp[0], Temp[i]);
		Heap_Sort(0, i - 1);
	}
}

//1.8计数排序
void Sort_Algorithms::Count_Sort()
{
	if (Vec.size() <= 0)
		return;
	//确定数列最大值
	int max = Vec[0];
	int min = Vec[0];
	for (int i = 1; i < Vec.size(); ++i)
	{
		if (Vec[i] > max)
			max = Vec[i];
		if (Vec[i] < min)
			min = Vec[i];
	}
	int d = max - min;
	// 确定统计数组长度并进行初始化
	vector<int> coutData;
	for (int i = 0; i <= d; ++i)
		coutData.push_back(0);
	// 遍历数组，统计每个数出现的次数
	for (int i = 0; i < Vec.size(); ++i)
		++coutData[Vec[i] - min];
	// 统计数组做变形，后面的元素等于前面的元素之和
	for (int i = 1; i <= d; ++i)
		coutData[i] += coutData[i - 1];
	// 倒序遍历原始数列，从统计数组找到正确的位置，输出到结果数组
	for (int i = Vec.size() - 1; i >= 0; i--)
	{
		Temp[coutData[Vec[i] - min] - 1] = Vec[i];        // 找到Vec[i]对应的coutData的值，值为多少，表示原来排序多少，（因为从1开始，所以再减1）
		coutData[Vec[i] - min]--;        // 然后将相应的coutData的值减1，表示下次再遇到此值时，原来的排序是多少。
	}
}

//1.9桶排序
void Sort_Algorithms::Bucket_Sort()
{
	int max = Temp[0];
	int min = Temp[0];
	// 确定元素的最值
	for (auto it : Temp)
	{
		if (it > max)	max = it;
		if (it < min)	min = it;
	}

	// 桶数: (max - min) / array.length的结果为数组大小的倍数（最大倍数），以倍数作为桶数
	// 【注意1】当序列大小vec.size()比较小，而元素值很大且分散(max - min比较大)，会造成很多“空桶”, 增加系统开销
	// 比如(0, 13, 19892)——> 很多“空桶”
	// 【注意2】：当待排序序列元素个数很多(vec.size()很大), 但是每个元素却又很小时, 只有一个桶, 这种情况比较耗时
	int bucketNum = (max - min) / Temp.size() + 1;

	// 初始化桶, 可以用数组实现, 也可以用vector实现, 这里选取vector实现, 原因下述
	// int** buckets = new int*[bucketNum];	// 数组实现桶，需要二维数组
	vector<vector<int> > vecBucket;	// vector容器实现桶，类似二维数组
	// 桶初始化
	for (size_t i = 0; i < bucketNum; i++)
	{
		vector<int> vecTmp;
		vecBucket.push_back(vecTmp);
	}
	// 用数组实现桶初始化
	// for (size_t i = 0; i < bucketNum; i++)
	// {
	// 	buckets[i] = new int[vec.size()];		// 每个桶最多存放vec.size()个元素
	// }

	// 将待排序元素挨个放入对应桶中
	for (size_t i = 0; i < Temp.size(); i++)
	{
		// 和上面【注意】结合看，如果只有1个桶, 要分开处理
		if (bucketNum == 1)
		{
			vecBucket[0].push_back(Temp[i]);
		}
		else
		{
			int bucketIndex = (Temp[i] - min) / bucketNum;	// 确定存放在哪个桶			
			bucketIndex = bucketIndex >= bucketNum ? bucketNum - 1 : bucketIndex;
			vecBucket[bucketIndex].push_back(Temp[i]);	// 这是用vector实现桶的好处, 直接“接”在后面自动扩容即可, 数组实现还需代码处理
		}
	}

	Temp.clear();
	// 遍历“桶组合”, 给每个桶中元素排序
	// 每个桶元素有序了, 则整个“桶组合”从“编号小”的桶遍历到“编号大”的桶，则为整体有序序列
	for (vector<vector<int> >::iterator iter = vecBucket.begin(); iter != vecBucket.end(); iter++)
	{
		vector<int> vecTmp = *iter;		// *iter也是一个vector, 内部存放了该桶内元素
		if (vecTmp.size() <= 0)
		{
			continue;
		}

		// 对每个桶进行排序, 这里借用选择排序
		// 当n较小时，对稳定性不作要求时宜用选择排序
		Selection_Sort(vecTmp);
		// InsertSort(vecTmp);	// 有兴趣读者也可以试用插入排序看看耗时
		for (auto it : vecTmp)
		{
			// 每个桶内元素有序后, 重新给vec赋值, 此时vec有序。
			Temp.push_back(it);
		}
	}

}

//1.10基数排序
int Sort_Algorithms::Max_Bit(vector<int>& data) {
	int d = 1; //保存最大的位数
	int p = 10;
	for (int i = 0; i < data.size(); ++i)
	{
		while (data[i] >= p)
		{
			p *= 10;
			++d;
		}
	}
	return d;
}
void Sort_Algorithms::Radix_Sort() {   //基数排序
	int d = Max_Bit(Temp);
	vector<int>temp;
	temp.assign(Temp.begin(), Temp.end());
	int count[10]; //计数器
	int i, j, k;
	int radix = 1;
	for (i = 1; i <= d; i++) //进行d次排序
	{
		for (j = 0; j < 10; j++)
			count[j] = 0; //每次分配前清空计数器
		for (j = 0; j < Temp.size(); j++)
		{
			k = (Temp[j] / radix) % 10; //统计每个桶中的记录数
			count[k]++;
		}
		for (j = 1; j < 10; j++)
			count[j] = count[j - 1] + count[j]; //将tmp中的位置依次分配给每个桶
		for (j = Temp.size() - 1; j >= 0; j--) //将所有桶中记录依次收集到tmp中
		{
			k = (Temp[j] / radix) % 10;
			temp[count[k] - 1] = Temp[j];
			count[k]--;
		}
		for (j = 0; j < Temp.size(); j++) //将临时数组的内容复制到data中
			Temp[j] = temp[j];
		radix = radix * 10;
	}
}

void Test6() {
	srand(time(nullptr));
	Sort_Algorithms T;
	DWORD t1 = NULL, t2 = NULL;  //用于记录算法运行时间
	int select;
	while (1) {
		Menu();
		cin >> select;
		switch (select)
		{
		case 0:  //退出
			system("pause");
			return;
			break;
		case 1:  //创建数组
			cout << "我们将会创建n个随机数进行算法测试(请输入n)\n";
			cout << "n  -- >";
			int num, Size;
			cin >> num;
			cout << "请您在输入随机数规模0到(Size-1)\n";
			cout << "Size  -- >";
			cin >> Size;
			T.Build_Vector(num, Size);
			break;
		case 2:  //遍历原数组
			T.TraverseVector1();
			break;
		case 3: //遍历排序后的数组
			T.TraverseVector2();
			break;
		case 4:   //冒泡排序
			T.Temp.assign(T.Vec.begin(), T.Vec.end());  //每次排序完还原(放在外部的原因是可以更精确的测量算法的速度)
			//取当前时刻
			t1 = GetTickCount();
			T.Bubble_Sort();  //冒泡排序
			//取当前时刻
			t2 = GetTickCount();
			cout << "\n当前用时:" << t2 - t1 << "ms\n";
			system("pause");
			system("cls");
			break;
		case 5:  //选择排序
			T.Temp.assign(T.Vec.begin(), T.Vec.end());  //每次排序完还原(放在外部的原因是可以更精确的测量算法的速度)
			//取当前时刻
			t1 = GetTickCount();
			T.Selection_Sort();  //选择排序
			//取当前时刻
			t2 = GetTickCount();
			cout << "\n当前用时:" << t2 - t1 << "ms\n";
			system("pause");
			system("cls");
			break;
		case 6:  //插入排序
			T.Temp.assign(T.Vec.begin(), T.Vec.end());  //每次排序完还原(放在外部的原因是可以更精确的测量算法的速度)
			//取当前时刻
			t1 = GetTickCount();
			T.Insertion_Sort();  //插入排序
			//取当前时刻
			t2 = GetTickCount();
			cout << "\n当前用时:" << t2 - t1 << "ms\n";
			system("pause");
			system("cls");
			break;
		case 7:  //希尔排序
			T.Temp.assign(T.Vec.begin(), T.Vec.end());  //每次排序完还原(放在外部的原因是可以更精确的测量算法的速度)
			//取当前时刻
			t1 = GetTickCount();
			T.Shell_Sort();  //希尔排序
			//取当前时刻
			t2 = GetTickCount();
			cout << "\n当前用时:" << t2 - t1 << "ms\n";
			system("pause");
			system("cls");
			break;
		case 8:  //归并排序
			T.Temp.assign(T.Vec.begin(), T.Vec.end());  //每次排序完还原(放在外部的原因是可以更精确的测量算法的速度)
			//取当前时刻
			t1 = GetTickCount();
			T.Merge_Sort(0, T.Vec.size() - 1);  //归并排序
			//取当前时刻
			t2 = GetTickCount();
			cout << "\n当前用时:" << t2 - t1 << "ms\n";
			system("pause");
			system("cls");
			break;
		case 9:  //快速排序
			T.Temp.assign(T.Vec.begin(), T.Vec.end());  //每次排序完还原(放在外部的原因是可以更精确的测量算法的速度)
			//取当前时刻
			t1 = GetTickCount();
			T.Quick_Sort(0, T.Temp.size() - 1);  //快速排序
			//取当前时刻
			t2 = GetTickCount();
			cout << "\n当前用时:" << t2 - t1 << "ms\n";
			system("pause");
			system("cls");
			break;
		case 10:
			T.Temp.assign(T.Vec.begin(), T.Vec.end());  //每次排序完还原(放在外部的原因是可以更精确的测量算法的速度)
			//取当前时刻
			t1 = GetTickCount();
			T.Heap_Sort(T.Temp.size());  //堆排序
			//取当前时刻
			t2 = GetTickCount();
			cout << "\n当前用时:" << t2 - t1 << "ms\n";
			system("pause");
			system("cls");
			break;
		case 11:
			T.Temp.assign(T.Vec.begin(), T.Vec.end());  //每次排序完还原(放在外部的原因是可以更精确的测量算法的速度)
			//取当前时刻
			t1 = GetTickCount();
			T.Count_Sort();  //计数排序
			//取当前时刻
			t2 = GetTickCount();
			cout << "\n当前用时:" << t2 - t1 << "ms\n";
			system("pause");
			system("cls");
			break;
		case 12:
			T.Temp.assign(T.Vec.begin(), T.Vec.end());  //每次排序完还原(放在外部的原因是可以更精确的测量算法的速度)
			//取当前时刻
			t1 = GetTickCount();
			T.Bucket_Sort();  //桶排序
			//取当前时刻
			t2 = GetTickCount();
			cout << "\n当前用时:" << t2 - t1 << "ms\n";
			system("pause");
			system("cls");
			break;
		case 13:
			T.Temp.assign(T.Vec.begin(), T.Vec.end());  //每次排序完还原(放在外部的原因是可以更精确的测量算法的速度)
			//取当前时刻
			t1 = GetTickCount();
			T.Radix_Sort();  //基数排序
			//取当前时刻
			t2 = GetTickCount();
			cout << "\n当前用时:" << t2 - t1 << "ms\n";
			system("pause");
			system("cls");
			break;
		case 14:{
			cout << "我们将会创建n个数的数组\n";
			cout << "n  -- >";
			int num;
			cin >> num;
			T.Build_TVector(num);
			break;
		}
		case 15: {
			cout << "请输入您要查询的数Num\n";
			cout << "Num  -->";
			int Num;
			cin >> Num;
			if (T.Search(Num)) {
				cout << "查询成功" << endl;
			}
			else {
				cout << "查询失败" << endl;
			}
			system("pause");
			system("cls");
			break;
		}
}	
}
	system("pause");

	return;
}

void Menu() {  //窗口
	cout << "\t输入数字进行选择:\n";
	cout << "\t1.生成新随机数数组数组进行测试\n";
	cout << "\t2.遍历原先数组\n";
	cout << "\t3.遍历排序后数组\n";
	cout << "\t4.冒泡排序\n";
	cout << "\t5.选择排序\n";
	cout << "\t6.插入排序\n";
	cout << "\t7.希尔排序\n";
	cout << "\t8.归并排序\n";
	cout << "\t9.快速排序\n";
	cout << "\t10.堆排序\n";
	cout << "\t11.计数排序\n";
	cout << "\t12.桶排序\n";
	cout << "\t13.基数排序\n";
	cout << "\t14.输入n个数组成数组\n";
	cout << "\t15.输入某个数在数组中进行查询(查询失败返回0)\n";
	cout << "\t0.退出\n";
	cout << "\t-->";
}

bool Sort_Algorithms::Search(int Num) {
	int Lim = 0;
	for (int i = 0; i < Vec.size(); i++) {
		if (Vec[i] == Num) {
			Lim++;
			cout << "该数在该数组是第" << i+1 << "个数  数值为" << Num << endl;
		}
	}
	if (Lim > 0) {
		return true;
	}
	else {
		return false;
	}
}