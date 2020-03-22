//给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。
//示例 1:
//输入 : 123
//输出 : 321
//示例 2 :
//输入 : -123
//输出 : -321
//示例 3 :
//输入 : 120
//输出 : 21
	/* class Solution {
	 public:
		 int reverse(int x) {
			 long result = 0;
			 while (x)
			 {
				 result = result * 10 + x % 10;
				 x /= 10;
			 }
			 if (result>INT_MAX || result<INT_MIN)//判断是否越界
				 return 0;
			 return result;
		 }
	 };*/