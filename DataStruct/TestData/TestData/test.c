#include<stdio.h>
#include<windows.h>

// ����쳲������ݹ�Fibonacci��ʱ�临�Ӷȣ�
long long Fibonacci_r(size_t N) {
	return N < 2 ? N : Fibonacci_r(N - 1) + Fibonacci_r(N - 2);
}
long long *Fibonacci(size_t N)
{
	long long * FibArray = malloc(sizeof(long long)*(N +1));//�����ڴ��
	FibArray[0] = 0;
	FibArray[1] = 1;

	//�Կռ任ʱ��
	for (size_t i = 2; i <= N; ++i){
		FibArray[i] = FibArray[i - 1] + FibArray[i - 2];
	}
	return FibArray;
}

int main()
{
	//printf("%d\n", Fibonacci_r(40));//��Ҫһ��ʱ��
	printf("%d\n", Fibonacci(40));//��Ҫһ��ʱ��
	system("pause");
	return 0;
}