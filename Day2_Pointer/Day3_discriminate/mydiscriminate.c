#include<stdio.h>
#include<windows.h>
//
int main()
{
	//Ò»Î¬Êý×é
	int a[] = { 1, 2, 3, 4 };
	printf("%d\n", sizeof(a));//16
	printf("%d\n", sizeof(a + 0));//4
	printf("%d\n", sizeof(*a));//4
	printf("%d\n", sizeof(a + 1));//4
	printf("%d\n", sizeof(a[1]));//4
	printf("%d\n", sizeof(&a));//4
	printf("%d\n", sizeof(*&a));//16
	printf("%d\n", sizeof(&a + 1));//4
	printf("%d\n", sizeof(&a[0]));//4
	printf("%d\n", sizeof(&a[0] + 1));//4
	system("pause");
	return 0;
}