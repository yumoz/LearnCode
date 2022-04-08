#include<stdio.h>
#include<Windows.h>
#pragma warning(disable:4996)
#include<string.h>
#include<assert.h>

//全局变量作用域测试题
int a = 1;
void test(){
	int a=2;
	a+=1;
}
int main(){
	test();
	printf("%d\n",a);
	system("pause");
	return 0;
}
#if 0
void ReverseWord(char *left,char *right)//字符串整体逆置函数
{
	assert(left&&right);//判断传入指针是否为空，可用if语句代替
	while(left<right){
		char ret= *left;
		*left=*right;
		*right =ret;
		left++;
		right--;
	}
}
void Reverse(char *arr,int len)
{
	ReverseWord(arr,arr+len-1);//逆置整个字符串参数分别为第一个元素和最后一个元素
	while(*arr){//当首元素不空时
		char *begin =arr;//将字符串赋值给begin地址
		while(*arr && (*arr!=' ')){//如果单词没有结束，指针继续向后走
			arr++;
		}
		ReverseWord(begin,arr-1);//逆置单词
		if(*begin == ' '){
			arr++;
		}
	}
}
int main()
{
	char arr[100]={0};//
	gets(arr);//字符串输入函数，还有一种是fgets形式的输入
	int len=strlen(arr);//计算输入字符串的长度
//	Reverse(arr,len);//传地址和长度
	ReverseWord(arr, arr + len - 1);
	printf("%s\n",arr);
	system("pause");
	return 0;
}


//求最小公倍数的一种方法，循环遍历法
int main()
{
	int x = 0, y = 0;
	int lcm = 0;//最大公倍数
	scanf("%d %d", &x, &y);
	if (x<y)//比较大小，交换顺序 之后 x>y 
	{
		int temp = x;
		x = y;
		y = temp;
	}
	for (int i = x; i>0; i++){//遍历，从最大数开始找，因为公倍数至少是两个数中最大的那个
		if (i%x == 0 && i%y == 0){//用遍历的数来模x和y，如果余数为0，那么就认为此数为要找的公倍数
			lcm = i;//记住此数
			break;//跳出循环
		}
	}
	printf("%d", lcm);
	system("pause");
	return 0;
}

//测试某程序为什么会出错
#include<stdio.h>

#include<Windows.h>

int main()
{
	double x = 2;
	double y;
	y = x + 3 / 2;//此处3/2为1
	printf("%lf\n", y);
	system("pause");
	return 0;
}

#endif