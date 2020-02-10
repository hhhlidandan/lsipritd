#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<mutex>
#include<thread>
using namespace std;
//����ģʽ
class Singleton
{
public:
	static volatile Singleton* GetInstance()
	{
		//��ֹ�߳�����
		if (m_In == nullptr)
		{
			m_mutex.lock();//����
			//��ⵥ����ʵ�����޴���
			if (m_In == nullptr)
				m_In = new Singleton;
			m_mutex.unlock();//����
		}
		return m_In;
	}
	//ֱ��д����������ֱ�ӵ�����������,Ϊ��֤����������������Ҫ����һ���ڲ���
	class CG
	{
	public:
		~CG()
		{
			if (m_In)
			{
				delete m_In;
				m_In = nullptr;
			}
		}
	};
private:
	Singleton()//���캯��
	{}
	//������
	Singleton(const Singleton&) = delete;//��������
	Singleton& operator=(const Singleton&) = delete;//��ֵ���������

	static volatile Singleton* m_In;//��̬�����ڳ�������ʱ�ʹ�������,�ڳ����˳���ʱ������
	static mutex m_mutex;
	static CG m_gc;
};
volatile Singleton* Singleton::m_In = nullptr;
mutex Singleton::m_mutex;
Singleton::CG m_gc;

void ThreadFunc()
{
	cout << Singleton::GetInstance() << endl;
}
void Test()
{
	thread t1(ThreadFunc);
	thread t2(ThreadFunc);
	thread t3(ThreadFunc);
	thread t4(ThreadFunc);

	t1.join();
	t2.join();
	t3.join();
	t4.join();
}
int main()
{
	Test();	
	system("pause");
	return 0;
}
//����ģʽ
//class Singleton
//{
//public:
//	static Singleton& GetInstance()//��ȡ����ı��������´������
//	{
//		return m_I;
//	}
//private:
//	//�����캯������Ϊ˽�еģ���ֹ���˵�
//	Singleton()
//	{}
//	Singleton(const Singleton&) = delete;
//	Singleton& operator=(const Singleton&) = delete;
//	static Singleton m_I;//��̬��Ա����  ��̬�����ڳ�������ʱ������
//};
//Singleton Singleton::m_I;//�������ʼ��
//
//int main()
//{
//	Singleton& s= Singleton::GetInstance();
//	system("pause");
//	return 0;
//}
///��ֹ�౻����
//���������캯���͸�ֵ���������������˽�е�
//class Test
//{
//public:
//	Test()
//	{}
//private:
//	//C++98
//	Test(Test& t);
//	Test& operator=(const Test&);
//	//C++11
//	//Test(Test& t) = delete;
//	//Test& operator=(const Test&) = delete;
//};
//int main()
//{
//	return 0;
//}
//��̬�������ڶ�����������ڳ�������ʱ�ʹ�����
