#include<stdio.h>

#include<windows.h>

struct S3 
{
	double d;
	char c;
	int i;
};
struct S4
{
	char c1;
	struct S3 s3;
	char *arr[3];
	short *b;
	double d;
};
struct S5
{
	char c;//1
	struct  S3 s;//7+16
	char *d;
	char e[3];
	float *fp;
	float f;
	double _d[3];
	struct S4 ss[2];
	char g;
};
int main()
{
	printf("%d\n", sizeof(struct S3));
	printf("%d\n", sizeof(struct S4));
	printf("%d\n", sizeof(struct S5));
	system("pause");
	return 0;
}