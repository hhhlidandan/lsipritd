#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<malloc.h>
//��ͷ�����ѭ��
//����ͷ��㣬��һ�����������ЧԪ��
//��ͷ��㣬�������Ч����

typedef int SDataType;

//�ڵ�Ľṹ  
typedef struct SListNode
{
	SDataType _data;//��������
	struct SListNode* _pNext;//ָ����һ�� �ڵ�ĵ�ַ
}Node;

//����Ľṹ
//�������¼������ֻҪ֪��ͷ�ڵ����
typedef struct SList
{
	Node* _pHead;
}SList,*PSList;

void SListInit(PSList pl);//��ʼ��
void SListDestory(PSList pl);//����

Node* BuySListNode(SDataType data);

void SListPushBack(PSList pl, SDataType data);//β��
void SListPopBack(PSList pl);//βɾ

void SListPushFront(PSList pl, SDataType data);//ͷ��
void SListPopFront(PSList pl);//ͷɾ

Node* SListFind(PSList pl, SDataType data);//��λ��
void SListInsert(PSList pl, Node* pos, SDataType data);//����λ�ò���
void SListErase(PSList pl, Node* pos);//����λ��ɾ��


void SListIsFindData(PSList pl, SDataType data);//���data�Ƿ���������
void SListRemove(PSList pl, SDataType data);// �Ƴ������е�һ��ֵΪdata��Ԫ�� 
void SListRemoveAll(PSList pl, SDataType data);// �Ƴ�����������ֵΪdata��Ԫ�� 
void SListSize(PSList pl);//// ��ȡ������ЧԪ�ظ��� 
void SListCapacity(PSList pl);// ��ȡ��������� 

int SListEmpty(PSList pl);// ��������Ƿ�Ϊ��

SDataType SListFront(PSList pl);// ��ȡ�����е�һ��Ԫ�� 
SDataType SListBack(PSList pl);// ��ȡ���������һ��Ԫ��
///////////////////////////////////////////////////////
void PrintSList(PSList pl);
//////////////////////////////////
void SListTest();