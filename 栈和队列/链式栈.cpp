#include <iostream>
using namespace std;

//������ڵ�
typedef struct Node
{
	int data;
	struct Node* next;
}Node,*LPNode;

typedef struct stack
{
	struct Node* stackTop;
	int size;
}stack, *PLstack;

//�����ڵ�
LPNode createNode(int data)
{
	LPNode newNode = (LPNode)malloc(sizeof(Node));
	if (newNode == NULL)
	{
		exit(-1);
	}
	newNode->data = data;
	return newNode;
}

//����ջ
PLstack createStack()
{
	PLstack myStack = (PLstack)malloc(sizeof(stack));
	if (myStack == NULL)
	{
		exit(-1);
	}
	myStack->size = 0;
	myStack->stackTop = NULL;
	return myStack;
}
//��ջ���� ��ͬ�������ͷ��
void push(PLstack myStack,int data)
{
	//�½�Ҫ����Ľڵ�
	LPNode newNode = createNode(data);
	newNode->next = myStack->stackTop;
	myStack->stackTop = newNode;
	myStack->size++;
}
//��ȡջ��Ԫ��
int top(PLstack myStack)
{
	if (myStack->size == 0)
	{
		cout << "ջΪ�գ��޷���ȡջ��Ԫ��" << endl;
		return NULL;
	}
	return myStack->stackTop->data;
}
//��ջ����
void pop(PLstack myStack)
{
	if (myStack->size == 0)
	{
		cout << "ջΪ�գ��޷���ջ" << endl;
		return;
	}
	LPNode next = myStack->stackTop->next;
	free(myStack->stackTop);
	myStack->stackTop = next;
	myStack->size--;
}
//����ͺ���
int empty(PLstack myStack)
{
	if (myStack->size == 0)
		return 0;
	return 1;
}

int main()
{
	PLstack myStack = createStack();
	push(myStack, 1);
	push(myStack, 2);
	push(myStack, 3);
	while (empty(myStack))
	{
		cout << top(myStack) << " " ;
		pop(myStack);
	}
	
	system("pause");
	return 0;
}
