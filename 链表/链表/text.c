#include "Slist.h"


int main()
{
	SListNode * pList = NULL;
	//这是一个链表的头指针

	SLsitPushBack(&pList, 1);
	SLsitPushBack(&pList, 2);
	SLsitPushBack(&pList, 3);
	SLsitPushBack(&pList, 4);

	SListPrint(pList);

	//SListPopBack(&pList);
	//SListPopBack(&pList);
	//SListPopBack(&pList);
	//SListPopBack(&pList);
	//SListPopBack(&pList);

	//SListPrint(pList);

	SListPopFront(&pList);

	SLsitPushFront(&pList, 4);
	SLsitPushFront(&pList, 5);
	SLsitPushFront(&pList, 6);
	SLsitPushFront(&pList, 7);

	SListPrint(pList);
	SListAppointPushBack(&pList, 4, 1);
	SListAppointPushBack(&pList, 4, 1);
	SListAppointPushBack(&pList, 4, 1);
	SListAppointPushBack(&pList, 4, 1);
	SListAppointPushBack(&pList, 4, 1);
	SListAppointPushBack(&pList, 4, 1);
	SListPrint(pList);

	SListAppointPopBack(&pList, 1);
	SListAppointPopBack(&pList, 1);
	SListAppointPopBack(&pList, 1);
	SListAppointPopBack(&pList, 1);
	SListPrint(pList);

	//SListRotateBack(&pList, 1);
    SListQust(pList,3,14);
	SListQust(pList,4,14);
	/*SListPrint(pList);
	SListPopFront(&pList);
	SListPopFront(&pList);
	SListPopFront(&pList);
	SListPopFront(&pList);
	SListPopFront(&pList);
	SListPopFront(&pList);
	SListPopFront(&pList);
	SListPopFront(&pList);
	SListPopFront(&pList);
	SListPopFront(&pList);*/
	SListPrint(pList);
	return 0;
}