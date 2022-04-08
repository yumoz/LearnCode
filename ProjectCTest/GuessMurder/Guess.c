#include<stdio.h>
//A说：不是我。B说：是C。C说：是D。D说：C在胡说  ；已知3个人说了真话，1个人说的是假话
#if 0
int main()
{
	int killer;
	for (killer = 'A'; killer <= 'D'; killer++)
	{
		if (((killer != 'A') + (killer == 'C') + (killer == 'D') + (killer != 'D')) == 3)
			//三真一假，进行逻辑判断
		{
			printf("凶手是%c", killer);
		}
	}
	return 0;
}
#endif

int main()
{
	int murder[4] = { 0 }; //默认4个人都不是凶手

	int i;
	for (i = 0; i < 4; i++) //遍历假设四个人中的某个人是凶手
	{
		murder[i] = 1; //假设某个人是凶手
		if ((murder[0] != 1) +
			(murder[2] == 1) +
			(murder[3] == 1) +
			(murder[3] != 1) == 3)
		{
			break; //满足就代表就是你了！
		}
		murder[i] = 0; //不满足还他清白
	}

	putchar('A' + i); //打印凶手的编号。我们的编号是0 1 2 3，加上'A'后变成A B C D。
	return 0;
}