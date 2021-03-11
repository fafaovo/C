//�Ƴ�ĳ��ֵ
void SListDelBack(SListNode** phead, SListDataType x)
{
	if (*phead == NULL)
	{
		return;
	}
	else
	{
		//˼·֮ͬǰ�����������ҵ�һ��ɾһ��
		SListNode * cur = *phead;
		SListNode * prev = NULL;

		while (cur)
		{
			if (cur->data == x){
				//���������и�����������Ǿ��������һ������Ҫ�ҵ�ֵ
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

//����������м�ڵ�[����ֻ�ܱ���һ������]
/*�������Ƕ�������ָ�룬
һ����ָ��fastһ����ָ��slow,
��ָ��һ��������,��ָ��һ����һ����
��ָ���ߵ�β����ָ�벻�����м���
����ǻ�����fast��������ҵ����һ����
�����ż����fast�����ᵽNULLβ���
*/
void middleNode(SListNode** phead){
	if (*phead == NULL)
	{
		return;
	}
	if ((*phead)->next == NULL)
	{
		printf("�м�����%d\n", (*phead)->data);
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
		printf("�м�����%d��%d\n", ptr->data, slow->data);
	}
	else
	{
		printf("�м�����%d\n", slow->data);
	}

}
