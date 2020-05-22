//题目描述
//一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
class Solution {
public:
	int jumpFloorII(int number) {
		//台阶 1  2  3     4
		//跳法 1 1+1 1+2+1   8
		if (number == 0 || number == 1)
			return 1;
		return 2 * jumpFloorII(number - 1);
		//f(1)=f(1-1)
		//f(2)=f(2-1)+f(2-2)
		//f(3)=f(3-1)+f(3-2)+f(3-3)
		//    f(n)=f(n-1)+f(n-2)+  f(0)
		//   f(n-1)=f(n-2)+  f(0)
		//   f(n)=2*f(n-1)
	}
};