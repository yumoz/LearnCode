//дһ���������ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ�����
//
//���磺����s1 = AABCD��s2 = BCDAA������1
//
//����s1 = abcd��s2 = ACBD������0.
//
//AABCD����һ���ַ��õ�ABCDA
//
//AABCD���������ַ��õ�BCDAA
//
//AABCD����һ���ַ��õ�DAABC
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
		int tmp = str1[0];//����Ԫ�ش洢����
		for (i = 0; i < length - 1; i++)//��������Ԫ��
		{
			str1[i] = str1[i + 1];//����һ��Ԫ�ظ�ǰһ��Ԫ��
		}
		str1[length - 1] = tmp;//����һ��Ԫ�ظ����һ��Ԫ��
		if (0 == strcmp(str1, str2))//�Ƚ������ַ����Ƿ����
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
		printf("s1Ϊs2��ת����ַ���!\n");
	}
	else
	{
		printf("s1����s2��ת����ַ���!\n");
	}
	system("pause");
	return 0;
}
#if 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning(disable:4996)

// ֻ��Ҫ��ԭ�ַ���������, ���������������������п����� 7�λᵽԭ�ַ���
// �ٿ�һ�´����ַ����ǲ��������ַ���(���������ַ��������)
// ����� �ҵ��� ��strstr����ֵ �����ǿ�NULL

int strRoundStr(char* src, char* find){
	char tmp[256] = { 0 };

	// ʹsrc��tmp ��������
	strcpy(tmp, src);
	strcat(tmp, src);

	// �������ֵ���ǿ� ����1 �����ҵ���
	// �������ֵΪ0, ��û�ҵ�
	return strstr(tmp, find) != NULL;
}
int main(){

	char src[] = "AABCD";

	char find[] = "BCDAA";// ������һ��֮��Ľ��
	printf("%d\n", strRoundStr(src, find));// �ҵ���

	char find1[] = "BDCAA";
	printf("%d\n", strRoundStr(src, find1));// û�ҵ�

	system("pause");
	return 0;
}
#endif