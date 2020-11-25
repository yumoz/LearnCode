#include<stdio.h>
#include<assert.h>
#include<windows.h>

int my_strcmp(char *dest, const char*src)
{
	while((*dest != '\0') && (*src != '\0'))
	{
		if (*dest < *src)
		{
			return -1;
		}
		else if (*dest > *src)
		{
			return 1;
		}
		else
		{
			++dest;
			++src;
		}
	}

}

int main()
{
	char a[20] = "abs";
	char b[10] = "abc";
	int c = my_strcmp(a, b);
	if (-1 == c){
		printf("str1<str2\n");
	}
	else if (1 == c){
		printf("str1>str2\n");
	}
	else{
		printf("str1=str2\n");
	}

	system("pause");
	return 0;
}