#pragma once

#include<stdio.h>
#include<Windows.h> /*	system	*/
#include<assert.h> /*	assert	*/
#include<stdlib.h>

#define N 8//�궨�壬������̬��������a[N]�Ĵ�С�������8������˳������ֻ�ܲ���8������
//��̬���ݵĴ�С�������ڴ��������⣬��������˱䳤��С

typedef int SLDatatype;//�ض���˳�����������

typedef struct
{
	SLDatatype a[N];//��̬���飬
	SLDatatype size;//˳������Ĵ洢����
}SL;

//˳����ʼ��
void SeqListInit(SL* ps);

void SeqListPushBack(SL*ps, SLDatatype x);//β��
void SeqListPopBack(SL *ps);//βɾ
void SeqListPushFront(SL *ps, SLDatatype x);//ͷ��
void SeqListPopFront(SL *ps);//ͷɾ

//����λ�ò����ɾ��
void SeqListInsert(SL* ps, int pos, SLDatatype x);
void SeqListErase(SL* ps, int pos);

//˳������
int SeqListFind(SL* ps, SLDatatype x);

//��ӡ˳���
void SeqListPrint(SL* ps);

//����˳���
void SeqListDestory(SL* ps);

//˳�������
void BubbleSort(SL*ps);

//���ֲ���
int Binarysearch(SL*ps, SLDatatype data);