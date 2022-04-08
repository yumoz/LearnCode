#include"SeqList.h"

//˳����ʼ��
void SeqListInit(SL *ps)
{
	//ps->a = (SLDatatype*)malloc(sizeof(SLDatatype) * 4);

	ps->size = 0;
	//ps->a = NULL;
	//ps->capacity = 0;
}

//˳���β��
void SeqListPushBack(SL*ps, SLDatatype x)
{
	assert(ps);
	ps->a[ps->size] = x;
	ps->size++;
}
//˳���βɾ
void SeqListPopBack(SL*ps)
{
	assert(ps);
	ps->a[ps->size - 1] = 0;
	ps->size--;
}

//˳���ͷ��
void SeqListPushFront(SL* ps, SLDatatype x)
{
	assert(ps);
	int end = ps->size - 1;//ĩβ
	while (end >= 0){
		ps->a[end + 1] = ps->a[end];
		--end;
	}
	ps->a[0] = x;//��������
	ps->size++;//˳���������չ1
}

//˳���ͷɾ
void SeqListPopFront(SL*ps)
{
	assert(ps);
	int start = 0;
	while (start < ps->size - 1){
		ps->a[start] = ps->a[start + 1];
		++start;
	}
	ps->size--;//ɾ��Ԫ�أ�������С
}

//����λ�ò���
void SeqListInsert(SL* ps, int pos, SLDatatype x)
{
	assert(ps);
	assert(pos <= (ps ->size) && pos >= 0);
	
	//���Լ���������Ƿ���Բ���
	//SeqListCheckCapacity(ps);

	int end = ps->size - 1;
	while (end >= pos){
		ps->a[end + 1] = ps->a[end];//����֮������ƶ�һλ
			--end;
	}
	ps->a[pos] = x;//��������
	ps->size++;//�Ѿ����룬��������
}
//����λ��ɾ��
void SeqListErase(SL* ps, int pos)
{
	assert(ps);
	assert(pos < ps->size && pos >= 0);

	int start = pos;
	while (start < ps->size - 1)//�ж�Ҫɾ��λ�ã����Ƿ�����Ч��Χ��
	{
		ps->a[start] = ps->a[start + 1];//ɾ������һλ��ǰһλ�ƶ�
		++start;//���ѭ����λ
	}
	ps->size--;//ɾ��˳���������С
}
//����
int SeqListFind(SL* ps, SLDatatype x)
{
	assert(ps);
	int i = 0;
	while (i < ps->size){
		if (ps->a[i] == x){
			return i;
		}
		++i;//�������ң���Χ��
	}
	return -1;//û�ҵ�
}

//����˳���
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
//˳�������
void BubbleSort(SL*ps)
{
	assert(ps);
	int len = ps->size -1;
	int flag = 1;
	for (int i = 0; i < len;i++){
		flag = 0;//�Ƚ���־λ��Ϊ0�������ж��Ƿ�ִ���˽���
		for (int j=0; j <= len-i; j++){
			if (ps->a[j] > ps->a[j + 1]){
				swap(&(ps->a[j]), &(ps->a[j + 1]));
				flag = 1;//��־λ�ı䣬ִ���˽���
				
			}
			
		}
		if (flag == 0)
			return;
	}
}
//����һ�����������ֲ��ҷ�����
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
				swap(&speq->a[maxpos], &speq->a[speq->size - 1 - i]);  // �Լ����Լ������Ϊ0
			}
		}
	}
}

//���ֲ���
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
//��ӡ˳�������
void SeqListPrint(SL* ps)
{
	assert(ps);
	for (int i = 0; i < ps->size; ++i)
	{
		printf("%3d ", ps->a[i]);
	}
	printf("\n");
}