#include "SList.h"

//����ȱ�㣺���˳��������ڴ�Ч�ʵ�

//β��ɾ��
void SListPopBack(SListNode** pphead)
{
	//1����
	//2��һ���ڵ�
	//3��һ�����Ͻڵ�
	if (*pphead == NULL)
	{
		return;
	}
	else if ((*pphead)->next == NULL){
		free(*pphead);
		*pphead = NULL;
	}
	else{
		SListNode* prev = NULL;
		SListNode* tail = *pphead;
		while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		tail = NULL;//д�ϲ�д��û��
		prev->next = NULL;

	}
}

SListNode * BuySListNode(SListDataType x)
{
	//����ڵ�
	SListNode * newNode = (SListNode*)malloc(sizeof(SListNode));
	if (newNode == NULL)
	{
		printf("����ڵ�ʧ��\n");
		exit(-1);
	}
	newNode->data = x;
	newNode->next = NULL;

	return newNode;
}
//β����������
void SListPushBack(SListNode** pphead,SListDataType x)//β��
{
	SListNode* newNode = BuySListNode(x);
	if (*pphead == NULL)
	{
		*pphead = newNode;
	}
	else
	{
		//������β��
		SListNode* tail = *pphead;
		while (tail->next != NULL)//���ʿ�ָ�룬������  �Ѿ��޸�
		{
			tail = tail->next;//�������tail���ƶ���β���ڵ�tailΪ��
			// ����tail ++��
		}
		tail->next = newNode;
	}
}
//��ӡ �������� ע��cur
void SListPrint(SListNode*phead)
{
	SListNode* cur = phead;
	while (cur!=NULL){
		printf("	%4d ",cur->data);
		cur = cur->next;//ǰһ���ṹ���Աnext�����һ���ṹ��ָ��
	}
	printf("    NULL\n");
}

//ͷ��
void SListPushFront(SListNode** pplist, SListDataType x)
{
	assert(pplist);

	// 1.��
	// 2.�ǿ�
	SListNode* newnode = BuySListNode(x);
	if (*pplist == NULL)
	{
		*pplist = newnode;
	}
	else
	{
		newnode->next = *pplist;
		*pplist = newnode;
	}
}

//ͷɾ
//void SListPopFront(SListNode** pplist)
//{
//	// 1.��
//	// 2.һ��
//	// 3.����������
//	SListNode* first = *pplist;
//	if (first == NULL)//��
//	{
//		return;
//	}
//	else if (first->next == NULL)//һ���ڵ�
//	{
//		free(first);
//		*pplist = NULL;
//	}
//	else
//	{
//		SListNode* next = first->next;
//		free(first);
//		*pplist = next;
//	}
//}
//ͷɾ����2
//��Ҫ�ı�ͷ��ָ��
void SListPopFront(SListNode** pplist)
{
	// 1.��
	// 2.һ�� + 3.����������
	SListNode* first = *pplist;
	if (first == NULL)//��
	{
		return;
	}
	else 
	{
		SListNode * next = first->next;

		free(first);
		*pplist = next;
	}
}
//���ң����޸�
SListNode* SListFind(SListNode* plist, SListDataType x)
{
	SListNode* cur = plist;
	while (cur)
	{
		if (cur->data == x)
			return cur;

		cur = cur->next;
	}

	return NULL;
}

//��ǰλ��֮����룬֮ǰ�������ʹ��˫������
void SListInsertAfter(SListNode* pos, SListDataType x)
{
	assert(pos);
	SListNode* next = pos->next;//�ȱ���next�ĵ�ַ

	// pos newnode next
	SListNode* newnode = BuySListNode(x);
	pos->next = newnode;
	newnode->next = next;
}

//��������ȱ�㣬��ϣͼ�͵�����
//void SListInsertAfter(SListNode* pos, SListDataType x)
//{
//	assert(pos);
//	
//	SListNode* newnode = BuySListNode(x);//����һ���ڵ�
//	newnode->next = pos->next;//��Ҫ����Ľڵ������Ľڵ�����
//	pos->next = newnode;//���µĽڵ������λ��֮��Ľڵ�
//
//}
//ɾ����һλ��
//void SListEraseAfter(SListNode* pos)
//{
//	assert(pos);
//	// pos next nextnext
//	SListNode* next = pos->next;
//
//	if (next != NULL)
//	{
//		SListNode* nextnext = next->next;
//		free(next);
//		pos->next = nextnext;
//	}
//}
void SListEraseAfter(SListNode* pos)
{
	assert(pos);
	if (pos->next)
	{
		SListNode* next = pos->next;
		SListNode* nextnext = next->next;
		pos->next = nextnext;
		free(next);
	}
}
//��������
void SListDestroy(SListNode *pList)
{
	SListNode *p;//��pָ��ͷ���
	while (pList->next){//��ͷ����ָ����Ϊ0����������βʱ
		p = pList->next;
		pList->next = p->next;
		free(p);//ɾ��p
		//pList->next--;
	}
	pList->next--;
	pList->next = NULL;//���Ҫ������ָ��ͷ����ָ���ָ���ֵΪ0
}
