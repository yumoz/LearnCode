#include<stdio.h>
#include<Windows.h>
#pragma warning(disable:4996)

int main()
{
	for (int i = 0; i < 50; i++){
		printf("%d->%s\n", i, strerror(i));
	}
	system("pause");
	return 0;
}
