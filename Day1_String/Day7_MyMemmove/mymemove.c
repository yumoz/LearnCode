#include<stdio.h>
#include<windows.h>

//�������ص�
void *my_memmove(void *det, const void *src, int n)
{
	void *ret = det;
	if ((char*)det <= (char *)src || (char *)det >= (char *)src + n){
		while (n--){
			*(char *)det = *(char *)src;
			det = (char *)det + 1;
			src = (char *)src + 1;
		}
	}
	else{
		det = (char *)det + n - 1;
		src = (char *)src + n - 1;
		while (n--){
			*(char *)det = *(char *)src;
			det = (char *)det - 1;
			src = (char *)src - 1;
		}
	}
	return ret;
}
int main()
{
	char arr[10] = "1234";
	char dst[10] = "56789";
	my_memmove(dst, arr, 4);
	printf("%s\n", dst);
	system("pause");
	return 0;
}