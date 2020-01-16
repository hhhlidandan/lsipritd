#include <iostream>						// Ԥ��������
using namespace std;						// ʹ�ñ�׼�����ռ�std

// ��(Person)��

class Person
{
protected:
string name;							// ����
	  int age;								// ����
	  string sex;							// �Ա�
	
public:
Person(string nm, int ag, string sx)		// ���캯��
	  // ����֪����nm(����), ag(����)��sx(�Ա�)�������
{
		name =  nm;					// ����
		age = ag;					// ����
		sex = sx;					// �Ա�
	  }						
	  void Show() const						// ��ʾ�����Ϣ
	  { 
		cout << "����:" << name << endl;	// ��ʾ����
		cout << "����:" << age << endl;	// ��ʾ����
		cout << "�Ա�:" << sex << endl;	// ��ʾ�Ա�
	  }	
};

// ��ʦ��
class Teacher: virtual public Person 
{
protected:
string title;						// ְ��
public:
Teacher(string nm, int ag, string sx, string tl): Person(nm, ag, sx)
{  title = tl; }					// ����ְ��
	  void Show() const					// ��ʾ�����Ϣ
	  { 
		Person::Show();					// ���û���Person�ĳ�Ա����Show()
		cout << "ְ��:" << title << endl;	// ��ʾְ��
		cout << endl; 
	  }	
};

// �ɲ���
class Cadre: virtual public Person 
{
protected:
string post;					// ְ��
public:
Cadre(string nm, int ag, string sx, string pt): Person(nm, ag, sx)	// ���캯��
	  { post = pt; }					// ����ְ��
	  void Show() const				// ��ʾ�����Ϣ
	  { 
		Person::Show();					// ���û���Person�ĳ�Ա����Show()
		cout << "ְ��:" << post << endl;	// ��ʾְ��
		cout << endl; 
	  }	
};

// ��ʦ��ɲ���
class TeacherCadre: public Teacher, public Cadre
{
protected:
double wages;						// ����
public:
  TeacherCadre(string nm, int ag, string sx, string tl, string pt, double wg)	
		: Person(nm, ag, sx), Teacher(nm, ag, sx, tl), Cadre(nm, ag, sx, pt)
	  { wages = wg; }						// ���ƹ���
	  void Show() const					// ��ʾ�����Ϣ
	  { 
		Person::Show();					// ���û���Person�ĳ�Ա����Show()
		cout << "ְ��:" << title << endl;	// ��ʾְ��
		cout << "ְ��:" << post << endl;	// ��ʾְ��
		cout << "����:" << wages << "Ԫ" << endl;					// ��ʾ����
		cout << endl;					// ����	
	  }	
};

int main()								// ������main()
{
	    Teacher objTeacher("����", 48, "��", "����");			// �������
	    Cadre objCadre("����", 56, "��", "Ժ��");				// �������
	TeacherCadre objTeacherCadre("����", 50, "Ů", "����", "Ժ��", 6890);	// �������

		objTeacher.Show();					// ��ʾ�����Ϣ
		objCadre.Show();						// ��ʾ�����Ϣ
		objTeacherCadre.Show();				// ��ʾ�����Ϣ

		return 0;                    			// ����ֵ0, ���ز���ϵͳ
}

