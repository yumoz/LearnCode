#include<stdio.h>
#include<windows.h>
#pragma warning (disable:4996)

int main()
{
	FILE * fp = fopen("test.txt", "w");
	/*for (char i = 'a'; i <= 'z'; i++){
		fputc(i, fp);
	}*/
	/*for (char i = 'a'; i <= 'z'; i++){
		fputc(i,fp);
	}*/
	fgets(fp);
	
	fputs(i, stdout);
	fclose(fp);
	fp = NULL;
	system("pause");
	return 0;
}