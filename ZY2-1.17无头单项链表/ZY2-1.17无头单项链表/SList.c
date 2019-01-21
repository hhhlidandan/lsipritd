#include "SList.h"

//不带头节点的单链表 ，第一个节点存储有效元素
typedef int SDataType;

// 节点结构 

// 链表的初始化 
void SListInit(SList* pl)
{
	assert(pl);//保证链表存在
	pl->_pHead = NULL;
}

// 在链表中尾插值为data的节点

//动态申请一个新的空间，创建一个新的结点
Node* BuySListNode(SDataType data)//动态申请一个新的空间，创建一个新的结点
{
	Node* pNode = (Node*)malloc(sizeof(Node));//传节点的大小，开辟新的空间
	if (NULL == pNode)
	{
		assert(0);
		return NULL;
	}
	pNode->_data = data;
	pNode->_pNext = NULL;//不知道下一个节点
	//return pNode;
}
//尾插
void SListPushBack(SList* pl, SDataType data)
{
	Node* pNewNode = NULL;
	Node* pCur = NULL;

	assert(pl);
	pNewNode = BuySListNode(data);

	pCur = pl->_pHead;
	//如果是空链表
	if (NULL == pl->_pHead)
	{
		pl->_pHead = pNewNode;
	}
	else//如果不是
	{
		while (pCur->_pNext)
		{
			pCur = pCur->_pNext;
		}
		pCur->_pNext = pNewNode;
	}
}

// 删除链表最后一个节点 
void SListPopBack(SList* pl)
{
	Node* ret = NULL;
	assert(pl);
	ret = pl->_pHead;
	//如果链表为空
	if (ret== NULL)
	{
		return;
	}
	//如果有一个结点
	else if (ret->_pNext == NULL)
	{
		free(ret);
		ret= NULL;
	}
	//如果链表存在的正常情况
	else
	{
		//找倒数第一个节点，并保存前一个节点
		//Node* pTailiNode = NULL;//尾节点
		//Node* preTaili = NULL;//前一个节点
		//assert(pl);
		//pTailiNode = pl->_pHead;//从前往后找尾节点
		//while (pTailiNode->_pNext)
		//{
		//	pTailiNode = pTailiNode->_pNext;

		//}
		//free(pTailiNode);
		//pPreTaili->_pNext = NULL;

		//找倒数第二个节点
		Node* pTailiNode = pl->_pHead;
		while (pTailiNode->_pNext->_pNext)
		{
			pTailiNode = pTailiNode->_pNext;
		}
		free(pTailiNode->_pNext);
		pTailiNode->_pNext = NULL;
	}
}

// 在链表第一个元素前插入值为data的节点 
void SListPushFront(SList* pl, SDataType data)
{
	Node* pNewNode = NULL;
	assert(pl);
	pNewNode = BuySListNode(data);
	pNewNode->_pNext = pl->_pHead;
	pl->_pHead = pNewNode;
}

// 删除链表中第一个节点 
void SListPopFront(SList* pl)
{
	Node* pCur = NULL;
	assert(pl);
	pCur = pl->_pHead;

	if (pl->_pHead == NULL)
		return;
	else
	{
		pl->_pHead = pCur->_pNext;
		free(pCur);
	}
	
}

//// 在链表pos位置后插入值为data的节点 
//任意位置的插入
//void SListInsertAfter(Node* pos, SDataType data)
//{
//	Node* pNewNode = NULL;
//	if (pos == NULL)
//		return;
//	pNewNode = BuySListNode(data);
//	pNewNode->_pNext = pos->_pNext;
//	pos->_pNext = pNewNode;
//}

// 删除链表中值为data的节点 
//任意位置删除
void SListErase(SList* pl, Node* pos)
{
	Node* pCur = NULL;
	Node* pPrePos = NULL;
	assert(pl);
	if (pl->_pHead == NULL || pos == NULL)
		return;
	//刚好在第一个节点
	if (pos == pl->_pHead)
	{
		pl->_pHead = pos->_pNext;
		free(pos);
		return;
	}
	//不在第一个节点
	pPrePos= pl->_pHead;
	while (pPrePos->_pNext!=pos)
	{
		pPrePos = pPrePos->_pNext;
	}
	pPrePos->_pNext = pos->_pNext;
	free(pos);
	pos = NULL;
}

