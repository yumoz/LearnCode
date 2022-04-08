#include "SList.h"

void testSList()
{
	//SListNode* phead = NULL;
	SListNode * pList = NULL;
	printf("β�壺\n");
	SListPushBack(&pList, 1);
	SListPushBack(&pList, 2);
	SListPushBack(&pList, 3);
	SListPushBack(&pList, 4);
	SListPrint(pList);

	printf("ͷ�壺\n");
	SListPushFront(&pList, -1);
	SListPushFront(&pList, -2);
	SListPushFront(&pList, -3);
	SListPrint(pList);

	printf("βɾ��\n");
	SListPopBack(&pList);
	SListPopBack(&pList);
	SListPrint(pList);

	printf("ͷɾ��\n");
	SListPopFront(&pList);
	SListPopFront(&pList);
	SListPrint(pList);

	printf("Find 2 and change:\n");
	SListNode * pos =SListFind(pList, 2);
	if (pos){
		pos->data = 30;
	}
	SListPrint(pList);

	printf("�в壺\n");
	SListNode * pos2 = SListFind(pList, 1);//ע����Ʋ���λ�ã���ֹ���
	SListInsertAfter(pos2, 50);
	SListPrint(pList);

	printf("��ɾ��\n");
	SListNode *pos3 = SListFind(pList, 1);
	SListEraseAfter(pos3);
	SListPrint(pList);

	printf("�������٣�\n");
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