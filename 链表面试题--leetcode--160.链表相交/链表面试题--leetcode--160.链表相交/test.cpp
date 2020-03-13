#include<iostream>
using namespace std;

struct ListNode {
    int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		//��������ཻ�������һ�����϶��ǹ������
		//�������Ҫ�ҵ������ཻ�ĵ�һ�����

		//������������ĳ��Ȳ�ͬ��������Ҫ�������������������Ȼ������֮����˼�����
		//�ó������ߵ�����������ĩβλ�õľ���һ��ʱ��������һ���ߣ��жϽ���Ƿ���ͬ
		//һ��Ҫ�ȽϽ�㣬���ܱȽϽ���ֵ����Ϊ�����ͬ��˵������ֵ����ַҲ��ͬ����������һ�������Ľ��
		//���ֻ�ǱȽ�ֵ��ͬ������������Ҳ��һ���ཻѽ��ֻ�н����ָ��ָ��ĵ�ַ��ͬ�ˣ�������ͬ���
		ListNode* Cur = NULL;
		ListNode* pA = headA;
		ListNode* pB = headB;
		int sizeA = 0;
		int sizeB = 0;
		while (pA)//��ǰ���������˳���¼����
		{
			sizeA++;
			pA = pA->next;
		}
		while (pB)
		{
			sizeB++;
			pB = pB->next;
		}
		//�����ཻ�����
		pA = headA;
		pB = headB;
		int gap = sizeA - sizeB;//��������ĳ���gap��
		if (gap>0)//A��
		{
			while (gap--)
			{
				pA = pA->next;
			}
		}
		else
		{
			while (gap++)
			{
				pB = pB->next;
			}
		}
		//�ȳ�֮��һ���ߣ��Ƚ�
		while (pA&&pB)
		{
			if (pA == pB)
			{
				Cur = pB;
				break;
			}
			pA = pA->next;
			pB = pB->next;
		}
		return Cur;
	}
};