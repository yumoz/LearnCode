#include<stdio.h>
int check_sys()
{
	//0000 0000 0000 0000 0000 0000 0000 0001
	//��i�ĵ�8���ֽ�ȡ����
	//����͵�ַλ��ŵ���0����ô�Ǵ�ˣ�������С��
	int i = 1;
	return (*(char *)&i);
}

int main()
{
	//������ ��Ƴ������жϵ�ǰ�������ֽ���
	int ret = check_sys();
	if (ret == 1){
		printf("С��\n");
	}
	else{
		printf("���\n");
	}


	//c�洢��ʽ��
	//-128-127   
	// -129
	//1 1000 0001
	//1 0111 1110
	//1 0111 1111
	//0111 1111 ��8λ �ض�
	//signed char a = -129;
	//signed char b = 127;

	//printf("a=%d size=%d\n", a,sizeof(a));
	//printf("b=%d size=%d\n", b,sizeof(b));
	return 0;
}

//������ ���波��
//int check_sys()
//{
//	union
//	{
//		int i;
//		char c;
//	}un;
//	un.i = 1;
//	return un.c;
//}