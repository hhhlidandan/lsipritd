//��Ŀ����
//����һ����������������е�����k����㡣
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
		//����1 
		//����һ���ж��ٸ����
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
		//����2
		ListNode* fast = pListHead;
		ListNode* slow = pListHead;
		while (k--)//����Ϊ���Լ�K==0�����ѭ�����һ������
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