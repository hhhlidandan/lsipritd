#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<malloc.h>
#include<string.h>
typedef int DataType;
typedef struct Heap
{
	DataType *array;
	int size;
	int capacity;
}Heap;
void HeapCreate(Heap* hp, DataType arr[], int size);//创建
void HeapDestory(Heap* hp);//销毁
void HeapPush(Heap* hp, DataType data);//插入
void HeapPop(Heap* hp);//堆的删除
DataType HeapTop(Heap* hp);//取堆顶元素
int HeapSize(Heap* hp);//堆的数据个数
int HeapEmpty(Heap* hp);//堆判空
void HeapSort(int *a, int size);//堆排序