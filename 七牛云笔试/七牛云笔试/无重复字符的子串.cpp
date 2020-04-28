class Solution {
public:
	/**
	*
	* @param s string×Ö·û´®
	* @return intÕûĞÍ
	*/
	int lengthOfLongestSubstring(string s) {
		// write code here\
		        if(s.size()==0) return 0;
		int start = 0;
		int end = 1;
		int count = 1;
		set<char> str;
		str.insert(s[start]);
		while (end<s.size())
		{
			if (str.find(s[end]) != str.end())
				str.erase(s[start++]);
			else
			{
				str.insert(s[end++]);
				count = max(count, end - start);
			}
		}
		return count;
	}
};