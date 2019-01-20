#define _CRT_SECURE_NO_WARNINGS
#include"SeqList.h"


//初始化
void SeqListInit(PSeqList* ps)
{
	//检查参数的合法性
	//if (NULL == ps)
		//return;

	assert(ps);
	ps->_array = (DataType*)malloc(6*sizeof(DataType));
	if (NULL == ps->_array)
	{
		perror("use malloc");
		return;
	}
	ps->_capacity = 6;//空间总大小，假如可以存放6个元素
	ps->_size = 0;//有效元素个数
}
//销毁
void SeqListDestroy(PSeqList *ps)
{
	assert(ps);
	if (ps->_array)//_array是元素中的有效个数
	{
		free(ps->_array);
		ps->_array = NULL;
		ps->_capacity = 0;
		ps->_size = 0;
	}
}

// 尾插 
void SeqListPushBack(PSeqList *ps, DataType data)
{
	assert(ps);
	_CheckCapaciy( ps);
	ps->_array[ps->_size] = data;
	ps->_size++;
}

// 尾删 
void SeqListPopBack(PSeqList* ps)
{
	assert(ps);
	if (0 == ps->_size)
		return;
	ps->_size--;
}
// 头插 
void SeqListPushFront(PSeqList* ps, DataType data)
{
	assert(ps);
	_CheckCapaciy(ps);
	//有效元素向后移
	for (int i = ps->_size - 1; i >= 0; i--)
	{
		ps->_array[i+1] = ps->_array[i];
	}
	ps->_array[0] = data;
	ps->_size++;
}
// 头删 
//是删第一个元素，其它元素向前移
void SeqListPopFront(PSeqList* ps)
{
	assert(ps);
	for (int i = 0; i < ps->_size; i++)
	{
		ps->_array[i] = ps->_array[i+1];
	}
	ps->_size--;
}
// 任意位置插入 
void SeqListInsert(PSeqList *ps, int pos, DataType data)//pos是插入元素的下标，data是插入的元素
{
	assert(ps);
	_CheckCapaciy(ps);
	for (int i = ps->_size - 1; i>pos; i--)
	{
		ps->_array[i+1] = ps->_array[i];
	}
	ps->_array[pos] = data;
	ps->_size++;
}
// 任意位置删除 
void SeqListErase(PSeqList *ps, int pos)
{
	assert(ps);
	if (ps->_size == 0)
	{
		printf("顺序表为空，无法删除\n");
		return;
	}
	for (int i = pos; i < ps->_size; i++)
	{
		ps->_array[i] = ps->_array[i+1];
	}
	ps->_size--;
}
// 检测data是否在顺序表中 
int SeqListFind(PSeqList* ps, DataType data)
{
	assert(ps);
	if (ps->_size = 0)
	{
		printf("顺序表为空，无法检测\n");
		return 0;
	}
	for (int i = 0; i < ps->_size; i++)
	{
		if (ps->_array[i] = data)
			return ps->_array;
	}
	return -1;
}
// 移除顺序表中第一个值为data的元素 
void SeqListRemove(PSeqList* ps, DataType data)
{
	assert(ps);
	if (ps->_size == 0)
	{
		printf("顺序表为空，无法删除\n");
	}
	for (int i = 0; i < ps->_size; i++)
	{
		if (ps->_array[i] == data)
		{
			for (int j = i; j < ps->_size; j++)
			{
				ps->_array[j] = ps->_array[j + 1];
			}
			break;
		}	
	}
	ps->_size--;
}
// 移除顺序表中所有值为data的元素 
void SeqListRemoveAll(PSeqList* ps, DataType data)
{
	assert(ps);
	if (ps->_size == 0)
	{
		printf("顺序表为空，无法删除\n");
		return;
	}
	int i = 0;
	while (i < ps->_size)
	{
			if (ps->_array[i] == data)
			{
				for (int j = i; j < ps->_size; j++)
				{
					ps->_array[j] = ps->_array[j + 1];
				}
				ps->_size--;
				continue;
			}
			i++;
	}
}
// 获取顺序表有效元素个数 
int SeqListSize(PSeqList *ps)
{
	assert(ps);
	return ps->_size;
}
// 获取顺序表的容量 
int SeqListCapacity(PSeqList* ps)
{
	assert(ps);
	return ps->_capacity;
}
// 检测顺序表是否为空 
int SeqListEmpty(PSeqList* ps)
{
	assert(ps);
	if (ps->_size == 0)
		return 0;
	return 1;
}
// 获取顺序表中第一个元素 
DataType SeqListFront(PSeqList* ps)
{
	assert(ps);
	return ps->_array[0];
}
// 获取顺序表中最后一个元素 
DataType SeqListBack(PSeqList* ps)
{
	assert(ps);
	return ps->_array[ps->_size - 1];
}
void _CheckCapaciy(PSeqList* ps)//检验空间是否需要扩容
{
	assert(ps);
	//个数小于空间大小则不需要扩容
	if (ps->_size < ps->_capacity)
		return;

	int new_capacity = ps->_capacity*2;
	DataType* str = (DataType*)realloc(ps->_array,sizeof(DataType)*(ps->_capacity+3));
	if (str == NULL)
	{
		return;
	}
	ps->_capacity += 3;
}
////////////////////////////////////// 
// 打印顺序表
void PrintSeqList(PSeqList* ps)
{
	for (int i = 0; i < ps->_size; i++)
	{
		printf("%d ", ps->_array[i]);
	}
	printf("\n");
}