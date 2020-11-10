#include<stdio.h>
int main()
{
	//c´æ´¢·½Ê½£º
	//-128-127   
	// -129
	//1 1000 0001
	//1 0111 1110
	//1 0111 1111
	//0111 1111 µÍ8Î» ½Ø¶Ï
	signed char a = -129;
	signed char b = 127;

	printf("a=%d size=%d\n", a,sizeof(a));
	printf("b=%d size=%d\n", b,sizeof(b));
	return 0;
}