#include "Heap.h"
void Swap(int* left, int* right)
{
	int tmp = *left;
	*left = *right;
	*right = tmp;
}
void CheckCapacity(Heap* hp)
{
	assert(hp);
	int newCapacity = hp->capacity * 2;
	if (hp->size >= hp->capacity)
	{
		//��Ҫ����
		DataType* temp = (DataType*)malloc(sizeof(DataType)*newCapacity);
		if (temp == NULL)
		{
			assert(0);
			return;
		}
		//memcpy(temp, hp->array, sizeof(DataType)*hp->size);
		for (int i = 0; i < hp->size; i++)
			temp[i] = hp->array[i];
		free(hp->array);
		hp->array = temp;
		hp->capacity = newCapacity;
	}
}
void HeapAdjustUp(Heap* hp, int child)
{
	int parent = (child - 1) >> 1;
	//����Ҫ�Һ�������С����˫�ױȽ�
	//����֮ǰ�Ѿ�����ѵ�������
	while (child)
	{
		if (hp->array[child] < hp->array[parent])
		{
			Swap(&hp->array[child], &hp->array[parent]);
			child = parent;
			parent = (child - 1) >> 1;
		}
		else
			return;
	}
}
void HeapAdjustDown(Heap* hp,int parent)
{
	int child = parent * 2 + 1;
	while (child < hp->size)//��֤���Ӵ���
	{
		if (hp->array[child] > hp->array[child + 1] && child + 1< hp->size)//��֤�Һ��Ӵ��ڣ�Ҫ��Ȼզ��
			child = child + 1;
		if (hp->array[parent] > hp->array[child])
		{
			Swap(&hp->array[child], &hp->array[parent]);
			parent = child;
			child = parent * 2 + 1;
		}		
		else
			return;	
	}
}
void HeapCreate(Heap* hp, DataType arr[], int size)//����
{
	assert(hp);
	hp->array = (DataType*)malloc(sizeof(DataType)*size);
	if (hp->array==NULL)//
	{
		assert(0);//��Ϊʲôʧ��
		return;
	}
	hp->capacity = size;
	memcpy(hp->array, arr, sizeof(DataType)*size);
	hp->size = size;
	//�Զ���Ԫ�ؽ������µ���,�ظ�������
	//���������������֮ǰ��Ҫ�ӵ�����һ����Ҷ�ӽ�㿪ʼ
	for (int root = (size - 2) >> 1; root >= 0;root--)
		HeapAdjustDown(hp, root);
}
void HeapDestory(Heap* hp)//����
{
	assert(hp);
	if (hp->array)
	{
		free(hp->array);
		hp->array =NULL;
		hp->capacity = 0;
		hp->size = 0;
	}
}
void HeapPush(Heap* hp, DataType data)//����
{
	assert(hp);
	CheckCapacity(hp);
	hp->array[hp->size] = data;
	hp->size++;
	HeapAdjustUp(hp,hp->size-1);
}
void HeapPop(Heap* hp)//�ѵ�ɾ��
{
	assert(hp);
	if (HeapEmpty(hp)) return;
	Swap(&hp->array[0], &hp->array[hp->size - 1]);
	hp->size--;
	HeapAdjustDown(hp, 0);
}
DataType HeapTop(Heap* hp)//ȡ�Ѷ�Ԫ��
{
	assert(hp&&!HeapEmpty(hp));
	return hp->array[0];
}
int HeapSize(Heap* hp)//�ѵ����ݸ���
{
	assert(hp);
	return hp->size;
}
int HeapEmpty(Heap* hp)//���п�
{
	assert(hp);
	return hp->size == 0;
}
/////////////////////////////////////////////////
void Adjust(int a[],int size,int parent)
{
	int child = parent * 2 + 1;
	while (child<size)
	{
		if (a[child] > a[child + 1] && child + 1<size)
			child = child + 1;
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else return;
	}
}
void HeapSort(int *a,int size)//������
{
	for (int root = (size - 2) >> 1; root >= 0; root--)//���뽨����С��
		Adjust(a, size,root);
	int end = size - 1;
	while (end)
	{
		int temp = a[0];
		a[0] = a[end];
		a[end] = temp;
		Adjust(a, end, 0);
		end--;
	}	
}