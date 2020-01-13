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

void SListIsFindData(PSList pl, SDataType data)//检测data是否是链表中
{
	assert(pl);
	Node* pCur = pl->_pHead;
	if (pl->_pHead == NULL)
	{
		printf("链表为空，无法检测");
		return;
	}
	while (pCur)
	{
		if (pCur->_data == data)
		{
			printf("%d在链表中", data);
			return;
		}
		pCur = pCur->_pNext;
	}
	printf("%d不在链表中",data);
	return;
}
void SListRemove(PSList pl, SDataType data)// 移除链表中第一个值为data的元素
{
	assert(pl);
	if (pl->_pHead == NULL)
	{
		printf("链表为空，无法移除元素\n");
		return;
	}
	Node* pCur = pl->_pHead;
	Node* pPre = NULL;//pCur前一个结点
	while (pCur->_pNext!=NULL)
	{
		while (pCur->_data != data)
		{
			if (pCur->_pNext == NULL)
			{
				printf("很遗憾，没有找到：");
				return;
			}
			pPre = pCur;
			pCur = pCur->_pNext;
		}
		if (pCur->_data==data)
		{
			if (pPre == NULL)
			{
				pl->_pHead = pCur->_pNext;
			}
			else
			{
				pPre->_pNext = pCur->_pNext;
			}
			free(pCur);
			pCur = NULL;
			printf("移除成功:   ");
			return;
		}
	}
	
	
}
//void SListRemoveAll(PSList pl, SDataType data)// 移除链表中所有值为data的元素
//{
//	assert(pl);
//	if (pl->_pHead == NULL)
//	{
//		printf("链表为空，无法移除元素\n");
//		return;
//	}
//	Node* pCur = pl->_pHead;
//	Node* pPre = NULL;//pCur的前一个结点
//	
//	while (pCur->_pNext!=NULL)
//	{
//		if (pCur->_data != data)
//		{
//			pPre = pCur;
//			pCur = pCur->_pNext;
//		}
//		else
//		{
//			if (pPre == NULL)
//			{
//				pl->_pHead = pCur->_pNext;
//			}
//			else
//			{
//				pPre->_pNext = pCur->_pNext;
//			}	
//			free(pCur);
//			pCur = NULL;
//			
//		}
//	}
//}
void SListSize(PSList pl)//// 获取链表有效元素个数 
{
	assert(pl);
	int count = 1;
	Node* pCur = pl->_pHead;
	while (pCur->_pNext)
	{
		if (pCur->_pNext)
		{
			pCur = pCur->_pNext;
		}
		count++;
	}
	printf("有效元素个数为:%d  :", count);
	return;
}
int SListEmpty(PSList pl)// 检测链表是否为空
{
	assert(pl);
	if (pl->_pHead)
	{
		printf("链表不为空：");
		return 0;
	}
	printf("链表为空：");
	return 0;
}

SDataType SListFront(PSList pl)// 获取链表中第一个元素 
{
	assert(pl);
	printf("链表中第一个元素为：%d:  ", pl->_pHead->_data);
	return pl->_pHead->_data;
}
SDataType SListBack(PSList pl)// 获取链表中最后一个元素
{
	assert(pl);
	Node* pCur = pl->_pHead;
	while (pCur->_pNext)
	{
		pCur = pCur->_pNext;
	}
	printf("链表中最后一个元素为:%d:   ", pCur->_data);
	return pCur->_data;
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