#include<iostream>
using namespace std;
//ֻ���ڶ��ϴ���
//class HeapOnly
//{
//	
//public:
//	static HeapOnly* CreateObject()//��̬��Ա�������Բ�ͨ���������
//	{
//		return new HeapOnly;
//	}
//	~HeapOnly()
//	{}
//private:
//	//C++98��
//	HeapOnly(const HeapOnly&);//ֻ������
//
//	///��C++11�У�delete���������ͷſռ䣬���ɿ���Ĭ�ϵĳ�Ա�����������߱�������ɾ���������캯�� 
//	HeapOnly(const HeapOnly&) = delete;//���ù�Ȩ��
//private:
//	HeapOnly()//���캯��
//	{}
//};
//int main()
//{
//	HeapOnly *p = HeapOnly::CreateObject();//�ڶ��ϴ�������1.���ٿռ�2.���ù��캯����
//	HeapOnly o(*p);
//	system("pause");
//	return 0;
//}

//ֻ��ջ�ϴ���
//

//class StackOnly
//{
//public:
//	static StackOnly CreateObject()//��ֵ�ķ�ʽ����
//	{
//		return StackOnly();
//	}
//private:
//	StackOnly()//���캯��
//	{}
//};
//int main()
//{
//	StackOnly::CreateObject();
//	system("pause");
//	return 0;
//}

class StackOnly1//���ܾ��Ե���ջ�ϴ���
{
public:
	StackOnly1()
	{
		cout << "StackOnly():" << endl;
	}
	StackOnly1(const StackOnly1&)
	{
		cout << "StackOnly(StackOnly&)" << endl;
	}
private:
	void* operator new(size_t size);

};
int main()
{
	return 0;
}