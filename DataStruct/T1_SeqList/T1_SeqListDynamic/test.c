#include "DynamicSeqList.h"

void TestSeqlist()
{

	SL s;
	SeqListInit(&s);

	printf("β��: \n");
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	SeqListPrint(&s);

	printf("ͷ��:\n");
	SeqListPushFront(&s, -1);
	SeqListPushFront(&s, -2);
	SeqListPrint(&s);

	printf("ͷɾ:\n");
	SeqListPopFront(&s);
	SeqListPrint(&s);

	printf("βɾ:\n");
	SeqListPopBack(&s);
	SeqListPrint(&s);

	printf("�м���룺\n");
	SeqListInsert(&s, 3, 10);
	SeqListPrint(&s);

	printf("�м�ɾ����\n");
	SeqListErase(&s, 3);
	SeqListPrint(&s);

	printf("Find it:\n");
	int key = -1;
	int ret = SeqListFind(&s, key);
	printf("	%4d�ǵ�%d��λ�õ�����\n", key, ret);

	printf("����˳���\n");
	SeqListDestory(&s);
	SeqListPrint(&s);


}
int main()
{
	TestSeqlist();//����
	system("pause");
	return 0;
}