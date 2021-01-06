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
	total = money/price;//计算第一次用钱可以买多少瓶子
	empty = total;//空瓶子数
	while (empty > 1){//
		total+= empty / 2;//计算出空瓶子可以换得多少饮料加上前一次总瓶子数
		empty = empty / 2 + empty % 2;//考虑偶数瓶子可以换的饮料 和 奇数个瓶子所剩下不能兑换的
	
	}
	printf("%d\n", total);
	system("pause");
	return 0;
}
