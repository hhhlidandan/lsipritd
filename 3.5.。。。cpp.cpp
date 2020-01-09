#include <iostream>					// 预处理命令
using namespace std;					// 使用标准命名空间std

// 人(people)类
class People
{
protected:
int age;						// 年龄
	  int height;						// 身高
	  int weight;						// 体重
	  static int num;					// 人数

public:
People(int a, int h, int w);		// 构造函数
	  void Eatting(){ weight++; }		// 进食使体重加1
	  void Sporting(){ height++; }		// 运动使身高加1
	  void Sleeping();					// 睡眠
	  void Show() const;				// 显示人的信息
	  static void ShowNum()				// 显示人数
	   { cout << "人数:" << num << endl; }
};

int People::num = 0;				// 初始化静态数据成员num

// 人(people)类的实现部分
People::People(int a, int h, int w): age(a), height(h), weight(w)
{ num++; }						// 由已知信息构造对象, 人数num将自加1

void People::Sleeping()			// 睡眠
{
	  age++;							// 睡眠使年龄加1
	  height++;						// 睡眠使身高加1
	  weight++;						// 睡眠使体重加1
}

void People::Show() const
// 显示人的信息
{
	  cout << "第" << num << "个人:" << endl;		// 显示人的序号
	  cout << "年龄:" << age << "岁" << endl;		// 显示年龄
	  cout << "身高:" << height << "厘米" <<endl;	// 显示身高
	  cout << "体重:" << weight << "市斤" << endl;// 显示体重
	  cout << endl;							// 换行
}

int main()							
{
	  People obj1(8, 120, 60);			// 定义对象
	  obj1.Eatting();					// 进食
	  obj1.Sporting();					// 运动
	  obj1.Sleeping();					// 睡眠
	  obj1.Show();						// 显示信息
	
	  People obj2(18, 170, 108);		// 定义对象
	  obj2.Eatting();					// 进食
	  obj2.Sporting();					// 运动
	  obj2.Sleeping();					// 睡眠
	  obj2.Show();						// 显示信息

	  People::ShowNum();				// 显示人数

	return 0;                    		// 返回值0,返回操作系统
}
