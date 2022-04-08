#include<stdio.h>
int main()
{

	char a[1000] = { 0 };
	int i = 0;
	for (i = 0; i<1000; i++)
	{
		a[i] = -1 - i;//a[999]=-1000
	}
	printf("%d", strlen(a));
	//unsigned char a = 200;
	//unsigned char b = 100;
	//unsigned char c = 0;
	//c = a + b;
	//printf("%d %d", a + b, c);
	return 0;
}