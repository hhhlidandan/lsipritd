//ʵ�� strStr() ������
//
//����һ�� haystack �ַ�����һ�� needle �ַ������� haystack �ַ������ҳ� needle �ַ������ֵĵ�һ��λ��(��0��ʼ)����������ڣ��򷵻� - 1��
//
//ʾ�� 1:
//
//���� : haystack = "hello", needle = "ll"
//��� : 2
//
//
//	 ʾ�� 2 :
//
// ���� : haystack = "aaaaa", needle = "bba"
//  ��� : -1

class Solution {
public:
	int strStr(string haystack, string needle) {
		return haystack.find(needle);

	}
};

//����2
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
//				i = i - j + 1;//ָ��ӵ�һ���ҵĵط��������һλ
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