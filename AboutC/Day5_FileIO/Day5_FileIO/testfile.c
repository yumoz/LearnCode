/* rewind example */
#include <stdio.h>
#include<windows.h>
#pragma warning(disable:4996)
int main()
{
	int n;
	FILE * pFile;
	char buffer[27];
	int *a = "hello new thing";
	pFile = fopen("myfile.txt", "w+");
	for (n = 'A'; n <= 'Z'; n++)
	{
		fputc(n, pFile);//���ļ�д
	}
	rewind(pFile);//���ļ�ָ���λ�ûص��ļ�����ʼλ��
	fread(buffer, 1, 26, pFile);
	fclose(pFile);
	buffer[26] = '\0';
	puts(buffer);//��ӡ����Ļ
	system("pause");
	return 0;
}