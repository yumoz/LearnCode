#include<stdio.h>
#include<Windows.h>

#if 0
#endif
//code 6���� ���������
int main()
{
	//��ϸ�������ݵĽ�ȡ��ѭ����ԭ��
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
	for (i = 9; i >= 0; i--){//9 8 7 6 5 4 3 2 1 0 -1  ��ѭ��
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
	//1111 1111 1111 1111 1111 1111 1110 1100   ����
	//j
	//0000 0000 0000 0000 0000 0000 0000 1010   ������ԭ�뷴�벹��һ��
	//+ 
	//=
	//1111 1111 1111 1111 1111 1111 1111 0110
	//��
	//1111 1111 1111 1111 1111 1111 1111 0101 //��1
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
	//1000 0000   -128�Ĳ���
	//��Ϊ��������ò������洢�ģ�����128��������ʽ�պ���-128�Ĳ�����ʽ

	//130
	//1000 0010   //130
	//1000 0001   //��1
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
	//1000 0000   -128,�涨
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
	char a = -1;//Ĭ��Ϊ�з��� 1000 0001 --> 1111 1110 --> 1111 1111(ȫ1)��ԭ�롢���롢����
	signed char b = -1;//ͬ��
	unsigned char c = -1;//���ʱ�򣬲������ͣ� 1000 0001 --> 1111 1110 --> 1111 1111����ȡʱ�������ͣ������޷����ͣ�1111 1111  ��ʮ������ʽ255��
	printf("%d %d %d\n", a, b, c);//-1 -1 255 %dΪ�������
	return 0;
}
#endif