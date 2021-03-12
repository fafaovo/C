void ListQustdao(SListNode ** phead, int x)
{
	// 先让快的走x步 ，此时块指针和慢指针相差了x步
	// 然后两个指针同时走,块指针走到尾的时候,两者还是相差了x步，
	// 此时就找到了倒数第X的数了，因为链表最后的NULL不算，所以说需要x-1    
	SListNode* slow = *phead;
	//slow慢的
	SListNode* fast = *phead;
	int count = x - 1;
	//fast快的
	while (slow)
	{
		if (count != 0)
		{
			if (fast)
			{
				fast = fast->next;
				count--;
			}
			else
				return NULL;
		}
		else
		{
			if ((fast->next) == NULL)
			{
				printf("找到了倒数第%d个数是是%d\n", x, slow->data);
				return;
			}
			else
			{
				fast = fast->next;
				slow = slow->next;
			}
		}
	}

}