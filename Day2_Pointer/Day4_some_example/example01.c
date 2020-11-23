#include<stdio.h>
#include<windows.h>
#pragma  warning (disable:4996)

//code 01
//int main()
//{
//	int a[5] = { 1, 2, 3, 4, 5 };
//	int *ptr = (int *)(&a + 1);
//	printf("%d,%d", *(a + 1), *(ptr - 1));//ptr-1即减的是一个字节
//	system("pause");
//	return 0;
//}

//code 03
int main()
{
	int a[4] = { 1, 2, 3, 4 };
	int *ptr1 = (int *)(&a + 1);
	int *ptr2 = (int *)((int)a + 1);//int类型加1所以，只加了一个字节
	
	printf("%x,%x", ptr1[-1], *ptr2);
	system("pause");
	return 0;
}