#include "seqlist.h"

//��ʼ������
void SeqListInit(SL* ps){
	ps->a = (SLDataType*)malloc(sizeof(SLDataType)* 4);
	if (ps->a == NULL){
		printf("�����ڴ�ʧ��\n");
		exit(-1);
		//ֱ�ӽ�����,��Ϊ�����ڴ涼û���������Բ���return
	}
	ps->size = 0;
	ps->capacity = 4;

	//s.size = 0;
	//s.a = NULL;
	//s.capacity = 0;
	////��ʾ��ʲô��û��ĳ�ʼ��
}

//��ӡ����
void seqListPrint(SL * ps){
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n�ռ����%d ʵ�ʸ���%d\n",ps->capacity,ps->size);
}

//���ݺ���
void zenrong(SL *ps){
	//���ݺ���
	ps->capacity *= 2;
	//��õ����ݷ�ʽ��*2
	ps->a = (SLDataType*)realloc(ps->a, sizeof(SLDataType)*ps->capacity);
	//�����Ժ���ԭ����ȥ������
	if (ps->a == NULL)
	{
		printf("����ʧ��");
		exit(-1);
	}
	//Ȼ������ж�
}


//β�� βɾ ͷ�� ͷɾ ����� ����ɾ
//β��
void SeqListPushBack(SL* ps, SLDataType x)
{
	assert(ps);
	//���������Ҫ����
	if (ps->size >= ps->capacity){
		zenrong(ps);
		//���ݺ���
	}

	ps->a[ps->size] = x;
	ps->size++;
}

//βɾ
void SeqListPopBack(SL * ps){
	assert(ps);

	//ps->a[ps->size - 1] = 0;
	//һ��ɾ���ݲ�ɾ������,ֻ�Ǽ�һ��
	ps->size--;
}

//ͷ��
void SeqListPushFront(SL* ps, SLDataType x)
{
	assert(ps);
	if (ps->size >= ps->capacity){
		zenrong(ps);
		//���ݺ���
	}
	int end = ps->size - 1;
	//ָ������ռ�����һ��λ��
	while (end>=0)
	{
		ps->a[end + 1] = ps->a[end];
		--end;
	}
	ps->a[0] = x;
	ps->size++;
}

//ͷɾ
void SeqListPopFront(SL * ps)
{
	assert(ps);
	int end = ps->size - 1;
	for (int i = 0; i < end; i++)
	{
		ps->a[i] = ps->a[i+1];
	}
	//��ǰ�����Ų��
	ps->size--;
}


//ָ������
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


//ָ��ɾ��
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

//����
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


//�ͷ����
void seqListDestory(SL * ps)
{
	free(ps->a);
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}