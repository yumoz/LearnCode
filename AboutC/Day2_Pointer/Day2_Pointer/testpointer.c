#include<stdio.h>
#include<Windows.h>

int main()
{
	char * str = "hello world";

	system("pause");
	return 0;

}

#if 0
int main()
{
	char str1[] = "hello world.";//字符数组,开辟11个字节，
	char str2[] = "hello world.";//和上述是两个地址，两个内存，所以不相等
	char *str3 = "hello world.";//str3和 str4 在字符常量区，所以只有一份内容
	char *str4 = "hello world.";//编译器将两份内容指向同一位置
	if (str1 == str2)
		printf("str1 == str2\n");
	else
		printf("str1 !=  str2 \n");
	if (str3 == str4)
		printf("str3 == str4\n");
	else
		printf("str3 != str4\n");
	system("pause");
	return 0;
}
#endif
