#include "SList.h"

//����ͷ�ڵ�ĵ����� ����һ���ڵ�洢��ЧԪ��
typedef int SDataType;

// �ڵ�ṹ 

// ����ĳ�ʼ�� 
void SListInit(SList* pl)
{
	assert(pl);//��֤�������
	pl->_pHead = NULL;
}

// ��������β��ֵΪdata�Ľڵ�

//��̬����һ���µĿռ䣬����һ���µĽ��
Node* BuySListNode(SDataType data)//��̬����һ���µĿռ䣬����һ���µĽ��
{
	Node* pNode = (Node*)malloc(sizeof(Node));//���ڵ�Ĵ�С�������µĿռ�
	if (NULL == pNode)
	{
		assert(0);
		return NULL;
	}
	pNode->_data = data;
	pNode->_pNext = NULL;//��֪����һ���ڵ�
	//return pNode;
}
//β��
void SListPushBack(SList* pl, SDataType data)
{
	Node* pNewNode = NULL;
	Node* pCur = NULL;

	assert(pl);
	pNewNode = BuySListNode(data);

	pCur = pl->_pHead;
	//����ǿ�����
	if (NULL == pl->_pHead)
	{
		pl->_pHead = pNewNode;
	}
	else//�������
	{
		while (pCur->_pNext)
		{
			pCur = pCur->_pNext;
		}
		pCur->_pNext = pNewNode;
	}
}

// ɾ���������һ���ڵ� 
void SListPopBack(SList* pl)
{
	Node* ret = NULL;
	assert(pl);
	ret = pl->_pHead;
	//�������Ϊ��
	if (ret== NULL)
	{
		return;
	}
	//�����һ�����
	else if (ret->_pNext == NULL)
	{
		free(ret);
		ret= NULL;
	}
	//���������ڵ��������
	else
	{
		//�ҵ�����һ���ڵ㣬������ǰһ���ڵ�
		//Node* pTailiNode = NULL;//β�ڵ�
		//Node* preTaili = NULL;//ǰһ���ڵ�
		//assert(pl);
		//pTailiNode = pl->_pHead;//��ǰ������β�ڵ�
		//while (pTailiNode->_pNext)
		//{
		//	pTailiNode = pTailiNode->_pNext;

		//}
		//free(pTailiNode);
		//pPreTaili->_pNext = NULL;

		//�ҵ����ڶ����ڵ�
		Node* pTailiNode = pl->_pHead;
		while (pTailiNode->_pNext->_pNext)
		{
			pTailiNode = pTailiNode->_pNext;
		}
		free(pTailiNode->_pNext);
		pTailiNode->_pNext = NULL;
	}
}

// �������һ��Ԫ��ǰ����ֵΪdata�Ľڵ� 
void SListPushFront(SList* pl, SDataType data)
{
	Node* pNewNode = NULL;
	assert(pl);
	pNewNode = BuySListNode(data);
	pNewNode->_pNext = pl->_pHead;
	pl->_pHead = pNewNode;
}

// ɾ�������е�һ���ڵ� 
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

//// ������posλ�ú����ֵΪdata�Ľڵ� 
//����λ�õĲ���
//void SListInsertAfter(Node* pos, SDataType data)
//{
//	Node* pNewNode = NULL;
//	if (pos == NULL)
//		return;
//	pNewNode = BuySListNode(data);
//	pNewNode->_pNext = pos->_pNext;
//	pos->_pNext = pNewNode;
//}

// ɾ��������ֵΪdata�Ľڵ� 
//����λ��ɾ��
void SListErase(SList* pl, Node* pos)
{
	Node* pCur = NULL;
	Node* pPrePos = NULL;
	assert(pl);
	if (pl->_pHead == NULL || pos == NULL)
		return;
	//�պ��ڵ�һ���ڵ�
	if (pos == pl->_pHead)
	{
		pl->_pHead = pos->_pNext;
		free(pos);
		return;
	}
	//���ڵ�һ���ڵ�
	pPrePos= pl->_pHead;
	while (pPrePos->_pNext!=pos)
	{
		pPrePos = pPrePos->_pNext;
	}
	pPrePos->_pNext = pos->_pNext;
	free(pos);
	pos = NULL;
}

// �������в���ֵΪdata�Ľڵ㣬�ҵ����ظýڵ�ĵ�ַ�����򷵻ؿ� 
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
// ��ȡ��������Ч�ڵ�ĸ��� 
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

// ��������Ƿ�Ϊ�� 
int SListEmpty(SList* pl)
{
	Node* pCur = NULL;
	assert(pl);
	pCur = pl->_pHead;
	if (pCur == NULL)
	{
		printf("����Ϊ��\n");
	}
	printf("����Ϊ��\n");
	return 0;
	
}
// ��ȡ����ĵ�һ���ڵ� 
Node* SListFront(SList* pl)
{
	assert(pl);
	return pl->_pHead;
}

//��ȡ��������һ���ڵ�
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
// �������� 
void SListDestroy(SList* pl)
{
	Node* pCur = NULL;
	assert(pl);
	pCur = pl->_pHead;
	while (pCur)//pCur��Ϊ��
	{
		pl->_pHead = pCur->_pNext;//����ڶ����ڵ�
		free(pCur);//�ͷŵ�һ���ڵ�
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
	while (pCur)//pCur��Ϊ��
	{

		printf("%d-->", pCur->_data);
		pCur = pCur->_pNext;
	}
	printf("NULL\n");
}
//β��
void TestList()
{
	SList s;//����һ������
	SListInit(&s);
	SListPushBack(&s, 1);
	SListPushBack(&s, 2);
	SListPushBack(&s, 3);
	SListPushBack(&s, 4);
	SListPushBack(&s, 5);
	SListPushBack(&s, 6);
	PrintSList(&s);
//βɾ
	SListPopBack(&s);
	PrintSList(&s);

//ͷ��
	SListPushFront(&s, 0);
	PrintSList(&s);

//ͷɾ
	SListPopFront(&s);
	PrintSList(&s);
//������posλ�ú����ֵΪdata�Ľڵ�
	SListInsertAfter(3, 3);
	PrintSList(&s);
// ɾ��������ֵΪdata�Ľڵ� 
	SListErase(&s,2);
	PrintSList(&s);
// ��ȡ��������Ч�ڵ�ĸ��� 
	SListSize(&s);
// ��������Ƿ�Ϊ�� 
	SListEmpty(&s);
	PrintSList(&s);
// ��ȡ����ĵ�һ���ڵ� 
	SListFront(&s);
	PrintSList(&s);
// ��ȡ��������һ���ڵ� 
	SListBack(&s);
	PrintSList(&s);

	SListRemove(&s, 2);
	SListRemoveAll(&s, 3);

	SListDestroy(&s);//��������
}
