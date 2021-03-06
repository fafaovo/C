#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

//给与两个有序数组，合并 需求时间复杂度O(M+N) 
//但是他的空间复杂度是O(M+N) 

void merge(int * A, int * B,int ASize,int BSize)
{
	//为了节约时间复杂度，所以我们需要用时间复杂度去换
	int * tmp = (int*)malloc(sizeof(int)*(ASize + BSize));
	//开辟一个数组，大小是A+B长度的总和
	int Ai = 0, Bi = 0, tmpi = 0;
	//这里我们需要创建三个指向数组元素的变量
	//当Ai小于数组A大小 或者 Bi小于数组B 时循环继续，当两个有一个大于时，循环停止
	while (Ai <ASize && Bi < BSize)
	{
		if (A[Ai] < B[Bi])
			tmp[tmpi++] = A[Ai++];
		else
			tmp[tmpi++] = B[Bi++];
		//比较两个数大小，把小的放到新数组中
	}
	//当循环结束时，我们需要将另外一个数组中还没遍历的数放到数组里面
	while (Ai < ASize)
		tmp[tmpi++] = A[Ai++];
	while (Bi < BSize)
		tmp[tmpi++] = B[Bi++];
	//打印
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