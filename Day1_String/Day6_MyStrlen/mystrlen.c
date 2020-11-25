#include<stdio.h>
#include<assert.h>
#include<windows.h>

int my_strlen(const char*src)
{
	assert(src != NULL);
	int count = 0;
	while (*src!='\0')
	{
		count++;
		src++;
	}

	return count;
}
int my_strlen1(const char *p)
{
	assert(p);
	if (*p == '\0')
		return 0;
	else
		return 1 + my_strlen(p + 1);
}
int my_strlen2(const char *p)
{
	const char *ret = NULL;
	assert(p);
	ret = p;
	while (*ret != '\0')
	{
		ret++;
	}
	return ret - p;
}

int main()
{
	const char a[20] = "abcdef";
	int len = my_strlen2(a);
	printf("len=%d\n", len);
	system("pause");
	return 0;
}