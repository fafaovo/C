//��ת�������� ��ת������
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
//	˼·�������ģ���ת������ʵ���Է�ת��ͷ����
//	�����и������� 1->2->3->4->NULL
//	������1��Ϊ��ͷָ��һ��NULL NULL<-1->2->3->4->NULL
//	Ȼ���������ú����ָ��ǰ���,��Ϊ�ú����ָ��ǰ��ᶪʧ��һ���ĵ�ַ
//	������Ҫһ��n3ָ��������ĵ�ַ�����ö�ָ��һ
//	�����n3ָ��NULLʱ��n1ָ��3 n2ָ��4, ��ʱ��Ҫ��ִ��һ�Σ���3<-4
//	����ѭ������n2 ==NULL ֹͣ
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
//		��һ�����Ƿ�ת��
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
	����ʹ��ͷ��ķ�ʽ����ת������飬
	�����½�һ���µ�����ָ��NULL
	Ȼ��ȥ��������*phead��������
	���Ƚ��ҵ��ĵ�һ��Ԫ�طŵ��µ�������
	��*phead ����һ��Ϊ NULL��Ȼ���ٰ� NewNodeָ��
	������������ʼλ��Ҳ����cur
	�����ŰѼ�¼��һ����ַλ�õ�next��ֵ��cur���ָ������
	���������������飬Ȼ���ٽ�ptrָ����һ������
	��nextΪNULL��ʱ����ָ����һ��������ѭ��
	���˽���������ʼλ�÷��ظ�*phead
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