#include "List.h"

/*双链表:结构复杂 操作简单*/

void TestList1()
{
	//初始化
	ListNode* phead = ListInit();
	//尾插
	ListPushBack(phead, 1);
	ListPushBack(phead, 2);
	ListPushBack(phead, 3);
	ListPushBack(phead, 4);

	ListPrint(phead);
	//尾删
	ListPopBack(phead);
	ListPopBack(phead);
	ListPopBack(phead);
	ListPopBack(phead);
	ListPopBack(phead);

	ListPrint(phead);

	ListPushFront(phead, 1);
	ListPushFront(phead, 2);
	ListPushFront(phead, 3);
	ListPushFront(phead, 4);

	ListPrint(phead);

	ListPopFront(phead);
	ListPopFront(phead);
	ListPopFront(phead);
	ListPopFront(phead);
	ListPopFront(phead);

	ListPrint(phead);

	ListInset(phead, 1);
	ListInset(phead, 2);
	ListInset(phead, 3);
	ListInset(phead, 4);
	//利用查找后插入
	ListInset(ListFind(phead, 4), 2);
	ListNode* pos= ListFind(phead, 2);
	ListErase(&pos, 2);

	ListPrint(phead);
}

int main()
{
	TestList1();
	return 0;
}