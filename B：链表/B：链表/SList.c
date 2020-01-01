#include "SList.h"
void SListInit(PSList pl)//初始化
{
	assert(pl);
	pl->_pHead = NULL;	
}

Node* BuySListNode(SDataType data)//获取新结点
{
	Node* pNode = (Node*)malloc(sizeof(Node));
	if (pNode == NULL)
	{
		assert(0);
		return NULL;
	}
	pNode->_data = data;
	pNode->_pNext = NULL;
	return pNode;
}

void SListPushBack(PSList pl, SDataType data)//尾插
{
	Node* pNewNode = NULL;//新结点
	Node* pCur = NULL;//链表最后一个结点
	assert(pl);
	pNewNode = BuySListNode(data);
	pCur = pl->_pHead;
	//检测链表是否为空
	if (pl->_pHead == NULL)
	{
		pl->_pHead = pNewNode;
	}
	else
	{
		while (pCur->_pNext)
		{
			pCur = pCur->_pNext;
		}
		pCur->_pNext = pNewNode;
	}
}
void SListPopBack(PSList pl)//尾删
{
	//找链表中最后一个结点，保存前一个结点（或倒数第二个结点）  链表至少有两个结点
	assert(pl);

	if (pl->_pHead == NULL)
	{
		printf("空链表\n");
		return;
	}
	else if (pl->_pHead->_pNext == NULL)//有一个结点
	{
		free(pl->_pHead);
		pl->_pHead = NULL;
	}
	else//至少有两个结点
	{
		Node* pCur = pl->_pHead;
		Node* pre = NULL;
		while (pCur->_pNext)
		{
			pre = pCur;//保存pCur的前一个结点
			pCur = pCur->_pNext;
		}
		free(pCur);
		pre->_pNext = NULL;
	}
}
void SListPushFront(PSList pl, SDataType data)//头插
{
	Node* pNewNode = NULL;
	assert(pl);
	pNewNode = BuySListNode(data);
	pNewNode->_pNext = pl->_pHead;;
	pl->_pHead = pNewNode;
}
void SListPopFront(PSList pl)//头删
{
	assert(pl);
	if (pl->_pHead == NULL)//无结点
	{
		printf("空链表\n");
		return;
	}
	else
	{
		Node* DeleteNode = pl->_pHead;
		pl->_pHead = pl->_pHead->_pNext;
		free(DeleteNode);
	}
}

Node* SListFind(PSList pl, SDataType data)//找位置
{
	assert(pl);
	Node* pCur = pl->_pHead;
	while (pCur)
	{
		if (pCur->_data == data)
		{
			return pCur;
		}
		pCur = pCur->_pNext;
	}
	return NULL;
}
void SListInsert(PSList pl, Node* pos, SDataType data)//任意位置插入(插在后面)
{
	Node* pNewNode = NULL;
	assert(pl);
	pNewNode = BuySListNode(data);
	pNewNode->_pNext = pos->_pNext;
	pos->_pNext = pNewNode;
	printf("插入成功:");
}
void SListErase(PSList pl, Node* pos)//任意位置删除
{
	Node* prePos = NULL;
	assert(pl);
	if (pl->_pHead == NULL||pos==NULL)
	{
		printf("链表为空或位置，无法删除\n");
		return;
	}
	if (pos == pl->_pHead)//pos刚好在第一个结点的位置
	{
		pl->_pHead = pos->_pNext;
	}
	else
	{
		prePos = pl->_pHead;
		while (prePos->_pNext != pos)
		{
			prePos = prePos->_pNext;
		}
		prePos->_pNext = pos->_pNext;
	}
	free(pos);
	printf("删除成功:");
}
void SListDestory(PSList pl)//销毁
{
	
	Node* pCur = NULL;
	assert(pl);
	pCur = pl->_pHead;
	
	while (pCur)
	{
		
		pl->_pHead = pCur->_pNext;//下个结点为第一个结点了
		free(pCur);
		pCur = pl->_pHead;
	}
	pl->_pHead = NULL;
	printf("销毁成功:");
}
//////////////////////////////////////
void PrintSList(PSList pl)
{
	Node* pCur = NULL;
	assert(pl);
	pCur = pl->_pHead;
	while (pCur)
	{
		printf("%d-->", pCur->_data);
		pCur = pCur->_pNext;
	}
	printf("NULL\n");
}

void SListTest1()
{
	SList s;
	SListInit(&s);
	SListPushBack(&s, 1);//尾插
	SListPushBack(&s, 2);
	SListPushBack(&s, 3);
	SListPushBack(&s, 4);
	SListPushBack(&s, 5);
	SListPushBack(&s, 6);
	PrintSList(&s);

	SListPopBack(&s);//尾删
	PrintSList(&s);

	SListPushFront(&s, 0);//头插
	PrintSList(&s);

	SListPopFront(&s);//头删
	PrintSList(&s);

	//任意位置插入
	Node* ret=SListFind(&s, 2);//找位置
	SListInsert(&s, ret, 8);
	PrintSList(&s);

	//任意位置删除
	ret = SListFind(&s, 2);
	SListErase(&s, ret);
	PrintSList(&s);

	SListDestory(&s);
	PrintSList(&s);
}
void SListTest()
{
	SListTest1();
}
