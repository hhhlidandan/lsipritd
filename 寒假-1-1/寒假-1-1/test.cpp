//×ª»»³ÉÐ¡Ð´×ÖÄ¸
#include<iostream>
using namespace std;
class Solution {
public:
	string toLowerCase(string str) {
		for (int i = 0; i<str.length(); i++)
		{
			if (str[i] >= 'A'&&str[i] <= 'Z')
			{
				str[i] = 'a' - 'A' + str[i];
			}
		}
		return str;
	}
};