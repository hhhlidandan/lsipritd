#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<malloc.h>
#include<assert.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//SeqList   �����Ŀռ��У�Ҳ�������飩


//C������û�����ֽṹ�����԰����Ƿ�װ��һ���ṹ��
//#define MAXSIZE 100

//��̬˳���
//struct SeqList
//{
//	DataType array[MAXSIZE];//����˳����е���ЧԪ��
//	int size;//��ЧԪ�ظ���

//};


//��̬˳���
typedef int DataType;//������ȡ���� ����Ԫ�����;ͺܺñ�
typedef struct SeqList
{
	DataType *_array;//��ЧԪ��
	int _size;//��ЧԪ�ظ���
	int _capacity;//��������������ռ��ܴ�С��
}SeqList,*PSeqList;//�����˽ṹ���������struct SeqList������ΪSeqList��


void SeqListInit(PSeqList ps);//��ʼ��˳���
void SeqListDestory(PSeqList ps);//��˳�������

void CheckIsCapacity(PSeqList ps);//����Ƿ���Ҫ����

void SeqListPushBack(PSeqList ps, DataType data);//β��
void SeqListPopBack(PSeqList ps);//βɾ

void SeqListPushFront(PSeqList ps, DataType data);//ͷ��
void SeqListPopFront(PSeqList ps);//ͷɾ

void SeqListInsert(PSeqList ps, int pos, DataType data);//����λ�ò���  ��[0,size)֮��
void SeqListErase(PSeqList ps, int pos);//����λ��ɾ��
 
int SeqListFind(PSeqList ps, DataType data);// ���data�Ƿ���˳�����

void SeqListRemove(PSeqList ps, DataType data);// �Ƴ�˳����е�һ��ֵΪdata��Ԫ�� 
void SeqListRemoveAll(PSeqList ps, DataType data);// �Ƴ�˳���������ֵΪdata��Ԫ�� 

void SeqListSize(PSeqList ps);//// ��ȡ˳�����ЧԪ�ظ��� 
void SeqListCapacity(PSeqList ps);// ��ȡ˳�������� 

int SeqListEmpty(PSeqList ps);// ���˳����Ƿ�Ϊ��

DataType SeqListFront(PSeqList ps);// ��ȡ˳����е�һ��Ԫ�� 
DataType SeqListBack(PSeqList ps);// ��ȡ˳��������һ��Ԫ��
/////////////////////////////////////////////////////////////
void PrintSeqList(PSeqList ps);//��ӡ