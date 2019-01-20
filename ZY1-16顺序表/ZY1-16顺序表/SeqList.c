#define _CRT_SECURE_NO_WARNINGS
#include"SeqList.h"


//��ʼ��
void SeqListInit(PSeqList* ps)
{
	//�������ĺϷ���
	//if (NULL == ps)
		//return;

	assert(ps);
	ps->_array = (DataType*)malloc(6*sizeof(DataType));
	if (NULL == ps->_array)
	{
		perror("use malloc");
		return;
	}
	ps->_capacity = 6;//�ռ��ܴ�С��������Դ��6��Ԫ��
	ps->_size = 0;//��ЧԪ�ظ���
}
//����
void SeqListDestroy(PSeqList *ps)
{
	assert(ps);
	if (ps->_array)//_array��Ԫ���е���Ч����
	{
		free(ps->_array);
		ps->_array = NULL;
		ps->_capacity = 0;
		ps->_size = 0;
	}
}

// β�� 
void SeqListPushBack(PSeqList *ps, DataType data)
{
	assert(ps);
	_CheckCapaciy( ps);
	ps->_array[ps->_size] = data;
	ps->_size++;
}

// βɾ 
void SeqListPopBack(PSeqList* ps)
{
	assert(ps);
	if (0 == ps->_size)
		return;
	ps->_size--;
}
// ͷ�� 
void SeqListPushFront(PSeqList* ps, DataType data)
{
	assert(ps);
	_CheckCapaciy(ps);
	//��ЧԪ�������
	for (int i = ps->_size - 1; i >= 0; i--)
	{
		ps->_array[i+1] = ps->_array[i];
	}
	ps->_array[0] = data;
	ps->_size++;
}
// ͷɾ 
//��ɾ��һ��Ԫ�أ�����Ԫ����ǰ��
void SeqListPopFront(PSeqList* ps)
{
	assert(ps);
	for (int i = 0; i < ps->_size; i++)
	{
		ps->_array[i] = ps->_array[i+1];
	}
	ps->_size--;
}
// ����λ�ò��� 
void SeqListInsert(PSeqList *ps, int pos, DataType data)//pos�ǲ���Ԫ�ص��±꣬data�ǲ����Ԫ��
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
// ����λ��ɾ�� 
void SeqListErase(PSeqList *ps, int pos)
{
	assert(ps);
	if (ps->_size == 0)
	{
		printf("˳���Ϊ�գ��޷�ɾ��\n");
		return;
	}
	for (int i = pos; i < ps->_size; i++)
	{
		ps->_array[i] = ps->_array[i+1];
	}
	ps->_size--;
}
// ���data�Ƿ���˳����� 
int SeqListFind(PSeqList* ps, DataType data)
{
	assert(ps);
	if (ps->_size = 0)
	{
		printf("˳���Ϊ�գ��޷����\n");
		return 0;
	}
	for (int i = 0; i < ps->_size; i++)
	{
		if (ps->_array[i] = data)
			return ps->_array;
	}
	return -1;
}
// �Ƴ�˳����е�һ��ֵΪdata��Ԫ�� 
void SeqListRemove(PSeqList* ps, DataType data)
{
	assert(ps);
	if (ps->_size == 0)
	{
		printf("˳���Ϊ�գ��޷�ɾ��\n");
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
// �Ƴ�˳���������ֵΪdata��Ԫ�� 
void SeqListRemoveAll(PSeqList* ps, DataType data)
{
	assert(ps);
	if (ps->_size == 0)
	{
		printf("˳���Ϊ�գ��޷�ɾ��\n");
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
// ��ȡ˳�����ЧԪ�ظ��� 
int SeqListSize(PSeqList *ps)
{
	assert(ps);
	return ps->_size;
}
// ��ȡ˳�������� 
int SeqListCapacity(PSeqList* ps)
{
	assert(ps);
	return ps->_capacity;
}
// ���˳����Ƿ�Ϊ�� 
int SeqListEmpty(PSeqList* ps)
{
	assert(ps);
	if (ps->_size == 0)
		return 0;
	return 1;
}
// ��ȡ˳����е�һ��Ԫ�� 
DataType SeqListFront(PSeqList* ps)
{
	assert(ps);
	return ps->_array[0];
}
// ��ȡ˳��������һ��Ԫ�� 
DataType SeqListBack(PSeqList* ps)
{
	assert(ps);
	return ps->_array[ps->_size - 1];
}
void _CheckCapaciy(PSeqList* ps)//����ռ��Ƿ���Ҫ����
{
	assert(ps);
	//����С�ڿռ��С����Ҫ����
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
// ��ӡ˳���
void PrintSeqList(PSeqList* ps)
{
	for (int i = 0; i < ps->_size; i++)
	{
		printf("%d ", ps->_array[i]);
	}
	printf("\n");
}