#include<stdio.h>
#include<windows.h>

struct S{
	int data[1000];
	int num;
};

struct S s = { { 1, 2, 3, 4 }, 1000 };
//�ܽ᣺�ṹ�崫��ʱ��Ҫ���ṹ��ĵ�ַ��

//�ṹ�崫��
void print1(struct S s)
{
	printf("%d\n", s.num);
}
//�ṹ���ַ����
void print2(struct S* ps)
{
	printf("%d\n", ps->num);
}

int main()
{
	print1(s);//���ṹ��
	print2(&s);//����ַ
	system("pause");
	return 0;
}