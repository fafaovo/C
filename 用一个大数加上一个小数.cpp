#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

void addToArrayForm(int * A,int Asize,int k)
{
	//我们假设这个大数可能用unsigned long long都存不下
	//在这个前提下我们需要用数组本身来进行加加，
	//所以说我们需要把k变成一个数组,
	//接着我们需要开一个数组去存储最终两个数组相加得到的数
	//所以我们需要去判断究竟哪个数大
	int KSize = 0;
	int KNum = k;
	int mall = 0;
	while (KNum)
	{
		++KSize;
		KNum /= 10;
	}
	//这里可以得到K的元素个数，用于判断K大还是A大
	mall = Asize > KSize ? Asize: KSize;
	//二目表达式判断，取最大的+1位,
	//因为两个数相加最多肯定是比最多位的多1位
	//参考99+1=100 
	int * retArr = (int*)malloc(sizeof(int)* (mall+1));
	//开辟空间
	int Ai = Asize - 1;
	//A数组起始位置
	int reti = 0;
	//数组ret起始位置
	int nextNum = 0;
	//进位
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
		//当Ai已经走完了可能越界,所以需要用0去替代
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
	//来分析一下这个循环,
	//一开始A指向的是最后一个元素 K%10得到个位
	//进来将数组A第Ai个元素和K的个位相加,再加上为0的nextNum
	//然后进行判断，当超过10的时候，减去10并且将nextNum = 1
	//下一次进来的时候nextNum就能被加上了
	//到最后循环出去后，判断最后一个进位
	//最后我们可以得到一个逆序的结果，我们将他再逆序一下就可以输出了
	//逆置
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
	//打印
	for (int i = 0; i < reti; i++)
	{
		printf("%d", retArr[i]);
	}
	//释放内存
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