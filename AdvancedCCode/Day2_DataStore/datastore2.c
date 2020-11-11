#include<stdio.h>
#include<Windows.h>

int main()
{
	//仔细分析数据的截取，循环的原因
	char a[1000];
	int i;
	for (i = 0; i < 1000; i++){
		a[i] = -1 - i;
		printf("%d\n", a[i]);
		Sleep(100);
	}
	printf("%d", strlen(a));

	system("pause");
	return 0;
}

#if 0
//256
// 0001 0000 0000

int main()
{
	unsigned char i = 257;
	printf("%d\n", i);//1
	system("pause");
	return 0;
}

int main()
{
	unsigned int i;
	for (i = 9; i >= 0; i--){//9 8 7 6 5 4 3 2 1 0 -1  死循环
		printf("%u\n", i);
		Sleep(1000);
	}
	system("pause");
	return 0;
}

int main()
{
	//i 
	//1000 0000 0000 0000 0000 0000 0001 0100   //-20
	//1111 1111 1111 1111 1111 1111 1110 1011
	//1111 1111 1111 1111 1111 1111 1110 1100   
	//j
	//0000 0000 0000 0000 0000 0000 0000 1010
	//+ =
	//1111 1111 1111 1111 1111 1111 1111 0110
	//读
	//1111 1111 1111 1111 1111 1111 1111 0101 //减1
	//1000 0000 0000 0000 0000 0000 0000 1010   //-10

	int i = -20;
	unsigned int j = 10;
	printf("%d\n", i + j);
	system("pause");
	return 0;
}

int main()
{
	// %d 
	//1000 0000   128
	//1000 0000   -128的补码
	//因为计算机是用补码来存储的，所以128二进制形式刚好是-128的补码形式

	//130
	//1000 0010   //130
	//1000 0001   //减1
	//1111 1110  //-126
	char a = 128;
	char b = 129;
	char c = 130;
	printf("%d %d %d\n", a, b, c);
	system("pause");
	return 0;
}
int main()
{
	//1000 000   -128
	//1111 1111 1111 1111 1111 1111 1000 0000

	char a = -128;
	printf("%u\n", a);//unsigned long
	return 0;
}

int main()
{
	//1）
	//1000 0001
	//1111 1110
	//1111 1111
	//1111 1110
	//1000 0001

	//2)
	//the same as 1)

	//3)
	//1000 0001
	//1111 1110
	//1111 1111     255

	char a = -1;
	signed char b = -1;
	unsigned char c = -1;
	printf("%d %d %d\n", a, b, c);//-1 -1 255
	return 0;
}
#endif