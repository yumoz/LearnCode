#include<stdio.h>
#include<assert.h>
#include<windows.h>
//字符串拼接函数

char *my_strcat(char *dest, const char*src)
{
	char *ret = dest;//定义一个临时变量用来暂存目标字符串
	assert(dest != NULL);
	assert(src != NULL);
	while (*dest)
	{
		dest++;
	}
	while ((*dest = *src))
	{
		src++;
		dest++;
	}
	return ret;
}

int main()
{
	char a[20] = "abcdef";
	char b[10] = "123456";
	char *c = my_strcat(a, b);
	printf("%s\n", a);
	system("pause");
	return 0;
}