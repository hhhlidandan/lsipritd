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

void SListIsFindData(PSList pl, SDataType data)//���data�Ƿ���������
{
	assert(pl);
	Node* pCur = pl->_pHead;
	if (pl->_pHead == NULL)
	{
		printf("����Ϊ�գ��޷����");
		return;
	}
	while (pCur)
	{
		if (pCur->_data == data)
		{
			printf("%d��������", data);
			return;
		}
		pCur = pCur->_pNext;
	}
	printf("%d����������",data);
	return;
}
void SListRemove(PSList pl, SDataType data)// �Ƴ������е�һ��ֵΪdata��Ԫ��
{
	assert(pl);
	if (pl->_pHead == NULL)
	{
		printf("����Ϊ�գ��޷��Ƴ�Ԫ��\n");
		return;
	}
	Node* pCur = pl->_pHead;
	Node* pPre = NULL;//pCurǰһ�����
	while (pCur->_pNext!=NULL)
	{
		while (pCur->_data != data)
		{
			if (pCur->_pNext == NULL)
			{
				printf("���ź���û���ҵ���");
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
			printf("�Ƴ��ɹ�:   ");
			return;
		}
	}
	
	
}
//void SListRemoveAll(PSList pl, SDataType data)// �Ƴ�����������ֵΪdata��Ԫ��
//{
//	assert(pl);
//	if (pl->_pHead == NULL)
//	{
//		printf("����Ϊ�գ��޷��Ƴ�Ԫ��\n");
//		return;
//	}
//	Node* pCur = pl->_pHead;
//	Node* pPre = NULL;//pCur��ǰһ�����
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
void SListSize(PSList pl)//// ��ȡ������ЧԪ�ظ��� 
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
	printf("��ЧԪ�ظ���Ϊ:%d  :", count);
	return;
}
int SListEmpty(PSList pl)// ��������Ƿ�Ϊ��
{
	assert(pl);
	if (pl->_pHead)
	{
		printf("����Ϊ�գ�");
		return 0;
	}
	printf("����Ϊ�գ�");
	return 0;
}

SDataType SListFront(PSList pl)// ��ȡ�����е�һ��Ԫ�� 
{
	assert(pl);
	printf("�����е�һ��Ԫ��Ϊ��%d:  ", pl->_pHead->_data);
	return pl->_pHead->_data;
}
SDataType SListBack(PSList pl)// ��ȡ���������һ��Ԫ��
{
	assert(pl);
	Node* pCur = pl->_pHead;
	while (pCur->_pNext)
	{
		pCur = pCur->_pNext;
	}
	printf("���������һ��Ԫ��Ϊ:%d:   ", pCur->_data);
	return pCur->_data;
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