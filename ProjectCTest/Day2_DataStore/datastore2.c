#include<stdio.h>
#include<Windows.h>

#if 0
#endif
//code 6最难 多分析几次
int main()
{
	//仔细分析数据的截取，循环的原因
	char a[1000];
	int i;
	for (i = 0; i < 1000; i++){
		a[i] = -1 - i;
		/*printf("%d\n", a[i]);
		Sleep(100);*/
	}
	printf("%d", strlen(a));//255

	system("pause");
	return 0;
}


#if 0
//256
// 0001 0000 0000

int main()
{
	unsigned char i = 256;
	printf("%d\n", i);//1
	system("pause");
	return 0;
}
#endif
#if 0
//code 5
int main()
{
	unsigned int i;
	for (i = 9; i >= 0; i--){//9 8 7 6 5 4 3 2 1 0 -1  死循环
		printf("%u\n", i);
		//Sleep(1000);
	}
	system("pause");
	return 0;
}
#endif
#if 0
//code4
int main()
{
	//i 
	//1000 0000 0000 0000 0000 0000 0001 0100   //-20
	//1111 1111 1111 1111 1111 1111 1110 1011
	//1111 1111 1111 1111 1111 1111 1110 1100   补码
	//j
	//0000 0000 0000 0000 0000 0000 0000 1010   正数，原码反码补码一样
	//+ 
	//=
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
#endif
#if 0
//code3
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
	printf("%d %d %d\n", a, b, c);//-128 -127 -126
	system("pause");
	return 0;
}
#endif

#if 0
//code2
int main()
{
	//1000 0000   -128,规定
	//1111 1111		1111 1111	1111 1111	 1000 0000

	char a = -128;
	printf("%u\n", a);//unsigned long 4294967168
	system("pause");
	return 0;
}
#endif 

#if 0
//code 1
int main()
{
	char a = -1;//默认为有符号 1000 0001 --> 1111 1110 --> 1111 1111(全1)，原码、反码、补码
	signed char b = -1;//同上
	unsigned char c = -1;//存的时候，不看类型， 1000 0001 --> 1111 1110 --> 1111 1111，读取时，看类型，读成无符号型，1111 1111  （十进制形式255）
	printf("%d %d %d\n", a, b, c);//-1 -1 255 %d为整形输出
	return 0;
}
#endif