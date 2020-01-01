#include "SList.h"
void SListInit(PSList pl)//��ʼ��
{
	assert(pl);
	pl->_pHead = NULL;	
}

Node* BuySListNode(SDataType data)//��ȡ�½��
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

void SListPushBack(PSList pl, SDataType data)//β��
{
	Node* pNewNode = NULL;//�½��
	Node* pCur = NULL;//�������һ�����
	assert(pl);
	pNewNode = BuySListNode(data);
	pCur = pl->_pHead;
	//��������Ƿ�Ϊ��
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
void SListPopBack(PSList pl)//βɾ
{
	//�����������һ����㣬����ǰһ����㣨�����ڶ�����㣩  �����������������
	assert(pl);

	if (pl->_pHead == NULL)
	{
		printf("������\n");
		return;
	}
	else if (pl->_pHead->_pNext == NULL)//��һ�����
	{
		free(pl->_pHead);
		pl->_pHead = NULL;
	}
	else//�������������
	{
		Node* pCur = pl->_pHead;
		Node* pre = NULL;
		while (pCur->_pNext)
		{
			pre = pCur;//����pCur��ǰһ�����
			pCur = pCur->_pNext;
		}
		free(pCur);
		pre->_pNext = NULL;
	}
}
void SListPushFront(PSList pl, SDataType data)//ͷ��
{
	Node* pNewNode = NULL;
	assert(pl);
	pNewNode = BuySListNode(data);
	pNewNode->_pNext = pl->_pHead;;
	pl->_pHead = pNewNode;
}
void SListPopFront(PSList pl)//ͷɾ
{
	assert(pl);
	if (pl->_pHead == NULL)//�޽��
	{
		printf("������\n");
		return;
	}
	else
	{
		Node* DeleteNode = pl->_pHead;
		pl->_pHead = pl->_pHead->_pNext;
		free(DeleteNode);
	}
}

Node* SListFind(PSList pl, SDataType data)//��λ��
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
void SListInsert(PSList pl, Node* pos, SDataType data)//����λ�ò���(���ں���)
{
	Node* pNewNode = NULL;
	assert(pl);
	pNewNode = BuySListNode(data);
	pNewNode->_pNext = pos->_pNext;
	pos->_pNext = pNewNode;
	printf("����ɹ�:");
}
void SListErase(PSList pl, Node* pos)//����λ��ɾ��
{
	Node* prePos = NULL;
	assert(pl);
	if (pl->_pHead == NULL||pos==NULL)
	{
		printf("����Ϊ�ջ�λ�ã��޷�ɾ��\n");
		return;
	}
	if (pos == pl->_pHead)//pos�պ��ڵ�һ������λ��
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
	printf("ɾ���ɹ�:");
}
void SListDestory(PSList pl)//����
{
	
	Node* pCur = NULL;
	assert(pl);
	pCur = pl->_pHead;
	
	while (pCur)
	{
		
		pl->_pHead = pCur->_pNext;//�¸����Ϊ��һ�������
		free(pCur);
		pCur = pl->_pHead;
	}
	pl->_pHead = NULL;
	printf("���ٳɹ�:");
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
	SListPushBack(&s, 1);//β��
	SListPushBack(&s, 2);
	SListPushBack(&s, 3);
	SListPushBack(&s, 4);
	SListPushBack(&s, 5);
	SListPushBack(&s, 6);
	PrintSList(&s);

	SListPopBack(&s);//βɾ
	PrintSList(&s);

	SListPushFront(&s, 0);//ͷ��
	PrintSList(&s);

	SListPopFront(&s);//ͷɾ
	PrintSList(&s);

	//����λ�ò���
	Node* ret=SListFind(&s, 2);//��λ��
	SListInsert(&s, ret, 8);
	PrintSList(&s);

	//����λ��ɾ��
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
