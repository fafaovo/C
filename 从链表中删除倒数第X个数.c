void ListQustdao(SListNode ** phead, int x)
{
	// ���ÿ����x�� ����ʱ��ָ�����ָ�������x��
	// Ȼ������ָ��ͬʱ��,��ָ���ߵ�β��ʱ��,���߻��������x����
	// ��ʱ���ҵ��˵�����X�����ˣ���Ϊ��������NULL���㣬����˵��Ҫx-1    
	SListNode* slow = *phead;
	//slow����
	SListNode* fast = *phead;
	int count = x - 1;
	//fast���
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
				printf("�ҵ��˵�����%d��������%d\n", x, slow->data);
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