
#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<malloc.h>

#define _CRT_SECURE_NO_WARNINGS 1

typedef int SLDataType;
typedef struct 
{
	SLDataType  *array;//�洢�ռ�Ļ���ַ
	size_t  size;//��Ч���ݵĸ���
	size_t capacity; //��ǰ����Ĵ洢��������sizeof��DataType��Ϊ��λ��
}SL;

void SeqListInit(SL *s);//��ʼ����̬˳���
void SeqlistDestory(SL *ps);//����

void SeqListPrint(SL *s);//��ӡ��̬˳���
void SeqListPushBack(SL *s, SLDataType x);//β��
void SeqListPushFront(SL *s, SLDataType x);//ͷ��

void SeqListPopFront(SL *s);//ͷɾ
void SeqListPopBack(SL *s);//βɾ


void CheckCapacity(SL *s);//�ж������Ƿ��Ѿ�����

void SeqListDestory(SL *s);//����˳���
void SeqListDClear(SL *s);//������ݱ�
void Insert(SL *s, int pos, SLDataType x);//��ָ��λ�ò���һ��Ԫ��
int SeqListDSize(SL *s);// ��ȡԪ�ظ���


// ˳������
int SeqListFind(SL *s, SLDataType x);
//˳��� 
void SeqListInsert(SL *s, size_t pos, SLDataType x);
//˳���ɾ��posλ�õ�ֵ
void SeqListErase(SL *s, size_t pos);

//��չ  ˳��������  ɾ��ָ��Ԫ�أ�ɾ��һ��Ԫ�ص