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
	while (child < hp->size)//保证左孩子存在
	{
		if (hp->array[child] > hp->array[child + 1] && child + 1< hp->size)//保证右孩子存在，要不然咋比
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
void HeapCreate(Heap* hp, DataType arr[], int size)//创建
{
	assert(hp);
	hp->array = (DataType*)malloc(sizeof(DataType)*size);
	if (hp->array==NULL)//
	{
		assert(0);//看为什么失败
		return;
	}
	hp->capacity = size;
	memcpy(hp->array, arr, sizeof(DataType)*size);
	hp->size = size;
	//对堆中元素进行向下调整,重复调几次
	//调上面的左右子树之前，要从倒数第一个非叶子结点开始
	for (int root = (size - 2) >> 1; root >= 0;root--)
	{
		HeapAdjustDown(hp, root);
	}
}
void HeapDestory(Heap* hp)//销毁
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
void HeapPush(Heap* hp, DataType data);//插入
void HeapPop(Heap* hp)//堆的删除
{

}
DataType HeapTop(Heap* hp)//取堆顶元素
{
	assert(hp&&!HeapEmpty(hp));
	return hp->array[0];
}
int HeapSize(Heap* hp)//堆的数据个数
{
	assert(hp);
	return hp->size;
}
int HeapEmpty(Heap* hp)//堆判空
{
	assert(hp);
	return hp->size == 0;
}
void HeapSort(int *a, int n);//堆排序