#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>


//void delstr(int * ps, int Size,int x)
//{
//	int i = 0;
//	while (i < Size)
//	{
//		if (ps[i] == x)
//		{
//			printf("%d", ps[i]);
//			int k = i;
//			while (k < Size)
//			{
//				ps[k] = ps[k + 1];
//				k++;
//			}
//			Size--;
//		}
//		else
//		{
//			i++;
//		}
//	}
//	printf("\n");
//	for (int i = 0; i < Size; i++)
//	{
//		printf("%d", ps[i]);
//	}
//}
//�ռ临�Ӷ�O(N**2)

void delstr(int * ps, int Size, int x)
//��һ�������ǽ��������ָ��,�ڶ���������Ԫ�ظ���[���ڱ�������],��������Ҫɾ�������е�ֵ
//��Ҫ��ʱ�临�Ӷ�ΪO(N)�ռ临�Ӷ�ΪO(1)ʱ,���Բ�ȡ���ַ�ʽ
{
	int src = 0, dst = 0;
	//�ȶ�������������������ָ������Ŀ�ͷ������Ϊ0��
	//��һ������src���ڱ�����������,
	//�ڶ�������dst���ڼ�¼������X�����ֵĸ���
	while (src < Size)
	{
		if (ps[src] != x)
		//��������Ԫ�ز�����xʱ,�Ͱ�ps[dst]����ps[src],Ȼ���ٽ���++
		//����������Ԫ�ص���xʱ,����src++
		//�Ϳ��Դ�dst��src��֮ǰ˵��dstָ�����ʵ�����ǵ���X�ĸ���,��ô����һ�β�����x��ʱ���Ǹ�������X�����ͻ��滻����������һ��X��λ��
		//�������ǵõ������鼴����dst��ΪԪ�ظ���ȥ����
		{
			ps[dst++] = ps[src++];
		}
		else
		{
			src++;
		}
	}
	//��������
	for (int i = 0; i < dst; i++)
	{
		printf("%d", ps[i]);
	}
}


int main()
{
	int arr[] = { 1, 2, 3, 4, 3, 6, 3, 3, 9, 3, 8, 2 };
	int size = sizeof(arr) / sizeof(arr[0]);
	delstr(arr,size, 3);
	return 0;
}