#include <iostream>				// Ԥ��������
using namespace std;				// ʹ�ñ�׼�����ռ�std

// ���Ծ�̬��Ա��
class Test
{
private:
static int count;				// ������

public:
Test(){ count++; } 			// ���캯��, ʵ�ֶԶ�����м���
	   static void Show(){ cout << "����" << count << "������!" << endl; }
	};

int Test::count = 0;					// Ϊ��̬���ݳ�Ա����ֵ
int main(void)
{
Test obj1,obj2,obj3;
Test::Show();
system("ֹͣ");
return 0;}
