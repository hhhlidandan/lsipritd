//203. �Ƴ�����Ԫ��
//ɾ�������е��ڸ���ֵ val �����нڵ㡣
//
//ʾ�� :
//
//���� : 1->2->6->3->4->5->6, val = 6
//��� : 1->2->3->4->5

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/

class Solution {
public:
	ListNode* removeElements(ListNode* head, int val) {
		if (!head)
			return head;
		struct ListNode* pPre = head;
		struct ListNode* pCur = pPre->next;
		while (pCur)
		{
			if (pCur->val == val)
			{
				pPre->next = pCur->next;
				pCur = pPre->next;
			}
			else
			{
				pPre = pCur;
				pCur = pCur->next;
			}
		}
		if (head->val == val)
			head = head->next;
		return head;
	}
};