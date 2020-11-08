#if 0
#include<stdio.h>
/*
5位运动员参加了10米台跳水比赛，有人让他们预测比赛结果：

A选手说：B第二，我第三；

B选手说：我第二，E第四；

C选手说：我第一，D第二；

D选手说：C最后，我第三；

E选手说：我第四，A第一；

比赛结束后，每位选手都说对了一半，请编程确定比赛的名次。
*/
int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int e = 0;
	for (a = 1; a <= 5; a++)
	{
		for (b = 1; b <= 5; b++)
		{
			for (c = 1; c <= 5; c++)
			{
				for (d = 1; d <= 5; d++)
				{
					for (e = 1; e <= 5; e++)
					{
						if (((b == 2) + (a == 3) == 1) &&
							((b == 2) + (e == 4) == 1) &&
							((c == 1) + (d == 2) == 1) &&
							((c == 5) + (d == 3) == 1) &&
							((e == 4) + (a == 1) == 1)){//判断是否有一半对
							if ((a*b*c*d*e == 120) && (a + b + c + d + e == 15)){
								//（1+2+3+4+5=15）（1*2*3*4*5=120）保证没有并列
								printf("a=%d b=%d c=%d d=%d e=%d\n", a, b, c, d, e);
							}
						}
					}
				}
			}
		}
	}

	return 0;
}
#endif
#include <stdio.h>

int checkData(int *p)
{
	int tmp[7] = { 0 }; //标记表，实际是哈希表的思路。一开始每个元素都是0。

	int i;
	for (i = 0; i < 5; i++)
	{
		if (tmp[p[i]]) //如果这个位置的标记已经是1，则代表重复，直接返回0。
		{
			return 0;
		}
		tmp[p[i]] = 1; //如果不是，则给这个位置标记为1。
	}
	return 1; //全部标记完毕也没有出现重复的情况，代表OK。
}

int main()
{
	int p[5]; //0 1 2 3 4分别代表a b c d e

	for (p[0] = 1; p[0] <= 5; p[0]++)
	{
		for (p[1] = 1; p[1] <= 5; p[1]++)
		{
			for (p[2] = 1; p[2] <= 5; p[2]++)
			{
				for (p[3] = 1; p[3] <= 5; p[3]++)
				{
					for (p[4] = 1; p[4] <= 5; p[4]++) //五层循环遍历
					{
						//这里是五个人的描述，由于比较表达式只有0和1两个结果，如果要两个条件有且只有一个为真，则可以用比较表达式的值总和为1的方式直接判定。别忘了还要判定不能并列。
						if ((p[1] == 2) + (p[0] == 3) == 1 && //B第二，我第三
							(p[1] == 2) + (p[4] == 4) == 1 && //我第二，E第四
							(p[2] == 1) + (p[3] == 2) == 1 && //我第一，D第二
							(p[2] == 5) + (p[3] == 3) == 1 && //C最后，我第三
							(p[4] == 4) + (p[0] == 1) == 1 && //我第四，A第一
							checkData(p) //不能并列
							)
						{
							for (int i = 0; i < 5; i++)
							{
								printf("%d ", p[i]);
							}
							putchar('\n');
						}
					}
				}
			}
		}
	}

	return 0;
}


//※之后为扩展了解内容。



//改进一：



//检查是否重复的过程，我们是用一个数组来做的，实际每个标签只有0和1两种可能，没必要一定要用数组做，可以考虑用一个位来做（哈希中的位图），代码如下：





int checkData(int *p)
{
	char tmp = 0;

	int i;
	for (i = 0; i < 5; i++)
	{
		tmp |= 1 << p[i];
		//tmp每次或上一位1，p[i]如果是1~5都有，则1<<1到1<<5都或上的结果将会是00111110，如果有并列，则一定会至少却其中一个1，结果就不会是00111110，所以可以判断tmp最终的结果是不是这个数字来判断有没有重复。
	}
	return tmp == 0x3E;
}




//改进二：



//循环代码又长又难看，可以考虑改成递归：





void diveRank(int * p, int n)
{
	if (n >= 5) //此时的n是用来控制循环层数的。
	{
		if ((p[1] == 2) + (p[0] == 3) == 1 && //B第二，我第三
			(p[1] == 2) + (p[4] == 4) == 1 && //我第二，E第四
			(p[2] == 1) + (p[3] == 2) == 1 && //我第一，D第二
			(p[2] == 5) + (p[3] == 3) == 1 && //C最后，我第三
			(p[4] == 4) + (p[0] == 1) == 1 && //我第四，A第一
			checkData(p)) //查重
		{
			for (int i = 0; i < 5; i++)
			{
				printf("%d ", p[i]);
			}
			putchar('\n');
		}
		return;
	}

	for (p[n] = 1; p[n] <= 5; p[n]++)
	{
		diveRank(p, n + 1); //通过递归模拟多层循环，每进一次递归相当于进了一层新的循环。
	}
}

int main()
{
	int p[5];

	diveRank(p, 0);

	return 0;
}




//改进三：



//以上的方法只是让代码简单了点，但还是需要5 ^ 5次比较，而如果本来就是做1~5的排列组合的话只需要5!次比较，能极大的减少遍历所需的次数（复杂度由O(n^n)降低为O(n!)），那是不是可以用一个递归完成对1~5的全排列呢？当然是可以的，所以我们可以进一步优化遍历的方式，将遍历用的递归程序改成这样：



#include <stdio.h>

void swapArgs(int * a, int * b) //交换函数
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void diveRank(int * p, int n)
{
	if (n >= 5) //此时的n也是用来控制循环层数的。
	{
		if ((p[1] == 2) + (p[0] == 3) == 1 && //B第二，我第三
			(p[1] == 2) + (p[4] == 4) == 1 && //我第二，E第四
			(p[2] == 1) + (p[3] == 2) == 1 && //我第一，D第二
			(p[2] == 5) + (p[3] == 3) == 1 && //C最后，我第三
			(p[4] == 4) + (p[0] == 1) == 1)   //我第四，A第一
			//由于此时是执行的全排列，所以查重也省了。
		{
			for (int i = 0; i < 5; i++)
			{
				printf("%d ", p[i]);
			}
			putchar('\n');
		}
		return;
	}

	int i;
	for (i = n; i < 5; i++) //这个递归方式就完成了对1~5的全排列，方法是从后向前不停的执行交换。可以参考改进二和原代码，将这个递归程序写回成循环后，可以更好的理解。
	{
		swapArgs(p + i, p + n);
		diveRank(p, n + 1);
		swapArgs(p + i, p + n);
	}
}

int main()
{
	int p[5] = { 1, 2, 3, 4, 5 }; //当然由于是全排列，所以初值必须给好。

	diveRank(p, 0);

	return 0;
}