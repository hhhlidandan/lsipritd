#include<stdio.h>

//��������������ϲ�Ϊһ���µ������������ء���������ͨ��ƴ�Ӹ�����������������нڵ���ɵġ�
//
//ʾ����
//
//���룺1->2->4, 1->3->4
//�����1->1->2->3->4->4
/**
* Definition for singly-linked list.
*/
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == NULL)
		{
			return l2;
		}
		if (l2 == NULL)
		{
			return l1;
		}
		ListNode* NewNode = NULL;//�½��
		ListNode* BeforeNode = NULL;//ǰһ�����
		int index = 1;
		while (l1 != NULL && l2 != NULL)
		{
			if (l1->val <= l2->val)
			{
				//��һ������Ϊͷ���
				if (index == 1)
				{
					NewNode = l1;
					index++;
				}
				if (BeforeNode != NULL)
				{
					BeforeNode->next = l1;

				}
				BeforeNode = l1;//�ѽ���Ƶ���ǰλ�ã��´ε�next������
				l1 = l1->next;
			}
			else if (l1->val>l2->val)
			{
				if (index == 1)
				{
					NewNode = l2;
					index++;
				}
				if (BeforeNode != NULL)
				{
					BeforeNode->next = l2;
				}
				BeforeNode = l2;
				l2 = l2->next;
			}
		}
		if (l1 != NULL)
		{
			BeforeNode->next = l1;
		}
		if (l2 != NULL)
		{
			BeforeNode->next = l2;
		}
		return NewNode;
	}
};