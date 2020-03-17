//142. �������� II
//�Ѷ�
//�е�
//
//
//����һ��������������ʼ�뻷�ĵ�һ���ڵ㡣 ��������޻����򷵻� null��
//Ϊ�˱�ʾ���������еĻ�������ʹ������ pos ����ʾ����β���ӵ������е�λ�ã������� 0 ��ʼ���� ��� pos �� - 1�����ڸ�������û�л���
//˵�����������޸ĸ���������
//
//ʾ�� 1��
//���룺head = [3, 2, 0, -4], pos = 1
//�����tail connects to node index 1
//���ͣ���������һ��������β�����ӵ��ڶ����ڵ㡣
//
//ʾ�� 2��
//���룺head = [1, 2], pos = 0
//�����tail connects to node index 0
//���ͣ���������һ��������β�����ӵ���һ���ڵ㡣
//
//ʾ�� 3��
//���룺head = [1], pos = -1
//�����no cycle
//���ͣ�������û�л���
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
		//������������
		while (fast&&fast->next)
		{
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast) break;
		}
		if (fast == NULL || fast->next == NULL)   return NULL;
		//����������,Ȼ��һ�����������ߣ�һ���������
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

