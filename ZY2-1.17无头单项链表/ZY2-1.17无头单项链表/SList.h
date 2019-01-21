#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<malloc.h>

//����ͷ�ڵ�ĵ����� 
typedef int SDataType;//��������Ԫ��

// �ڵ�ṹ 
typedef struct SListNode
{
	SDataType _data;//����Ԫ��
	struct SListNode* _pNext;//����ָ����һ���ڵ�ĵ�ַ
}Node;

// ��һ������ṹ 
typedef struct SList
{
	Node* _pHead;////����Ľṹ����һ��ͷָ�������
}SList;


// ����ĳ�ʼ�� 
void SListInit(SList* pl);

// ��������β��ֵΪdata�Ľڵ� 
Node* BuySListNode(SDataType data);
//β��
void SListPushBack(SList* pl, SDataType data);

//βɾ
void SListPopBack(SList* pl);

// �������һ��Ԫ��ǰ����ֵΪdata�Ľڵ� 
void SListPushFront(SList* pl, SDataType data);

// ɾ�������е�һ���ڵ� 
void SListPopFront(SList* pl);

// ������posλ�ú������Ϊdata�Ľڵ� 
void SListInsertAfter(Node* pos, SDataType data);

// ɾ��������ֵΪdata�Ľڵ� 
void SListErase(SList* pl, Node* pos);

// �������в���ֵΪdata�Ľڵ㣬�ҵ����ظýڵ�ĵ�ַ�����򷵻ؿ� 
Node* SListFind(SList* pl, SDataType data);



// ��ȡ��������Ч�ڵ�ĸ��� 
int SListSize(SList* pl);

// ��������Ƿ�Ϊ�� 
int SListEmpty(SList* pl);
// ��ȡ����ĵ�һ���ڵ� 
Node* SListFront(SList* pl);

// ��ȡ��������һ���ڵ� 
Node* SListBack(SList* pl);
// �������� 
void SListDestroy(SList* pl);

void SListRemove(SList* pl, SDataType data);
void SListRemoveAll(SList* pl, SDataType data);
//��ӡ
void PrintSList(SList* pl);
//����
void TestList();
