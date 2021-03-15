//排序链表
void insertionSortList(SListNode ** head)
{
	//假设,传入的是空链表或者只有一个元素，直接返回
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	//新建一个指向头 和 一个指向头下一个的指针,然后将这个指向头的next改成NULL
	//作为新的链表,此时链表只有一个值，然后从旧的链表中依次取出值进行插入
	//此时cur就能找到原本头的下一个
	SListNode * sortHead = *head;
	SListNode * cur = (*head)->next;
	sortHead->next = NULL;
	while (cur)
	{
		//这里记录了cur的下一个的地址
		SListNode * next = cur->next;
		//如果cur 小于等于 sorthead 那么就直接进行头插
		//cur指向的是旧链表的第二个值 而新链表第一个值原本是旧链表的第一个值
		if (cur->data <= sortHead->data)
		{
			cur->next = sortHead;
			sortHead = cur;
		}
		else
		{
			SListNode* sortPrev = sortHead;
			SListNode* sortCur = sortHead->next;
			//此处遍历新链表，进行中间插入
			while (sortCur)
			{
				if (cur->data <= sortCur->data)
				{
					sortPrev->next = cur;
					cur->next = sortCur;
					break;
				}
				else
				{
					sortPrev = sortCur;
					sortCur = sortCur->next;
				}
			}
			//此处循环已结束，需要判断是否是break跳出还是新数组已经遍历完成了，如果是完成进行尾插
			if (sortCur == NULL)
			{
				sortPrev->next = cur;
				cur->next = NULL;
			}
		}
		//然后将下一个值赋给cur，进行下一次的循环
		cur = next;
	}
	*head = sortHead;

}