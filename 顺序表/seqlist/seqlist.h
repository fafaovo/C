#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#pragma once
//��ֹ���ظ�����

typedef int SLDataType;
//��int����ΪSLDataType,�Ժ���Ҫ�޸ĳ���������ֱ�Ӹ�int����

typedef struct SeqList
{
	SLDataType* a;
	int size;
	//��Ч���ݵĸ���
	int capacity;//����
}SL, SeqList;
//˳�����Ч�����������б���������

//β�� βɾ ͷ�� ͷɾ ����� ����ɾ
void seqListPrint(SL * ps);
void SeqListInit(SL * ps);
void SeqListPushBack(SL* ps, SLDataType x);
void SeqListPopBack(SL * ps);
void SeqListPushFront(SL* ps, SLDataType x);
void SeqListPopFront(SL * ps);
void SeqListInsert(SL * ps, int pos, SLDataType x);
//����һ��λ��
void SeqListErase(SL * ps, int pos);
//����
int SeqListFind(SL *ps, SLDataType x);
//�ͷ��ڴ�
void seqListDestory(SL * ps);