#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<windows.h>

void *My_memcpy(void *dst, const void *src, size_t size)
{
	char *psrc;
	char *pdst;
	if (NULL == dst || NULL == src){//判断指针是否为空	
		return NULL;
	}
	if ((src < dst) && (char *)src + size >(char *)dst){ // 自后向前拷贝	
		psrc = (char *)src + size - 1;
		pdst = (char *)dst + size - 1;
		while (size--){
			*pdst-- = *psrc--;
		}
	}
	else{
		psrc = (char *)src;
		pdst = (char *)dst;
		while (size--){
			*pdst++ = *psrc++;
		}
	}
	return dst;
}

int main()
{
	char buf[100] = "abcdefghijk";
	char dst[100] = {0};
	My_memcpy(dst, buf, 11);
	printf("%s\n", dst);
	system("pause");
	return 0;
}
