#include "Heap.c"
int main()
{
	Heap s;
	int arr[] = { 5, 3, 8, 4, 2, 7, 6, 1, 0 };
	HeapSort(arr, sizeof(arr) / sizeof(arr[0]));
	HeapCreate(&s,arr,sizeof(arr)/sizeof(arr[0]));//����
	printf("top= %d\n", HeapTop(&s));//ȡ�Ѷ�Ԫ��
	printf("size= %d\n", HeapSize(&s));//�ѵ����ݸ���

	HeapPush(&s, 9);//����
	printf("top= %d\n", HeapTop(&s));//ȡ�Ѷ�Ԫ��
	printf("size= %d\n", HeapSize(&s));//�ѵ����ݸ���

	HeapPush(&s, 0);//����
	printf("top= %d\n", HeapTop(&s));//ȡ�Ѷ�Ԫ��
	printf("size= %d\n", HeapSize(&s));//�ѵ����ݸ���

	HeapPop(&s);//�ѵ�ɾ��
	printf("top= %d\n", HeapTop(&s));//ȡ�Ѷ�Ԫ��
	printf("size= %d\n", HeapSize(&s));//�ѵ����ݸ���

	//HeapEmpty(&s);//���п�
	//HeapSort(int *a, int n);//������
	HeapDestory(&s);//����
	system("pause");
	return 0;
}