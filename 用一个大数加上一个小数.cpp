#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

void addToArrayForm(int * A,int Asize,int k)
{
	//���Ǽ����������������unsigned long long���治��
	//�����ǰ����������Ҫ�����鱾�������мӼӣ�
	//����˵������Ҫ��k���һ������,
	//����������Ҫ��һ������ȥ�洢��������������ӵõ�����
	//����������Ҫȥ�жϾ����ĸ�����
	int KSize = 0;
	int KNum = k;
	int mall = 0;
	while (KNum)
	{
		++KSize;
		KNum /= 10;
	}
	//������Եõ�K��Ԫ�ظ����������ж�K����A��
	mall = Asize > KSize ? Asize: KSize;
	//��Ŀ���ʽ�жϣ�ȡ����+1λ,
	//��Ϊ������������϶��Ǳ����λ�Ķ�1λ
	//�ο�99+1=100 
	int * retArr = (int*)malloc(sizeof(int)* (mall+1));
	//���ٿռ�
	int Ai = Asize - 1;
	//A������ʼλ��
	int reti = 0;
	//����ret��ʼλ��
	int nextNum = 0;
	//��λ
	while (mall--)
	{
		int ret = 0;
		if (Ai < 0)
		{
			ret = 0 + (k % 10) + nextNum;
		}
		else
		{
			ret = A[Ai] + (k % 10) + nextNum;
		}
		//��Ai�Ѿ������˿���Խ��,������Ҫ��0ȥ���
		if (ret > 9)
		{
			ret -= 10;
			nextNum = 1;
		}
		else
		{
			nextNum = 0;
		}
		retArr[reti] = ret;
		reti++;
		Ai--;
		k /= 10;
	}
	if (nextNum == 1)
	{
		retArr[reti] = 1;
		reti++;
	}
	//������һ�����ѭ��,
	//һ��ʼAָ��������һ��Ԫ�� K%10�õ���λ
	//����������A��Ai��Ԫ�غ�K�ĸ�λ���,�ټ���Ϊ0��nextNum
	//Ȼ������жϣ�������10��ʱ�򣬼�ȥ10���ҽ�nextNum = 1
	//��һ�ν�����ʱ��nextNum���ܱ�������
	//�����ѭ����ȥ���ж����һ����λ
	//������ǿ��Եõ�һ������Ľ�������ǽ���������һ�¾Ϳ��������
	//����
	int left = 0;
	int right = reti - 1;
	while (left < right)
	{
		int tmp = retArr[left];
		retArr[left] = retArr[right];
		retArr[right] = tmp;
		++left;
		--right;
	}
	//��ӡ
	for (int i = 0; i < reti; i++)
	{
		printf("%d", retArr[i]);
	}
	//�ͷ��ڴ�
	free(retArr);
	retArr = NULL;
}


int main()
{
	int arr[] = {1, 1, 2, 1, 5 };
	int ASize = sizeof(arr) / sizeof(arr[0]);
	int k = 111806;
	addToArrayForm(arr, ASize,k);
	return 0;
}