#include<stdio.h>
int check_sys()
{
	//0000 0000 0000 0000 0000 0000 0000 0001
	//将i的低8个字节取出来
	//如果低地址位存放的是0，那么是大端；否则是小段
	int i = 1;
	return (*(char *)&i);
}

int main()
{
	//面试题 设计程序来判断当前机器的字节序。
	int ret = check_sys();
	if (ret == 1){
		printf("小端\n");
	}
	else{
		printf("大端\n");
	}


	//c存储方式：
	//-128-127   
	// -129
	//1 1000 0001
	//1 0111 1110
	//1 0111 1111
	//0111 1111 低8位 截断
	//signed char a = -129;
	//signed char b = 127;

	//printf("a=%d size=%d\n", a,sizeof(a));
	//printf("b=%d size=%d\n", b,sizeof(b));
	return 0;
}

//联合体 后面尝试
//int check_sys()
//{
//	union
//	{
//		int i;
//		char c;
//	}un;
//	un.i = 1;
//	return un.c;
//}