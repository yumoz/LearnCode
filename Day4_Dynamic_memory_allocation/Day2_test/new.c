#include<stdio.h>
#include<stdlib.h>

int main()
{
	//malloc ����ֵ�� ָ�򿪱ٺÿռ��ָ��
	//�������ʧ�ܣ�����һ��NULLָ�룬
	//���malloc����һ��Ҫ������ֵ���
	int *p = NULL;
	p = (int *)malloc(10 * sizeof(int));
	if (NULL == p){
		printf("malloc error\n");
	}
	else{
		int i = 0;
		for (i = 0; i < 10; i++){
			*(p + i) = i;
		}
	}
	//��ӡ���
	for (int i = 0; i < 10; i++){
		printf("%d\n", *(p + i));
	}
	free(p);
	p = NULL;
	system("pause");
	return 0;
}