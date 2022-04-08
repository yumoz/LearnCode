#include<stdio.h>
#include<windows.h>
//

int main()
{
	char *p = "abcdef";

	printf("%d\n", sizeof(p));//指针大小

	printf("%d\n", sizeof(p+1));//指针大小

	printf("%d\n", sizeof(*p));//首元素占一个字节

	printf("%d\n", sizeof(p[0]));//the same as up

	printf("%d\n", sizeof(&p));//指针的地址，所以任然是4个

	printf("%d\n", sizeof(&p+1));

	printf("%d\n", sizeof(&p[0]+1));


	//printf("%d\n", strlen(p));

	//printf("%d\n", strlen(p + 1));

	//printf("%d\n", strlen(*p));

	//printf("%d\n", strlen(p[0]));

	//printf("%d\n", strlen(&p));

	//printf("%d\n", strlen(&p+1));

	//printf("%d\n", strlen(&p[0]+1));





	//二维数组

	int a[3][4] = {0};

	printf("%d\n",sizeof(a));

	printf("%d\n", sizeof(a[0][0]));

	printf("%d\n", sizeof(a[0]));

	printf("%d\n", sizeof(a[0] + 1));

	printf("%d\n", sizeof(*(a[0] + 1)));

	printf("%d\n", sizeof(a + 1));

	printf("%d\n", sizeof(*(a + 1)));

	printf("%d\n", sizeof(&a[0] + 1));

	printf("%d\n", sizeof(*(&a[0] + 1)));

	printf("%d\n", sizeof(*a));

	printf("%d\n", sizeof(a[3]));
	system("pause");
	return 0;
}

#if 0
int main()
{
	//一维数组
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
#endif