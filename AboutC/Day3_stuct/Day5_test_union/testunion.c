#include<stdio.h>

#include<windows.h>

//���ϵĳ�Ա��ͬ��һ���ڴ�ռ䣬һ�����������Ĵ�С������������Ա�Ĵ�С

union Un
{
	char c;
	int i;
};
int check_sys()
{
	union
	{
		int i;
		char c;
	}_un;
	_un.i = 1;
	return _un.c;
}
//������
int check_sys2()
{
	int a = 1;
	return *(char *)&a;//�����ʹ洢�ضϣ�ǿת��char* ���� ���ٽ����ÿ�����ֵ
}
int main()
{
	union Un un;//���ϱ����Ķ���
	//�����������С
	printf("%d\n", sizeof(un));//�������ϱ�����С
	//��������С��
	un.i = 1;//������Ա��ֵ1
	if (un.c & 0x01){//�ж�
		printf("С��\n");
	}
	else{
		printf("���\n");
	}
	//����ʵ�ִ�С�˲���
	int ret = check_sys();
	if (ret == 1){
		printf("С��\n");
	}
	else{
		printf("���\n");
	}
	int ret2 = check_sys2();
	if (ret == 1){
		printf("С��\n");
	}
	else{
		printf("���\n");
	}
	system("pause");
	return 0;
}