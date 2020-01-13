#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<malloc.h>
//无头单项非循环
//不带头结点，第一个结点存的是有效元素
//带头结点，不存放有效数据

typedef int SDataType;

//节点的结构  
typedef struct SListNode
{
	SDataType _data;//保存数据
	struct SListNode* _pNext;//指向下一个 节点的地址
}Node;

//链表的结构
//把链表记录下来，只要知道头节点就行
typedef struct SList
{
	Node* _pHead;
}SList,*PSList;

void SListInit(PSList pl);//初始化
void SListDestory(PSList pl);//销毁

Node* BuySListNode(SDataType data);

void SListPushBack(PSList pl, SDataType data);//尾插
void SListPopBack(PSList pl);//尾删

void SListPushFront(PSList pl, SDataType data);//头插
void SListPopFront(PSList pl);//头删

Node* SListFind(PSList pl, SDataType data);//找位置
void SListInsert(PSList pl, Node* pos, SDataType data);//任意位置插入
void SListErase(PSList pl, Node* pos);//任意位置删除


void SListIsFindData(PSList pl, SDataType data);//检测data是否在链表中
void SListRemove(PSList pl, SDataType data);// 移除链表中第一个值为data的元素 
void SListRemoveAll(PSList pl, SDataType data);// 移除链表中所有值为data的元素 
void SListSize(PSList pl);//// 获取链表有效元素个数 
void SListCapacity(PSList pl);// 获取链表的容量 

int SListEmpty(PSList pl);// 检测链表是否为空

SDataType SListFront(PSList pl);// 获取链表中第一个元素 
SDataType SListBack(PSList pl);// 获取链表中最后一个元素
///////////////////////////////////////////////////////
void PrintSList(PSList pl);
//////////////////////////////////
void SListTest();