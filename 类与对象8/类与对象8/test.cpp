#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
using namespace std;
//�๲�����˶��ٸ�������
//�����ı���---���ܰ�����ÿ�������У�Ӧ��ʱ���ж�����
//int t_count = 0;//ȫ�ֱ�������
//ʹ��ȫ�ֱ�����ȱ�ݣ�����ȫ�������ȫ�ֱ������ڲ����ˣ�
//��������Ϊ��ĳ�Ա������������
//������һ������ĳ�Ա��������ֱ�Ӷ��������ÿ�������(ֻ�ܼ�¼��ǰ����)����������static��
class Test
{
public:
	Test() :_a(0)
	{
		t_count++;
	}
	Test(Test& a)
	{
		t_count++;
	}
	~Test()
	{
		t_count--;
	}
	static int GetCount()//��̬��Ա����
	{
		return t_count;
	}
	//int GetCount1()//��ͨ��Ա����
	//{
	//	cout<<this<<endl;
	//
	//	return this->_a;
	//}
private:
	int _a;
	static int t_count;//��̬��Ա����
};
int Test::t_count = 0;//��̬��Ա�����������ʼ��
void testCount()
{
	Test t1, t2;
	cout << Test::GetCount() << endl;
	//cout << t_count << endl;
}
int main()
{
	Test::GetCount();
	Test t1, t2;
	cout << Test::GetCount() << endl;
	//cout << t1.GetCount() << endl;//Ҳ����ͨ���������
	testCount();
	cout << Test::GetCount() << endl;

	//cout << &t1.t_count << "=" << &t2.t_count << endl;
	system("pause");
	return 0;
}
//��ͨ��Ա������
//�����ڳ�ʼ���б��г�ʼ��
//ÿ�����󶼰���
//����ͨ���������
//static��Ա������
//����
//ֻ��һ�ݣ�û�а����ھ���Ķ����У��������ж�����ģ�
//����ͨ������ֱ�ӷ��ʣ�Ҳ��ͨ������+�������޶���ֱ�ӷ���(������ĳһ������Ķ���)
//
//����������������ɵڶ��ַ���
//��̬��Ա���������Բ�ͨ���������

//��ͨ���͵ĳ�Ա��������ͨ���������

//��ͨ�ĳ�Ա������
//��һ�����ص�thisָ�룬
//���Է�����ͨ�ĳ�Ա����
//��̬��Ա������
//û��thisָ��
//���ܷ�����ͨ�ĳ�Ա����
int main()
{
	Test::GetCount();
	Test t1, t2;
	cout << Test::GetCount() << endl;
	//cout << t1.GetCount() << endl;//Ҳ����ͨ���������
	return 0;
}
