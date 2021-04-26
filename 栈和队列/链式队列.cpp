#include <iostream>
using namespace std;

//单链表节点
typedef struct Node
{
	int data;
	struct Node* next;
}Node,*LPNode;

//队列
typedef struct Queue
{
	LPNode frontNode;
	LPNode tailNode;
	int size;
}Queue,*LPQueue;

//新建队列
LPQueue creatQueue()
{
	//在堆开辟一块空间给队列
	LPQueue myQueue = (LPQueue)malloc(sizeof(Queue));
	if (myQueue == NULL)
	{
		exit(-1);
	}
	myQueue->frontNode = myQueue->tailNode = NULL;
	myQueue->size = 0;
	return myQueue;
}
//C++中的STL 封装容器用的
//创建节点
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
//push 插入 链表尾插
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
//链表头删
void pop(LPQueue myQueue)
{
	if (myQueue->size == 0)
	{
		cout << "没有可出栈的元素" << endl;
		return;
	}
	LPNode next = myQueue->frontNode->next;
	free(myQueue->frontNode);
	myQueue->frontNode = next;
	myQueue->size--;
}
//获取队头元素
int front(LPQueue myQueue)
{
	if (myQueue->size == 0)
	{
		cout << "队为空,无法获取队头元素" << endl;
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