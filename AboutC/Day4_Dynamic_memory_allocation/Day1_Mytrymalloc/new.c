#include <stdio.h>
#include<stdlib.h>
#define num 10
int main()
{
	//����1
	//int num = 0;
	//scanf("%d", &num);
	int arr[num] = { 0 };
	//����2
	int* ptr = NULL;
	//ptr = (int*)malloc(num*sizeof(int));
	//ptr = calloc(10, sizeof(int));
	ptr = realloc(ptr, 1000);
	if (NULL != ptr)//�ж�ptrָ���Ƿ�Ϊ��
	{
		for (int i = 0; i < num; i++)
		{
			*(ptr + i) = i;
		}
	}
	else{//����ʧ��
		exit(EXIT_FAILURE);
	}

	// ��ӡ���
	for (int i = 0; i < num; i++){
		printf("%d ", *(ptr + i));
	}
	free(ptr);//�ͷ�ptr��ָ��Ķ�̬�ڴ�
	ptr = NULL;//�Ƿ��б�Ҫ��
	system("pause");
	return 0;
}