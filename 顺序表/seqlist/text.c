#define _CRT_SECURE_NO_WARNINGS 1
#include "seqlist.h"


// ����ͷβ����ɾ��
void TestSeqList1()
{
	SeqList s;
	//����
	SeqListInit(&s);
	//��ʼ��
	//β��
	for (size_t i = 1; i < 15; i++)
	{
		SeqListPushBack(&s, i);
	}
	
	seqListPrint(&s);
	//��ӡ

	SeqListPopBack(&s);
	SeqListPopBack(&s);
	//βɾ
	seqListPrint(&s);

	SeqListPushFront(&s, 0);
	SeqListPushFront(&s, -1);
	SeqListPushFront(&s, -2);
	SeqListPushFront(&s, -3);
	SeqListPushFront(&s, -4);
	SeqListPushFront(&s, -5);
	//ͷ��
	seqListPrint(&s);

	SeqListPopFront(&s);
	SeqListPopFront(&s);
	SeqListPopFront(&s);
	SeqListPopFront(&s);
	SeqListPopFront(&s);
	//ͷɾ
	seqListPrint(&s);

	//�����
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

	//����
	printf("����ҵ��±���%d\n", SeqListFind(&s, 10));


	seqListDestory(&s);




}


int main()
{
	TestSeqList1();
	return 0;
}