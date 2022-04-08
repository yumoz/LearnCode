#include "DynamicSeqList.h"

//初始化顺序表
void SeqListInit(SL *s)//初始化动态顺序表
{
	assert(s);
	s->array = (SLDataType*)malloc(3 * sizeof(SLDataType));
	//assert(s->array);
	if (s->array == NULL)
	{
		printf("申请内存失败\n");
		exit(-1);
	}
	s->size = 0;
	s->capacity = 3;
}

//检测容量，看顺序表是否饱和
void CheckCapacity(SL *s)
{
	if (s->size == s->capacity)
	{
		s->array = (SLDataType*)realloc(s->array, 2 * s->capacity*sizeof(SLDataType));
		assert(s->array);
		s->capacity *= 2;
	}
}

//尾插
void SeqListPushBack(SL *s, SLDataType x)//
{
	assert(s);
	CheckCapacity(s);
	s->array[s->size] = x;
	s->size++;
	//SeqListInsert(s, s->size, x);//way 2
}

//头插 给顺序表头部插入一个数字
void SeqListPushFront(SL *s, SLDataType x)//头插
{
	int i = s->size;//顺序表总容量
	assert(s);
	CheckCapacity(s);
	assert(s);

	for (; i >= 0; i--){
		s->array[i] = s->array[i - 1];
	}
	s->array[0] = x;
	s->size++;

	//SeqListInsert(s, 0, x);
}

//头删 顺序表容量减少一个
void SeqListPopFront(SL *s)
{
	assert(s);
	size_t i = 0;
	if (s->size == 1)
	{
		s->size = 0;
	}
	else
	{
		for (i = 0; i < s->size; i++)
		{
			s->array[i] = s->array[i + 1];
		}
	}
	s->size--;

	//SeqListErase(s, 0);
}

void SeqListPopBack(SL *s)//尾删
{
	assert(s);
	if (s->size == 0)
	{
		printf("顺序表里面无数据\n");
		return;
	}
	s->size--;

	//SeqListErase(s, s->size--);
}

int SeqListFind(SL *s, SLDataType x)
{
	for (size_t i = 0; i < s->size; i++){
		if (s->array[i] == x){
			return i;
		}
	}
	return -1;
}
//任意位置插入删除
void SeqListInsert(SL *s, size_t pos, SLDataType x)
{
	assert(s);
	assert(pos <= s->size && pos >= 0);
	CheckCapacity(s);
	size_t end = s->size - 1;
	while (end >= pos)
	{
		s->array[end + 1] = s->array[end];//插入位以后元素向后移动
		--end;
	}
	s->array[pos] = x;// 往pos位置插入数字
	s->size++;
}

//顺序表删除
//指定位置删除
void SeqListErase(SL *s, size_t pos)
{
	assert(s && pos < s->size);//assert括号里面语句写的是正确的范围。或者可以使用 if语句判断，比较明了
	size_t start = pos;
	while (start < s->size - 1){
		s->array[start] = s->array[start + 1];
		++start;
	}
	s->size--;
}
void SeqListDestory(SL *s)//销毁顺序表
{
	assert(s);
	free(s->array);
	s->array = NULL;
	s->size = s->capacity = 0;
}

//遍历顺序表 并打印
void SeqListPrint(SL *s)//打印动态顺序表
{
	size_t i = 0;
	for (; i < s->size; ++i)
	{
		printf("	%4d", s->array[i]);//空格保证的是 输出格式控制，%4d也是格式控制
	}
	printf("\n");
}
