/*
��һ��������,���б������������һ��randomֵ�����ֵ�����������������ĳ���ڵ�ĵ�ַ
������Ҫ��һ������ȥ������������
�������ǽ��е�һ�������ڵ㣬�������Ľڵ㶼�ŵ��½ڵ�ĺ󷽣��ٸ����ӣ����������˳���� 1->2->3->4->1->NULL
�����󽫻��� 1->1->2->2->3->3->4->4->1->1->NULL

�ڶ����� ���Ǽ���1�����ֵָ��3�ĵ�ַ ������cur��ʾ1 ��stc��ʾ3 ��ô���� cur->random ��ָ�� stc
��ô cur->next->random �ͻ�ָ�� stc->next  Ҳ����1���ƵĽڵ��ָ��3���ƵĽڵ� ��ϸƷ

��������𿪾ͺ���
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
	//1.�����ڵ�
	struct Node * cur = head;
	while (cur)
	{
		Node * copy = (Node*)malloc(sizeof(Node));
		//�½��ڵ�
		copy->next = NULL;
		copy->random = NULL;
		//��ʼ��
		copy->val = cur->val;
		//���ڵ㸳ֵ

		Node* next = cur->next;
		//��ʱ�½�һ��ָ����һ���ɽڵ��ָ��
		cur->next = copy;
		copy->next = next;

		cur = next;
		//�ڵ�ӹ�
	}

	//2.�������ڵ��random
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
	//3.������������
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