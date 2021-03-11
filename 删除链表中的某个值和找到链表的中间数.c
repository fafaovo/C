//移除某个值
void SListDelBack(SListNode** phead, SListDataType x)
{
	if (*phead == NULL)
	{
		return;
	}
	else
	{
		//思路同之前，遍历数组找到一个删一个
		SListNode * cur = *phead;
		SListNode * prev = NULL;

		while (cur)
		{
			if (cur->data == x){
				//但是这里有个特殊情况，那就是如果第一个就是要找的值
				if (cur == *phead){
					*phead = cur->next;
					free(cur);
					cur = *phead;
				}
				else
				{
					prev->next = cur->next;
					free(cur);
					cur = prev;
				}
			}
			else{
				prev = cur;
				cur = cur->next;
			}
		}
	}
}

//返回链表的中间节点[需求只能遍历一次数组]
/*假设我们定义两个指针，
一个快指针fast一个慢指针slow,
快指针一次走两步,慢指针一次走一步，
块指针走到尾，慢指针不就是中间了
如果是基数，fast到最后是找到最后一个数
如果是偶数，fast到最后会到NULL尾结点
*/
void middleNode(SListNode** phead){
	if (*phead == NULL)
	{
		return;
	}
	if ((*phead)->next == NULL)
	{
		printf("中间数是%d\n", (*phead)->data);
	}
	SListNode* slow = *phead;
	SListNode* fast = *phead;
	SListNode* ptr = NULL;
	while (fast  && fast->next)
	{
		ptr = slow;
		slow = slow->next;
		fast = fast->next->next;
	}
	if (fast == NULL)
	{
		printf("中间数是%d和%d\n", ptr->data, slow->data);
	}
	else
	{
		printf("中间数是%d\n", slow->data);
	}

}
