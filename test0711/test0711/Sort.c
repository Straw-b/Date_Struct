#include "Sort.h"
#include <stdio.h>
#include "Stack.h"


//��ӡ
void PrintArray(int array[], int size)
{
	for (int i = 0; i < size; ++i)
		printf("%d ", array[i]);
	printf("\n");

}


// ֱ�Ӳ�������
// ��������������У�û��ʹ�ö���ĸ����ռ䣬�ռ临�Ӷȣ�O(1)
// ʱ�临�Ӷȣ�O(N^2)
// �ȶ��ԣ��ȶ�
void InsertSort(int array[], int size)
{
	//ע�⣺i��1��ʼ--->ԭ��
	// ���ѭ�����ƣ��ж��ٸ�������Ҫ����size-1
	for (int i = 1; i < size; ++i)
	{
		// ģ�ⵥ��Ԫ�صĲ������
		int key = array[i];
		int end = i - 1;

		// �Ҵ�����Ԫ���������е�λ��
		// �������£���Ҫ��iλ��֮ǰ���е�Ԫ������������а��ƣ���ʱ�临�Ӷ�ΪO(N)
		while (end >= 0 && key < array[end])
		{
			array[end + 1] = array[end];
			end--;
		}

		//����Ԫ��
		array[end + 1] = key;
	}
}


// ϣ������
// ʱ�临�Ӷȣ�O(N^1.25)--O(1.6N^1.25)
// �ռ临�Ӷȣ�O(1)
// �ȶ��ԣ����ȶ�
void ShellSort(int array[], int size)
{
	int gap = size; // �±�ļ��
	while (gap > 1)
	{
		// gap /= 2 ���� gapÿ��ȡ���� 
		gap = gap / 3 + 1;

		// ע�⣺i��gap��ʼ
		for (int i = gap; i < size; ++i)
		{
			// ģ�ⵥ��Ԫ�صĲ������
			int key = array[i];
			int end = i - gap;

			// �Ҵ�����Ԫ���������е�λ��
			while (end >= 0 && key < array[end])
			{
				array[end + gap] = array[end];
				end -= gap;
			}

			//����Ԫ�أ����뵽��ǰ�������һ��λ��
			array[end + gap] = key;
		}
	}
}


// ����
void Swap(int* left, int* right)
{
	int temp = *left;
	*left = *right;
	*right = temp;
}

// ѡ������
// ʱ�临�Ӷȣ�O(N^2)
// �ռ临�Ӷȣ�O(1)
// �ȶ��ԣ����ȶ�
void SelectSort(int array[], int size)
{
	for (int i = 0; i < size - 1; ++i)
	{
		// �ҵ�ǰ���������Ԫ�ص�λ��
		int maxPos = 0;
		for (int j = 1; j < size - i; ++j)
		{
			if (array[j] > array[maxPos])
				maxPos = j;
		}

		// ����
		if (maxPos != size - i - 1)
		{
			Swap(&array[maxPos], &array[size - i - 1]);
		}
	}
}

// ѡ������ĸĽ�
void SelectSortOP(int array[], int size)
{
	int begin = 0, end = size - 1; // [begin end]
	while (begin < end)
	{
		// ��[begin end]��������������С��Ԫ��
		int maxPos = begin, minPos = begin;
		int  j = begin + 1;

		while (j <= end)
		{
			if (array[j] > array[maxPos])
				maxPos = j;

			if (array[j] < array[minPos])
				minPos = j;

			++j;
		}

		// ������Ԫ�ز�����������λ��
		if (maxPos != end)
		{
			Swap(&array[maxPos], &array[end]);
		}

		// ���endλ�ô洢�ĸպ�����СԪ�أ�����Ľ����ͽ���С��λ�ø�����
		// ��СԪ�ص�λ�÷����ı䣬��������minPos
		if (minPos == end)
			minPos = maxPos;

		// �����СԪ�ز���������ʼ���λ��
		if (minPos != begin)
		{
			Swap(&array[minPos], &array[begin]);
		}

		++begin;
		--end;
	}
}


