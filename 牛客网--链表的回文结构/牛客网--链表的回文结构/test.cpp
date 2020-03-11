//��Ŀ����
//����һ�����������һ��ʱ�临�Ӷ�ΪO(n), ����ռ临�Ӷ�ΪO(1)���㷨���ж����Ƿ�Ϊ���Ľṹ��
//
//����һ�������ͷָ��A���뷵��һ��boolֵ���������Ƿ�Ϊ���Ľṹ����֤������С�ڵ���900��
//
//����������
//1->2->2->1
//���أ�true
#include<iostream>
#include<vector>
using namespace std;
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) : val(x), next(NULL) {}
};
//����1  ����һ�����������ͷ�Ƚ�
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
//����2  ���м��㣬���ú�벿�֣������ֽ��бȽ�
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
		//���м���
		while (fast&&fast->next)
		{
			fast = fast->next->next;
			p = slow;//�����ָ���ǰһ����㣬���ָ���������ֱ�ӱȽ�
			slow = slow->next;
		}
		p->next == NULL;

		ListNode* B = reverseListNode(slow);//����
		//�Ƚ�
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