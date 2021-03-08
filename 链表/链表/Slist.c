#include "Slist.h"

//��ӡ
void SListPrint(SListNode* phead)
{
	SListNode * cur = phead;
	while (cur != NULL)
//����phead���ڿ�ָ���ʱ��ѭ������
	{	
		printf("%d->", cur->data);
		cur = cur->next;
//�ο�˳�������������ṹ���һ�������Ǵ����ֵ
//�ڶ���������һ������ĵ�ַ��
//����˵�ý��ڶ�����λ�ô洢�ĵ�ַ����cur
	}
	printf("NULL\n");
}

//�����ڴ�
SListNode * BuySListNode(SListDataType x)
{
	SListNode * newNode = (SListNode*)malloc(sizeof(SListNode));
	if (newNode == NULL)
	{
		printf("�����ڴ�ʧ��");
		exit(-1);
	}
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}


//β�� β���ص����β��nextΪ��
void SLsitPushBack(SListNode** pphead, SListDataType x)
{
	SListNode* newNode = BuySListNode(x);
	//�ʼ�����ǿյģ�����˵cur->next�õ���һ���ǿ�ָ��
	if (*pphead == NULL)
	{		
		*pphead = newNode;
	}
	else
	{
		//����Ϊ��ʱ������Ҫ��β��
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
	//��һ������������ǿյģ�ֱ�ӷ���
	{
		printf("û�п�ɾ��������");
		return;
	}
	else if ((*pphead)->next == NULL)
	//�ڶ�����������������о�һ��ֵ��ֱ���ͷ�
	{
		free(*pphead);
		*pphead = NULL;
	}
	//���������
	else
	{
	//�������������ҵ�������һ���͵����ڶ���
		SListNode* cur = *pphead;
		SListNode* prev = cur;
		while (cur->next != NULL)
		{
			prev = cur;
			//����ǰһ��
			cur = cur->next;
		}
		free(cur);
		//��ʵcur�Ǹ��ֲ����������˺�����������
		cur = NULL;
		prev->next = NULL;
	}
}


//ͷ��
void SLsitPushFront(SListNode** phead, SListDataType x)
{
	//����ͷ������*phead ��ͷ��ַ�ŵ�һ���������棬
	//Ȼ���ͷ�ĵ�ַ����һ���¿��ٵĿռ��ڣ�Ȼ��һ��ʼͷ�ĵ�ַ�����µ�ַ��next
	//pheadΪ��Ҳû��ϵ
	SListNode * NewNode = BuySListNode(x);
	SListNode * tmp = *phead;
	*phead = NewNode;
	(*phead)->next = tmp;
	
}
//ͷɾ
void SListPopFront(SListNode** pphead)
{
	if (*pphead == NULL)
	{
		printf("û�п�ɾ��������");
		return;
	}
	//��ʵelseҲ�ܴ�����һ���ǿ�ָ������
	/*else if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}*/
	else
	{
		//��ͷ����һ����ַ�浽һ��������,Ȼ��ֱ���ͷ�ͷ���ռ䣬�������°�ͷ����һ��ʼָ��ĵڶ�����ַ
		SListNode* cur = (*pphead)->next;
		free(*pphead);
		*pphead = cur;
	}
}

//����
void SListQust(SListNode* phead, SListDataType x, SListDataType y)
{
	SListNode* cur = phead;
	int count = 0;
	while (cur != NULL)
	{
		count++;
		//����ǵڼ���Ԫ��
		/*if (count == x)
		{
			cur->data = y;
			return;
		}*/
		//�����������������
		if (cur->data == x)
		{
			printf("���ҵ�%d�ҵ����ǵ�%d��Ԫ��\n",x, count);
			cur->data = y;
			return;
		}
		cur = cur->next;
	}
}

//ָ��λ�ò���
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
			printf("��ָ����λ�ù���");
		}
	}
}

//ָ��λ��ɾ��
void SListAppointPopBack(SListNode** phead, int pos)
{
	if (*phead == NULL)
	{
		printf("û�п���ɾ��");
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
				//ǰ�����ptr Ҫɾ������cur �������cur->next
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
			printf("������Χ");
		}
	}
}

void SListRotateBack(SListNode** phead, int rotate)
{

}

