#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)

//Drink Water Question
int main()
{
	int  total = 0;
	int empty = 0;
	int money = 0;
	int price = 0;
	printf("input money and price# ");
	scanf("%d %d", &money,&price);
	total = money/price;//�����һ����Ǯ���������ƿ��
	empty = total;//��ƿ����
	while (empty > 1){//
		total+= empty / 2;//�������ƿ�ӿ��Ի��ö������ϼ���ǰһ����ƿ����
		empty = empty / 2 + empty % 2;//����ż��ƿ�ӿ��Ի������� �� ������ƿ����ʣ�²��ܶһ���
	
	}
	printf("%d\n", total);
	system("pause");
	return 0;
}
