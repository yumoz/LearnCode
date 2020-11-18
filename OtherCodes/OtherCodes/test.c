#include<stdio.h>
#include<windows.h>

//这个程序是用来写C语言常见的基础代码及扩展

//图形打印
void PrintStar(int num)
{
	for (int i = 0; i < num; i++){
		printf("*");
	}
}
void PrintSpace(int num)
{
	for (int i = 0; i < num; i++){
		printf(" ");
	}
}

//用函数来实现打印
#if 0
//打印直角三角形
int main()
{
	int row = 10;
	for (int i = 1; i < row; i++){
		PrintStar(i);//调用函数，传入参数，如果参数是1个，则打印一个星号
		printf("\n");
	}
	system("pause");
	return 0;
}

//打印直角三角形
int main()
{
	int row = 10;
	for (int i = 1; i < row; i++){
		PrintSpace(row - i);
		PrintStar(i);//调用函数，传入参数，如果参数是1个，则打印一个星号
		printf("\n");
	}
	system("pause");
	return 0;
}


//打印直角三角形
int main()
{
	int row = 10;
	for (int i = 10; i > 0; i--){
		PrintSpace(row - i);
		PrintStar(i);//调用函数，传入参数，如果参数是1个，则打印一个星号
		printf("\n");
	}
	system("pause");
	return 0;
}
#endif

//打印直角三角形
int main()
{
	int row = 10;
	for (int i = 10; i > 0; i--){
		//PrintSpace(row - i);
		PrintStar(i);//调用函数，传入参数，如果参数是1个，则打印一个星号
		printf("\n");
	}
	system("pause");
	return 0;
}