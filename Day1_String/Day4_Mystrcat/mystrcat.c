#include<stdio.h>
#include<assert.h>
#include<windows.h>

char *my_strcat(char *dest, const char*src)
{
	char *ret = dest;
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