#include <iostream>
using namespace std;


//描述单一个体 别名一个指针一个结构体变量
typedef struct treeNode
{
	char data;	//数据域字符表示
	struct treeNode* LChild;
	struct treeNode* RChild;
}TREE,*LPTREE;


//新建节点
LPTREE createNode(char data)
{
	LPTREE newNode = (LPTREE)malloc(sizeof(TREE));
	if (newNode == NULL) {
		exit(-1);
	}
	newNode->data = data;
	newNode->LChild = NULL;
	newNode->RChild = NULL;
	return newNode;
}
//没有规律的树
void inserNode(LPTREE parentNode, LPTREE LChild, LPTREE RChild)
{
	parentNode->LChild = LChild;
	parentNode->RChild = RChild;

}

//打印当前结点的元素
void printCurNodeDate(LPTREE curData)
{
	cout << curData->data << " ";
}
//递归法
//先序: 根左右
void preOrder(LPTREE root)
{
	if (root != NULL)
	{
		printCurNodeDate(root);
		preOrder(root->LChild);
		preOrder(root->RChild);
	}
}
/* 
这个递归的意思是将每一个结点都作为一个根结点
依次打印本身->左节点->右节点 
每次打印左节点时又将左节点作为根去打印
知道遇到空指针即叶子末端
*/

//中序 左 根 右
void midOrder(LPTREE root)
{
	if (root != NULL)
	{
		midOrder(root->LChild);
		printCurNodeDate(root);
		midOrder(root->RChild);
	}
}

//后续 左 右 根
void lastOrder(LPTREE root)
{
	if (root != NULL)
	{
		lastOrder(root->LChild);
		lastOrder(root->RChild);
		printCurNodeDate(root);
	}
}


int main()
{
	//非常拉跨的创建过程，没有任何用
	//可以称为静态二叉树
	LPTREE A = createNode('A');
	LPTREE B = createNode('B');
	LPTREE C = createNode('C');
	LPTREE D = createNode('D');
	LPTREE E = createNode('E');
	LPTREE F = createNode('F');
	LPTREE G = createNode('G');
	inserNode(A, B, C);
	inserNode(B, D, NULL);
	inserNode(D, NULL, G);
	inserNode(C, E, F);

	cout << "先序遍历" << endl;
	preOrder(A);
	cout << endl;
	cout << "中序遍历" << endl;
	midOrder(A);
	cout << endl;
	cout << "后序遍历" << endl;
	lastOrder(A);
	cout << endl;


	system("pause");
	return 0;
}