// ���µ���
void HeapAdjustDwon(int array[], int size, int parent)
{
	// ��child���parent�ϴ�ĺ��ӣ�Ĭ���ȱ��parent������
	// �ȱ�����ӵ�ԭ���ǣ����parent�к��ӣ�һ�����������ӣ�Ȼ������Һ���
	int child = parent * 2 + 1;

	while (child < size)
	{
		// ��parent�нϴ�ĺ��ӣ���parent���Һ��ӱȽ�
		// �����ȱ�֤parent���Һ��Ӵ���
		if (child + 1 < size && array[child + 1] > array[child])
			child += 1;

		// ���parent�Ƿ�����ѵ�����
		if (array[child] > array[parent])
		{
			Swap(&array[child], &array[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			return;
		}
	}
}

// ������
// ʱ�临�Ӷȣ�O(Nlog2N)
// �ռ临�Ӷȣ�O(1)
// �ȶ��ԣ����ȶ�
void HeapSort(int array[], int size)
{
	int end = size - 1;
	// 1.���ѣ����򽨴�ѣ�����С��
	// �ӵ�����һ����Ҷ�ӽڵ��λ�ÿ�ʼʹ�öѵ�����һֱ���������ڵ��λ��
	for (int root = (size - 2) / 2; root >= 0; root--)
		HeapAdjustDwon(array, size, root);// ���µ���--->ʱ�临�Ӷȣ�O(log2N)

	// 2.����-->���ö�ɾ����˼������
	while (end)
	{
		Swap(&array[0], &array[end]);
		HeapAdjustDwon(array, end, 0);
		end--;
	}
}


// ð������
// ʱ�临�Ӷȣ�O(N^2)
// �ռ临�Ӷȣ�O(1)
// �ȶ��ԣ��ȶ�
void BubbleSort(int array[], int size)
{
	//����ð������
	for (int i = 0; i < size - 1; ++i)  //-1��Ŀ���ǿ�����ðһ�ˣ���Ϊ���һ��ð������ֻʣ��һ��Ԫ��
	{
		//����ð�ݵķ�ʽ��������λ�õ�Ԫ�ؽ��бȽϣ�����������������ͽ��н���

		////��ʽһ��j����ʾǰһ��Ԫ�ص��±�
		//for (int j = 0; j < size - i - 1; ++j) //-1��Ŀ�ģ�j���ֻ��ȡ��ð������ĵ����ڶ���Ԫ��
		//{
		//	if (array[j] > array[j + 1])
		//		Swap(&array[j], &array[j + 1]);
		//}

		//��ʽ����j����ʾ��һ��Ԫ�ص��±꣬jҪȡ�����һ��Ԫ��
		for (int j = 1; j < size - i; ++j)
		{
			if (array[j - 1] > array[j])
				Swap(&array[j - 1], &array[j]);
		}
	}
}

// �Ľ�
void BubbleSortOP(int array[], int size)
{
	int flag = 0;
	//����ð������
	for (int i = 0; i < size - 1; ++i)  //-1��Ŀ���ǿ�����ðһ�ˣ���Ϊ���һ��ð������ֻʣ��һ��Ԫ��
	{
		//����ð�ݵķ�ʽ��������λ�õ�Ԫ�ؽ��бȽϣ�����������������ͽ��н���
		flag = 0; //����ð�ݻ�û�бȽϣ���˽�flag����Ϊ0
		for (int j = 1; j < size - i; ++j)  //j����ʾ��һ��Ԫ�ص��±꣬jҪȡ�����һ��Ԫ��
		{
			if (array[j - 1] > array[j])
			{
				Swap(&array[j - 1], &array[j]);
				flag = 1; //�ڸ���ð��ʱ���仹����
			}
		}
		if (!flag)
			return;
	}
}



// ����ȡ�з�����������ȡ���м��������Ϊ��׼ֵ
int GetMiddleIndex(int array[], int left, int right)
{
	int mid = left + ((right - left) >> 1);
	// �������ݣ�left��mid��right-1��
	if (array[left] < array[right - 1])
	{
		if (array[mid] < array[left])
			return left;
		else if (array[mid] > array[right - 1])
			return right - 1;
		else
			return mid;
	}
	else
	{
		if (array[mid] > array[left])
			return left;
		else if (array[mid] < array[right - 1])
			return right - 1;
		else
			return mid;
	}
}

// ��׼ֵ�ָ�
// 1.hoare�����������˼�����
int Partion1(int array[], int left, int right)
{
	int begin = left;
	int end = right - 1;
	int keyofindex = GetMiddleIndex(array, left, right); // ����ȡ�з�
	if (keyofindex != right - 1)
		Swap(&array[keyofindex], &array[right - 1]);
	int key = array[right - 1];

	while (begin < end)
	{
		//��begin��ǰ�����ң��ұȻ�׼ֵ���Ԫ�أ��ҵ��˾�ͣ����
		while (begin < end && array[begin] <= key) // ��ֹԽ��
			begin++;

		//��end�Ӻ������ң��ұȻ�׼ֵС��Ԫ�أ��ҵ��˾�ͣ����
		while (begin < end && array[end] >= key) // ��ֹԽ��
			end--;

		if (begin < end) // ����ͬһ��λ��
			Swap(&array[begin], &array[end]);
	}

	if (begin != right - 1) // ��ֹbegin��end��key�����λ��
		Swap(&array[begin], &array[right - 1]);

	return begin;
}

// 2.�ڿӷ�
int Partion2(int array[], int left, int right)
{
	int begin = left;
	int end = right - 1;
	int keyofindex = GetMiddleIndex(array, left, right); // ����ȡ�з�
	if (keyofindex != right - 1)
		Swap(&array[keyofindex], &array[right - 1]);
	int key = array[right - 1];

	while (begin < end)
	{
		//endλ���γ���һ���µĿ�
		//��begin��ǰ�����ң��ұȻ�׼ֵ���Ԫ��
		while (begin < end && array[begin] <= key)
			begin++;
		//��beginλ�ô��Ԫ����endλ�õĿ�
		if (begin < end)
		{
			array[end] = array[begin];
			end--;
		}

		//beginλ���γ���һ���µĿ�
		//��end�Ӻ���ǰ�ң��ұȻ�׼ֵС��Ԫ��
		while (begin < end && array[end] >= key)
			end--;
		//��endλ��С��Ԫ����beginλ�õĿ�
		if (begin < end)
		{
			array[begin] = array[end];
			begin++;
		}
	}

	//�û�׼ֵ�����ͣ������һ����
	array[begin] = key;

	return begin;
}

// 3.ǰ��ָ�뷨
int Partion3(int array[], int left, int right)
{
	int cur = left;
	int prev = cur - 1;
	int keyofindex = GetMiddleIndex(array, left, right); // ��������ȡ�з�����ȡ����ֵ�ĸ���
	if (keyofindex != right - 1)
		Swap(&array[keyofindex], &array[right - 1]);
	int key = array[right - 1];

	while (cur < right)
	{
		if (array[cur] < key && ++prev != cur)
			Swap(&array[cur], &array[prev]);
		++cur;
	}

	if (++prev != right - 1) // ��ֹcur��prev��key�����λ��
		Swap(&array[right - 1], &array[prev]);

	return prev;
}

// ��������
// ʱ�临�Ӷȣ�O(N^2)
// �ռ临�Ӷȣ�O(1)
// �ȶ��ԣ����ȶ�
// [left,right)��ʾ������Ԫ�ص�����
void QuickSort(int array[], int left, int right)
{
	// �趨��ֵ��С����ֵʱʹ�ò����������Ż�
	if (right - left < 16) 
	{
		InsertSort(array + left, right - left);
	}
	else
	{
		// Partion���ջ�׼ֵ������л��ֳ������֣��󲿷�Ԫ�رȻ�׼ֵС���Ҳ��ֱȻ�׼ֵ��
		// �ú������ػ�׼ֵ�������е�λ��
		// [left,right)�����еĻ�׼ֵλ���Ѿ���ź��ˣ���׼ֵ���ͻ�׼ֵ�Ҳ಻һ������
		//int div = Partion1(array, left, right); // hoare��
		//int div = Partion2(array, left, right); // �ڿӷ�
		int div = Partion3(array, left, right); // ǰ��ָ�뷨

		//��׼ֵ����ࣺ[left, div)
		QuickSort(array, left, div);

		//��׼ֵ���Ҳࣺ[div + 1, right)
		QuickSort(array, div + 1, right);
	}
}



// ��������ǵݹ�
// ��ջ�����ݹ�ת��Ϊѭ��
void QuickSortNor(int array[], int size)
{
	int left = 0;
	int right = size;
	Stack s;
	StackInit(&s); // ��ʼ��
	StackPush(&s, right); // �Ƚ������size
	StackPush(&s, left); // ����ȳ���0
	
	while (!StackEmpty(&s))
	{
		// �Ȱ��ջ�׼ֵ�����л���
		left = StackTop(&s); // ��ȡջ��Ԫ�أ���ȡ��0
		StackPop(&s); // ��ջ��βɾ
		right = StackTop(&s); // size
		StackPop(&s); // ��ջ��βɾ

		if (right - left > 1) // ������
		{
			int div = Partion1(array, left, right); // hoare���Ȼ�������
			
			// ����ջ����������
			// �Ż�׼ֵ������-->���Ұ벿�ֵ�������ջ[div+1,right)
			StackPush(&s, right); // ѹ�Ұ벿�ֵ��Ұ����ջ��β��
			StackPush(&s, div + 1); // ѹ�Ұ벿�ֵ�����
			// �Ż�׼ֵ���Ұ��-->����벿�ֵ�������ջ[left,div)
			StackPush(&s, div); // ѹ��벿�ֵ��Ұ����ջ��β��
			StackPush(&s, left); // ѹ��벿�ֵ�����
		}
	}
	StackDestroy(&s);
}








////////////////////////////////////////////////////////////////////
void TestSort()
{
	int array[] = { 4, 1, 7, 6, 3, 9, 5, 8, 0, 2 };
	//int array[] = { 4, 1, 7, 6, 3, 9, 2, 8, 0, 5 };
	PrintArray(array, sizeof(array) / sizeof(array[0]));

	//InsertSort(array, sizeof(array) / sizeof(array[0]));
	//ShellSort(array, sizeof(array) / sizeof(array[0]));
	//SelectSort(array, sizeof(array) / sizeof(array[0]));
	//SelectSortOP(array, sizeof(array) / sizeof(array[0]));
	//HeapSort(array, sizeof(array) / sizeof(array[0]));
	//BubbleSort(array, sizeof(array) / sizeof(array[0]));
	//BubbleSortOP(array, sizeof(array) / sizeof(array[0]));
	//QuickSort(array, 0, sizeof(array) / sizeof(array[0]));
	QuickSortNor(array, sizeof(array) / sizeof(array[0]));

	PrintArray(array, sizeof(array) / sizeof(array[0]));
}


