#pragma once

#include <stdio.h>
#include<windows.h>
#include<assert.h>

#define ListSize 100      //���Ա����󳤶�
typedef int DataType;

typedef struct
{
	DataType data[ListSize];   //������洢���Ա��е�Ԫ��
	DataType length;           //˳���ĳ���

}SeqList, *PSeqList;

void InitSeqList(PSeqList L);  //˳���ĳ�ʼ������
int LengthList(PSeqList L); //��˳���ĳ���
int GetData(PSeqList L, int i); //�������ݱ��е�i��Ԫ�ص�ֵ
int InsList(PSeqList L, int i, DataType e);   //��˳���ĵ�i��λ�ò���Ԫ��
int DelList(PSeqList L, DataType i, DataType* e); //ɾ��˳���L�ĵ�i������Ԫ��
int Locate(PSeqList L, DataType e); //��������Ԫ��e�ڱ��е�λ��
void PushFront(PSeqList L, DataType e); //ͷ�壬�ڱ�ͷ����Ԫ��e
void PopFront(PSeqList L);    //ͷɾ,ɾ�����еĵ�һ��Ԫ��
void PushBack(PSeqList L, DataType e);  //β�壬�ڱ�β����Ԫ��e
void PopBack(PSeqList L); //βɾ��ɾ����βԪ��
void ClearList(PSeqList L);  //���˳���
int EmptyList(PSeqList L);   //�ж�˳����Ƿ�Ϊ��
void PrintList(PSeqList L);  //��ӡ����Ԫ��
