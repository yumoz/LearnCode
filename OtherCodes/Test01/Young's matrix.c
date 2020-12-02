#include<stdio.h>
#include<windows.h>

#define true 1
#define false 0

#define N 4
typedef int bool;

//杨氏矩阵查找,从右上角向左下角查找
bool  YangSearch(int a[][N], int M, int key, int *i, int *j)
{
	if (key<a[0][0] || key>a[M - 1][N - 1])
		return false;
	int row = 0;
	int col = N - 1;
	while (row < M&&col >= 0)
	{
		if (key == a[row][col])
		{
			*i = row;
			*j = col;
			return true;
		}
		else if (key > a[row][col])
		{
			row++;
		}
		else if (key < a[row][col])
		{
			col--;
		}
	}
	return false;
}


int main(void)
{
	int a[4][4] = { { 1, 5, 7, 9 }, { 4, 6, 10, 15 }, { 8, 11, 12, 19 }, { 14, 16, 18, 21 } };//列出矩阵
	int i = -1;
	int j = -1;
	int key = 14;// searched number
	bool b = YangSearch(a, 4, key, &i, &j);//函数调用
	if (b)
	{
		printf("查找到%d，位置为%d,%d\n", key, i, j);
	}
	system("pause");
	return 0;
}