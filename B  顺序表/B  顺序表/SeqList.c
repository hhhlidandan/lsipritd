#include "SeqList.h"

void SeqListInit(PSeqList ps)
{
	assert(ps);
	//先设置一个容量(假设可以存放10个元素)，在这个基础上再动态开辟
	ps->_array = (DataType*)malloc(sizeof(DataType)* 10);
	if (NULL == ps->_array)
	{
		return;
	}
	ps->_capacity = 10;
	ps->_size = 0;
}
//void CheckIsCapacity(PSeqList ps)//
//{
//
//}
void SeqListPushBack(PSeqList ps, DataType data)//尾插
{
	assert(ps);
	//CheckIsCapacity(ps);
	ps->_array[ps->_size] = data;
	ps->_size++;
}
void SeqListPopBack(PSeqList ps)//尾删
{
	assert(ps);
	if (ps->_size == 0)
	{
		return;
	}
	ps->_size--;
	//ps->_array[ps->_size] = 0;
}
void SeqListPushFront(PSeqList ps, DataType data)//头插
{
	assert(ps);
	//CheckIsCapacity(ps);
	for (int i = ps->_size; i > 0; i--)
	{
		ps->_array[i] = ps->_array[i-1];
	}
	ps->_array[0] = data;
	ps->_size++;//插完有效元素个数也要加+1
}
void SeqListPopFront(PSeqList ps)//头删
{
	assert(ps);
	if (ps->_size == 0)
		return;
	//i 元素被搬移到位置的下标
	for (int i = 0; i < ps->_size-1; i++)
	{
		ps->_array[i] = ps->_array[i + 1];
	}
	ps->_size--;
}

void SeqListInsert(PSeqList ps, int pos, DataType data)//任意位置插入
{
	assert(ps);
	//CheckIsCapacity(ps);
	for (int i = ps->_size; i > pos; i--)
	{
		ps->_array[i] = ps->_array[i - 1];
	}
	ps->_array[pos] = data;
	ps->_size++;
}
void SeqListErase(PSeqList ps, int pos)//任意位置删除
{
	assert(ps);
	if (ps->_size == 0)
	{
		printf("顺序表为空，无法删除\n");
		return;
	}
		
	for (int i = pos; i < ps->_size-1; i++)
	{
		ps->_array[i] = ps->_array[i + 1];
	}
	ps->_size--;
}

void SeqListDestory(PSeqList ps)
{
	assert(ps);
	if (ps->_array)
	{
		free(ps->_array);
		ps->_array = NULL;
		ps->_capacity = 0;
		ps->_size = 0;
	}	
}
/////////////////////////////////////////////////////////////////
//test
void PrintSeqList(PSeqList ps)
{
	assert(ps);
	for (int i = 0; i < ps->_size-1; i++)
	{
		printf("%d->", ps->_array[i]);
	}
	printf("%d", ps->_array[ps->_size-1]);
	printf("\n");
}