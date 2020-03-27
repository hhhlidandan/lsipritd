#include "Heap.c"
int main()
{
	Heap s;
	int arr[] = { 5, 3, 8, 4, 2, 7, 6, 1, 0 };
	HeapSort(arr, sizeof(arr) / sizeof(arr[0]));
	HeapCreate(&s,arr,sizeof(arr)/sizeof(arr[0]));//创建
	printf("top= %d\n", HeapTop(&s));//取堆顶元素
	printf("size= %d\n", HeapSize(&s));//堆的数据个数

	HeapPush(&s, 9);//插入
	printf("top= %d\n", HeapTop(&s));//取堆顶元素
	printf("size= %d\n", HeapSize(&s));//堆的数据个数

	HeapPush(&s, 0);//插入
	printf("top= %d\n", HeapTop(&s));//取堆顶元素
	printf("size= %d\n", HeapSize(&s));//堆的数据个数

	HeapPop(&s);//堆的删除
	printf("top= %d\n", HeapTop(&s));//取堆顶元素
	printf("size= %d\n", HeapSize(&s));//堆的数据个数

	//HeapEmpty(&s);//堆判空
	//HeapSort(int *a, int n);//堆排序
	HeapDestory(&s);//销毁
	system("pause");
	return 0;
}