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



//Sort-Algorithms.h����ʵ����
#include"Test6.h"




//����Vector����
void Sort_Algorithms::Build_Vector(int n, int Size) {
	Vec.clear();  //�������
	//�������������
	for (int i = 0; i < n; i++) {
		Vec.push_back(rand() % Size);
	}
	Temp.assign(Vec.begin(), Vec.end());  //assign�Դ��������Tempԭvector
	system("pause");
	system("cls");
}

//�������޸�����Vector����
void Sort_Algorithms::Build_TVector(int n) {
	Vec.clear();  //���Vector����
	int UTemp;
	cout << "�밴�˸�ʽ[1 2]һ��������Ҫ�����" << n << "����" << endl;
	for (int i = 0; i < n; i++) {
		cin >> UTemp;
		Vec.push_back(UTemp);  //ѹ��������
	}
	Temp.assign(Vec.begin(), Vec.end());  //assign�Դ��������Tempԭvector  �����Temp��public�Ķ���
	system("pause");
	system("cls");
}

//����ԭ��Vector
void Sort_Algorithms::TraverseVector1() {  //���õ���������ԭVector
	int num = 1;

	vector<int>::iterator it = Vec.begin();  //������iterator���Կ�������ָ��
	for (; it != Vec.end(); ++it, num++) {
		cout << setw(7) << (*it);
		if (num == 17) {
			cout << endl;
			num = num - 17;
		}
	}
	//for (auto elem : Vec) {  //�Զ���ȡ��Vec.Begin��Vec.end  (auto�ʶ�ʹ��)
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
//����������Vector
void Sort_Algorithms::TraverseVector2() {  //���õ��������������Vector
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

//1.1ð������
void Sort_Algorithms::Bubble_Sort() {
	Temp.assign(Vec.begin(), Vec.end());  //ÿ�������껹ԭ
	int i, j;
	for (i = 0; i < Temp.size(); i++)
		for (j = 0; j < Temp.size() - 1 - i; j++)
			if (Temp[j] > Temp[j + 1]) {  //  >��Ӧ����  <��Ӧ����
				swap(Temp[j], Temp[j + 1]);
			}
}

//1.2ѡ������(���Կ����������ð������)
void Sort_Algorithms::Selection_Sort() {
	for (int i = 0; i < Temp.size() - 1; i++) {
		int min = i;
		for (int j = i + 1; j < Temp.size(); j++)
			if (Temp[j] < Temp[min])  //  >��Ӧ����  <��Ӧ����
				min = j;
		swap(Temp[i], Temp[min]);
	}
}
void Sort_Algorithms::Selection_Sort(vector<int>& vec) {  //����Ͱ�����ѡ������
	int minPos = -1;
	int len = vec.size();
	for (size_t i = 0; i < len - 1; i++)
	{
		minPos = i;
		for (size_t j = i + 1; j < len; j++)	// ��������
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

//1.3��������
void Sort_Algorithms::Insertion_Sort() {
	for (int j = 1; j < Temp.size(); j++) {
		int key = Temp[j];
		int i = j - 1;
		while (i >= 0 && Temp[i] > key) {  //Temp[i]>key������  Temp[i]<key����
			Temp[i + 1] = Temp[i];
			i = i - 1;
		}
		Temp[i + 1] = key;
	}
}
void Sort_Algorithms::Insertion_Sort(vector<int>& vec)  //����ʵ��Ͱ�������õĲ�������
{
	int len = vec.size();
	// ���±�Ϊ1��Ԫ��ѡ�����λ�ã���Ϊ�±�Ϊ0��Ԫ��ֻ��һ����Ĭ������
	for (size_t i = 1; i < len; i++)
	{
		int temp = vec[i];
		int j = i;
		// ����������ұ߿�ʼ�Ƚϣ��ҵ�����С����
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

//1.4ϣ������(���Կ���������Ĳ�������(����ÿ��С������в�������))
void Sort_Algorithms::Shell_Sort() {
	//1.��������a�ĳ��ȣ�ȷ��������h�ĳ�ʼֵ��
	int h = 1;
	while (h < Temp.size() / 2) {
		h = 2 * h + 1;  //���ҵ�������
	}
	//2.ϣ������
	while (h >= 1) {
		//����
		//2.1.�ҵ��������Ԫ��
		for (int i = h; i < Temp.size(); i++) {  //��ʱh+1��Ԫ�����һ��
			//2.2�Ѵ������Ԫ�ز��뵽����������
			for (int j = i; j >= h; j -= h) {
				//�������Ԫ����a[j],�Ƚ�a[j]��a[j-h]
				if (Temp[j - h] > Temp[j]) {  //>��Ӧ����  <��Ӧ����
					//С�����ͷ��β���бȽ�
					//����Ԫ��
					swap(Temp[j - h], Temp[j]);
				}
				else {
					//������Ԫ���Ѿ��ҵ��˺��ʵ�λ�ã�����ѭ����
					break;
				}
			}
		}
		//��Сh��ֵ
		h = h / 2;
	}
}

//1.5�鲢����
void Sort_Algorithms::Merge_Sort(int low, int mid, int high) {
	int i, k;
	int* tmp = (int*)malloc((high - low + 1) * sizeof(int));
	//high-low+1���ǻ�û��֮ǰ��Ԫ���ܸ���
	//����ռ䣬ʹ���СΪ����
	//���һ�� ������
	int left_low = low;
	int left_high = mid;
	//�ұ�һ�� ������
	int right_low = mid + 1;
	int right_high = high;
	for (k = 0; left_low <= left_high && right_low <= right_high; k++) {  // �Ƚ�����ָ����ָ���Ԫ��
		if (Temp[left_low] <= Temp[right_low]) {
			tmp[k] = Temp[left_low++];
		}
		/* �����Ϊ����
		*  1 3 2 9 5 7
		*  2 7 3 5 1 6
		*  �ȱȽ�1��2,Ȼ���1��������ʱ����temp��,�ٵڶ���2��3�Ƚ�,��2�ٴ��浽��ʱ����temp��
		*  ���������Ǻ���++,˵����ѭ��ֱ�ӽ��������left_low����left_high����right_low����right_high
		*/
		else {
			tmp[k] = Temp[right_low++];
		}
	}
	//����һ����ǰ��ȡ��
	//��һ����ֱ�Ӽӵ���ʱ����temp����
	if (left_low <= left_high) {  //����һ��������ʣ�ֱ࣬�Ӹ��Ƴ���ճ���ϲ�����β
	//memcpy(tmp+k, Temp+left_low, (left_high-left_low+l)*sizeof(int));
		for (i = left_low; i <= left_high; i++)
			tmp[k++] = Temp[i];
	}
	if (right_low <= right_high) {
		//���ڶ���������ʣ�ֱ࣬�Ӹ��Ƴ���ճ���ϲ�����β
		//memcpy(tmp+k, Temp+right_low, (right_high-right_low+1)*sizeof(int));
		for (i = right_low; i <= right_high; i++)
			tmp[k++] = Temp[i];
	}
	for (i = 0; i < high - low + 1; i++)
		Temp[low + i] = tmp[i];  //����ʱ�������Ԫ������ú�
	free(tmp);
}
void Sort_Algorithms::Merge_Sort(int first, int last) {
	int mid = 0;
	if (first < last) {
		//ÿ�ζ԰�ֽ��д���
		mid = (first + last) / 2; /* ע���ֹ��� */
		/*mid = first/2 + last/2;*/
		//mid = (first & last) + ((first ^ last) >> 1);
		//���õݹ齫�����Ϊ������
		Merge_Sort(first, mid);
		Merge_Sort(mid + 1, last);
		Merge_Sort(first, mid, last);  //�鲢
	}
}

//1.6��������
void Sort_Algorithms::Quick_Sort(int start, int end) {
	if (start >= end)  //���ֻ��һ��Ԫ��
		return;
	int mid = Temp[end];  //��β��Ԫ�ص����м�ֵ
	int left = start, right = end - 1;  //��ȥ�м�ֵ�����
	while (left < right) { //��������Χ����Ѱ����ŦԪֵС����Ԫ�أ�Ȼ�����Ԫ�����Ҳ�Ԫ�ؽ���
		while (Temp[left] < mid && left < right) //��ͼ������ҵ�һ������ŦԪ�����Ԫ��
			//���м�ֵСleft������
			left++;
		while (Temp[right] >= mid && left < right) //��ͼ���Ҳ��ҵ�һ������ŦԪ��С��Ԫ��
			//���м�ֵ��right������
			right--;
		swap(Temp[left], Temp[right]); //����Ԫ��
	}
	if (Temp[left] >= Temp[end])
		swap(Temp[left], Temp[end]);
	else
		left++;
	//�ݹ�
	Quick_Sort(start, left - 1);
	Quick_Sort(left + 1, end);
}

//1.7������
void Sort_Algorithms::Heap_Sort(int start, int end) {
	// ��������ָ�������ָ��
	int dad = start;
	int son = dad * 2 + 1;
	while (son <= end) { //�������ָ���ڷ�Χ�ڲ����Ƚ�
		if (son + 1 <= end && Temp[son] < Temp[son + 1]) //�ȱȽ����������С,ѡ������
			son++;
		if (Temp[dad] > Temp[son]) //����������������ֱ����������
			return;
		else { // ���򽻻����������پ����������������Ƚ�
			swap(Temp[dad], Temp[son]);
			dad = son;
			son = dad * 2 + 1;
		}
	}
}
void Sort_Algorithms::Heap_Sort(int len) {
	// ��ʼ����i�����һ������㿪ʼ����
	for (int i = len / 2 - 1; i >= 0; i--)
		Heap_Sort(i, len - 1);
	// �Ƚ���һ��Ԫ�غ��Ѿ��źõ�Ԫ��ǰһλ�������������µ���(�յ�����Ԫ��֮ǰ��Ԫ��)��ֱ���������
	for (int i = len - 1; i > 0; i--) {
		swap(Temp[0], Temp[i]);
		Heap_Sort(0, i - 1);
	}
}

//1.8��������
void Sort_Algorithms::Count_Sort()
{
	if (Vec.size() <= 0)
		return;
	//ȷ���������ֵ
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
	// ȷ��ͳ�����鳤�Ȳ����г�ʼ��
	vector<int> coutData;
	for (int i = 0; i <= d; ++i)
		coutData.push_back(0);
	// �������飬ͳ��ÿ�������ֵĴ���
	for (int i = 0; i < Vec.size(); ++i)
		++coutData[Vec[i] - min];
	// ͳ�����������Σ������Ԫ�ص���ǰ���Ԫ��֮��
	for (int i = 1; i <= d; ++i)
		coutData[i] += coutData[i - 1];
	// �������ԭʼ���У���ͳ�������ҵ���ȷ��λ�ã�������������
	for (int i = Vec.size() - 1; i >= 0; i--)
	{
		Temp[coutData[Vec[i] - min] - 1] = Vec[i];        // �ҵ�Vec[i]��Ӧ��coutData��ֵ��ֵΪ���٣���ʾԭ��������٣�����Ϊ��1��ʼ�������ټ�1��
		coutData[Vec[i] - min]--;        // Ȼ����Ӧ��coutData��ֵ��1����ʾ�´���������ֵʱ��ԭ���������Ƕ��١�
	}
}

//1.9Ͱ����
void Sort_Algorithms::Bucket_Sort()
{
	int max = Temp[0];
	int min = Temp[0];
	// ȷ��Ԫ�ص���ֵ
	for (auto it : Temp)
	{
		if (it > max)	max = it;
		if (it < min)	min = it;
	}

	// Ͱ��: (max - min) / array.length�Ľ��Ϊ�����С�ı���������������Ա�����ΪͰ��
	// ��ע��1�������д�Сvec.size()�Ƚ�С����Ԫ��ֵ�ܴ��ҷ�ɢ(max - min�Ƚϴ�)������ɺܶࡰ��Ͱ��, ����ϵͳ����
	// ����(0, 13, 19892)����> �ܶࡰ��Ͱ��
	// ��ע��2����������������Ԫ�ظ����ܶ�(vec.size()�ܴ�), ����ÿ��Ԫ��ȴ�ֺ�Сʱ, ֻ��һ��Ͱ, ��������ȽϺ�ʱ
	int bucketNum = (max - min) / Temp.size() + 1;

	// ��ʼ��Ͱ, ����������ʵ��, Ҳ������vectorʵ��, ����ѡȡvectorʵ��, ԭ������
	// int** buckets = new int*[bucketNum];	// ����ʵ��Ͱ����Ҫ��ά����
	vector<vector<int> > vecBucket;	// vector����ʵ��Ͱ�����ƶ�ά����
	// Ͱ��ʼ��
	for (size_t i = 0; i < bucketNum; i++)
	{
		vector<int> vecTmp;
		vecBucket.push_back(vecTmp);
	}
	// ������ʵ��Ͱ��ʼ��
	// for (size_t i = 0; i < bucketNum; i++)
	// {
	// 	buckets[i] = new int[vec.size()];		// ÿ��Ͱ�����vec.size()��Ԫ��
	// }

	// ��������Ԫ�ذ��������ӦͰ��
	for (size_t i = 0; i < Temp.size(); i++)
	{
		// �����桾ע�⡿��Ͽ������ֻ��1��Ͱ, Ҫ�ֿ�����
		if (bucketNum == 1)
		{
			vecBucket[0].push_back(Temp[i]);
		}
		else
		{
			int bucketIndex = (Temp[i] - min) / bucketNum;	// ȷ��������ĸ�Ͱ			
			bucketIndex = bucketIndex >= bucketNum ? bucketNum - 1 : bucketIndex;
			vecBucket[bucketIndex].push_back(Temp[i]);	// ������vectorʵ��Ͱ�ĺô�, ֱ�ӡ��ӡ��ں����Զ����ݼ���, ����ʵ�ֻ�����봦��
		}
	}

	Temp.clear();
	// ������Ͱ��ϡ�, ��ÿ��Ͱ��Ԫ������
	// ÿ��ͰԪ��������, ��������Ͱ��ϡ��ӡ����С����Ͱ����������Ŵ󡱵�Ͱ����Ϊ������������
	for (vector<vector<int> >::iterator iter = vecBucket.begin(); iter != vecBucket.end(); iter++)
	{
		vector<int> vecTmp = *iter;		// *iterҲ��һ��vector, �ڲ�����˸�Ͱ��Ԫ��
		if (vecTmp.size() <= 0)
		{
			continue;
		}

		// ��ÿ��Ͱ��������, �������ѡ������
		// ��n��Сʱ�����ȶ��Բ���Ҫ��ʱ����ѡ������
		Selection_Sort(vecTmp);
		// InsertSort(vecTmp);	// ����Ȥ����Ҳ�������ò������򿴿���ʱ
		for (auto it : vecTmp)
		{
			// ÿ��Ͱ��Ԫ�������, ���¸�vec��ֵ, ��ʱvec����
			Temp.push_back(it);
		}
	}

}

//1.10��������
int Sort_Algorithms::Max_Bit(vector<int>& data) {
	int d = 1; //��������λ��
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
void Sort_Algorithms::Radix_Sort() {   //��������
	int d = Max_Bit(Temp);
	vector<int>temp;
	temp.assign(Temp.begin(), Temp.end());
	int count[10]; //������
	int i, j, k;
	int radix = 1;
	for (i = 1; i <= d; i++) //����d������
	{
		for (j = 0; j < 10; j++)
			count[j] = 0; //ÿ�η���ǰ��ռ�����
		for (j = 0; j < Temp.size(); j++)
		{
			k = (Temp[j] / radix) % 10; //ͳ��ÿ��Ͱ�еļ�¼��
			count[k]++;
		}
		for (j = 1; j < 10; j++)
			count[j] = count[j - 1] + count[j]; //��tmp�е�λ�����η����ÿ��Ͱ
		for (j = Temp.size() - 1; j >= 0; j--) //������Ͱ�м�¼�����ռ���tmp��
		{
			k = (Temp[j] / radix) % 10;
			temp[count[k] - 1] = Temp[j];
			count[k]--;
		}
		for (j = 0; j < Temp.size(); j++) //����ʱ��������ݸ��Ƶ�data��
			Temp[j] = temp[j];
		radix = radix * 10;
	}
}

void Test6() {
	srand(time(nullptr));
	Sort_Algorithms T;
	DWORD t1 = NULL, t2 = NULL;  //���ڼ�¼�㷨����ʱ��
	int select;
	while (1) {
		Menu();
		cin >> select;
		switch (select)
		{
		case 0:  //�˳�
			system("pause");
			return;
			break;
		case 1:  //��������
			cout << "���ǽ��ᴴ��n������������㷨����(������n)\n";
			cout << "n  -- >";
			int num, Size;
			cin >> num;
			cout << "�����������������ģ0��(Size-1)\n";
			cout << "Size  -- >";
			cin >> Size;
			T.Build_Vector(num, Size);
			break;
		case 2:  //����ԭ����
			T.TraverseVector1();
			break;
		case 3: //��������������
			T.TraverseVector2();
			break;
		case 4:   //ð������
			T.Temp.assign(T.Vec.begin(), T.Vec.end());  //ÿ�������껹ԭ(�����ⲿ��ԭ���ǿ��Ը���ȷ�Ĳ����㷨���ٶ�)
			//ȡ��ǰʱ��
			t1 = GetTickCount();
			T.Bubble_Sort();  //ð������
			//ȡ��ǰʱ��
			t2 = GetTickCount();
			cout << "\n��ǰ��ʱ:" << t2 - t1 << "ms\n";
			system("pause");
			system("cls");
			break;
		case 5:  //ѡ������
			T.Temp.assign(T.Vec.begin(), T.Vec.end());  //ÿ�������껹ԭ(�����ⲿ��ԭ���ǿ��Ը���ȷ�Ĳ����㷨���ٶ�)
			//ȡ��ǰʱ��
			t1 = GetTickCount();
			T.Selection_Sort();  //ѡ������
			//ȡ��ǰʱ��
			t2 = GetTickCount();
			cout << "\n��ǰ��ʱ:" << t2 - t1 << "ms\n";
			system("pause");
			system("cls");
			break;
		case 6:  //��������
			T.Temp.assign(T.Vec.begin(), T.Vec.end());  //ÿ�������껹ԭ(�����ⲿ��ԭ���ǿ��Ը���ȷ�Ĳ����㷨���ٶ�)
			//ȡ��ǰʱ��
			t1 = GetTickCount();
			T.Insertion_Sort();  //��������
			//ȡ��ǰʱ��
			t2 = GetTickCount();
			cout << "\n��ǰ��ʱ:" << t2 - t1 << "ms\n";
			system("pause");
			system("cls");
			break;
		case 7:  //ϣ������
			T.Temp.assign(T.Vec.begin(), T.Vec.end());  //ÿ�������껹ԭ(�����ⲿ��ԭ���ǿ��Ը���ȷ�Ĳ����㷨���ٶ�)
			//ȡ��ǰʱ��
			t1 = GetTickCount();
			T.Shell_Sort();  //ϣ������
			//ȡ��ǰʱ��
			t2 = GetTickCount();
			cout << "\n��ǰ��ʱ:" << t2 - t1 << "ms\n";
			system("pause");
			system("cls");
			break;
		case 8:  //�鲢����
			T.Temp.assign(T.Vec.begin(), T.Vec.end());  //ÿ�������껹ԭ(�����ⲿ��ԭ���ǿ��Ը���ȷ�Ĳ����㷨���ٶ�)
			//ȡ��ǰʱ��
			t1 = GetTickCount();
			T.Merge_Sort(0, T.Vec.size() - 1);  //�鲢����
			//ȡ��ǰʱ��
			t2 = GetTickCount();
			cout << "\n��ǰ��ʱ:" << t2 - t1 << "ms\n";
			system("pause");
			system("cls");
			break;
		case 9:  //��������
			T.Temp.assign(T.Vec.begin(), T.Vec.end());  //ÿ�������껹ԭ(�����ⲿ��ԭ���ǿ��Ը���ȷ�Ĳ����㷨���ٶ�)
			//ȡ��ǰʱ��
			t1 = GetTickCount();
			T.Quick_Sort(0, T.Temp.size() - 1);  //��������
			//ȡ��ǰʱ��
			t2 = GetTickCount();
			cout << "\n��ǰ��ʱ:" << t2 - t1 << "ms\n";
			system("pause");
			system("cls");
			break;
		case 10:
			T.Temp.assign(T.Vec.begin(), T.Vec.end());  //ÿ�������껹ԭ(�����ⲿ��ԭ���ǿ��Ը���ȷ�Ĳ����㷨���ٶ�)
			//ȡ��ǰʱ��
			t1 = GetTickCount();
			T.Heap_Sort(T.Temp.size());  //������
			//ȡ��ǰʱ��
			t2 = GetTickCount();
			cout << "\n��ǰ��ʱ:" << t2 - t1 << "ms\n";
			system("pause");
			system("cls");
			break;
		case 11:
			T.Temp.assign(T.Vec.begin(), T.Vec.end());  //ÿ�������껹ԭ(�����ⲿ��ԭ���ǿ��Ը���ȷ�Ĳ����㷨���ٶ�)
			//ȡ��ǰʱ��
			t1 = GetTickCount();
			T.Count_Sort();  //��������
			//ȡ��ǰʱ��
			t2 = GetTickCount();
			cout << "\n��ǰ��ʱ:" << t2 - t1 << "ms\n";
			system("pause");
			system("cls");
			break;
		case 12:
			T.Temp.assign(T.Vec.begin(), T.Vec.end());  //ÿ�������껹ԭ(�����ⲿ��ԭ���ǿ��Ը���ȷ�Ĳ����㷨���ٶ�)
			//ȡ��ǰʱ��
			t1 = GetTickCount();
			T.Bucket_Sort();  //Ͱ����
			//ȡ��ǰʱ��
			t2 = GetTickCount();
			cout << "\n��ǰ��ʱ:" << t2 - t1 << "ms\n";
			system("pause");
			system("cls");
			break;
		case 13:
			T.Temp.assign(T.Vec.begin(), T.Vec.end());  //ÿ�������껹ԭ(�����ⲿ��ԭ���ǿ��Ը���ȷ�Ĳ����㷨���ٶ�)
			//ȡ��ǰʱ��
			t1 = GetTickCount();
			T.Radix_Sort();  //��������
			//ȡ��ǰʱ��
			t2 = GetTickCount();
			cout << "\n��ǰ��ʱ:" << t2 - t1 << "ms\n";
			system("pause");
			system("cls");
			break;
		case 14:{
			cout << "���ǽ��ᴴ��n����������\n";
			cout << "n  -- >";
			int num;
			cin >> num;
			T.Build_TVector(num);
			break;
		}
		case 15: {
			cout << "��������Ҫ��ѯ����Num\n";
			cout << "Num  -->";
			int Num;
			cin >> Num;
			if (T.Search(Num)) {
				cout << "��ѯ�ɹ�" << endl;
			}
			else {
				cout << "��ѯʧ��" << endl;
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

void Menu() {  //����
	cout << "\t�������ֽ���ѡ��:\n";
	cout << "\t1.���������������������в���\n";
	cout << "\t2.����ԭ������\n";
	cout << "\t3.�������������\n";
	cout << "\t4.ð������\n";
	cout << "\t5.ѡ������\n";
	cout << "\t6.��������\n";
	cout << "\t7.ϣ������\n";
	cout << "\t8.�鲢����\n";
	cout << "\t9.��������\n";
	cout << "\t10.������\n";
	cout << "\t11.��������\n";
	cout << "\t12.Ͱ����\n";
	cout << "\t13.��������\n";
	cout << "\t14.����n�����������\n";
	cout << "\t15.����ĳ�����������н��в�ѯ(��ѯʧ�ܷ���0)\n";
	cout << "\t0.�˳�\n";
	cout << "\t-->";
}

bool Sort_Algorithms::Search(int Num) {
	int Lim = 0;
	for (int i = 0; i < Vec.size(); i++) {
		if (Vec[i] == Num) {
			Lim++;
			cout << "�����ڸ������ǵ�" << i+1 << "����  ��ֵΪ" << Num << endl;
		}
	}
	if (Lim > 0) {
		return true;
	}
	else {
		return false;
	}
}