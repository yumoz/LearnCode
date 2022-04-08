#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int SListDataType;

//���� �ض���
typedef struct SListNode 
{
	SListDataType data;
	struct SListNode * next;//�����һ���ṹ����׵�ַ
}SListNode;

//��̬����һ���ڵ�
SListNode * BuySListNode(SListDataType x);
//������β��
void SListPushBack(SListNode** pphead, SListDataType x);//β���
//������βɾ
void SListPopBack(SListNode** pphead);//βɾ��
//������ͷ��
void SListPushFront(SListNode** pphead, SListDataType x); //ͷ���
//������ͷɾ
void SListPopFront(SListNode** pphead);//ͷɾ��

//��������� �� ��
SListNode* SListFind(SListNode * plist, SListDataType x);

//��������posλ��֮�����x
void SListInsertAfter(SListNode *pos, SListDataType x);

//������ɾ��posλ��֮���ֵ
void SListEraseAfter(SListNode * pos);

//�����������
void SListDestory(SListNode * plist);

void SListDestroy(SListNode *pList);
//�������ӡ
void SListPrint(SListNode*phead);


