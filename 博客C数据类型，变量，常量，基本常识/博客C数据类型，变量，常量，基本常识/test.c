//����

//�������
//int age = 150;
//char ch = "w";

//�����ķ���
//#include<stdio.h>
//int global = 2019;//ȫ�ֱ���
//int main()//������ڲ�
//{
//	int local = 2018;//�ֲ�����
//	int global = 2020;//��Ȼ���ʹ�����ⲿ�ı�����ͬ
//	printf("global = %d\n", global);//2020���ֲ����ȣ�
//	return 0;
//}

//��������������

//#include<stdio.h>
//int main()
//{//�����age������������ʹ�ã���ô�����������������������������Ҳ�ʹ����￪ʼ
//	int age = 10;
//	{//�����ageͬ��
//		int age = 5;//�ڶ���age�������ڿ�ʼ
//		printf("age = %d\n", age);//age = 5
//	}//�ڶ���age�������ڽ���
//	printf("%d\n", age);//10
//	return 0;
//}//��һ��age���˴�����������ھͽ�����


//����
//const ���εĳ�����
//#include<stdio.h>
//int main()
//{//����const:
//	int num1 = 0;
//	num1 = 20;
//	printf("num1 = %d\n", num1);//num1 = 20
//	//��const֮��
//	const int num2 = 0;//����const֮��num2�Ͳ��ܱ��޸���
//	num2 = 20;
//	prinf("num2 = %d\n", num2);//num2=0
//
//	const int n = 10;
//	// int arr[n] = {0};//�þ���������е�nӦΪ�����������n����const,�ͳɳ�����(����)��	
//	int arr[10] = { 0 };//������������
//
//}

//ö�ٳ���

//#include<stdio.h>
//enum Sex//enumΪö�ٹؼ���
//{
//	MALE,//ö�ٳ���//Ĭ�ϳ�ʼֵ����0��ʼ��0��1��2....
//	//��� MALE ����ʼֵ������MALE=5,��ô��ʼֵ�ʹ�5��ʼ��5��6��7....
//	FEMALE,
//	SECRET
//};
