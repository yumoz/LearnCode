#include<stdio.h>
#include<stdlib.h>

int main()
{
	//malloc 返回值是 指向开辟好空间的指针
	//如果开辟失败，返回一个NULL指针，
	//因此malloc函数一定要做返回值检测
	int *p = NULL;
	p = (int *)malloc(10 * sizeof(int));
	if (NULL == p){
		printf("malloc error\n");
	}
	else{
		int i = 0;
		for (i = 0; i < 10; i++){
			*(p + i) = i;
		}
	}
	//打印输出
	for (int i = 0; i < 10; i++){
		printf("%d\n", *(p + i));
	}
	free(p);
	p = NULL;
	system("pause");
	return 0;
}