#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<malloc.h>

//不带头节点的单链表 
typedef int SDataType;//保存整形元素

// 节点结构 
typedef struct SListNode
{
	SDataType _data;//保存元素
	struct SListNode* _pNext;//保存指向下一个节点的地址
}Node;

// 给一个链表结构 
typedef struct SList
{
	Node* _pHead;////链表的结构，给一个头指针向后走
}SList;


// 链表的初始化 
void SListInit(SList* pl);

// 在链表中尾插值为data的节点 
Node* BuySListNode(SDataType data);
//尾插
void SListPushBack(SList* pl, SDataType data);

//尾删
void SListPopBack(SList* pl);

// 在链表第一个元素前插入值为data的节点 
void SListPushFront(SList* pl, SDataType data);

// 删除链表中第一个节点 
void SListPopFront(SList* pl);

// 在链表pos位置后插入置为data的节点 
void SListInsertAfter(Node* pos, SDataType data);

// 删除链表中值为data的节点 
void SListErase(SList* pl, Node* pos);

// 在链表中查找值为data的节点，找到返回该节点的地址，否则返回空 
Node* SListFind(SList* pl, SDataType data);



// 获取链表中有效节点的个数 
int SListSize(SList* pl);

// 检测链表是否为空 
int SListEmpty(SList* pl);
// 获取链表的第一个节点 
Node* SListFront(SList* pl);

// 获取链表的最后一个节点 
Node* SListBack(SList* pl);
// 销毁链表 
void SListDestroy(SList* pl);

void SListRemove(SList* pl, SDataType data);
void SListRemoveAll(SList* pl, SDataType data);
//打印
void PrintSList(SList* pl);
//测试
void TestList();
