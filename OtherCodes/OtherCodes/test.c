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
	return 0;
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
	return 0;
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
	return 0;
}
#endif

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
	return 0;
}