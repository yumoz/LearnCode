#include <stdio.h>
#include<assert.h>
#include<windows.h>

const char *my_strstr(const char *str, const char *sub_str)
{
	assert(str);
	assert(sub_str);
	for (int i = 0; str[i] != '\0'; i++)
	{
		int tem = i; //tem保留主串中的起始判断下标位置 
		int j = 0;
		while (str[i++] == sub_str[j++])
		{
			if (sub_str[j] == '\0')
			{
				return &str[tem];//返回值为地址
			}
		}
		i = tem;
	}
	return NULL;
}

int main()
{
	char *s = "helloyumoz's blog";
	char *sub = "yumoz";
	printf("%s\n", my_strstr(s, sub));
	system("pause");
	return 0;
}