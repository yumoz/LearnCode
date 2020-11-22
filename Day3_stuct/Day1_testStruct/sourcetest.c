#include<stdio.h>
#include<string.h>
#include<windows.h>
#pragma warning(disable:4996)
struct  stu{
	char name[20];
	int age;
	char sex[10];
};
int main()
{
	struct stu student = { "yumoz", 18, "m" };
	struct stu *p=NULL;//定义一个指向struct STUDENT 结构体类型的指针变量p
	p = &student;//p指向结构体变量student的首地址，即第一个成员变量
	strcpy((*p).name, "lin");//修改结构体的成员变量，（*p）.name 等价于student.name
	p->age = 17;//另一种形式访问赋值

	//指向结构体数组的指针
	struct stu s[5] = { { "小红", 22, 'f' }, { "小明", 21, 'M'}, { "小七", 23, 'F'} };
	struct stu *_p = s;

	//for (int i=0; i < 3; ++i){
	//	//printf("name:%s;age:%d;sex:%c\n", _p->name, _p->age, _p->sex);
	//	printf("name:%s;age:%d;sex:%c\n", _p[i].name, _p[i].age, _p[i].sex);
	//}
	for (; _p < s+3; ++_p){
		printf("name:%s;age:%d;sex:%s\n", _p->name, _p->age, _p->sex);		//问题：为什么打印性别要用%s，%c为什么不行？
	}
	//printf("%s\n", p->name);
	//printf("%s\n", student.name);
	//printf("%d\n", p->age);
	//printf("%d\n", (*p).age);
	system("pause");
	return 0;
}