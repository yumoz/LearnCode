#include "SList.h"

//链表缺点：相比顺序表，申请内存效率低

//尾部删除
void SListPopBack(SListNode** pphead)
{
	//1、空
	//2、一个节点
	//3、一个以上节点
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
		tail = NULL;//写上不写都没事
		prev->next = NULL;

	}
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
//尾部插入数据
void SListPushBack(SListNode** pphead,SListDataType x)//尾插
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
//打印 遍历链表 注意cur
void SListPrint(SListNode*phead)
{
	SListNode* cur = phead;
	while (cur!=NULL){
		printf("	%4d ",cur->data);
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

//头删
//void SListPopFront(SListNode** pplist)
//{
//	// 1.空
//	// 2.一个
//	// 3.两个及以上
//	SListNode* first = *pplist;
//	if (first == NULL)//空
//	{
//		return;
//	}
//	else if (first->next == NULL)//一个节点
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
//头删方法2
//需要改变头部指针
void SListPopFront(SListNode** pplist)
{
	// 1.空
	// 2.一个 + 3.两个及以上
	SListNode* first = *pplist;
	if (first == NULL)//空
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
//查找，并修改
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

//当前位置之后插入，之前插入可以使用双向链表，
void SListInsertAfter(SListNode* pos, SListDataType x)
{
	assert(pos);
	SListNode* next = pos->next;//先保存next的地址

	// pos newnode next
	SListNode* newnode = BuySListNode(x);
	pos->next = newnode;
	newnode->next = next;
}

//单链表有缺点，哈希图和单链表
//void SListInsertAfter(SListNode* pos, SListDataType x)
//{
//	assert(pos);
//	
//	SListNode* newnode = BuySListNode(x);//申请一个节点
//	newnode->next = pos->next;//把要插入的节点给申请的节点连接
//	pos->next = newnode;//把新的节点给插入位置之后的节点
//
//}
//删除后一位置
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
//链表销毁
void SListDestroy(SListNode *pList)
{
	SListNode *p;//让p指向头结点
	while (pList->next){//当头结点的指针域不为0，即不是链尾时
		p = pList->next;
		pList->next = p->next;
		free(p);//删除p
		//pList->next--;
	}
	pList->next--;
	pList->next = NULL;//最后不要忘了让指向头结点的指针的指针的值为0
}
