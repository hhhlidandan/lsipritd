//题目描述
//编写代码，以给定值x为基准将链表分割成两部分，所有小于x的结点排在大于或等于x的结点之前
//
//给定一个链表的头指针 ListNode* pHead，请返回重新排列后的链表的头指针。注意：分割以后保持原来的数据顺序不变。
#include<iostream>

struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) : val(x), next(NULL) {}
};

class Partition {
public:
	ListNode* partition(ListNode* pHead, int x) {
		//先给两个链表，定义结构体类型的变量
		ListNode small(0);
		ListNode large(0);
		//给两个链表分别定义指针（进行尾插）
		ListNode* largeNode = &large;
		ListNode* smallNode = &small;
		while (pHead)
		{
			if (pHead->val < x)
			{
				smallNode->next = pHead;
				smallNode = pHead;
			}
			else
			{
				largeNode->next = pHead;
				largeNode = pHead;
			}
			pHead = pHead->next;
		}
		largeNode->next = NULL;//要让最后的结点指向空//  ->  指针访问结构体里的内容
		smallNode->next = large.next;//将两个链表连接
		return small.next;//     .  结构体类型变量访问内部成员
	}
};