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
	//ptr = (int*)malloc(num*sizeof(int));
	//ptr = calloc(10, sizeof(int));
	ptr = realloc(ptr, 1000);
	if (NULL != ptr)//判断ptr指针是否为空
	{
		for (int i = 0; i < num; i++)
		{
			*(ptr + i) = i;
		}
	}
	else{//开辟失败
		exit(EXIT_FAILURE);
	}

	// 打印输出
	for (int i = 0; i < num; i++){
		printf("%d ", *(ptr + i));
	}
	free(ptr);//释放ptr所指向的动态内存
	ptr = NULL;//是否有必要？
	system("pause");
	return 0;
}