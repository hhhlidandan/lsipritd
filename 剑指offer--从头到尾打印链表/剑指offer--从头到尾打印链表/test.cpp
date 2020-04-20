#include<iostream>
#include<vector>
#include<stack>
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
	vector<int> printListFromTailToHead(ListNode* head)
	{
		//����
		//vector<int> ret;
		//if (head == NULL) return ret;
		//ListNode* pre = NULL;
		//ListNode* cur = head->next;
		//while (cur)//����
		//{
		//	head->next = pre;
		//	pre = head;
		//	head = cur;
		//	cur = cur->next;
		//}
		//head->next = pre;
		//while (head)//��ӡ
		//{
		//	ret.push_back(head->val);
		//	head = head->next;
		//}
		//return ret;

		//����ջ
		stack<int> s;
		vector<int> v;
		while (head)
		{
			s.push(head->val);
			head = head->next;
		}
		while (!s.empty())
		{
			v.push_back(s.top());
			s.pop();
		}
		return v;

		//�ⷨ4�����������
		/*vector<int> v;
		while (head)
		{
			v.push_back(head->val);
			head = head->next;
		}
		return vector<int>(v.rbegin(), v.rend());*/
	}
};
//�ݹ�
void printListFromTailToHead(ListNode* head)
{
	if (head == NULL) return;
	if (head->next)
		printListFromTailToHead(head->next);
	printf("%d ", head->val);
}
int main()
{

}