#include<stdio.h>
#include<windows.h>
#pragma warning (disable:4996)

int main()
{
	FILE * fp = fopen("test.txt", "wb");
	long size;
	if (fp == NULL)
		perror("Error opening file");
	else{
		fputs("this is ", fp);
		fseek(fp, 5, SEEK_SET);
		fputs("Sam", fp);
		size = ftell(fp);//�����ļ�ָ���������ʼλ�õ�ƫ����
		fclose(fp);
		printf("Size is %ld bytes. \n", size);
	}


	//for (char i = 'a'; i <= 'z'; i++){
	//	fputc(i, fp);
	//}

	//fclose(fp);
	fp = NULL;
	system("pause");
	return 0;
}