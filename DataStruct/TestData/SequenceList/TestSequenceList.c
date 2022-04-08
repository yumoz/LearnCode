#include "SeqList.h"

int main()
{
	SeqList L;
	DataType data;
	//��ʼ��˳���
	InitSeqList(&L);
	//�ڱ��в���Ԫ��
	printf("�����ڱ��в���Ԫ��(1,2,3,4,5)��\n");
	InsList(&L, 1, 1);
	InsList(&L, 2, 2);
	InsList(&L, 3, 3);
	InsList(&L, 4, 4);
	InsList(&L, 5, 5);

	//��ӡ����Ԫ��
	printf("����Ԫ���У�\n");
	PrintList(&L);
	//ͷ��
	printf("�ڱ�ͷ���β���Ԫ�أ�6,7:\n");
	PushFront(&L, 6);
	PushFront(&L, 7);
	//β��
	printf("�ڱ�β���β���Ԫ�أ�8,9:\n");
	PushBack(&L, 8);
	PushBack(&L, 9);
	printf("����Ԫ���У�\n");
	PrintList(&L);
	//ͷɾ
	printf("ͷɾһ��Ԫ��:\n");
	PopFront(&L);
	//βɾ
	printf("βɾһ��Ԫ��:\n");
	PopBack(&L);
	//������е�4��Ԫ��ֵ
	PrintList(&L);
	printf("���е�4��Ԫ��ֵΪ��\n%d\n", GetData(&L, 4));
	//���ұ��е� i��Ԫ�ص�λ��
	printf("Ԫ��2�ڱ��е�λ��Ϊ��\n");
	printf("%d\n", Locate(&L, 2));
	//ɾ�����е�2��Ԫ�ض�Ӧ��ֵ
	printf("ɾ�����е�2��Ԫ�أ�%d\n", DelList(&L, 2, &data));
	printf("˳���ĳ���Ϊ��%d\n", LengthList(&L));
	printf("����Ԫ��Ϊ��\n");
	PrintList(&L);
	//printf("ɾ����Ԫ��ֵΪ��%d\n", data);
	//���˳���
	ClearList(&L);
	PrintList(&L);
	system("pause");
	return 0;
}