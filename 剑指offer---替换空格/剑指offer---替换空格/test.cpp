//��Ŀ����
//��ʵ��һ����������һ���ַ����е�ÿ���ո��滻�ɡ� % 20����
//���磬���ַ���ΪWe Are Happy.�򾭹��滻֮����ַ���ΪWe%20Are % 20Happy��
#include<iostream>
using namespace std;

class Solution {
public:
	void replaceSpace(char *str, int length) {
		if (str == NULL || length <= 0)
			return;
		int i = 0, count = 0, NowLen = 0;
		while (str[i] != '\0')
		{
			NowLen++;
			if (str[i] == ' ')   count++;
			i++;
		}

		int newLength = NowLen + count * 2;
		if (newLength>length) return;

		int before = NowLen;
		int now = newLength;
		while (before<now&&before >= 0)
		{
			if (str[before] == ' ')
			{
				str[now--] = '0';
				str[now--] = '2';
				str[now--] = '%';
			}
			else
				str[now--] = str[before];
			before--;
		}
	}
};
