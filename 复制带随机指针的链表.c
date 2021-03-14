/*
有一个单链表,他有比正常单链表多一个random值，这个值随机存放了这个链表中某个节点的地址
我们需要用一个函数去复制整个链表
首先我们进行第一步拷贝节点，将创建的节点都放到新节点的后方，举个例子，正常链表的顺序是 1->2->3->4->1->NULL
拷贝后将会变成 1->1->2->2->3->3->4->4->1->1->NULL

第二部分 我们假设1的随机值指向3的地址 我们用cur表示1 用stc表示3 那么就是 cur->random 会指向 stc
那么 cur->next->random 就会指向 stc->next  也就是1复制的节点会指向3复制的节点 你细品

最后把链表拆开就好了
*/
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>

struct Node {
    int val;
    struct Node *next;
    struct Node *random;
};

typedef struct Node Node;
struct Node* copyRandomList(struct Node* head)
{
	if (head == NULL)
	{
		return NULL;
	}
	//1.拷贝节点
	struct Node * cur = head;
	while (cur)
	{
		Node * copy = (Node*)malloc(sizeof(Node));
		//新建节点
		copy->next = NULL;
		copy->random = NULL;
		//初始化
		copy->val = cur->val;
		//将节点赋值

		Node* next = cur->next;
		//临时新建一个指向下一个旧节点的指针
		cur->next = copy;
		copy->next = next;

		cur = next;
		//节点接轨
	}

	//2.处理拷贝节点的random
	cur = head;
	while (cur)
	{
		struct Node * copy = cur->next;
		if (cur->random)
		{
			copy->random = cur->random->next;
		}
		else
		{
			copy->random = NULL;
		}
		cur = cur->next->next;
	}
	//3.拆解出复制链表
	cur = head;
	Node* copyHead = head->next;
	while (cur)
	{
		struct Node* copy = cur->next;
		struct Node* next = copy->next;

		cur->next = next;
		if (next)
		{
			copy->next = next->next;
		}
		else
		{
			copy->next = NULL;
		}
		cur = next;
	}
	return copyHead;
}