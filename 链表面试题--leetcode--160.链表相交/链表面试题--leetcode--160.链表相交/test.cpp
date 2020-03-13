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
		//链表如果相交，它最后一个结点肯定是公共结点
		//这道题是要找到它们相交的第一个结点

		//可能两个链表的长度不同，所以先要将两个链表长度求出来，然后看它们之间差了几步，
		//让长链表走到跟短链表与末尾位置的距离一样时，它们再一起走，判断结点是否相同
		//一定要比较结点，不能比较结点的值，因为结点相同，说明他的值、地址也相同，这样才算一个公共的结点
		//如果只是比较值相同，那两个链表也不一定相交呀，只有结点中指针指向的地址相同了，才是相同结点
		ListNode* Cur = NULL;
		ListNode* pA = headA;
		ListNode* pB = headB;
		int sizeA = 0;
		int sizeB = 0;
		while (pA)//从前往后遍历，顺便记录个数
		{
			sizeA++;
			pA = pA->next;
		}
		while (pB)
		{
			sizeB++;
			pB = pB->next;
		}
		//处理相交的情况
		pA = headA;
		pB = headB;
		int gap = sizeA - sizeB;//两个链表的长度gap步
		if (gap>0)//A长
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
		//等长之后一起走，比较
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