#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<malloc.h>
#include<assert.h>
#include<stdio.h>
#include<stdlib.h>
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


//��ʼ��˳���
void SeqListInit(PSeqList ps);
void SeqListDestory(PSeqList ps);

void SeqListPushBack(PSeqList ps, DataType data);//β��
void SeqListPopBack(PSeqList ps);//βɾ
void CheckIsCapacity(PSeqList ps);//����Ƿ���Ҫ����
void SeqListPushFront(PSeqList ps, DataType data);//ͷ��
void SeqListPopFront(PSeqList ps);//ͷɾ

void SeqListInsert(PSeqList ps, int pos, DataType data);//����λ�ò���  ��[0,size)֮��
void SeqListErase(PSeqList ps, int pos);//����λ��ɾ��

 
int SeqListFind(PSeqList ps, DataType data);// ���data�Ƿ���˳�����

/////////////////////////////////////////////////////////////
void PrintSeqList(PSeqList ps);