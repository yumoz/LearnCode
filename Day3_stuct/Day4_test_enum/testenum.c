#include<stdio.h>
#include<windows.h>

enum Color
{
	red,
	orange,
	yellow,
	green,
	blue,
	purple
};
enum Day
{
	mon,
	tues,
	wed,
	thur,
	fri,
	sat,
	sun
}_day;
int main()
{
	printf("%d\n", red);
	for (_day = mon; _day < sun; _day++)//循环打印枚举类型各变量值
	{
		printf("%d\n", _day);
	}
	system("pause");
	return 0;
}