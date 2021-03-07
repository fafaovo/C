#include "seqlist.h"

//初始化函数
void SeqListInit(SL* ps){
	ps->a = (SLDataType*)malloc(sizeof(SLDataType)* 4);
	if (ps->a == NULL){
		printf("申请内存失败\n");
		exit(-1);
		//直接结束掉,因为申请内存都没法申请所以不用return
	}
	ps->size = 0;
	ps->capacity = 4;

	//s.size = 0;
	//s.a = NULL;
	//s.capacity = 0;
	////表示你什么都没存的初始化
}

//打印函数
void seqListPrint(SL * ps){
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n空间个数%d 实际个数%d\n",ps->capacity,ps->size);
}

//增容函数
void zenrong(SL *ps){
	//增容函数
	ps->capacity *= 2;
	//最好的增容方式是*2
	ps->a = (SLDataType*)realloc(ps->a, sizeof(SLDataType)*ps->capacity);
	//增容以后用原来的去接收他
	if (ps->a == NULL)
	{
		printf("增容失败");
		exit(-1);
	}
	//然后进行判断
}


//尾插 尾删 头插 头删 任意插 任意删
//尾插
void SeqListPushBack(SL* ps, SLDataType x)
{
	assert(ps);
	//如果满了需要增容
	if (ps->size >= ps->capacity){
		zenrong(ps);
		//增容函数
	}

	ps->a[ps->size] = x;
	ps->size++;
}

//尾删
void SeqListPopBack(SL * ps){
	assert(ps);

	//ps->a[ps->size - 1] = 0;
	//一般删数据不删真数据,只是减一下
	ps->size--;
}

//头插
void SeqListPushFront(SL* ps, SLDataType x)
{
	assert(ps);
	if (ps->size >= ps->capacity){
		zenrong(ps);
		//增容函数
	}
	int end = ps->size - 1;
	//指向这个空间的最后一个位置
	while (end>=0)
	{
		ps->a[end + 1] = ps->a[end];
		--end;
	}
	ps->a[0] = x;
	ps->size++;
}

//头删
void SeqListPopFront(SL * ps)
{
	assert(ps);
	int end = ps->size - 1;
	for (int i = 0; i < end; i++)
	{
		ps->a[i] = ps->a[i+1];
	}
	//从前往后的挪动
	ps->size--;
}


//指定插入
void SeqListInsert(SL * ps, int pos, SLDataType x)
{
	assert(ps);
	assert(pos < ps->size && pos >= 0);
	if (ps->size==ps->capacity)
	{
		zenrong(ps);
	}
	int end = ps->size - 1;
	while (end >= pos)
	{
		ps->a[end + 1] = ps->a[end];
		--end;
	}
	ps->a[pos] = x;
	ps->size++;
}


//指定删除
void SeqListErase(SL * ps, int pos)
{
	assert(ps);
	assert(pos < ps->size && pos >= 0);
	int end = ps->size;
	for (int i = pos; i < end; i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}

//查找
int SeqListFind(SL *ps, SLDataType x)
{
	assert(ps);
	for (size_t i = 0; i < ps->size; i++)
	{   
		if (ps->a[i] == x)
		{
			return i;
		}
	}
	return -1;
}


//释放清空
void seqListDestory(SL * ps)
{
	free(ps->a);
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}