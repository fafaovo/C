#include <iostream>
using namespace std;

//单链表节点
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

//创建节点
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

//创建栈
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
//入栈操作 等同于链表的头插
void push(PLstack myStack,int data)
{
	//新建要插入的节点
	LPNode newNode = createNode(data);
	newNode->next = myStack->stackTop;
	myStack->stackTop = newNode;
	myStack->size++;
}
//获取栈顶元素
int top(PLstack myStack)
{
	if (myStack->size == 0)
	{
		cout << "栈为空，无法获取栈顶元素" << endl;
		return NULL;
	}
	return myStack->stackTop->data;
}
//出栈操作
void pop(PLstack myStack)
{
	if (myStack->size == 0)
	{
		cout << "栈为空，无法出栈" << endl;
		return;
	}
	LPNode next = myStack->stackTop->next;
	free(myStack->stackTop);
	myStack->stackTop = next;
	myStack->size--;
}
//万金油函数
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
