#include<stdio.h>
#include<Windows.h>

int main()
{
	char * str = "hello world";

	system("pause");
	return 0;

}

#if 0
int main()
{
	char str1[] = "hello world.";//�ַ�����,����11���ֽڣ�
	char str2[] = "hello world.";//��������������ַ�������ڴ棬���Բ����
	char *str3 = "hello world.";//str3�� str4 ���ַ�������������ֻ��һ������
	char *str4 = "hello world.";//����������������ָ��ͬһλ��
	if (str1 == str2)
		printf("str1 == str2\n");
	else
		printf("str1 !=  str2 \n");
	if (str3 == str4)
		printf("str3 == str4\n");
	else
		printf("str3 != str4\n");
	system("pause");
	return 0;
}
#endif
