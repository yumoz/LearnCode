#include<stdio.h>
#include<windows.h>
#include<assert.h>

typedef int SListDataType;

typedef struct SListNode
{
	SListDataType data;
	struct SListNode *next;
}SListNode;

SListNode* ReverseList(SListNode *head)
{
	if (head == NULL || head->next == NULL)
		return head;
	SListNode *n1 = NULL, *n2 = head, *n3 = head->next;
	while (n2){
		//��ת
		n2->next = n1;
		//����
		n1 = n2;
		n2 = n3;
		if (n3)
		{
			n3 = n3->next;
		}
	}
	return n1;
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

void SListPrint(SListNode*phead)
{
	SListNode* cur = phead;
	while (cur != NULL){
		printf("	%4d ", cur->data);
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

//β����������
void SListPushBack(SListNode** pphead, SListDataType x)//β��
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
			tail = tail->next;//��������tail���ƶ���β���ڵ�tailΪ��
			// ����tail ++��
		}
		tail->next = newNode;
	}
}
void testSList()
{
	//SListNode* phead = NULL;
	SListNode * pList = NULL;
	printf("β�壺\n");
	SListPushBack(&pList, 1);
	SListPushBack(&pList, 2);
	SListPushBack(&pList, 3);
	SListPushBack(&pList, 4);
	SListPushBack(&pList, 5);
	SListPushBack(&pList, 6);
	SListPushBack(&pList, 7);
	SListPrint(pList);

	printf("���ú��������\n");
	SListNode* ret = ReverseList(pList);
	SListPrint(ret);

}
int main()
{
	testSList();
	system("pause");
	return 0;
}