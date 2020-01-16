#include <iostream>						// 预处理命令
using namespace std;						// 使用标准命名空间std

// 人(Person)类

class Person
{
protected:
string name;							// 姓名
	  int age;								// 年龄
	  string sex;							// 性别
	
public:
Person(string nm, int ag, string sx)		// 构造函数
	  // 由已知参数nm(姓名), ag(年龄)和sx(性别)构造对象
{
		name =  nm;					// 姓名
		age = ag;					// 年龄
		sex = sx;					// 性别
	  }						
	  void Show() const						// 显示相关信息
	  { 
		cout << "姓名:" << name << endl;	// 显示姓名
		cout << "年龄:" << age << endl;	// 显示年龄
		cout << "性别:" << sex << endl;	// 显示性别
	  }	
};

// 教师类
class Teacher: virtual public Person 
{
protected:
string title;						// 职称
public:
Teacher(string nm, int ag, string sx, string tl): Person(nm, ag, sx)
{  title = tl; }					// 复制职称
	  void Show() const					// 显示相关信息
	  { 
		Person::Show();					// 调用基类Person的成员函数Show()
		cout << "职称:" << title << endl;	// 显示职称
		cout << endl; 
	  }	
};

// 干部类
class Cadre: virtual public Person 
{
protected:
string post;					// 职务
public:
Cadre(string nm, int ag, string sx, string pt): Person(nm, ag, sx)	// 构造函数
	  { post = pt; }					// 复制职务
	  void Show() const				// 显示相关信息
	  { 
		Person::Show();					// 调用基类Person的成员函数Show()
		cout << "职务:" << post << endl;	// 显示职务
		cout << endl; 
	  }	
};

// 教师兼干部类
class TeacherCadre: public Teacher, public Cadre
{
protected:
double wages;						// 工资
public:
  TeacherCadre(string nm, int ag, string sx, string tl, string pt, double wg)	
		: Person(nm, ag, sx), Teacher(nm, ag, sx, tl), Cadre(nm, ag, sx, pt)
	  { wages = wg; }						// 复制工资
	  void Show() const					// 显示相关信息
	  { 
		Person::Show();					// 调用基类Person的成员函数Show()
		cout << "职称:" << title << endl;	// 显示职称
		cout << "职务:" << post << endl;	// 显示职务
		cout << "工资:" << wages << "元" << endl;					// 显示工资
		cout << endl;					// 换行	
	  }	
};

int main()								// 主函数main()
{
	    Teacher objTeacher("张三", 48, "男", "教授");			// 定义对象
	    Cadre objCadre("李四", 56, "男", "院长");				// 定义对象
	TeacherCadre objTeacherCadre("王五", 50, "女", "教授", "院长", 6890);	// 定义对象

		objTeacher.Show();					// 显示相关信息
		objCadre.Show();						// 显示相关信息
		objTeacherCadre.Show();				// 显示相关信息

		return 0;                    			// 返回值0, 返回操作系统
}

