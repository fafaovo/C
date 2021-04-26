#include <iostream>
using namespace std;

//������ڵ�
typedef struct Node
{
	int data;
	struct Node* next;
}Node,*LPNode;

//����
typedef struct Queue
{
	LPNode frontNode;
	LPNode tailNode;
	int size;
}Queue,*LPQueue;

//�½�����
LPQueue creatQueue()
{
	//�ڶѿ���һ��ռ������
	LPQueue myQueue = (LPQueue)malloc(sizeof(Queue));
	if (myQueue == NULL)
	{
		exit(-1);
	}
	myQueue->frontNode = myQueue->tailNode = NULL;
	myQueue->size = 0;
	return myQueue;
}
//C++�е�STL ��װ�����õ�
//�����ڵ�
LPNode creatNode(int data)
{
	LPNode myNode = (LPNode)malloc(sizeof(Node));
	if (myNode == NULL)
	{
		exit(-1);
	}
	myNode->data = data;
	myNode->next = NULL;
	return myNode;
}
//push ���� ����β��
void push(LPQueue myQueue, int data)
{
	LPNode newNode = creatNode(data);
	if (myQueue->size == 0)
	{
		myQueue->tailNode = myQueue->frontNode = newNode;
	}
	else
	{
		myQueue->tailNode->next = newNode;
		myQueue->tailNode = newNode;
	}
	myQueue->size++;
}
//����ͷɾ
void pop(LPQueue myQueue)
{
	if (myQueue->size == 0)
	{
		cout << "û�пɳ�ջ��Ԫ��" << endl;
		return;
	}
	LPNode next = myQueue->frontNode->next;
	free(myQueue->frontNode);
	myQueue->frontNode = next;
	myQueue->size--;
}
//��ȡ��ͷԪ��
int front(LPQueue myQueue)
{
	if (myQueue->size == 0)
	{
		cout << "��Ϊ��,�޷���ȡ��ͷԪ��" << endl;
		return myQueue->size;
	}
	return myQueue->frontNode->data;
}
int empty(LPQueue myQueue)
{
	if (myQueue->size == 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}


int main() 
{
	LPQueue myQueue = creatQueue();
	push(myQueue, 1);
	push(myQueue, 2);
	push(myQueue, 3);
	while (empty(myQueue))
	{
		cout << front(myQueue) << endl;
		pop(myQueue);
	}
	
	system("pause");
	return 0;
}