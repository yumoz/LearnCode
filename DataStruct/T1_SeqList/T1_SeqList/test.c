#include"SeqList.h"

void test()
{
	SL s;
	//顺序表初始化
	SeqListInit(&s);
	printf("初始化：");
	SeqListPrint(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 7);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 9);
	SeqListPushBack(&s, 6);
	SeqListPushBack(&s, 10);
	SeqListPushBack(&s, 8);

	printf("尾插后：");
	SeqListPrint(&s);

	/*printf("Sort：");
	BubbleSort(&s);
	SeqListPrint(&s);*/


	printf("BinSearch:\n");
	printf("Find 7 located %d\n",Binarysearch(&s, 7));




	/*SeqListPopBack(&s);
	SeqListPopBack(&s);
	printf("尾删后：");
	SeqListPrint(&s);


	SeqListPushFront(&s, -1);
	SeqListPushFront(&s, -2);
	printf("头插后：");
	SeqListPrint(&s);

	SeqListPopFront(&s);
	SeqListPopFront(&s);
	printf("头删后：");
	SeqListPrint(&s);

	printf("任位插：");
	SeqListInsert(&s, 3, -1);
	SeqListPrint(&s);

	printf("任位删：");
	SeqListErase(&s, 3);
	SeqListPrint(&s);

	printf("查找数：");
	printf("Find 3: the %d number \n",SeqListFind(&s, 1));*/

	//printf("销毁顺序表：");
	//SeqListDestory(&s);
	////SeqListPrint(&s);



}

int main()
{
	test();
	system("pause");
	return 0;
}