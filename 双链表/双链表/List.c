#include "List.h"




//�������
ListNode* BuyListNode(LTDateType x)
{
	//�����½��
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	//��ʼ��
	node->data = x;
	node->next = NULL;
	node->prev = NULL;
	return node;
}

//��ʼ��
ListNode* ListInit()
{
	ListNode* phead = BuyListNode(0);
	phead->next = phead;
	phead->prev = phead;
	return phead;
}


//��ӡ
void ListPrint(ListNode* phead)
{
	assert(phead);
	ListNode* cur = phead->next;
	if (cur == phead)
	{
		printf("û��Ԫ�ؿɴ�ӡ\n");
	}
	else
	{
		printf("head->");
		while (cur != phead)
		{
			printf("%d->", cur->data);
			cur = cur->next;
		}
		printf("\n");
	}
}

//β��
void ListPushBack(ListNode* phead, LTDateType x)
{
	//���ı�ͷ�ڵ����Բ���Ҫ������ָ��
	assert(phead);
	//��tailָ��ͷ����һ����β
	ListNode* tail = phead->prev;
	//�½�һ���µĽڵ�
	ListNode* newnode = BuyListNode(x);
	
	//��β�ڵ����һ��ָ���½ڵ�
	tail->next = newnode;
	//���½ڵ����һ��ָ��β���
	newnode->prev = tail;
	//���½ڵ����һ��ָ��ͷ���
	newnode->next = phead;
	//���ͷ�ڵ����һ��ָ���½ڵ�
	phead->prev = newnode;
}

//βɾ
void ListPopBack(ListNode* phead)
{
	assert(phead);
	//����ֻ��һ��ͷ�ڵ�
	if (phead->next == phead)
	{
		printf("û�п�ɾ���Ľڵ�\n");
		return;
	}
	else
	{
		//ͷ������һ���ڵ��Ǵ�ɾ����β�ڵ�
		ListNode* del = phead->prev;
		//β������һ���ڵ�
		ListNode* cur = del->prev;
		//��cur����һ���ڵ�ָ��ͷ���
		cur->next = phead;
		//Ȼ���ٽ�ͷ������һ��ָ��cur
		phead->prev = cur;
		//��ʱdel�Ѿ���ȫ���Ͽ��ˣ�ֱ���ͷž���
		free(del);
		del = NULL;
	}
	

	//�����Ҳ����ֻ��һ��ͷ����һ������,
	//ֻ��������ָ������غ���
	/*
	//����ֻ��һ���ڵ�ʱ,��ʵ����ʡ��ռ临�Ӷ�
	if ((*phead)->next->next == *phead)
	{
		ListNode* cur = (*phead)->next;
		free(cur);
		(*phead)->prev = *phead;
		(*phead)->next = *phead;
		return;
	}
	*/



}

//ͷ��
void ListPushFront(ListNode* phead, LTDateType x)
{
	//�����Ƿ�Ϊ��
	assert(phead);
	//�½��ڵ�
	ListNode* newnode = BuyListNode(x);
	//��ͷ�ڵ����һ���ڵ����next
	ListNode* next = phead->next;

	//����ڵ�
	phead->next = newnode;
	newnode->prev = phead;

	newnode->next = next;
	next->prev = newnode;
}
//ͷɾ
void ListPopFront(ListNode* phead)
{
	assert(phead);
	if (phead->next == phead){
		printf("û�п�ɾ���Ľڵ�\n");
		return;
	}
	ListNode* del = phead->next;
	ListNode* delNext = del->next;
	
	phead->next = delNext;
	delNext->prev = phead;

	free(del);
	del = NULL;
}

//����
ListNode* ListFind(ListNode* phead, LTDateType x)
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur!=phead)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

//ָ��λ�ò���
void ListInset(ListNode* pos, LTDateType x)
{
	assert(pos);
	ListNode* newNode = BuyListNode(x);
	ListNode* posPrev = pos->prev;

	newNode->next = pos;
	pos->prev = newNode;

	newNode->prev = posPrev;
	posPrev->next = newNode;
}

void ListErase(ListNode** pos)
{
	assert(*pos);
	ListNode * posNext = (*pos)->next;
	ListNode * posPrev = (*pos)->prev;
	posNext->prev = posPrev;
	posPrev->next = posNext;
	free(*pos);
	*pos = NULL;
}