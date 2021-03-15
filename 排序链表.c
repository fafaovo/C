//��������
void insertionSortList(SListNode ** head)
{
	//����,������ǿ��������ֻ��һ��Ԫ�أ�ֱ�ӷ���
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	//�½�һ��ָ��ͷ �� һ��ָ��ͷ��һ����ָ��,Ȼ�����ָ��ͷ��next�ĳ�NULL
	//��Ϊ�µ�����,��ʱ����ֻ��һ��ֵ��Ȼ��Ӿɵ�����������ȡ��ֵ���в���
	//��ʱcur�����ҵ�ԭ��ͷ����һ��
	SListNode * sortHead = *head;
	SListNode * cur = (*head)->next;
	sortHead->next = NULL;
	while (cur)
	{
		//�����¼��cur����һ���ĵ�ַ
		SListNode * next = cur->next;
		//���cur С�ڵ��� sorthead ��ô��ֱ�ӽ���ͷ��
		//curָ����Ǿ�����ĵڶ���ֵ ���������һ��ֵԭ���Ǿ�����ĵ�һ��ֵ
		if (cur->data <= sortHead->data)
		{
			cur->next = sortHead;
			sortHead = cur;
		}
		else
		{
			SListNode* sortPrev = sortHead;
			SListNode* sortCur = sortHead->next;
			//�˴����������������м����
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
			//�˴�ѭ���ѽ�������Ҫ�ж��Ƿ���break���������������Ѿ���������ˣ��������ɽ���β��
			if (sortCur == NULL)
			{
				sortPrev->next = cur;
				cur->next = NULL;
			}
		}
		//Ȼ����һ��ֵ����cur��������һ�ε�ѭ��
		cur = next;
	}
	*head = sortHead;

}