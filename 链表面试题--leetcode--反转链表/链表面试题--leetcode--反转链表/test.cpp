//206. 反转链表
//反转一个单链表。
//示例 :
//输入 : 1->2->3->4->5->NULL
//输出 : 5->4->3->2->1->NULL
// 进阶 :
//你可以迭代或递归地反转链表。你能否用两种方法解决这道题？

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
		//三个指针法
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

		//递归
		//输入：1->2->3->4->5->NULL
		//输出 : 5->4->3->2->1->NULL
		if (head)
		{
			reverseList(head->next);
			printf("%d", head->val);
		}
	}
};
//三个指针
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
//用递归方式打印    遵循后调用先退出
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
//将递归转成循环  有些代码可以直接转化为循环，有些递归需要借助栈转化为循环
