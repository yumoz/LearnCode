#include<stdio.h>
#include<string.h>
#include<windows.h>
#pragma warning(disable:4996)
struct  stu{
	char name[20];
	int age;
	char sex[10];
};
int main()
{
	struct stu student = { "yumoz", 18, "m" };
	struct stu *p=NULL;//����һ��ָ��struct STUDENT �ṹ�����͵�ָ�����p
	p = &student;//pָ��ṹ�����student���׵�ַ������һ����Ա����
	strcpy((*p).name, "lin");//�޸Ľṹ��ĳ�Ա��������*p��.name �ȼ���student.name
	p->age = 17;//��һ����ʽ���ʸ�ֵ

	//ָ��ṹ�������ָ��
	struct stu s[5] = { { "С��", 22, 'f' }, { "С��", 21, 'M'}, { "С��", 23, 'F'} };
	struct stu *_p = s;

	//for (int i=0; i < 3; ++i){
	//	//printf("name:%s;age:%d;sex:%c\n", _p->name, _p->age, _p->sex);
	//	printf("name:%s;age:%d;sex:%c\n", _p[i].name, _p[i].age, _p[i].sex);
	//}
	for (; _p < s+3; ++_p){
		printf("name:%s;age:%d;sex:%s\n", _p->name, _p->age, _p->sex);		//���⣺Ϊʲô��ӡ�Ա�Ҫ��%s��%cΪʲô���У�
	}
	//printf("%s\n", p->name);
	//printf("%s\n", student.name);
	//printf("%d\n", p->age);
	//printf("%d\n", (*p).age);
	system("pause");
	return 0;
}