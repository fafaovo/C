#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//最简单的算法
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
算法最优秀方法
假设我们有个数组是1234旋转两次
我们将第二个作为起始位置分割，分别逆置数组
21 43
然后整体逆置
3412
得到旋转两次的结果
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
	//input可能大于数组大小，那么倍数就被模没了，用余数去旋转
	//打个比方，数组大小是2,旋转2次，那么数组不变，假设旋转了3次
	//那么就相当于旋转了1次
	input %= size;

	reverse(Arr, 0, size - input - 1);
	//第一次逆置input前面的数 总大小-逆置次数-1得到底数
	reverse(Arr, size - input, size-1);
	//第二次逆置input后面的数 分割线在size - input - 1 所以说右半边起始位置是 size - input
	reverse(Arr, 0, size - 1);
	//第三次逆置整个数组
	
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