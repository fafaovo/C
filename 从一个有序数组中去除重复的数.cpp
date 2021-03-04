#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//从一个有序数列中移除重复出现的数字
void StrDel(int * ps, int x)
{
	int str = 0;
	int dst = 0;
	int cur = 1;
	//先定义都在初始位置的str和tmp,str用于遍历整个数组,tmp用于记录没有重复出现的数字
	//但是如果使用str+1，那么这个str+1将会越界,所以说需要额外定义一个变量cur代替str+1
	while (cur < x)
	{
		if (ps[str] != ps[cur])
			//这里是if (ps[str] != ps[str+1])可能越界指针的地方
		{
			ps[dst] = ps[str];
			str++;
			dst++;
			cur++;
		}
		else{
			str++;
			cur++;
		}
		//如果数组中第一个和第二个相等，
		//那么tmp不动,str继续遍历整个数组
		//如果不相等，那么就把第一个数字赋给tmp，也就是第一个位置，并且同时进行++
		//以此类推
	}
	//当遍历到最后一次判断完时，str指向的是数组倒数第二个,cur指向的是最后一个，
	//假如说两者相等,两者同时加加,没有赋任何值，str指向最后一个，如果此时ps[cur]则会越界，
	//但是此时已经跳出判断了，此时再将最后一个元素赋给dst
	//假如说两者不相等，进入if中，将倒数第二个赋给dst,然后再将倒数第一个赋给dst
	ps[dst] = ps[str];
	dst++;
	str++;
	
	for (int i = 0; i < dst; i++)
	{
		printf("%d ", ps[i]);
	}
}


int main(){
	int arr[] = { 1, 1, 2, 2, 3, 3, 4, 5, 6, 7, 7 ,7,8,8};
	int Size = sizeof(arr) / sizeof(arr[0]);
	StrDel(arr, Size);
}