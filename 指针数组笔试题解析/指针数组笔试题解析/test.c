#include<stdio.h>
#include<string.h>
#include<windows.h>
#pragma warning(disable:4996)

//sizeof �ַ������ٿռ�Ĵ�С������'\0'
//strlen �ַ������ȣ�������ַ�������Ч����,������'\0'
//������һ�������Ԫ�صĵ�ַ
//ֻ�����������������������ĵ�ַ 1.sizeof(������)����ʹ��ʱ��2.&������
int main()
{
	//һά���� 
	//int a[] = { 1, 2, 3, 4 };
	//printf("%d\n", sizeof(a));//16 ��������ĵ�ַ
	//printf("%d\n", sizeof(a + 0));//4  ��Ԫ�ص�ַ
	//printf("%d\n", sizeof(*a));//4 ��Ԫ��
	//printf("%d\n", sizeof(a + 1));//4 �ڶ���Ԫ�صĵ�ַ
	//printf("%d\n", sizeof(a[1])); //4 �ڶ���Ԫ�صĵ�ַ
	//printf("%d\n", sizeof(&a));// 4 ��������ĵ�ַ
	//printf("%d\n", sizeof(*&a));//16 �������� *&a�൱��a
	//printf("%d\n", sizeof(&a + 1));// 4 ��һ������ĵ�ַ
	//printf("%d\n", sizeof(&a[0]));//4 ��Ԫ�صĵ�ַ
	//printf("%d\n", sizeof(&a[0] + 1));//4 �ڶ���Ԫ�صĵ�ַ

	//�ַ����� 
	char arr[] = {'a','b','c','d','e','f'}; //��32λƽ̨�£�char����ռ1���ֽڴ�С
	//printf("%d\n", sizeof(arr)); //6 �������飬������6���ַ�
	//printf("%d\n", sizeof(arr+0)); //4 ��Ԫ�ص�ַ��ָ����ǵ�ַ������Ϊ4
	//printf("%d\n", sizeof(*arr)); //1 ��Ԫ�� 
	//printf("%d\n", sizeof(arr[1])); //1 �ڶ���Ԫ��
	//printf("%d\n", sizeof(&arr)); //4 ����ĵ�ַ
	//printf("%d\n", sizeof(&arr+1)); //4 ָ����һ������
	//printf("%d\n", sizeof(&arr[0]+1));//4�ڶ���Ԫ�صĵ�ַ

	//printf("%d\n", strlen(arr)); //���� �Ҳ���'\0'����֪��'\0'��λ�ã�
	//printf("%d\n", strlen(arr + 0)); //���� 
	//printf("%d\n", strlen(*arr)); // ���� strlen��Ҫ����ȥ���ǵ�ַ

	//printf("%d\n", strlen(arr[1])); //����
	//printf("%d\n", strlen(&arr)); //���� �Ҳ���'\0'
	//printf("%d\n", strlen(&arr + 1));//�� ָ����һ��Ԫ�ص��׵�ַ������Ȼ��֪��'\0'��λ��
	//printf("%d\n", strlen(&arr[0] + 1));// �ڶ���Ԫ�صĵ�ַ������Ȼ��֪��'\0'��λ��


	//char arr[] = "abcdef"; 
	//sizeof ���ַ������Ȱ���'\0'
	//printf("%d\n", sizeof(arr)); //7 ��������  �ַ������ٿռ�Ĵ�С����'\0'
	//printf("%d\n", sizeof(arr + 0));//4 ��Ԫ�ص�ַ
	//printf("%d\n", sizeof(*arr)); //1 ��Ԫ��
	//printf("%d\n", sizeof(arr[1])); //1 �ڶ���Ԫ��
	//printf("%d\n", sizeof(&arr)); //4 ��������ĵ�ַ
	//printf("%d\n", sizeof(&arr + 1));//4 ��һ������ĵ�ַ
	//printf("%d\n", sizeof(&arr[0] + 1));//4 �ڶ���Ԫ�صĵ�ַ

	//strlen����ЧԪ�ظ�����������'\0'
	//printf("%d\n", strlen(arr)); //6 ����ĳ��� ��'\0'ͣ��
	//printf("%d\n", strlen(arr + 0)); //6 
	//printf("%d\n", strlen(*arr)); //�� ��Ҫ����ַ
	//printf("%d\n", strlen(arr[1])); //��
	//printf("%d\n", strlen(&arr));//6 ��������ĵ�ַ
	//printf("%d\n", strlen(&arr + 1)); //���ֵ�� ָ��'\0'���棨������������飩
	//printf("%d\n", strlen(&arr[0] + 1));//5  �ӵڶ�Ԫ�ؿ�ʼ

	//char *p = "abcdef"; 
	//printf("%d\n", sizeof(p)); //4 ���ַ��ĵ�ַ ָ��Ĵ�С
	//printf("%d\n", sizeof(p + 1)); // 4 �ڶ����ַ��ĵ�ַ
	//printf("%d\n", sizeof(*p)); //1 ��һ��Ԫ�صĴ�С
	//printf("%d\n", sizeof(p[0])); //1 ��һ��Ԫ�صĴ�С
	//printf("%d\n", sizeof(&p)); //4 p�ĵ�ַ������ָ�룩
	//printf("%d\n", sizeof(&p + 1));//4 ��һ������ĵ�ַ
	//printf("%d\n", sizeof(&p[0] + 1));//4 ��һ��Ԫ�صĵ�ַ

	//printf("%d\n", strlen(p));//6
	//printf("%d\n", strlen(p + 1));//5 
	////printf("%d\n", strlen(*p)); //�� 
	////printf("%d\n", strlen(p[0])); //��
	//printf("%d\n", strlen(&p)); //���ֵ ����ָ���'\0'��ȷ��
	//printf("%d\n", strlen(&p + 1)); //���ֵ 
	//printf("%d\n", strlen(&p[0] + 1));//5 �ӵڶ���Ԫ�ؿ�ʼ

	//��ά���� 
	//���԰�������һά����
	//a[3][4]:һ��һά��������3��Ԫ�أ�ÿ��Ԫ��������4��Ԫ��
	//int a[3][4] = {0}; 
	//printf("%d\n",sizeof(a)); //48 ��������Ĵ�С
	//printf("%d\n",sizeof(a[0][0])); //4 ��һ�е�һ��Ԫ�صĴ�С����һ�����ֵĴ�С��
	//printf("%d\n",sizeof(a[0])); //16 ��һ�е�Ԫ�أ����飩�Ĵ�С
	//printf("%d\n",sizeof(a[0]+1)); //4 ��һ�еڶ���Ԫ�صĵ�ַ
	//printf("%d\n",sizeof(*(a[0]+1)));// 4 ��һ�еڶ���Ԫ��
	//printf("%d\n",sizeof(a+1)); //4 �ڶ���Ԫ�صĵ�ַ
	//printf("%d\n",sizeof(*(a+1))); //16 �ڶ���Ԫ�صĴ�С
	//printf("%d\n",sizeof(&a[0]+1));//4 �ڶ���Ԫ�صĵ�ַ ���ڶ���Ԫ�أ�
	//printf("%d\n",sizeof(*(&a[0]+1))); //16 �ڶ���Ԫ�صĴ�С
	//printf("%d\n",sizeof(*a)); //16 ��һ��Ԫ�صĴ�С
	//printf("%d\n",sizeof(a[3]));//16 Խ�磬��sizeof�ǹؼ��֣������Ŀռ��Ƿ�Ϊ��

	
	system("pause");
	return 0;
}
