#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#pragma once
//防止被重复定义

typedef int SLDataType;
//将int定义为SLDataType,以后需要修改成其他类型直接改int就行

typedef struct SeqList
{
	SLDataType* a;
	int size;
	//有效数据的个数
	int capacity;//容量
}SL, SeqList;
//顺序表，有效数组在数组中必须是连续

//尾插 尾删 头插 头删 任意插 任意删
void seqListPrint(SL * ps);
void SeqListInit(SL * ps);
void SeqListPushBack(SL* ps, SLDataType x);
void SeqListPopBack(SL * ps);
void SeqListPushFront(SL* ps, SLDataType x);
void SeqListPopFront(SL * ps);
void SeqListInsert(SL * ps, int pos, SLDataType x);
//多了一个位置
void SeqListErase(SL * ps, int pos);
//查找
int SeqListFind(SL *ps, SLDataType x);
//释放内存
void seqListDestory(SL * ps);