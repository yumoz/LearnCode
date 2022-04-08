#include "DynamicSeqList.h"

void TestSeqlist()
{

	SL s;
	SeqListInit(&s);

	printf("尾插: \n");
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	SeqListPrint(&s);

	printf("头插:\n");
	SeqListPushFront(&s, -1);
	SeqListPushFront(&s, -2);
	SeqListPrint(&s);

	printf("头删:\n");
	SeqListPopFront(&s);
	SeqListPrint(&s);

	printf("尾删:\n");
	SeqListPopBack(&s);
	SeqListPrint(&s);

	printf("中间插入：\n");
	SeqListInsert(&s, 3, 10);
	SeqListPrint(&s);

	printf("中间删除：\n");
	SeqListErase(&s, 3);
	SeqListPrint(&s);

	printf("Find it:\n");
	int key = -1;
	int ret = SeqListFind(&s, key);
	printf("	%4d是第%d个位置的数字\n", key, ret);

	printf("销毁顺序表\n");
	SeqListDestory(&s);
	SeqListPrint(&s);


}
int main()
{
	TestSeqlist();//测试
	system("pause");
	return 0;
}