#include"SeqList.h"

//顺序表初始化
void SeqListInit(SL *ps)
{
	//ps->a = (SLDatatype*)malloc(sizeof(SLDatatype) * 4);

	ps->size = 0;
	//ps->a = NULL;
	//ps->capacity = 0;
}

//顺序表尾插
void SeqListPushBack(SL*ps, SLDatatype x)
{
	assert(ps);
	ps->a[ps->size] = x;
	ps->size++;
}
//顺序表尾删
void SeqListPopBack(SL*ps)
{
	assert(ps);
	ps->a[ps->size - 1] = 0;
	ps->size--;
}

//顺序表头插
void SeqListPushFront(SL* ps, SLDatatype x)
{
	assert(ps);
	int end = ps->size - 1;//末尾
	while (end >= 0){
		ps->a[end + 1] = ps->a[end];
		--end;
	}
	ps->a[0] = x;//插入数据
	ps->size++;//顺序表容量扩展1
}

//顺序表头删
void SeqListPopFront(SL*ps)
{
	assert(ps);
	int start = 0;
	while (start < ps->size - 1){
		ps->a[start] = ps->a[start + 1];
		++start;
	}
	ps->size--;//删除元素，容量缩小
}

//任意位置插入
void SeqListInsert(SL* ps, int pos, SLDatatype x)
{
	assert(ps);
	assert(pos <= (ps ->size) && pos >= 0);
	
	//可以检查容量看是否可以插入
	//SeqListCheckCapacity(ps);

	int end = ps->size - 1;
	while (end >= pos){
		ps->a[end + 1] = ps->a[end];//插入之后，向后移动一位
			--end;
	}
	ps->a[pos] = x;//插入数据
	ps->size++;//已经插入，容量扩大
}
//任意位置删除
void SeqListErase(SL* ps, int pos)
{
	assert(ps);
	assert(pos < ps->size && pos >= 0);

	int start = pos;
	while (start < ps->size - 1)//判断要删除位置，它是否在有效范围内
	{
		ps->a[start] = ps->a[start + 1];//删除，后一位向前一位移动
		++start;//向后循环移位
	}
	ps->size--;//删除顺序表，内容缩小
}
//查找
int SeqListFind(SL* ps, SLDatatype x)
{
	assert(ps);
	int i = 0;
	while (i < ps->size){
		if (ps->a[i] == x){
			return i;
		}
		++i;//继续查找，范围内
	}
	return -1;//没找到
}

//销毁顺序表
//void SeqListDestory(SL* ps)
//{
//	free(ps);
//	//ps->a = NULL;
//	ps->size = 0;
//}


static void swap(int *x, int *y)
{
	*x ^= *y;
	*y ^= *x;
	*x ^= *y;
}
//顺序表排序
void BubbleSort(SL*ps)
{
	assert(ps);
	int len = ps->size -1;
	int flag = 1;
	for (int i = 0; i < len;i++){
		flag = 0;//先将标志位置为0，后续判断是否执行了交换
		for (int j=0; j <= len-i; j++){
			if (ps->a[j] > ps->a[j + 1]){
				swap(&(ps->a[j]), &(ps->a[j + 1]));
				flag = 1;//标志位改变，执行了交换
				
			}
			
		}
		if (flag == 0)
			return;
	}
}
//定义一个函数给二分查找法排序
static void selectsort(SL*speq)
{
	int i = 0, j = 0, k = 0;
	int maxpos = 0;
	assert(speq);
	for (i = 0; i < speq->size - 1; i++)
	{
		maxpos = 0;
		for (j = 1; j < speq->size - i; j++)
		{
			if (speq->a[maxpos] < speq->a[j])
			{
				maxpos = j;
				k = 1;
			}
		}
		if (0 == k)
		{
			return;
		}
		else
		{
			if (maxpos != speq->size - 1 - i)
			{
				swap(&speq->a[maxpos], &speq->a[speq->size - 1 - i]);  // 自己跟自己亦或会变为0
			}
		}
	}
}

//二分查找
int Binarysearch(SL*ps, SLDatatype data)
{
	int mid = 0;
	int left = 0, right = 0;
	assert(ps);
	left = 0;
	right = ps->size - 1;
	mid = (ps->size) / 2;
	selectsort(ps);
	while (left <= right)
	{
		if (data == ps->a[mid])
		{
			return mid;
		}
		else if (data > ps->a[mid])
		{
			left = mid;
			mid = mid + (right - mid) / 2 + 1;
		}
		else
		{
			right = mid;
			mid = left + (mid - left) / 2 + 1;
		}
	}
	return -1;
}
//打印顺序表内容
void SeqListPrint(SL* ps)
{
	assert(ps);
	for (int i = 0; i < ps->size; ++i)
	{
		printf("%3d ", ps->a[i]);
	}
	printf("\n");
}