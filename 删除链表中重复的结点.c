/*https://www.nowcoder.com/questionTerminal/fc533c45b73a41b0b44ccba763f866ef*/
/*在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。*/
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
		//当这个链表只有一个元素或者没有元素直接返回
		if (pHead == NULL || pHead->next == NULL)
		{
			return pHead;
		}
		//我们需要定义三个指针，第一个指针指向cur前面的元素
		//第二个指针指向第一个元素
		//最后一个指针指向第二个元素
		ListNode * prev = NULL;
		ListNode * cur = pHead;
		ListNode * next = pHead->next;
		//当next走到尾的时候,意味着循环结束
		//因为next是最前面的指针
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
				//当找到两个元素相等时，让next走，
				//去判断下一个元素是否又和cur相等
				//最终next会在不相等的元素停下来
				//此时将cur到next之间的元素删掉就好了
				while (next && cur->val == next->val)
				{
					next = next->next;
				}
				//将prev的下一个指向next,并且释放其中的其他元素
				//但是前提是prev不为空，如果一上来第一个数和第二个数就相等的haul
				//那么prev就为空,此时就会发生段错误
				if (prev)
				{
					prev->next = next;
				}
				else
				{
					pHead = next;
					//此时next已经循环到不相等的元素，直接把头给到next
				}

				//释放
				while (cur != next)
				{
					ListNode* del = cur;
					cur = cur->next;
					free(del);
				}
				//释放完后cur会走到next的位置
				if (next)
					next = cur->next;
			}
		}
		return pHead;
	}
};