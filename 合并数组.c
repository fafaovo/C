#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

//���������������飬�ϲ� ����ʱ�临�Ӷ�O(M+N) 
//�������Ŀռ临�Ӷ���O(M+N) 

void merge(int * A, int * B,int ASize,int BSize)
{
	//Ϊ�˽�Լʱ�临�Ӷȣ�����������Ҫ��ʱ�临�Ӷ�ȥ��
	int * tmp = (int*)malloc(sizeof(int)*(ASize + BSize));
	//����һ�����飬��С��A+B���ȵ��ܺ�
	int Ai = 0, Bi = 0, tmpi = 0;
	//����������Ҫ��������ָ������Ԫ�صı���
	//��AiС������A��С ���� BiС������B ʱѭ����������������һ������ʱ��ѭ��ֹͣ
	while (Ai <ASize && Bi < BSize)
	{
		if (A[Ai] < B[Bi])
			tmp[tmpi++] = A[Ai++];
		else
			tmp[tmpi++] = B[Bi++];
		//�Ƚ���������С����С�ķŵ���������
	}
	//��ѭ������ʱ��������Ҫ������һ�������л�û���������ŵ���������
	while (Ai < ASize)
		tmp[tmpi++] = A[Ai++];
	while (Bi < BSize)
		tmp[tmpi++] = B[Bi++];
	//��ӡ
	for (int i = 0; i < tmpi; i++)
		printf("%d", tmp[i]);


}


int main()
{
	int A[] = { 1, 2, 3, 4, 5, 6};
	int B[] = { 2, 7, 8, 9 };
	int ASize = sizeof(A) / sizeof(A[0]);
	int BSize = sizeof(B) / sizeof(B[0]);
	merge(A, B, ASize, BSize);
	return 0;
}