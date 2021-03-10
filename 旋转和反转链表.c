//旋转链表（链表 旋转次数）
void SListRotateBack(SListNode** phead, int rotate)
{
	if (*phead == NULL || rotate == 0)
	{
		return;
	}
	else
	{
		for (int i = 0; i < rotate; i++)
		{
			SListNode * cur = *phead;
			while (cur != NULL)
			{
				SListDataType result = (*phead)->data;
				(*phead)->data = cur->data;
				cur->data = result;
				cur = cur->next;
			}
		}
	}
}

//void fanzhuanSList(SListNode** phead)
//{
//	/*
//	思路是这样的，反转链表其实可以反转箭头方向
//	假设有个链表是 1->2->3->4->NULL
//	我们让1作为开头指向一个NULL NULL<-1->2->3->4->NULL
//	然后再依次让后面的指向前面的,因为让后面的指向前面会丢失下一个的地址
//	所以需要一个n3指向第三个的地址，即用二指向一
//	到最后n3指向NULL时，n1指向3 n2指向4, 此时需要在执行一次，让3<-4
//	所以循环会在n2 ==NULL 停止
//	*/
//	if (*phead == NULL || (*phead)->next == NULL)
//	{
//		return;
//	}	
//	SListNode * n1 = NULL;
//	SListNode * n2 = *phead;
//	SListNode * n3 = (*phead)->next;
//	while (n2)
//	{
//		这一步就是反转了
//		n2->next = n1;
//		n1 = n2;
//		n2 = n3;
//		if (n3){
//			n3 = n3->next;
//		}		
//	}
//	*phead = n1;
//}

void fanzhuanSList(SListNode** phead)
{
	/*
	我们使用头插的方式来旋转这个数组，
	首先新建一个新的链表，指向NULL
	然后去遍历整个*phead整个链表
	首先将找到的第一个元素放到新的链表中
	即*phead 的下一个为 NULL，然后再把 NewNode指向
	这个新数组的起始位置也就是cur
	紧接着把记录下一个地址位置的next赋值给cur这个指针用于
	继续遍历整个数组，然后再将ptr指向下一个链表
	当next为NULL的时候不再指向下一个，结束循环
	至此将新链表起始位置返回给*phead
	*/
	if (*phead == NULL || (*phead)->next == NULL)
	{
		return;
	}
	SListNode * NewNode = NULL;
	SListNode * cur = *phead;
	SListNode * next = cur->next;
	while (cur)
	{
		cur->next = NewNode;
		NewNode = cur;
		cur = next;
		if (next){
			next = next->next;
		}
	}
	*phead = NewNode;
}