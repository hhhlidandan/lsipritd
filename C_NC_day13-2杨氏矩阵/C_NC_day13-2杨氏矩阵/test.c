////2.
//////���Ͼ��� 
////��һ����ά����.
////�����ÿ�д������ǵ����ģ�ÿ�д��ϵ����ǵ�����.
////�������������в���һ�������Ƿ���ڡ�
////ʱ�临�Ӷ�С��O(N);
//
////���飺
//
//#include<stdio.h>
//#include<assert.h>
//#include<windows.h>
//#pragma warning(disable:4996)
//
//
//int Check(int a[][3], int sz,int k)
//{
//	assert(a);//���ָ�벻��Ϊ��
//	assert(sz > 0);
//	//1 2 3
//	//2 3 4
//	//3 4 5
//	int i = 0;//�� [0][2](3)��ʼ��
//	int j = 2;
//	while (i<3&&j>=0)
//	{
//		if (k > a[i][j])
//		{//����i��
//			i++;
//		}
//		else if (k < a[i][j])
//		{//����j��
//			j--;
//		}
//		else
//		{
//			printf("�ҵ��ˣ�%d,a[%d][%d]\n", k, i, j);
//			return 1;
//		}	
//		
//	}
//	return 0;
//			
//}
//int main()
//{
//	int a[][3] = { 1, 2, 3, 2, 3, 4, 3, 4, 5 };
//	int sz = sizeof(a) / sizeof(a[0]);
////	int i = 0;
////��ʾ����	
//	/*for (; i < sz; i++)
//	{
//		int j = 0;
//		for (; j < sz; j++)
//		{
//			printf("%d ", a[i][j]);
//		}
//		printf("\n");
//	}*/
//	int ret = Check(a, sz, 4);
//	printf("%d\n", ret);
//	system("pause");
//	return 0;
//}