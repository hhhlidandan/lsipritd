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
	printf("初始化:  有效元素:%d; 容量:%d\n", ps->_size, ps->_capacity);
}
//void CheckIsCapacity(PSeqList ps)//
//{
//	assert(ps);
//	if (ps->_capacity > ps->_size)
//	{
//		printf("不需要扩容\n");
//	}
//	else
//	{
//		DataType *p = (DataType*)realloc(ps->_array,(ps->_capacity+3)*sizeof(DataType));
//		if (p == NULL)
//			printf("扩容失败\n");
//		else
//		{
//			ps->_capacity += 3;
//			printf("扩容成功\n");
//		}
//	}
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
	if (pos<0 || pos > ps->_size)
	{
		printf("输入位置有误\n");
		return;
	}
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

int SeqListFind(PSeqList ps, DataType data)//检测data是否在顺序表中
{
	assert(ps);
	if (ps->_size == 0)
	{
		printf("顺序表为空，无法检测\n");
		return 0;
	}
	for (int i = 0; i < ps->_size; i++)
	{
		if (ps->_array[i] == data)
		{
			printf("%d在顺序表中:", data);
			return ps->_array[i];
		}
	}
	printf("%d不在顺序表中:", data);
	return -1;
}

void SeqListRemove(PSeqList ps, DataType data)// 移除顺序表中第一个值为data的元素
{
	assert(ps);
	if (ps->_size == 0)
	{
		printf("顺序表为空，无法移除\n");
		return;
	}
	for (int i = 0; i < ps->_size; i++)
	{
		if (ps->_array[i] == data)
		{
			for (int j = i; j < ps->_size - 1; j++)
			{
				ps->_array[j] = ps->_array[j + 1];	
			}
			ps->_size--;
			return;	
		}
	}
}
void SeqListRemoveAll(PSeqList ps, DataType data)// 移除顺序表中所有值为data的元素
{
	assert(ps);
	if (ps->_size == 0)
	{
		printf("顺序表为空，无法移除\n");
		return;
	}
	int i = 0;
	while (i < ps->_size)
	{
		//
		if (ps->_array[i] == data)
		{
			for (int j = i; j < ps->_size-1; j++)
			{
				ps->_array[j] = ps->_array[j + 1];
			}
			ps->_size--;
			continue;//继续判断这个位置上是不是要删除的
		}
		i++;//不是指针就向后移
		
	}	
}

void SeqListSize(PSeqList ps)// 获取顺序表有效元素个数 
{
	assert(ps);
	printf("顺序表中的有效元素个数为: %d : ",ps->_size);
	//return ps->_size;
}

void SeqListCapacity(PSeqList ps)// 获取顺序表的容量
{
	assert(ps);
	printf("顺序表中的容量为为：%d : ", ps->_capacity);
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
		printf("销毁成功\n");
	}	
}

int SeqListEmpty(PSeqList ps)//检测顺序表是否为空
{
	assert(ps);
	if (ps->_size == 0)
	{
		printf("顺序表为空\n");
		return 0;
	}
	return 1;
}

DataType SeqListFront(PSeqList ps)// 获取顺序表中第一个元素
{
	assert(ps);
	printf("顺序表中第一个元素为:%d\n", ps->_array[0]);
	return ps->_array[0];

}
DataType SeqListBack(PSeqList ps)// 获取顺序表中最后一个元素
{
	assert(ps);
	printf("顺序表中最后一个元素为：%d\n", ps->_array[ps->_size - 1]);
	return ps->_array[ps->_size];
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