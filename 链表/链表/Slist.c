#include "Slist.h"

//打印
void SListPrint(SListNode* phead)
{
	SListNode * cur = phead;
	while (cur != NULL)
//假设phead等于空指针的时候，循环结束
	{	
		printf("%d->", cur->data);
		cur = cur->next;
//参考顺序表里面的链表，结构体第一个变量是储存的值
//第二个的是下一个链表的地址，
//所以说用将第二个的位置存储的地址赋给cur
	}
	printf("NULL\n");
}

//开辟内存
SListNode * BuySListNode(SListDataType x)
{
	SListNode * newNode = (SListNode*)malloc(sizeof(SListNode));
	if (newNode == NULL)
	{
		printf("申请内存失败");
		exit(-1);
	}
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}


//尾插 尾的特点就是尾的next为空
void SLsitPushBack(SListNode** pphead, SListDataType x)
{
	SListNode* newNode = BuySListNode(x);
	//最开始链表是空的，所以说cur->next得到的一定是空指针
	if (*pphead == NULL)
	{		
		*pphead = newNode;
	}
	else
	{
		//当不为空时，就需要找尾了
		SListNode * cur = *pphead;
		while (cur->next != NULL)
		{
			cur = cur->next;
		}
		cur->next = newNode;
	}
}


void SListPopBack(SListNode** pphead)
{
	if (*pphead == NULL)
	//第一种情况，假设是空的，直接返回
	{
		printf("没有可删除的链表");
		return;
	}
	else if ((*pphead)->next == NULL)
	//第二种情况，假设链表中就一个值，直接释放
	{
		free(*pphead);
		*pphead = NULL;
	}
	//第三种情况
	else
	{
	//遍历整个链表，找到倒数第一个和倒数第二个
		SListNode* cur = *pphead;
		SListNode* prev = cur;
		while (cur->next != NULL)
		{
			prev = cur;
			//这是前一个
			cur = cur->next;
		}
		free(cur);
		//其实cur是个局部变量，出了函数就销毁了
		cur = NULL;
		prev->next = NULL;
	}
}


//头插
void SLsitPushFront(SListNode** phead, SListDataType x)
{
	//首先头部就是*phead 将头地址放到一个变量里面，
	//然后把头的地址赋给一个新开辟的空间内，然后将一开始头的地址赋给新地址的next
	//phead为空也没关系
	SListNode * NewNode = BuySListNode(x);
	SListNode * tmp = *phead;
	*phead = NewNode;
	(*phead)->next = tmp;
	
}
//头删
void SListPopFront(SListNode** pphead)
{
	if (*pphead == NULL)
	{
		printf("没有可删除的数据");
		return;
	}
	//其实else也能处理下一个是空指针的情况
	/*else if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}*/
	else
	{
		//将头的下一个地址存到一个变量里,然后直接释放头这块空间，并且重新把头给到一开始指向的第二个地址
		SListNode* cur = (*pphead)->next;
		free(*pphead);
		*pphead = cur;
	}
}

//查找
void SListQust(SListNode* phead, SListDataType x, SListDataType y)
{
	SListNode* cur = phead;
	int count = 0;
	while (cur != NULL)
	{
		count++;
		//这个是第几个元素
		/*if (count == x)
		{
			cur->data = y;
			return;
		}*/
		//下面这个是用数字找
		if (cur->data == x)
		{
			printf("你找的%d找到了是第%d个元素\n",x, count);
			cur->data = y;
			return;
		}
		cur = cur->next;
	}
}

//指定位置插入
void SListAppointPushBack(SListNode** phead, SListDataType x, int pos)
{
	SListNode * NewNode = BuySListNode(x);
	if (*phead == NULL)
	{
		*phead = NewNode;
	}
	else
	{
		SListNode * cur = * phead;
		SListNode * tmp = NULL;
		int count = 0;
		while (cur != NULL)
		{	
			if (count == pos)
			{
				NewNode->next = cur;
				tmp->next = NewNode;
			}
			tmp = cur;
			count++;
			cur = cur->next;
		}
		if (count < pos)
		{
			printf("你指定的位置过大");
		}
	}
}

//指定位置删除
void SListAppointPopBack(SListNode** phead, int pos)
{
	if (*phead == NULL)
	{
		printf("没有可以删除");
	}
	else if ((*phead)->next == NULL && pos == 0)
	{
		free(*phead);
		*phead = NULL;
	}
	else if (pos == 0)
	{
		SListNode* cur = (*phead)->next;
		free(*phead);
		*phead = cur;
	}
	else
	{
		SListNode * cur = *phead;
		SListNode * ptr = NULL;
		int count = 0;
		while (cur != NULL)
		{
			if (count == pos)
			{
				//前面的是ptr 要删除的是cur 后面的是cur->next
				ptr->next = cur->next;
				free(cur);
				break;
			}
			count++;
			ptr = cur;
			cur = cur->next;
		}
		if (count < pos)
		{
			printf("超出范围");
		}
	}
}

void SListRotateBack(SListNode** phead, int rotate)
{

}

