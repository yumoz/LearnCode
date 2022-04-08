#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int SListDataType;

//链表 重定义
typedef struct SListNode 
{
	SListDataType data;
	struct SListNode * next;//存放下一个结构体的首地址
}SListNode;

//动态申请一个节点
SListNode * BuySListNode(SListDataType x);
//单链表尾插
void SListPushBack(SListNode** pphead, SListDataType x);//尾添加
//单链表尾删
void SListPopBack(SListNode** pphead);//尾删除
//单链表头插
void SListPushFront(SListNode** pphead, SListDataType x); //头添加
//单链表头删
void SListPopFront(SListNode** pphead);//头删除

//单链表查找 和 改
SListNode* SListFind(SListNode * plist, SListDataType x);

//单链表在pos位置之后插入x
void SListInsertAfter(SListNode *pos, SListDataType x);

//单链表删除pos位置之后的值
void SListEraseAfter(SListNode * pos);

//单链表的销毁
void SListDestory(SListNode * plist);

void SListDestroy(SListNode *pList);
//单链表打印
void SListPrint(SListNode*phead);


