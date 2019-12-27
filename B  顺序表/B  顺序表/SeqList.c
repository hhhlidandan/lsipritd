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
	printf("��ʼ��:  ��ЧԪ��:%d; ����:%d\n", ps->_size, ps->_capacity);
}
//void CheckIsCapacity(PSeqList ps)//
//{
//	assert(ps);
//	if (ps->_capacity > ps->_size)
//	{
//		printf("����Ҫ����\n");
//	}
//	else
//	{
//		DataType *p = (DataType*)realloc(ps->_array,(ps->_capacity+3)*sizeof(DataType));
//		if (p == NULL)
//			printf("����ʧ��\n");
//		else
//		{
//			ps->_capacity += 3;
//			printf("���ݳɹ�\n");
//		}
//	}
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
	if (pos<0 || pos > ps->_size)
	{
		printf("����λ������\n");
		return;
	}
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

int SeqListFind(PSeqList ps, DataType data)//���data�Ƿ���˳�����
{
	assert(ps);
	if (ps->_size == 0)
	{
		printf("˳���Ϊ�գ��޷����\n");
		return 0;
	}
	for (int i = 0; i < ps->_size; i++)
	{
		if (ps->_array[i] == data)
		{
			printf("%d��˳�����:", data);
			return ps->_array[i];
		}
	}
	printf("%d����˳�����:", data);
	return -1;
}

void SeqListRemove(PSeqList ps, DataType data)// �Ƴ�˳����е�һ��ֵΪdata��Ԫ��
{
	assert(ps);
	if (ps->_size == 0)
	{
		printf("˳���Ϊ�գ��޷��Ƴ�\n");
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
void SeqListRemoveAll(PSeqList ps, DataType data)// �Ƴ�˳���������ֵΪdata��Ԫ��
{
	assert(ps);
	if (ps->_size == 0)
	{
		printf("˳���Ϊ�գ��޷��Ƴ�\n");
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
			continue;//�����ж����λ�����ǲ���Ҫɾ����
		}
		i++;//����ָ��������
		
	}	
}

void SeqListSize(PSeqList ps)// ��ȡ˳�����ЧԪ�ظ��� 
{
	assert(ps);
	printf("˳����е���ЧԪ�ظ���Ϊ: %d : ",ps->_size);
	//return ps->_size;
}

void SeqListCapacity(PSeqList ps)// ��ȡ˳��������
{
	assert(ps);
	printf("˳����е�����ΪΪ��%d : ", ps->_capacity);
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
		printf("���ٳɹ�\n");
	}	
}

int SeqListEmpty(PSeqList ps)//���˳����Ƿ�Ϊ��
{
	assert(ps);
	if (ps->_size == 0)
	{
		printf("˳���Ϊ��\n");
		return 0;
	}
	return 1;
}

DataType SeqListFront(PSeqList ps)// ��ȡ˳����е�һ��Ԫ��
{
	assert(ps);
	printf("˳����е�һ��Ԫ��Ϊ:%d\n", ps->_array[0]);
	return ps->_array[0];

}
DataType SeqListBack(PSeqList ps)// ��ȡ˳��������һ��Ԫ��
{
	assert(ps);
	printf("˳��������һ��Ԫ��Ϊ��%d\n", ps->_array[ps->_size - 1]);
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