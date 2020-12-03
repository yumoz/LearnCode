#ifndef __CONTRACT_H__
#define __CONTRACT_H__

#include<stdio.h>
#include<windows.h>
#include<assert.h>

#pragma warning(disable:4996)

#define SIZE 128
#define NUM 1
#define INC_SIZE 1

//姓名、性别、年龄、电话、住址
typedef struct person{
	char name[SIZE / 4];
	char sex;
	int age;
	char telphone[SIZE / 4];
	char address[SIZE];
}person_t;

typedef struct contact{
	int cap;
	int size;
	person_t persons[0];
}contact_t;

#endif
