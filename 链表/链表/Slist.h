#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>


typedef int SListDataType;
//节点
typedef struct SListNode
{
	SListDataType data;
//这里存的是需要存储的东西
	struct SListNode* next;
//这里存着下一个节点的地址
}SListNode;

//尾插尾删
void SLsitPushBack(SListNode** phead, SListDataType x);
void SListPopBack(SListNode** phead);
//头插头删
void SLsitPushFront(SListNode** phead, SListDataType x);
void SListPopFront(SListNode** phead);
//打印
void SListPrint(SListNode* phead);

//查找 
void SListQust(SListNode* phead, SListDataType x, SListDataType y);

//指定插入，指定删除
void SListAppointPushBack(SListNode** phead, SListDataType x,int wz);
void SListAppointPopBack(SListNode** phead, int wz);

//逆转链表
void SListRotateBack(SListNode** phead, int rotate);