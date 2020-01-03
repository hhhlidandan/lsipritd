//实现 strStr() 函数。
//
//给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置(从0开始)。如果不存在，则返回 - 1。
//
//示例 1:
//
//输入 : haystack = "hello", needle = "ll"
//输出 : 2
//
//
//	 示例 2 :
//
// 输入 : haystack = "aaaaa", needle = "bba"
//  输出 : -1

class Solution {
public:
	int strStr(string haystack, string needle) {
		return haystack.find(needle);

	}
};

//方法2
//class Solution {
//public:
//	int strStr(string haystack, string needle) {
//		if (haystack.size()<needle.size())
//			return -1;
//		for (int i = 0; i<haystack.size() - needle.size() + 1; i++)
//		{
//			if (haystack.substr(i, needle.size()) == needle)
//				return i;
//		}
//		return -1;
//
//	}
//};
//class Solution {
//public:
//	int strStr(string haystack, string needle) {
//		if (needle == NULL)
//			return 0;
//		char HSArray[] = haystack.toCharArray();
//		char NArray[] = haystack.toCharArray();
//		int i = 0;
//		int j = 0;
//		while (i<HSArray.length&&j<NArray.length)
//		{
//			if (HSArray[i] = NArray[j])
//			{
//				i++;
//				j++;
//			}
//			else
//			{
//				i = i - j + 1;//指针从第一次找的地方向后移了一位
//				j = 0;
//			}
//		}
//		if (j == NArray.length)
//		{
//			return i - j;
//		}
//		return -1;
//
//	}
//};