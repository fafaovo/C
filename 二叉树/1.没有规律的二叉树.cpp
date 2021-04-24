#include <iostream>
using namespace std;


//������һ���� ����һ��ָ��һ���ṹ�����
typedef struct treeNode
{
	char data;	//�������ַ���ʾ
	struct treeNode* LChild;
	struct treeNode* RChild;
}TREE,*LPTREE;


//�½��ڵ�
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
//û�й��ɵ���
void inserNode(LPTREE parentNode, LPTREE LChild, LPTREE RChild)
{
	parentNode->LChild = LChild;
	parentNode->RChild = RChild;

}

//��ӡ��ǰ����Ԫ��
void printCurNodeDate(LPTREE curData)
{
	cout << curData->data << " ";
}
//�ݹ鷨
//����: ������
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
����ݹ����˼�ǽ�ÿһ����㶼��Ϊһ�������
���δ�ӡ����->��ڵ�->�ҽڵ� 
ÿ�δ�ӡ��ڵ�ʱ�ֽ���ڵ���Ϊ��ȥ��ӡ
֪��������ָ�뼴Ҷ��ĩ��
*/

//���� �� �� ��
void midOrder(LPTREE root)
{
	if (root != NULL)
	{
		midOrder(root->LChild);
		printCurNodeDate(root);
		midOrder(root->RChild);
	}
}

//���� �� �� ��
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
	//�ǳ�����Ĵ������̣�û���κ���
	//���Գ�Ϊ��̬������
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

	cout << "�������" << endl;
	preOrder(A);
	cout << endl;
	cout << "�������" << endl;
	midOrder(A);
	cout << endl;
	cout << "�������" << endl;
	lastOrder(A);
	cout << endl;


	system("pause");
	return 0;
}