// 在链表中查找值为data的节点，找到返回该节点的地址，否则返回空 
Node* SListFind(SList* pl, SDataType data)
{
	Node* pCur = NULL;
	assert(pl);
	pCur = pl->_pHead;

	/*if (pl->_pHead == NULL)
	{
		return 0;
	}*/
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
// 获取链表中有效节点的个数 
int SListSize(SList* pl)
{
	Node* pCur = NULL;
	int count = 0;
	assert(pl);
	pCur = pl->_pHead;
	while (pCur)
	{
		if (pCur)
		{
			count++;
			pCur = pCur->_pNext;		
		}
	}
	return count;
}

// 检测链表是否为空 
int SListEmpty(SList* pl)
{
	Node* pCur = NULL;
	assert(pl);
	pCur = pl->_pHead;
	if (pCur == NULL)
	{
		printf("链表为空\n");
	}
	printf("链表不为空\n");
	return 0;
	
}
// 获取链表的第一个节点 
Node* SListFront(SList* pl)
{
	assert(pl);
	return pl->_pHead;
}

//获取链表的最后一个节点
Node* SListBack(SList* pl)
{
	Node* pCur = NULL;
	assert(pl);

	pCur = pl->_pHead;
	while (pCur->_pNext)
	{
		pCur = pCur->_pNext;
	}
	return pCur;
}
// 销毁链表 
void SListDestroy(SList* pl)
{
	Node* pCur = NULL;
	assert(pl);
	pCur = pl->_pHead;
	while (pCur)//pCur不为空
	{
		pl->_pHead = pCur->_pNext;//保存第二个节点
		free(pCur);//释放第一个节点
		pCur = pl->_pHead;
	}
	pl->_pHead = NULL;
}

void SListRemove(SList* pl, SDataType data)
{
	Node* pCur = NULL;
	assert(pl);
	pCur = pl->_pHead;
	Node* pos=ListFind(data);
	while (pCur->_pNext!=pos)
	{
		pCur = pCur->_pNext;
	}
	pCur->_pNext = pos->_pNext;
	free(pos);
	pos = NULL;
}
void SListRemoveAll(SList* pl, SDataType data)
{
	Node* pCur = NULL;
	assert(pl);
	pCur = pl->_pHead;
	Node* pos = ListFind(data);
	while ()
	while (pCur->_pNext != pos)
	{
		pCur = pCur->_pNext;
		pCur->_pNext = pos->_pNext;
		free(pos);
		pos = NULL;
	}
	if (pCur->_pNext == NULL)
	{
		free(pCur);
		pCur = NULL;
	}
}
void PrintSList(SList* pl)
{
	Node* pCur = NULL;
	assert(pl);
	pCur = pl->_pHead;
	while (pCur)//pCur不为空
	{

		printf("%d-->", pCur->_data);
		pCur = pCur->_pNext;
	}
	printf("NULL\n");
}
//尾插
void TestList()
{
	SList s;//创建一个链表
	SListInit(&s);
	SListPushBack(&s, 1);
	SListPushBack(&s, 2);
	SListPushBack(&s, 3);
	SListPushBack(&s, 4);
	SListPushBack(&s, 5);
	SListPushBack(&s, 6);
	PrintSList(&s);
//尾删
	SListPopBack(&s);
	PrintSList(&s);

//头插
	SListPushFront(&s, 0);
	PrintSList(&s);

//头删
	SListPopFront(&s);
	PrintSList(&s);
//在链表pos位置后插入值为data的节点
	SListInsertAfter(3, 3);
	PrintSList(&s);
// 删除链表中值为data的节点 
	SListErase(&s,2);
	PrintSList(&s);
// 获取链表中有效节点的个数 
	SListSize(&s);
// 检测链表是否为空 
	SListEmpty(&s);
	PrintSList(&s);
// 获取链表的第一个节点 
	SListFront(&s);
	PrintSList(&s);
// 获取链表的最后一个节点 
	SListBack(&s);
	PrintSList(&s);

	SListRemove(&s, 2);
	SListRemoveAll(&s, 3);

	SListDestroy(&s);//销毁链表
}
