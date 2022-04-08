//写一个函数，判断一个字符串是否为另外一个字符串旋转之后的字符串。
//
//例如：给定s1 = AABCD和s2 = BCDAA，返回1
//
//给定s1 = abcd和s2 = ACBD，返回0.
//
//AABCD左旋一个字符得到ABCDA
//
//AABCD左旋两个字符得到BCDAA
//
//AABCD右旋一个字符得到DAABC
#include <stdio.h>
#include <windows.h>
#include <string.h>

int compare(char *str1, char *str2)
{
	int i = 0;
	int j = 0;
	int length = strlen(str1);
	for (j = 1; j <= length; j++)
	{
		int tmp = str1[0];//将首元素存储起来
		for (i = 0; i < length - 1; i++)//遍历所有元素
		{
			str1[i] = str1[i + 1];//将后一个元素给前一个元素
		}
		str1[length - 1] = tmp;//将第一个元素给最后一个元素
		if (0 == strcmp(str1, str2))//比较两个字符串是否相等
		{
			return 1;
		}
	}
	return 0;
}

int main()
{
	char s1[10] = "ABCDEFGH";
	char s2[10] = "EFGHABCD";
	printf("s1 = %s\n", s1);
	printf("s2 = %s\n", s2);
	if (1 == compare(s1,s2))
	{
		printf("s1为s2旋转后的字符串!\n");
	}
	else
	{
		printf("s1不是s2旋转后的字符串!\n");
	}
	system("pause");
	return 0;
}
#if 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning(disable:4996)

// 只需要把原字符串来两遍, 包括了左旋和右旋的所有可能性 7次会到原字符串
// 再看一下待查字符串是不是它的字符串(来两遍后的字符串里面的)
// 如果是 找到了 则strstr返回值 绝不是空NULL

int strRoundStr(char* src, char* find){
	char tmp[256] = { 0 };

	// 使src在tmp 里来两遍
	strcpy(tmp, src);
	strcat(tmp, src);

	// 如果返回值不是空 返回1 代表找到了
	// 如果返回值为0, 则没找到
	return strstr(tmp, find) != NULL;
}
int main(){

	char src[] = "AABCD";

	char find[] = "BCDAA";// 算左旋一个之后的结果
	printf("%d\n", strRoundStr(src, find));// 找到了

	char find1[] = "BDCAA";
	printf("%d\n", strRoundStr(src, find1));// 没找到

	system("pause");
	return 0;
}
#endif