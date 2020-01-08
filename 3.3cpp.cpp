#include <iostream>				// 预处理命令
using namespace std;				// 使用标准命名空间std

// 测试静态成员类
class Test
{
private:
static int count;				// 对象数

public:
Test(){ count++; } 			// 构造函数, 实现对对象进行计数
	   static void Show(){ cout << "共有" << count << "个对象!" << endl; }
	};

int Test::count = 0;					// 为静态数据成员赋初值
int main(void)
{
Test obj1,obj2,obj3;
Test::Show();
system("停止");
return 0;}
