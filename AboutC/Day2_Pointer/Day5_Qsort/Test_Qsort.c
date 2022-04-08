#if 0


/* qsort example */
#include <stdio.h>      /* printf */
#include <stdlib.h>     /* qsort */
#include<windows.h>		/* system */

int values[] = { 40, 10, 100, 90, 20, 25 };

int compare(const void * a, const void * b)
{
	return (*(int*)a - *(int*)b);
}

int main()
{
	int n;
	qsort(values, 6, sizeof(int), compare);	//qsort函数
	for (n = 0; n < 6; n++)	
		printf("%d ", values[n]);
	return 0;
}
#endif

#include <stdio.h>
#include<windows.h>

//qosrt函数的使用者得实现一个比较函数
int int_cmp(const void * p1, const void * p2) {
	return (*(int *)p1 - *(int *)p2);
}
int main()
{
	int arr[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
	int i = 0;

	qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(int), int_cmp);
	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}