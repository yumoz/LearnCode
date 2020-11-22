#include<stdio.h>

#include<windows.h>

//联合的成员共同用一块内存空间，一个连个变量的大小，至少是最大成员的大小

union Un
{
	char c;
	int i;
};
int check_sys()
{
	union
	{
		int i;
		char c;
	}_un;
	_un.i = 1;
	return _un.c;
}
//方法二
int check_sys2()
{
	int a = 1;
	return *(char *)&a;//对整型存储截断，强转成char* 类型 ，再解引用看返回值
}
int main()
{
	union Un un;//联合变量的定义
	//测量联合体大小
	printf("%d\n", sizeof(un));//计算联合变量大小
	//联合体测大小端
	un.i = 1;//给最大成员赋值1
	if (un.c & 0x01){//判断
		printf("小端\n");
	}
	else{
		printf("大端\n");
	}
	//函数实现大小端测试
	int ret = check_sys();
	if (ret == 1){
		printf("小端\n");
	}
	else{
		printf("大端\n");
	}
	int ret2 = check_sys2();
	if (ret == 1){
		printf("小端\n");
	}
	else{
		printf("大端\n");
	}
	system("pause");
	return 0;
}