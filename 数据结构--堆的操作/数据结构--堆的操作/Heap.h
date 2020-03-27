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
void HeapCreate(Heap* hp, DataType arr[], int size);//����
void HeapDestory(Heap* hp);//����
void HeapPush(Heap* hp, DataType data);//����
void HeapPop(Heap* hp);//�ѵ�ɾ��
DataType HeapTop(Heap* hp);//ȡ�Ѷ�Ԫ��
int HeapSize(Heap* hp);//�ѵ����ݸ���
int HeapEmpty(Heap* hp);//���п�
void HeapSort(int *a, int size);//������