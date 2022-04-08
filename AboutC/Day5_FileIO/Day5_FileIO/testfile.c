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
		fputc(n, pFile);//向文件写
	}
	rewind(pFile);//让文件指针的位置回到文件的起始位置
	fread(buffer, 1, 26, pFile);
	fclose(pFile);
	buffer[26] = '\0';
	puts(buffer);//打印到屏幕
	system("pause");
	return 0;
}