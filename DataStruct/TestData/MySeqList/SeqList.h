
#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<malloc.h>

#define _CRT_SECURE_NO_WARNINGS 1

typedef int SLDataType;
typedef struct 
{
	SLDataType  *array;//存储空间的基地址
	size_t  size;//有效数据的个数
	size_t capacity; //当前分配的存储容量（以sizeof（DataType）为单位）
}SL;

void SeqListInit(SL *s);//初始化动态顺序表
void SeqlistDestory(SL *ps);//销毁

void SeqListPrint(SL *s);//打印动态顺序表
void SeqListPushBack(SL *s, SLDataType x);//尾插
void SeqListPushFront(SL *s, SLDataType x);//头插

void SeqListPopFront(SL *s);//头删
void SeqListPopBack(SL *s);//尾删


void CheckCapacity(SL *s);//判断容量是否已经满了

void SeqListDestory(SL *s);//销毁顺序表
void SeqListDClear(SL *s);//清空数据表
void Insert(SL *s, int pos, SLDataType x);//在指定位置插入一个元素
int SeqListDSize(SL *s);// 获取元素个数


// 顺序表查找
int SeqListFind(SL *s, SLDataType x);
//顺序表 
void SeqListInsert(SL *s, size_t pos, SLDataType x);
//顺序表删除pos位置的值
void SeqListErase(SL *s, size_t pos);

//拓展  顺序表的排序  删除指定元素，删除一类元素等