//206. ��ת����
//��תһ��������
//ʾ�� :
//���� : 1->2->3->4->5->NULL
//��� : 5->4->3->2->1->NULL
// ���� :
//����Ե�����ݹ�ط�ת�������ܷ������ַ����������⣿

#include<stdio.h>

 //Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if (head == NULL)  return 0;
		ListNode* p = head->next;
		ListNode* Cur = head;
		head->next = NULL;
		while (p)
		{
			Cur = head;
			head = p;
			p = head->next;
			head->next = Cur;
		}
		return head;
	}
};