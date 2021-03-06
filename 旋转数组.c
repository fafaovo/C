#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//��򵥵��㷨
//void rotate(int * Arr, int size, int input)
//{
//	for (int i = 0; i < input; i++)
//	{
//		int end = Arr[size - 1];
//		int k = size - 1;
//		while (k > 0)
//		{
//			Arr[k] = Arr[k - 1];
//			k--;
//		}
//		Arr[0] = end;
//	}
//	for (int i = 0; i < size; i++)
//	{
//		printf("%d", Arr[i]);
//	}
//	printf("\n");
//}

/*
�㷨�����㷽��
���������и�������1234��ת����
���ǽ��ڶ�����Ϊ��ʼλ�÷ָ�ֱ���������
21 43
Ȼ����������
3412
�õ���ת���εĽ��
*/
void reverse(int* nums, int left, int right)
{
	while (left < right)
	{
		int tmp = nums[left];
		nums[left] = nums[right];
		nums[right] = tmp;
		right--;
		left++;
	}
}

void rotate(int * Arr,int size,int input)
{
	//input���ܴ��������С����ô�����ͱ�ģû�ˣ�������ȥ��ת
	//����ȷ��������С��2,��ת2�Σ���ô���鲻�䣬������ת��3��
	//��ô���൱����ת��1��
	input %= size;

	reverse(Arr, 0, size - input - 1);
	//��һ������inputǰ����� �ܴ�С-���ô���-1�õ�����
	reverse(Arr, size - input, size-1);
	//�ڶ�������input������� �ָ�����size - input - 1 ����˵�Ұ����ʼλ���� size - input
	reverse(Arr, 0, size - 1);
	//������������������
	
}



int main()
{
	int Arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int size = sizeof(Arr) / sizeof(Arr[0]);
	int input = 252145451574884;
	rotate(Arr,size,input);
	for (int i = 0; i < size; i++)
	{
		printf("%d", Arr[i]);
	}
	return 0;
}