#define _CRT_SECURE_NO_WARNINGS 1

//�������������
//1. ԭ���Ƴ����������е�Ԫ��val��Ҫ��ʱ�临�Ӷ�ΪO(N)���ռ临�Ӷ�ΪO(1)
int removeElement(int* nums, int numsSize, int val)
{
	int count = 0;//��¼val����
	for (int i = 0; i < numsSize; ++i)
	{
		if (nums[i] == val)
			count++;
		else
			nums[i - count] = nums[i];
	}
	return numsSize - count;
}

//2. ɾ�����������е��ظ���
int removeDuplicates(int* nums, int numsSize)
{
	int count = 0;
	if (numsSize < 2)
		return numsSize;
	for (int i = 1; i < numsSize; ++i)
	{
		if (nums[count] != nums[i])
			nums[++count] = nums[i];
	}
	return ++count;
}

//3. �ϲ�������������
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
	int index = m + n - 1; //���Ԫ����nums1�еĴ洢λ��
	//n>0����ʾnum2�л���Ԫ��δ����
	while (n > 0)
	{
		if (m > 0 && nums1[m - 1] > nums2[n - 1])
		{
			nums1[index--] = nums1[m - 1];
			m--;
		}
		else
		{
			nums1[index--] = nums2[n - 1];
			n--;
		}
	}
}

//4. ��ת����


//5. ������ʽ�������ӷ�

