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
	ptr = (int*)malloc(num*sizeof(int));
	if (NULL != ptr)//�ж�ptrָ���Ƿ�Ϊ��
	{
		int i = 0;
		for (i = 0; i < num; i++)
		{
			*(ptr + i) = 0;
		}
	}
	free(ptr);//�ͷ�ptr��ָ��Ķ�̬�ڴ�
	ptr = NULL;//�Ƿ��б�Ҫ��
	system("pause");
	return 0;
}