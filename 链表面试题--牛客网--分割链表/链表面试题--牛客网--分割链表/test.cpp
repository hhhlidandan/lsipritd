//��Ŀ����
//��д���룬�Ը���ֵxΪ��׼������ָ�������֣�����С��x�Ľ�����ڴ��ڻ����x�Ľ��֮ǰ
//
//����һ�������ͷָ�� ListNode* pHead���뷵���������к�������ͷָ�롣ע�⣺�ָ��Ժ󱣳�ԭ��������˳�򲻱䡣
#include<iostream>

struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) : val(x), next(NULL) {}
};

class Partition {
public:
	ListNode* partition(ListNode* pHead, int x) {
		//�ȸ�������������ṹ�����͵ı���
		ListNode small(0);
		ListNode large(0);
		//����������ֱ���ָ�루����β�壩
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
		largeNode->next = NULL;//Ҫ�����Ľ��ָ���//  ->  ָ����ʽṹ���������
		smallNode->next = large.next;//��������������
		return small.next;//     .  �ṹ�����ͱ��������ڲ���Ա
	}
};