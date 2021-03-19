#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


typedef int LTDateType;

typedef struct ListNode
{
	struct ListNode * prev;
	struct ListNode * next;
	LTDateType data;
}ListNode;

//初始化函数
ListNode* ListInit();
//创建节点
ListNode* BuyListNode(LTDateType x);
//遍历链表
void ListPrint(ListNode* phead);
//尾插
void ListPushBack(ListNode* phead, LTDateType x);
//尾删
void ListPopBack(ListNode* phead);

//头插
void ListPushFront(ListNode* phead, LTDateType x);
//头删
void ListPopFront(ListNode* phead);

//查找(找到后返回链表的指针) (是查也是修改)
ListNode* ListFind(ListNode* phead, LTDateType x);

//指定位置插入和删除
//指定位置插入可以用到查找,即将找到的指针传入
void ListInset(ListNode* pos, LTDateType x);

void ListErase(ListNode** pos);



/*
链表和顺序表(数组)的区别和联系:
1.顺序表就是在数组的基础上实现增删查改,并且插入时可以动态增长
顺序表的缺陷:1.可能存在一定程度的空间浪费,
			 2.增容有一定的效率损失
			 3.中间或者头部插入删除，时间复杂度为O（N)，因为要挪动数据
这些问题链表来解决了
链表的缺陷:不能随机访问(比如说二分查找需要随机访问)

互补的数据结构
*/



