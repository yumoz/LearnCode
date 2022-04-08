#include "SList.h"

void testSList()
{
	//SListNode* phead = NULL;
	SListNode * pList = NULL;
	printf("尾插：\n");
	SListPushBack(&pList, 1);
	SListPushBack(&pList, 2);
	SListPushBack(&pList, 3);
	SListPushBack(&pList, 4);
	SListPrint(pList);

	printf("头插：\n");
	SListPushFront(&pList, -1);
	SListPushFront(&pList, -2);
	SListPushFront(&pList, -3);
	SListPrint(pList);

	printf("尾删：\n");
	SListPopBack(&pList);
	SListPopBack(&pList);
	SListPrint(pList);

	printf("头删：\n");
	SListPopFront(&pList);
	SListPopFront(&pList);
	SListPrint(pList);

	printf("Find 2 and change:\n");
	SListNode * pos =SListFind(pList, 2);
	if (pos){
		pos->data = 30;
	}
	SListPrint(pList);

	printf("中插：\n");
	SListNode * pos2 = SListFind(pList, 1);//注意控制插入位置，防止溢出
	SListInsertAfter(pos2, 50);
	SListPrint(pList);

	printf("中删：\n");
	SListNode *pos3 = SListFind(pList, 1);
	SListEraseAfter(pos3);
	SListPrint(pList);

	printf("链表销毁：\n");
	SListDestroy(pList);
	SListPrint(pList);
	//
}
int main()
{
	testSList();
	system("pause");
	return 0;
}