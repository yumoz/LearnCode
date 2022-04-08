#pragma once

#include<stdio.h>
#include<Windows.h> /*	system	*/
#include<assert.h> /*	assert	*/
#include<stdlib.h>

#define N 8//宏定义，决定静态分配数组a[N]的大小，如果是8，代表顺序表最多只能插入8个数据
//静态数据的大小，存在内存利用问题，于是提出了变长大小

typedef int SLDatatype;//重定义顺序表数据类型

typedef struct
{
	SLDatatype a[N];//静态数组，
	SLDatatype size;//顺序表分配的存储容量
}SL;

//顺序表初始化
void SeqListInit(SL* ps);

void SeqListPushBack(SL*ps, SLDatatype x);//尾插
void SeqListPopBack(SL *ps);//尾删
void SeqListPushFront(SL *ps, SLDatatype x);//头插
void SeqListPopFront(SL *ps);//头删

//任意位置插入和删除
void SeqListInsert(SL* ps, int pos, SLDatatype x);
void SeqListErase(SL* ps, int pos);

//顺序表查找
int SeqListFind(SL* ps, SLDatatype x);

//打印顺序表
void SeqListPrint(SL* ps);

//销毁顺序表
void SeqListDestory(SL* ps);

//顺序表排序
void BubbleSort(SL*ps);

//二分查找
int Binarysearch(SL*ps, SLDatatype data);