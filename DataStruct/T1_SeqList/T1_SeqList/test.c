#include"SeqList.h"

void test()
{
	SL s;
	//˳����ʼ��
	SeqListInit(&s);
	printf("��ʼ����");
	SeqListPrint(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 7);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 9);
	SeqListPushBack(&s, 6);
	SeqListPushBack(&s, 10);
	SeqListPushBack(&s, 8);

	printf("β���");
	SeqListPrint(&s);

	/*printf("Sort��");
	BubbleSort(&s);
	SeqListPrint(&s);*/


	printf("BinSearch:\n");
	printf("Find 7 located %d\n",Binarysearch(&s, 7));




	/*SeqListPopBack(&s);
	SeqListPopBack(&s);
	printf("βɾ��");
	SeqListPrint(&s);


	SeqListPushFront(&s, -1);
	SeqListPushFront(&s, -2);
	printf("ͷ���");
	SeqListPrint(&s);

	SeqListPopFront(&s);
	SeqListPopFront(&s);
	printf("ͷɾ��");
	SeqListPrint(&s);

	printf("��λ�壺");
	SeqListInsert(&s, 3, -1);
	SeqListPrint(&s);

	printf("��λɾ��");
	SeqListErase(&s, 3);
	SeqListPrint(&s);

	printf("��������");
	printf("Find 3: the %d number \n",SeqListFind(&s, 1));*/

	//printf("����˳���");
	//SeqListDestory(&s);
	////SeqListPrint(&s);



}

int main()
{
	test();
	system("pause");
	return 0;
}