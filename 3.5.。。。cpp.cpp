#include <iostream>					// Ԥ��������
using namespace std;					// ʹ�ñ�׼�����ռ�std

// ��(people)��
class People
{
protected:
int age;						// ����
	  int height;						// ���
	  int weight;						// ����
	  static int num;					// ����

public:
People(int a, int h, int w);		// ���캯��
	  void Eatting(){ weight++; }		// ��ʳʹ���ؼ�1
	  void Sporting(){ height++; }		// �˶�ʹ��߼�1
	  void Sleeping();					// ˯��
	  void Show() const;				// ��ʾ�˵���Ϣ
	  static void ShowNum()				// ��ʾ����
	   { cout << "����:" << num << endl; }
};

int People::num = 0;				// ��ʼ����̬���ݳ�Աnum

// ��(people)���ʵ�ֲ���
People::People(int a, int h, int w): age(a), height(h), weight(w)
{ num++; }						// ����֪��Ϣ�������, ����num���Լ�1

void People::Sleeping()			// ˯��
{
	  age++;							// ˯��ʹ�����1
	  height++;						// ˯��ʹ��߼�1
	  weight++;						// ˯��ʹ���ؼ�1
}

void People::Show() const
// ��ʾ�˵���Ϣ
{
	  cout << "��" << num << "����:" << endl;		// ��ʾ�˵����
	  cout << "����:" << age << "��" << endl;		// ��ʾ����
	  cout << "���:" << height << "����" <<endl;	// ��ʾ���
	  cout << "����:" << weight << "�н�" << endl;// ��ʾ����
	  cout << endl;							// ����
}

int main()							
{
	  People obj1(8, 120, 60);			// �������
	  obj1.Eatting();					// ��ʳ
	  obj1.Sporting();					// �˶�
	  obj1.Sleeping();					// ˯��
	  obj1.Show();						// ��ʾ��Ϣ
	
	  People obj2(18, 170, 108);		// �������
	  obj2.Eatting();					// ��ʳ
	  obj2.Sporting();					// �˶�
	  obj2.Sleeping();					// ˯��
	  obj2.Show();						// ��ʾ��Ϣ

	  People::ShowNum();				// ��ʾ����

	return 0;                    		// ����ֵ0,���ز���ϵͳ
}
