#include<stdio.h>
#include<windows.h>
#include<assert.h>

#pragma warning(disable:4996)

char *MyStrcpy(char *dst, const char *str)
{
	assert(NULL != str);
	assert(NULL != dst);
	char *cp = dst;
	while (*cp = *str){
		cp++;
		str++;
	}
	return dst;
}
int main()
{
	const char *arr = "abcdefg1234";
	char RecStr[20] = { 0 };
	printf("RecvString:%s\n", MyStrcpy(RecStr, arr));
	system("pause");
	return 0;

}