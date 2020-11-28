/* fread example: read an entire file */
#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#pragma  warning (disable:4996)

int main()
{
	FILE * pf;
	pf=fopen("test.txt","wb");
	fputs("This is an test file.",pf);
	fseek(pf,9,SEEK_SET);
	fputs("sam",pf);
	fclose(pf);
	system("pause");
	return 0;
}
#if 0
int main() {
	FILE * fp = fopen("data.txt", "wb");

	if (NULL == fp){
		printf("fopen error!\n");
		return 1;
	}
	char buf[] = "abcd1234";
	fwrite(buf, sizeof(buf), 1, fp);

	printf("Sleep 5s ......\n");
	Sleep(5000);
	printf("Sleep end\n");
	fclose(fp);
	
	system("pause");
	return 0;
}
#endif