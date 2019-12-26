#include "SeqList.h"

void SeqListInit(PSeqList ps)
{
	assert(ps);
	//������һ������(������Դ��10��Ԫ��)��������������ٶ�̬����
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
void SeqListPushBack(PSeqList ps, DataType data)//β��
{
	assert(ps);
	//CheckIsCapacity(ps);
	ps->_array[ps->_size] = data;
	ps->_size++;
}
void SeqListPopBack(PSeqList ps)//βɾ
{
	assert(ps);
	if (ps->_size == 0)
	{
		return;
	}
	ps->_size--;
	//ps->_array[ps->_size] = 0;
}
void SeqListPushFront(PSeqList ps, DataType data)//ͷ��
{
	assert(ps);
	//CheckIsCapacity(ps);
	for (int i = ps->_size; i > 0; i--)
	{
		ps->_array[i] = ps->_array[i-1];
	}
	ps->_array[0] = data;
	ps->_size++;//������ЧԪ�ظ���ҲҪ��+1
}
void SeqListPopFront(PSeqList ps)//ͷɾ
{
	assert(ps);
	if (ps->_size == 0)
		return;
	//i Ԫ�ر����Ƶ�λ�õ��±�
	for (int i = 0; i < ps->_size-1; i++)
	{
		ps->_array[i] = ps->_array[i + 1];
	}
	ps->_size--;
}

void SeqListInsert(PSeqList ps, int pos, DataType data)//����λ�ò���
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
void SeqListErase(PSeqList ps, int pos)//����λ��ɾ��
{
	assert(ps);
	if (ps->_size == 0)
	{
		printf("˳���Ϊ�գ��޷�ɾ��\n");
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