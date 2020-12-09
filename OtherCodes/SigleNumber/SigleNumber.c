
/*
* 需求

一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。请写程序找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。
 
 示例 1：
 输入：nums = [4,1,4,6]
 输出：[1,6] 或 [6,1]
 示例 2：
 输入：nums = [1,2,10,4,1,4,3,3]
 输出：[2,10] 或 [10,2]
  

  限制：
  2 <= nums <= 10000

  gcc singleNumbers-I.c -g -o a.exe -DDEBUG
  */

#include <stdio.h>
#include <stdlib.h>
#include<windows.h>

//方法一
//
//int* singleNumbers(int* nums, int numsSize, int* returnSize){
//
//	//判断传参是否为空
//	if (NULL == nums || 0 == numsSize){
//		*returnSize = 0;
//		return NULL;
//	}
//	int * retp = NULL;
//	int featureCode = 0, seperator = 0, i = 0, x = 0, y = 0;
//
//	retp = (int *)malloc(2 * sizeof(int));
//	if (NULL == retp){//判断malloc成功与否
//		*returnSize = 0;
//		return NULL;
//	}
//	memset(retp, 0, 2 * sizeof(int));//将开辟的内存空间清零
//	*returnSize = 2;//???
//
//	//0^任何都为任何数，出现两次的数字被异或除掉,只剩出现一次的数字
//	//分离出来只剩下两个数字异或的内容
//	for (i = 0; i < numsSize; i++){
//		featureCode = featureCode ^ nums[i];
//	}
//
//	//接下来两个不同的数字的异或中分离出来 不同的数字
//
//	//取得最右侧的1的特征值，只会含有一个数字（不同为1），作为1个的特征值
//	//判断 featureCode=7，-7在内存中的存储方式，决定了我们从以下代码 & 按位与中取到的最右侧的 1 即为、
//	//0000 ... ... 0001
//	seperator = featureCode & (-featureCode);
//
//
//	//提取第一个数字
//	//此时 seperator 为1 
//	//如果 nums[i]=2 , 就会执行if语句中异或内容，于是就分离出来 2
//	for (i = 0; i < numsSize; i++){
//		/*出现2次的数字被^去掉了*/
//		if (0 != (nums[i] & seperator)){
//			x = x ^ nums[i];//分离出来x=1
//		}
//	}
//
//	/*通过^，把X从featureCode里面去掉，这剩下y*/
//	y = featureCode ^ x;
//	retp[0] = x;//1
//	retp[1] = y;//6
//
//	return retp;
//}


//方法2
int * singleNumbers(int * nums, int numsSize, int* returnSize)
{
	int ret = 0;
	//用0异或所有数组元素，找出只出现一次元素的异或结果
	for (int i = 0; i < numsSize; i++){
		ret ^= nums[i];
	}

	//找出ret的第m位
	int m = 0;
	while (m < 32){
			{
				if (ret&(1 << m))
					break;
				else
					++m;
			}

		//分离
		int x1 = 0, x2 = 0;
		for (int i = 0; i < numsSize; i++)
		{
			if (nums[i] & (1 << m)){
				x1 ^= nums[i];
			}
			else{
				x2 ^= nums[i];
			}
		}

		int  * retArr = (int *)malloc(sizeof(int) * 2);
		retArr[0] = x1;
		retArr[1] = x2;
		*returnSize = 2;

		return retArr;
	}
}
int main()
{
	int *retp = NULL;
	int returnSize = 0;

	int Array[] = { 3, 2, 3, 6 };//1 6出现一次
	int len = sizeof(Array) / sizeof(Array[0]);
	retp = singleNumbers(Array, len, &returnSize);
	printf("共:%d,分别为:[%d %d]", returnSize, retp[0], retp[1]);
	system("pause");
	return 0;
}
//
//void testsingleNumbers(void){
//
//	printf("\n************  testsingleNumbers ************ \n");
//	int * retp = NULL;
//	int returnSize = 0;
//
//	int nums1[4] = { 4, 1, 4, 6 };
//	retp = singleNumbers(nums1, 4, &returnSize);
//	printf("returnSize = %d, retp[0] = %d, retp[1] = %d\n", returnSize, retp[0], retp[1]);
//	if (NULL != retp){
//		free(retp);
//		retp = NULL;
//	}
//
//	int nums2[8] = { 1, 2, 10, 4, 1, 4, 3, 3 };
//	retp = singleNumbers(nums2, 8, &returnSize);
//	printf("returnSize = %d, retp[0] = %d, retp[1] = %d\n", returnSize, retp[0], retp[1]);
//	if (NULL != retp){
//		free(retp);
//		retp = NULL;
//	}
//
//	return;
//
//}
//
//int main(int argc, char ** argv){
//	testsingleNumbers();
//	system("pause");
//	return 0;
//}