//题目描述
//输入一个链表，输出该链表中倒数第k个结点。
#include<iostream>
using namespace std;
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
	val(x), next(NULL) {
	}
};

class Solution {
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		//方法1 
		//计算一共有多少个结点
		//unsigned count=0;
		//ListNode* cur=pListHead;
		//while(cur)
		//{
		//    count++;
		//    cur=cur->next;
		//}
		//ListNode* p=pListHead;
		//while(count!=k&&p)
		//{
		//    p=p->next;
		//   count--;
		///}
		//return p;
		//方法2
		ListNode* fast = pListHead;
		ListNode* slow = pListHead;
		while (k--)//链表为空以及K==0在这个循环里就一起检测了
		{
			if (fast) fast = fast->next;
			else return NULL;
		}
		while (fast)
		{
			slow = slow->next;
			fast = fast->next;
		}
		return slow;
	}
};