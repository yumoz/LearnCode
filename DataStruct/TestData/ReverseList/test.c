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
		//反转
		n2->next = n1;
		//迭代
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
	//插入节点
	SListNode * newNode = (SListNode*)malloc(sizeof(SListNode));
	if (newNode == NULL)
	{
		printf("申请节点失败\n");
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
		cur = cur->next;//前一个结构体成员next存放下一个结构体指针
	}
	printf("    NULL\n");
}

//头插
void SListPushFront(SListNode** pplist, SListDataType x)
{
	assert(pplist);

	// 1.空
	// 2.非空
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

//尾部插入数据
void SListPushBack(SListNode** pphead, SListDataType x)//尾插
{
	SListNode* newNode = BuySListNode(x);
	if (*pphead == NULL)
	{
		*pphead = newNode;
	}
	else
	{
		//遍历找尾巴
		SListNode* tail = *pphead;
		while (tail->next != NULL)//访问空指针，出问题  已经修改
		{
			tail = tail->next;//形象理解tail在移动，尾部节点tail为空
			// 切勿tail ++；
		}
		tail->next = newNode;
	}
}
void testSList()
{
	//SListNode* phead = NULL;
	SListNode * pList = NULL;
	printf("尾插：\n");
	SListPushBack(&pList, 1);
	SListPushBack(&pList, 2);
	SListPushBack(&pList, 3);
	SListPushBack(&pList, 4);
	SListPushBack(&pList, 5);
	SListPushBack(&pList, 6);
	SListPushBack(&pList, 7);
	SListPrint(pList);

	printf("逆置后的链表：\n");
	SListNode* ret = ReverseList(pList);
	SListPrint(ret);

}
int main()
{
	testSList();
	system("pause");
	return 0;
}