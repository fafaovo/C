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
//空间复杂度O(N**2)

void delstr(int * ps, int Size, int x)
//第一个参数是接收数组的指针,第二个是数组元素个数[用于遍历数组],第三个是要删除数组中的值
//当要求时间复杂度为O(N)空间复杂度为O(1)时,可以采取这种方式
{
	int src = 0, dst = 0;
	//先定义两个变量，两个都指向数组的开头，即都为0，
	//第一个变量src用于遍历整个数组,
	//第二个变量dst用于记录不等于X的数字的个数
	while (src < Size)
	{
		if (ps[src] != x)
		//当遍历的元素不等于x时,就把ps[dst]赋给ps[src],然后再进行++
		//当遍历到的元素等于x时,仅把src++
		//就可以错开dst和src，之前说到dst指向的其实都不是等于X的个数,那么当下一次不等于x的时候，那个不等于X的数就会替换掉数组中上一个X的位置
		//最终我们得到的数组即可用dst作为元素个数去遍历
		{
			ps[dst++] = ps[src++];
		}
		else
		{
			src++;
		}
	}
	//遍历数组
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