//142. 环形链表 II
//难度
//中等
//
//
//给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
//为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 - 1，则在该链表中没有环。
//说明：不允许修改给定的链表。
//
//示例 1：
//输入：head = [3, 2, 0, -4], pos = 1
//输出：tail connects to node index 1
//解释：链表中有一个环，其尾部连接到第二个节点。
//
//示例 2：
//输入：head = [1, 2], pos = 0
//输出：tail connects to node index 0
//解释：链表中有一个环，其尾部连接到第一个节点。
//
//示例 3：
//输入：head = [1], pos = -1
//输出：no cycle
//解释：链表中没有环。
#include<iostream>
using namespace std;
 struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		ListNode* slow = head;
		ListNode* fast = head;
		//先让他们相遇
		while (fast&&fast->next)
		{
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast) break;
		}
		if (fast == NULL || fast->next == NULL)   return NULL;
		//到这就相等了,然后一个从相遇点走，一个从起点走
		ListNode* go = fast;
		ListNode* pHead = head;
		while (go != pHead)
		{
			go = go->next;
			pHead = pHead->next;
		}
		return pHead;
	}
};

