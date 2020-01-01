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

void PrintSList(PSList pl);
//////////////////////////////////
void SListTest();