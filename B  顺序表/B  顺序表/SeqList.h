#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<malloc.h>
#include<assert.h>
#include<stdio.h>
#include<stdlib.h>
//SeqList   连续的空间中（也就是数组）


//C语言中没有这种结构，所以把它们封装成一个结构体
//#define MAXSIZE 100

//静态顺序表
//struct SeqList
//{
//	DataType array[MAXSIZE];//保存顺序表中的有效元素
//	int size;//有效元素个数

//};


//动态顺序表
typedef int DataType;//给类型取别名 数组元素类型就很好变
typedef struct SeqList
{
	DataType *_array;//有效元素
	int _size;//有效元素个数
	int _capacity;//数组的总容量（空间总大小）
}SeqList,*PSeqList;//定义了结构体变量（把struct SeqList重命名为SeqList）


//初始化顺序表
void SeqListInit(PSeqList ps);
void SeqListDestory(PSeqList ps);

void SeqListPushBack(PSeqList ps, DataType data);//尾插
void SeqListPopBack(PSeqList ps);//尾删
void CheckIsCapacity(PSeqList ps);//检测是否需要扩容
void SeqListPushFront(PSeqList ps, DataType data);//头插
void SeqListPopFront(PSeqList ps);//头删

void SeqListInsert(PSeqList ps, int pos, DataType data);//任意位置插入  在[0,size)之间
void SeqListErase(PSeqList ps, int pos);//任意位置删除

 
int SeqListFind(PSeqList ps, DataType data);// 检测data是否在顺序表中

/////////////////////////////////////////////////////////////
void PrintSeqList(PSeqList ps);