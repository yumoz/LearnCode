#include<stdio.h>

#include<windows.h>

int main()
{
	int *ptr = malloc(1000);
	if (ptr != NULL){
		for (int i = 0; i < 10; i++){
			*(ptr + i) = i;
		}
	}
	else{
		exit(1);
	}

	ptr = realloc(ptr, 10000);
	//
	//for (int i = 0; i < 10; i++){
	//	printf("%d ", *(ptr + i));
	//}
	
	system("pause");
	return 0;
}