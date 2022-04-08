#include<stdio.h>
#include<windows.h>

// 计算斐波那契递归Fibonacci的时间复杂度？
long long Fibonacci_r(size_t N) {
	return N < 2 ? N : Fibonacci_r(N - 1) + Fibonacci_r(N - 2);
}
long long *Fibonacci(size_t N)
{
	long long * FibArray = malloc(sizeof(long long)*(N +1));//开辟内存块
	FibArray[0] = 0;
	FibArray[1] = 1;

	//以空间换时间
	for (size_t i = 2; i <= N; ++i){
		FibArray[i] = FibArray[i - 1] + FibArray[i - 2];
	}
	return FibArray;
}

int main()
{
	//printf("%d\n", Fibonacci_r(40));//需要一段时间
	printf("%d\n", Fibonacci(40));//需要一段时间
	system("pause");
	return 0;
}