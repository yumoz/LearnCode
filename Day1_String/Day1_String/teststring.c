#include<stdio.h>
#include<Windows.h>
#include<string.h>
#pragma warning(disable:4996)



int main()
{
	char src[] = "abcde";
	char dst[10] = { 0 };
	strcpy(dst, src);
	printf("%s\n", dst);
	system("pause");
	return 0;
}
#if 0
int main()
{
	char str1[20];
	char str2[20];
	strcpy(str1,"To be ");
	strcpy(str2,"or not to be");
	strncat(str1,str2,6);

	// ���������ʽ���ܽ�
	//puts(str1);//�Ǹ�ʽ������������ʽ���Żس�
	fputs(str1, stdout);//��������س�
	puts("");//��ӡ�˻س�
	printf("%s\n", str1);

	system("pause");
	return 0;
}


//strncpy 
int main()
{
	const char * src = "hello";
	char dst[20]="20201116\0xxxxx";
	strncpy(dst,src,strlen(src)+1);//��Ҫ��\0һ�𿽱���dst��
	system("pause");
	return 0;
}

int main()
{
	const char *str1 = "abcdef";
	const char *str2 = "bbb";
	if (strlen(str2) - strlen(str1) > 0){
		//�����޷�����֮����Ȼ�Ǹ��޷�������ֻҪstr1��= str2���϶����Ǵ��ں�
		//�˴���������������
		printf("str2>str1\n");
	}
	else{
		printf("str1>str2");
	}
	system("pause");
	return 0;
}

int main()
{
	const char *src = "hello";
	char  dst[20] = "abcdefghljk\0xxxxxx";
//	strncat(dst, src, strlen(src));//����ʱ��dst��\0����ƶ�
	strncpy(dst, src, strlen(src));
	system("pause");
	return 0;
}

int main()
{
	const char *str1 = "abc";
	const char *str2 = "abcd";
	if (strcmp(str1, str2)==0)//do not leave ==0
	{
		printf("equal\n");
	}
	else
	{
		printf("un equal\n");
	}
	system("pause");
	return 0;
}
#endif