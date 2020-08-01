void _MergeSort(int* a, int left, int right, int* tmp)
{
	if (left >= right)
		return;

	int mid = left + ((right - left) >> 1);

	// [left, mid]
	// [mid+1, right]
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid + 1, right, tmp);

	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int index = left;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] <= a[begin2])
			tmp[index++] = a[begin1++];
		else
			tmp[index++] = a[begin2++];
	}

	while (begin1 <= end1)
	{
		tmp[index++] = a[begin1++];
	}

	while (begin2 <= end2)
	{
		tmp[index++] = a[begin2++];
	}

	memcpy(a + left, tmp + left, sizeof(int)*(right - left + 1));
}


void MergeSort(int* a, int n)
{
	assert(a);
	int* tmp = (int*)malloc(sizeof(int)*n);
	_MergeSort(a, 0, n - 1, tmp);
	free(tmp);
}

/*
�ǵݹ�������ݹ������෴����һ��Ԫ��������Ԫ�ع����������飬
�����Ա����鹹���������飬ֱ��������������
Ҫ��midָ�봫�룬��Ϊ����һ������ʱ�����¼���mid���ֻ�������
��Ҫָ��mid��λ��
*/
void merge(int* a, int left, int mid, int right, int* tmp)
{
	// [left, mid]
	// [mid+1, right]
	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int index = left;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] <= a[begin2])
			tmp[index++] = a[begin1++];
		else
			tmp[index++] = a[begin2++];
	}

	while (begin1 <= end1)
	{
		tmp[index++] = a[begin1++];
	}

	while (begin2 <= end2)
	{
		tmp[index++] = a[begin2++];
	}

	memcpy(a + left, tmp + left, sizeof(int)*(right - left + 1));
}

/*
k������ʾÿ��k��Ԫ�ع鲢
*/
void mergePass(int *arr, int k, int n, int *temp)
{
	int i = 0;
	//��ǰ����,��2������Ϊk�������кϲ�Ϊ1��
	while (i < n - 2 * k + 1)
	{
		merge(arr, i, i + k - 1, i + 2 * k - 1, temp);
		i += 2 * k;
	}
	//�ϲ�����[i, n - 1]�������벿��[i, i + k - 1]�Լ�����һ���������Ұ벿��[i + k, n - 1]
	if (i < n - k)
	{
		merge(arr, i, i + k - 1, n - 1, temp);
	}

}

// �鲢����ǵݹ��
void MergeSortNonR(int *arr, int length)
{
	int k = 1;
	int *temp = (int *)malloc(sizeof(int)* length);
	while (k < length)
	{
		mergePass(arr, k, length, temp);
		k *= 2;
	}
	free(temp);
}

void TestMergeSort()
{
	int a[] = { 3, 4, 6, 1, 2, 8, 0, 5, 7 };
	MergeSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

// O(Max(N, ��Χ))
// O(N+��Χ) ʱ�临�Ӷ�
// O(��Χ) �ռ临�Ӷ�
void CountSort(int* a, int n)
{
	int max = a[0], min = a[0];
	for (int i = 0; i < n; ++i)
	{
		if (a[i] > max)
			max = a[i];

		if (a[i] < min)
			min = a[i];
	}
	//�ҵ����ݵķ�Χ
	int range = max - min + 1;
	int* countArray = (int*)malloc(range*sizeof(int));
	memset(countArray, 0, sizeof(int)*range);
	//��������λ�ã����Խ�ʡ�ռ�
	for (int i = 0; i < n; ++i)
	{
		countArray[a[i] - min]++;
	}
	//���ܴ����ظ������ݣ��м����漸��
	int index = 0;
	for (int i = 0; i < range; ++i)
	{
		while (countArray[i]--)
		{
			a[index++] = i + min;
		}
	}
}

void TestCountSort()
{
	int a[] = { 3, 4, 6, 2, 8, 5, 2, 2, 9, 9, 1000000, 99999 };
	CountSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

void TestSortOP()
{
	const int n = 1000000;
	int* a1 = (int*)malloc(sizeof(int)*n);
	int* a2 = (int*)malloc(sizeof(int)*n);
	int* a3 = (int*)malloc(sizeof(int)*n);
	int* a4 = (int*)malloc(sizeof(int)*n);
	int* a5 = (int*)malloc(sizeof(int)*n);
	int* a6 = (int*)malloc(sizeof(int)*n);
	int* a7 = (int*)malloc(sizeof(int)*n);
	int* a8 = (int*)malloc(sizeof(int)*n);

	srand(time(0));
	for (int i = 0; i < n; ++i)
	{
		a1[i] = rand();
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
		a7[i] = a1[i];
		a8[i] = a1[i];
	}
	a8[n] = 100000000;

	size_t begin1 = clock();
	//InsertSort(a1, n);
	size_t end1 = clock();
	printf("%u\n", end1 - begin1);

	size_t begin2 = clock();
	ShellSort(a2, n);
	size_t end2 = clock();
	printf("%u\n", end2 - begin2);

	size_t begin3 = clock();
	//SelectSort(a3, n);
	size_t end3 = clock();
	printf("%u\n", end3 - begin3);

	size_t begin4 = clock();
	HeapSort(a4, n);
	size_t end4 = clock();
	printf("%u\n", end4 - begin4);

	size_t begin5 = clock();
	//BubbleSort(a5, n);
	size_t end5 = clock();
	printf("%u\n", end5 - begin5);

	size_t begin6 = clock();
	QuickSort(a6, 0, n - 1);
	size_t end6 = clock();
	printf("%u\n", end6 - begin6);

	size_t begin7 = clock();
	MergeSort(a7, n);
	size_t end7 = clock();
	printf("%u\n", end7 - begin7);

	size_t begin8 = clock();
	CountSort(a8, n);
	size_t end8 = clock();
	printf("%u\n", end8 - begin8);
}
