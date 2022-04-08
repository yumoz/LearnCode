#include "DynamicSeqList.h"

//��ʼ��˳���
void SeqListInit(SL *s)//��ʼ����̬˳���
{
	assert(s);
	s->array = (SLDataType*)malloc(3 * sizeof(SLDataType));
	//assert(s->array);
	if (s->array == NULL)
	{
		printf("�����ڴ�ʧ��\n");
		exit(-1);
	}
	s->size = 0;
	s->capacity = 3;
}

//�����������˳����Ƿ񱥺�
void CheckCapacity(SL *s)
{
	if (s->size == s->capacity)
	{
		s->array = (SLDataType*)realloc(s->array, 2 * s->capacity*sizeof(SLDataType));
		assert(s->array);
		s->capacity *= 2;
	}
}

//β��
void SeqListPushBack(SL *s, SLDataType x)//
{
	assert(s);
	CheckCapacity(s);
	s->array[s->size] = x;
	s->size++;
	//SeqListInsert(s, s->size, x);//way 2
}

//ͷ�� ��˳���ͷ������һ������
void SeqListPushFront(SL *s, SLDataType x)//ͷ��
{
	int i = s->size;//˳���������
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

//ͷɾ ˳�����������һ��
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

void SeqListPopBack(SL *s)//βɾ
{
	assert(s);
	if (s->size == 0)
	{
		printf("˳�������������\n");
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
//����λ�ò���ɾ��
void SeqListInsert(SL *s, size_t pos, SLDataType x)
{
	assert(s);
	assert(pos <= s->size && pos >= 0);
	CheckCapacity(s);
	size_t end = s->size - 1;
	while (end >= pos)
	{
		s->array[end + 1] = s->array[end];//����λ�Ժ�Ԫ������ƶ�
		--end;
	}
	s->array[pos] = x;// ��posλ�ò�������
	s->size++;
}

//˳���ɾ��
//ָ��λ��ɾ��
void SeqListErase(SL *s, size_t pos)
{
	assert(s && pos < s->size);//assert�����������д������ȷ�ķ�Χ�����߿���ʹ�� if����жϣ��Ƚ�����
	size_t start = pos;
	while (start < s->size - 1){
		s->array[start] = s->array[start + 1];
		++start;
	}
	s->size--;
}
void SeqListDestory(SL *s)//����˳���
{
	assert(s);
	free(s->array);
	s->array = NULL;
	s->size = s->capacity = 0;
}

//����˳��� ����ӡ
void SeqListPrint(SL *s)//��ӡ��̬˳���
{
	size_t i = 0;
	for (; i < s->size; ++i)
	{
		printf("	%4d", s->array[i]);//�ո�֤���� �����ʽ���ƣ�%4dҲ�Ǹ�ʽ����
	}
	printf("\n");
}
