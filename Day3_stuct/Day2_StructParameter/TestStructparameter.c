#include<stdio.h>
#include<windows.h>

struct S{
	int data[1000];
	int num;
};

struct S s = { { 1, 2, 3, 4 }, 1000 };
//总结：结构体传参时，要传结构体的地址。

//结构体传参
void print1(struct S s)
{
	printf("%d\n", s.num);
}
//结构体地址传参
void print2(struct S* ps)
{
	printf("%d\n", ps->num);
}

int main()
{
	print1(s);//传结构体
	print2(&s);//传地址
	system("pause");
	return 0;
}