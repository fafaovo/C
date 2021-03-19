#include "List.h"




//创建结点
ListNode* BuyListNode(LTDateType x)
{
	//创建新结点
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	//初始化
	node->data = x;
	node->next = NULL;
	node->prev = NULL;
	return node;
}

//初始化
ListNode* ListInit()
{
	ListNode* phead = BuyListNode(0);
	phead->next = phead;
	phead->prev = phead;
	return phead;
}


//打印
void ListPrint(ListNode* phead)
{
	assert(phead);
	ListNode* cur = phead->next;
	if (cur == phead)
	{
		printf("没有元素可打印\n");
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

//尾插
void ListPushBack(ListNode* phead, LTDateType x)
{
	//不改变头节点所以不需要传二级指针
	assert(phead);
	//将tail指向头的下一个即尾
	ListNode* tail = phead->prev;
	//新建一个新的节点
	ListNode* newnode = BuyListNode(x);
	
	//将尾节点的下一个指向新节点
	tail->next = newnode;
	//将新节点的上一个指向尾结点
	newnode->prev = tail;
	//将新节点的下一个指向头结点
	newnode->next = phead;
	//最后将头节点的上一个指向新节点
	phead->prev = newnode;
}

//尾删
void ListPopBack(ListNode* phead)
{
	assert(phead);
	//处理只有一个头节点
	if (phead->next == phead)
	{
		printf("没有可删除的节点\n");
		return;
	}
	else
	{
		//头结点的上一个节点是待删除的尾节点
		ListNode* del = phead->prev;
		//尾结点的上一个节点
		ListNode* cur = del->prev;
		//将cur的下一个节点指向头结点
		cur->next = phead;
		//然后再将头结点的上一个指向cur
		phead->prev = cur;
		//此时del已经完全被断开了，直接释放就行
		free(del);
		del = NULL;
	}
	

	//上面的也兼容只有一个头结点和一个结点的,
	//只不过两个指针会来回横跳
	/*
	//处理只有一个节点时,其实可以省点空间复杂度
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

//头插
void ListPushFront(ListNode* phead, LTDateType x)
{
	//断言是否为空
	assert(phead);
	//新建节点
	ListNode* newnode = BuyListNode(x);
	//将头节点的下一个节点给到next
	ListNode* next = phead->next;

	//插入节点
	phead->next = newnode;
	newnode->prev = phead;

	newnode->next = next;
	next->prev = newnode;
}
//头删
void ListPopFront(ListNode* phead)
{
	assert(phead);
	if (phead->next == phead){
		printf("没有可删除的节点\n");
		return;
	}
	ListNode* del = phead->next;
	ListNode* delNext = del->next;
	
	phead->next = delNext;
	delNext->prev = phead;

	free(del);
	del = NULL;
}

//查找
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

//指定位置插入
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