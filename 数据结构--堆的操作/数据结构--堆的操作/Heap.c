#include "Heap.h"
void Swap(int* left, int* right)
{
	int tmp = *left;
	*left = *right;
	*right = tmp;
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
	{
		HeapAdjustDown(hp, root);
	}
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
void HeapPush(Heap* hp, DataType data);//����
void HeapPop(Heap* hp)//�ѵ�ɾ��
{

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
void HeapSort(int *a, int n);//������