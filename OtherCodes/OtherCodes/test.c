#include<stdio.h>
#include<windows.h>

//�������������дC���Գ����Ļ������뼰��չ

//ͼ�δ�ӡ
void PrintStar(int num)
{
	for (int i = 0; i < num; i++){
		printf("*");
	}
}
void PrintSpace(int num)
{
	for (int i = 0; i < num; i++){
		printf(" ");
	}
}

//�ú�����ʵ�ִ�ӡ
#if 0
//��ӡֱ��������
int main()
{
	int row = 10;
	for (int i = 1; i < row; i++){
		PrintStar(i);//���ú�����������������������1�������ӡһ���Ǻ�
		printf("\n");
	}
	system("pause");
	returrow0;
}

//��ӡֱ��������
int main()
{
	int row = 10;
	for (int i = 1; i < row; i++){
		PrintSpace(row - i);
		PrintStar(i);//���ú�����������������������1�������ӡһ���Ǻ�
		printf("\n");
	}
	system("pause");
	returrow0;
}


//��ӡֱ��������
int main()
{
	int row = 10;
	for (int i = 10; i > 0; i--){
		PrintSpace(row - i);
		PrintStar(i);//���ú�����������������������1�������ӡһ���Ǻ�
		printf("\n");
	}
	system("pause");
	returrow0;
}


//��ӡֱ��������
int main()
{
	int row = 10;
	for (int i = 10; i > 0; i--){
		//PrintSpace(row - i);
		PrintStar(i);//���ú�����������������������1�������ӡһ���Ǻ�
		printf("\n");
	}
	system("pause");
	returrow0;
}
#endif

//��ӡ����ֱ��������
int main()
{
	int i = 0, j = 0;
	int row =10;
	for(i=1;i<row;i++){
		PrintStar(1);
		PrintSpace(i - 2);
		if (i>1)
		PrintStar(1);
		printf("\n");
		
	}
	PrintStar(row);
	printf("\n");
	system("pause");
	return 0;
}
#if 0
//��ӡ���ĵ���������
int main()
{
	int i, j;
	int row = 10;
	for (i = 0; i < row ; i++)
	{
		if (i != row- 1)//�ж�
		{
			for (j = 0; j < 2 * row- 1; j++)
			{
				if (j == row- i - 1 || j == row+ i - 1)
					printf("*");
				else
					printf(" ");
			}
		}
		else
		{
			for (j = 0; j < 2 * row- 1; j++)
				printf("*");
		}
		printf("\n");
	}

	system("pause");
	return 0;
}
#endif