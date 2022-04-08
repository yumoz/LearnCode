#include <stdio.h>
#include<stdlib.h>
#define num 10
int main()
{
	//代码1
	//int num = 0;
	//scanf("%d", &num);
	int arr[num] = { 0 };
	//代码2
	int* ptr = NULL;
	ptr = (int*)malloc(num*sizeof(int));
	if (NULL != ptr)//判断ptr指针是否为空
	{
		int i = 0;
		for (i = 0; i < num; i++)
		{
			*(ptr + i) = 0;
		}
	}
	free(ptr);//释放ptr所指向的动态内存
	ptr = NULL;//是否有必要？
	system("pause");
	return 0;
}