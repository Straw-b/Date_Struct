#define _CRT_SECURE_NO_WARNINGS 1

//数组相关面试题
//1. 原地移除数组中所有的元素val，要求时间复杂度为O(N)，空间复杂度为O(1)
int removeElement(int* nums, int numsSize, int val)
{
	int count = 0;//记录val个数
	for (int i = 0; i < numsSize; ++i)
	{
		if (nums[i] == val)
			count++;
		else
			nums[i - count] = nums[i];
	}
	return numsSize - count;
}

//2. 删除排序数组中的重复项
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

//3. 合并两个有序数组
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
	int index = m + n - 1; //最大元素在nums1中的存储位置
	//n>0：表示num2中还有元素未搬移
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

//4. 旋转数组


//5. 数组形式的整数加法

