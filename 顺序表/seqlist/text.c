#define _CRT_SECURE_NO_WARNINGS 1
#include "seqlist.h"


// 测试头尾插入删除
void TestSeqList1()
{
	SeqList s;
	//定义
	SeqListInit(&s);
	//初始化
	//尾插
	for (size_t i = 1; i < 15; i++)
	{
		SeqListPushBack(&s, i);
	}
	
	seqListPrint(&s);
	//打印

	SeqListPopBack(&s);
	SeqListPopBack(&s);
	//尾删
	seqListPrint(&s);

	SeqListPushFront(&s, 0);
	SeqListPushFront(&s, -1);
	SeqListPushFront(&s, -2);
	SeqListPushFront(&s, -3);
	SeqListPushFront(&s, -4);
	SeqListPushFront(&s, -5);
	//头插
	seqListPrint(&s);

	SeqListPopFront(&s);
	SeqListPopFront(&s);
	SeqListPopFront(&s);
	SeqListPopFront(&s);
	SeqListPopFront(&s);
	//头删
	seqListPrint(&s);

	//随机插
	SeqListInsert(&s, 2, 11);
	SeqListInsert(&s, 2, 12);
	SeqListInsert(&s, 11, 13);
	SeqListInsert(&s, 2, 14);

	seqListPrint(&s);

	SeqListErase(&s, 0);
	SeqListErase(&s, 1);
	SeqListErase(&s, 2);
	SeqListErase(&s, 3);

	seqListPrint(&s);

	//查找
	printf("你查找的下标是%d\n", SeqListFind(&s, 10));


	seqListDestory(&s);




}


int main()
{
	TestSeqList1();
	return 0;
}