#include<stdio.h>
#include<Windows.h>
#pragma warning(disable:4996)
#include<string.h>
#include<assert.h>

//ȫ�ֱ��������������
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
void ReverseWord(char *left,char *right)//�ַ����������ú���
{
	assert(left&&right);//�жϴ���ָ���Ƿ�Ϊ�գ�����if������
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
	ReverseWord(arr,arr+len-1);//���������ַ��������ֱ�Ϊ��һ��Ԫ�غ����һ��Ԫ��
	while(*arr){//����Ԫ�ز���ʱ
		char *begin =arr;//���ַ�����ֵ��begin��ַ
		while(*arr && (*arr!=' ')){//�������û�н�����ָ����������
			arr++;
		}
		ReverseWord(begin,arr-1);//���õ���
		if(*begin == ' '){
			arr++;
		}
	}
}
int main()
{
	char arr[100]={0};//
	gets(arr);//�ַ������뺯��������һ����fgets��ʽ������
	int len=strlen(arr);//���������ַ����ĳ���
//	Reverse(arr,len);//����ַ�ͳ���
	ReverseWord(arr, arr + len - 1);
	printf("%s\n",arr);
	system("pause");
	return 0;
}


//����С��������һ�ַ�����ѭ��������
int main()
{
	int x = 0, y = 0;
	int lcm = 0;//��󹫱���
	scanf("%d %d", &x, &y);
	if (x<y)//�Ƚϴ�С������˳�� ֮�� x>y 
	{
		int temp = x;
		x = y;
		y = temp;
	}
	for (int i = x; i>0; i++){//���������������ʼ�ң���Ϊ�������������������������Ǹ�
		if (i%x == 0 && i%y == 0){//�ñ���������ģx��y���������Ϊ0����ô����Ϊ����ΪҪ�ҵĹ�����
			lcm = i;//��ס����
			break;//����ѭ��
		}
	}
	printf("%d", lcm);
	system("pause");
	return 0;
}

//����ĳ����Ϊʲô�����
#include<stdio.h>

#include<Windows.h>

int main()
{
	double x = 2;
	double y;
	y = x + 3 / 2;//�˴�3/2Ϊ1
	printf("%lf\n", y);
	system("pause");
	return 0;
}

#endif