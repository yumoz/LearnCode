#include<stdio.h>
#include<windows.h>

//位运算解决

//int missingNumber(int* nums, int numsSize){
//	if (!nums || !numsSize)  return 0;
//	int ans = nums[0];
//	ans ^= 0;
//	ans ^= numsSize;
//	for (int i = 1; i < numsSize; i++) {
//		ans ^= nums[i];
//		ans ^= i;
//	}
//	return ans;
//}

int missingNumber(int* nums, int numsSize){
	if (!nums || !numsSize)  return 0;
	int ans = 0;
	ans ^= numsSize;
	for (int i = 0; i < numsSize; i++) {
		ans ^= nums[i];
		ans ^= i;
	}
	return ans;
}

int main()
{
	int numArray[] = { 1, 3, 0, 4, 2, 6, 7 };//缺5
	int len = sizeof(numArray) / sizeof(numArray[0]);
	printf("missing number: %d\n",missingNumber(numArray, len));
	system("pause");
	return 0;
}

#if 0
int missingNumber(int* nums, int numsSize) {
	int ret = numsSize;
	for (int i = 0; i < numsSize; i++)
		ret ^= nums[i] ^ i;
	return ret;
}
#endif
#if 0
int missingNumber(int* nums, int numsSize){
	int sum = 0, i;
	for (i = 0; i < numsSize; i++){
		sum += nums[i];
	}
	return ((numsSize * (1 + numsSize)) / 2) - sum;
}
#endif

#if 0
//排序方法解决missing number问题
int get_mid(int* p, int left, int right)
{
	int pivot = p[left];
	while (left < right)
	{
		while (p[right] >= pivot && left < right)
			right--;
		p[left] = p[right];
		while (p[left] <= pivot && left < right)
			left++;
		p[right] = p[left];
	}
	p[left] = pivot;
	return left;
}
//排序 
//指针变量p用来接收数组的地址
void Quick_sort(int* p, int left, int right)
{
	if (left < right)//如果左边的小于右边的数组元素
	{
		int mid = get_mid(p, left, right);
		Quick_sort(p, left, mid - 1);
		Quick_sort(p, mid + 1, right);
	}
}

//查找消失的数字
//nums :用指针来接收实参中的地址
//numSize：用整形变量来接收数组长度
int missingNumber(int* nums, int numsSize) {
	Quick_sort(nums, 0, numsSize - 1);
	for (int i = 0; i < numsSize; i++)
	{
		if (nums[i] != i)
			return i;
	}
	return numsSize;
}

int main()
{
	int numArray[] = { 1, 3, 0, 4, 2, 6, 7 };//缺5
	int len = sizeof(numArray) / sizeof(numArray[0]);
	printf("missing number: %d\n",missingNumber(numArray, len));
	system("pause");
	return 0;
}
#endif