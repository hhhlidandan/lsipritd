//#include<stdio.h>
//#include<stdlib.h>
//#pragma warning(disable:4996)
//
//时间复杂度: O(1)
//空间复杂度 : O(N)
//稳定性：稳定
//使用场景：接近有序，数据量较小

//void Insertsort(int *array, int n)
//{
//	for (int i = 1; i < n; i++)
//	{
//		int key = array[i];//key是与前面元素比较的元素
//		int end = i - 1;//有序中的最后一个元素
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