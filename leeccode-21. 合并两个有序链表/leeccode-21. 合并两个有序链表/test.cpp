#include<stdio.h>

//将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
//
//示例：
//
//输入：1->2->4, 1->3->4
//输出：1->1->2->3->4->4
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
		ListNode* NewNode = NULL;//新结点
		ListNode* BeforeNode = NULL;//前一个结点
		int index = 1;
		while (l1 != NULL && l2 != NULL)
		{
			if (l1->val <= l2->val)
			{
				//第一个设置为头结点
				if (index == 1)
				{
					NewNode = l1;
					index++;
				}
				if (BeforeNode != NULL)
				{
					BeforeNode->next = l1;

				}
				BeforeNode = l1;//把结点移到当前位置，下次的next再连接
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