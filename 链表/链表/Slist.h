#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>


typedef int SListDataType;
//�ڵ�
typedef struct SListNode
{
	SListDataType data;
//����������Ҫ�洢�Ķ���
	struct SListNode* next;
//���������һ���ڵ�ĵ�ַ
}SListNode;

//β��βɾ
void SLsitPushBack(SListNode** phead, SListDataType x);
void SListPopBack(SListNode** phead);
//ͷ��ͷɾ
void SLsitPushFront(SListNode** phead, SListDataType x);
void SListPopFront(SListNode** phead);
//��ӡ
void SListPrint(SListNode* phead);

//���� 
void SListQust(SListNode* phead, SListDataType x, SListDataType y);

//ָ�����룬ָ��ɾ��
void SListAppointPushBack(SListNode** phead, SListDataType x,int wz);
void SListAppointPopBack(SListNode** phead, int wz);

//��ת����
void SListRotateBack(SListNode** phead, int rotate);