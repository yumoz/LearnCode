#include "SeqList.h"

int k = 0;  //ȫ�ֱ��������������ֲ�����ѭ������
//��ʼ��˳���
void InitSeqList(PSeqList L)
{
	if (L == NULL)
	{
		return;
	}
	L->length = 0;
}

//��˳���ĳ���

int LengthList(PSeqList L)
{
	if (L == NULL)
	{
		return 0;
	}
	return L->length;
}

//�������ݱ��е�i��Ԫ�ص�ֵ
int GetData(PSeqList L, int i)
{
	if (L->length < 1 || (L->length > LengthList(L)))
	{
		return 0;
	}
	//����Ԫ�ص���Ŵ�1��ʼ�������±��0��ʼ����i��Ԫ�ض�Ӧ�������±�Ϊi-1;
	return L->data[i - 1];
}

//��L�е�i��λ�ã������µ�����Ԫ��e

int InsList(PSeqList L, int i, DataType e)
{

	//�жϲ���λ���Ƿ�Ϸ�
	if (i < 1 || L->length >(LengthList(L) + 1))
	{
		printf("����λ�ò��Ϸ�!\n");
		return 0;
	}
	//�ж�˳����Ƿ�����
	else if (L->length >= ListSize)
	{
		printf("˳������������ܲ��룡\n");
		return 0;
	}
	else
	{
		for (k = i; k <= L->length; k--)
		{
			L->data[k + 1] = L->data[k];
		}
		L->data[i - 1] = e;
		L->length++;   //���ݱ�ĳ��ȼ�1
		return 1;
	}
	return 0;
}

//ɾ��L�ĵ�i������Ԫ��

int DelList(PSeqList L, DataType i, DataType* e)
{
	if (L->length < 1)
	{
		printf("��Ϊ�գ�\n");
		return  0;
	}
	*e = L->data[i - 1];
	for (k = i; k < L->length; k++)
	{
		L->data[k - 1] = L->data[k];
	}
	L->length--;
	return *e;
}

//����e�ڱ��е�λ��

int Locate(PSeqList L, DataType e)
{
	for (k = 0; k < L->length; k++)
	{
		if (L->data[k] == e)
		{
			//kΪe��Ӧ�������±꣬�ڱ��ж�Ӧ���ӦΪk+1
			return k + 1;
		}
	}
	return 0;
}

//ͷ�壬�ڱ�ͷ����Ԫ��e

void PushFront(PSeqList L, DataType e)
{
	if (L->length == ListSize)
	{
		printf("˳������������ܲ��룡\n");
	}
	//������Ԫ�����κ���һλ
	for (k = L->length; k > 0; k--)
	{
		L->data[k] = L->data[k - 1];
	}
	//����Ԫ��
	L->data[0] = e;
	L->length++;
}

//ͷɾ,ɾ��˳����еĵ�һ��Ԫ�أ���˳����е�Ԫ��������ǰ�ƶ�һλ

void PopFront(PSeqList L)
{
	if (EmptyList(L))
	{
		printf("˳���Ϊ�գ����ܲ��룡\n");
	}
	for (k = 1; k <= L->length - 1; k++)
	{
		L->data[k - 1] = L->data[k];
	}
	L->length--;
}

//β��
void PushBack(PSeqList L, DataType e)
{
	if (L->length == ListSize)
	{
		printf("˳������������ܲ���!\n");
	}
	L->data[L->length] = e;
	L->length++;
}


//βɾ
void PopBack(PSeqList L)
{
	if (EmptyList(L))
	{
		printf("��Ϊ�գ�\n");
	}
	L->length--;

}

//���˳���
void ClearList(PSeqList L)
{
	L->length = 0;
}

//�жϱ��Ƿ�Ϊ��

int EmptyList(PSeqList L)
{
	if (L->length == 0)
	{
		return 1;
	}
	return 0;
}

//��ӡ����Ԫ��

void PrintList(PSeqList L)
{
	if (EmptyList(L))
	{
		printf("��Ϊ�գ�\n");
		return;
	}
	for (k = 0; k < L->length; k++)
	{
		printf("%-3d", L->data[k]);
	}
	printf("\n");
}