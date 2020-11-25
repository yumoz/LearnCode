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

	// 几种输出方式的总结
	//puts(str1);//非格式化输出，输出格式带着回车
	fputs(str1, stdout);//输出不带回车
	puts("");//打印了回车
	printf("%s\n", str1);

	system("pause");
	return 0;
}


//strncpy 
int main()
{
	const char * src = "hello";
	char dst[20]="20201116\0xxxxx";
	strncpy(dst,src,strlen(src)+1);//需要把\0一起拷贝到dst中
	system("pause");
	return 0;
}

int main()
{
	const char *str1 = "abcdef";
	const char *str2 = "bbb";
	if (strlen(str2) - strlen(str1) > 0){
		//两个无符号数之减任然是个无符号数，只要str1！= str2，肯定会是大于号
		//此处发生了整形提升
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
//	strncat(dst, src, strlen(src));//拷贝时，dst中\0向后移动
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