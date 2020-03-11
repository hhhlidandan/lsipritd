//题目描述
//对于一个链表，请设计一个时间复杂度为O(n), 额外空间复杂度为O(1)的算法，判断其是否为回文结构。
//
//给定一个链表的头指针A，请返回一个bool值，代表其是否为回文结构。保证链表长度小于等于900。
//
//测试样例：
//1->2->2->1
//返回：true
#include<iostream>
#include<vector>
using namespace std;
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) : val(x), next(NULL) {}
};
//方法1  放在一个数组里，从两头比较
class PalindromeList {
public:
	bool chkPalindrome(ListNode* A) {
		vector<int> num;
		num.resize(900);
		int count = 0;
		while (A)
		{
			num[count++] = A->val;
			A = A->next;
		}
		int left = 0, right = count - 1;
		while (left <= right)
		{
			if (num[left] != num[right])
				return false;
			left++, right--;
		}
		return true;
	}
};
//方法2  找中间结点，逆置后半部分，两部分进行比较
class PalindromeList {
public:

	ListNode* reverseListNode(ListNode* head)
	{
		ListNode* Cur = NULL;
		ListNode* p = NULL;
		ListNode* Node = head;
		while (Node)
		{
			Cur = Node->next;
			Node->next = p;
			p = Node;
			Node = Cur;
		}
		return p;
	}
	bool chkPalindrome(ListNode* A) {
		ListNode* fast = A;
		ListNode* slow = A;
		ListNode* p = A;
		//找中间结点
		while (fast&&fast->next)
		{
			fast = fast->next->next;
			p = slow;//标记慢指针的前一个结点，最后分割两个链表，直接比较
			slow = slow->next;
		}
		p->next == NULL;

		ListNode* B = reverseListNode(slow);//逆置
		//比较
		while (A&&B)
		{
			if (A->val != B->val)
				return false;
			A = A->next;
			B = B->next;
		}
		return true;
	}
};