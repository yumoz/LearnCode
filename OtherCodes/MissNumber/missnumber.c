#include<stdio.h>
#include<windows.h>

#if 0
int missingNumber(int* nums, int numsSize){
	if (!nums || !numsSize)  return 0;
	int ans = nums[0];
	ans ^= 0;
	ans ^= numsSize;
	for (int i = 1; i < numsSize; i++) {
		ans ^= nums[i];
		ans ^= i;
	}
	return ans;
}
#endif
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
void Quick_sort(int* p, int left, int right)
{
	if (left < right)
	{
		int mid = get_mid(p, left, right);
		Quick_sort(p, left, mid - 1);
		Quick_sort(p, mid + 1, right);
	}
}

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
	int numArray[] = { 1, 3, 0, 4, 2, 6, 7 };
	int num = sizeof(numArray) / sizeof(numArray[0]);
	printf("missing number: %d\n",missingNumber(numArray, num));
	system("pause");
	return 0;
}