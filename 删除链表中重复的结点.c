/*https://www.nowcoder.com/questionTerminal/fc533c45b73a41b0b44ccba763f866ef*/
/*��һ������������У������ظ��Ľ�㣬��ɾ�����������ظ��Ľ�㣬�ظ��Ľ�㲻��������������ͷָ�롣*/
/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};
*/
class Solution {
public:
	ListNode* deleteDuplication(ListNode* pHead) {
		//���������ֻ��һ��Ԫ�ػ���û��Ԫ��ֱ�ӷ���
		if (pHead == NULL || pHead->next == NULL)
		{
			return pHead;
		}
		//������Ҫ��������ָ�룬��һ��ָ��ָ��curǰ���Ԫ��
		//�ڶ���ָ��ָ���һ��Ԫ��
		//���һ��ָ��ָ��ڶ���Ԫ��
		ListNode * prev = NULL;
		ListNode * cur = pHead;
		ListNode * next = pHead->next;
		//��next�ߵ�β��ʱ��,��ζ��ѭ������
		//��Ϊnext����ǰ���ָ��
		while (next)
		{
			if (cur->val != next->val)
			{
				prev = cur;
				cur = next;
				next = next->next;
			}
			else
			{
				//���ҵ�����Ԫ�����ʱ����next�ߣ�
				//ȥ�ж���һ��Ԫ���Ƿ��ֺ�cur���
				//����next���ڲ���ȵ�Ԫ��ͣ����
				//��ʱ��cur��next֮���Ԫ��ɾ���ͺ���
				while (next && cur->val == next->val)
				{
					next = next->next;
				}
				//��prev����һ��ָ��next,�����ͷ����е�����Ԫ��
				//����ǰ����prev��Ϊ�գ����һ������һ�����͵ڶ���������ȵ�haul
				//��ôprev��Ϊ��,��ʱ�ͻᷢ���δ���
				if (prev)
				{
					prev->next = next;
				}
				else
				{
					pHead = next;
					//��ʱnext�Ѿ�ѭ��������ȵ�Ԫ�أ�ֱ�Ӱ�ͷ����next
				}

				//�ͷ�
				while (cur != next)
				{
					ListNode* del = cur;
					cur = cur->next;
					free(del);
				}
				//�ͷ����cur���ߵ�next��λ��
				if (next)
					next = cur->next;
			}
		}
		return pHead;
	}
};