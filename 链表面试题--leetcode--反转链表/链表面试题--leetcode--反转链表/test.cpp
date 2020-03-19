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
		//����ָ�뷨
		/*if (head == NULL)  return 0;
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
		return head;*/

		//�ݹ�
		//���룺1->2->3->4->5->NULL
		//��� : 5->4->3->2->1->NULL
		if (head)
		{
			reverseList(head->next);
			printf("%d", head->val);
		}
	}
};
//����ָ��
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if (head == NULL) return NULL;
		ListNode* p = NULL;
		ListNode* Cur = head->next;
		while (head)
		{
			head->next = p;
			p = head;
			head = Cur;
			if (head) Cur = head->next;
		}
		return p;
	}
};
//�õݹ鷽ʽ��ӡ    ��ѭ��������˳�
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return head;
		ListNode* newhead = reverseList(head->next);
		head->next->next = head;
		head->next = NULL;
		return newhead;
	}
};
//���ݹ�ת��ѭ��  ��Щ�������ֱ��ת��Ϊѭ������Щ�ݹ���Ҫ����ջת��Ϊѭ��
