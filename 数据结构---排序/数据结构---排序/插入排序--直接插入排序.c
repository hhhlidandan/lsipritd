//#include<stdio.h>
//#include<stdlib.h>
//#pragma warning(disable:4996)
//
//ʱ�临�Ӷ�: O(1)
//�ռ临�Ӷ� : O(N)
//�ȶ��ԣ��ȶ�
//ʹ�ó������ӽ�������������С

//void Insertsort(int *array, int n)
//{
//	for (int i = 1; i < n; i++)
//	{
//		int key = array[i];//key����ǰ��Ԫ�رȽϵ�Ԫ��
//		int end = i - 1;//�����е����һ��Ԫ��
//		while (key < array[end]&&end >= 0)
//		{
//			array[end + 1] = array[end];
//			end--;
//		}
//		array[end + 1] = key;
//	}
//}
//int main()
//{
//	int array[] = { 5, 2, 4, 6, 1, 3 };
//	int size = sizeof(array) / sizeof(array[0]);
//	Insertsort(array, size);
//	for (int i = 0; i < size; i++)
//	{
//		printf("%d ", array[i]);
//	}
//	system("pause");
//	return 0;
//}