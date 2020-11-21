#include<stdio.h>
#include<windows.h>

int main()
{
	char *pstr = "hello world.";
	printf("%s\n", pstr);
	system("pause");
	return 0;
}
#if 0
int main()
{
	char ch = 'w';
	char *pc = &ch;
	*pc = 'y';
	printf("%c\n", *pc);
	system("pause");
	return 0;
}
#endif