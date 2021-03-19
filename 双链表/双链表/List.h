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

//��ʼ������
ListNode* ListInit();
//�����ڵ�
ListNode* BuyListNode(LTDateType x);
//��������
void ListPrint(ListNode* phead);
//β��
void ListPushBack(ListNode* phead, LTDateType x);
//βɾ
void ListPopBack(ListNode* phead);

//ͷ��
void ListPushFront(ListNode* phead, LTDateType x);
//ͷɾ
void ListPopFront(ListNode* phead);

//����(�ҵ��󷵻������ָ��) (�ǲ�Ҳ���޸�)
ListNode* ListFind(ListNode* phead, LTDateType x);

//ָ��λ�ò����ɾ��
//ָ��λ�ò�������õ�����,�����ҵ���ָ�봫��
void ListInset(ListNode* pos, LTDateType x);

void ListErase(ListNode** pos);



/*
�����˳���(����)���������ϵ:
1.˳������������Ļ�����ʵ����ɾ���,���Ҳ���ʱ���Զ�̬����
˳����ȱ��:1.���ܴ���һ���̶ȵĿռ��˷�,
			 2.������һ����Ч����ʧ
			 3.�м����ͷ������ɾ����ʱ�临�Ӷ�ΪO��N)����ΪҪŲ������
��Щ���������������
�����ȱ��:�����������(����˵���ֲ�����Ҫ�������)

���������ݽṹ
*/



