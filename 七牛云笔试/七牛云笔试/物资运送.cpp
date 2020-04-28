class Solution {
public:
	/**
	*
	* @param passNums int整型一维数组 每个关卡的通行证有效期（后续可进入关卡数，第一个数字为A城，最后一个数字为B城）
	* @param passNumsLen int passNums数组长度
	* @return bool布尔型
	*/
	bool canEnter(int* passNums, int passNumsLen) {
		// write code here
		int i = 0;
		while (i<passNumsLen)
		{
			int beforeCount = passNums[i];
			if (passNums[i] == 0)    return false;
			if (passNums[i]>beforeCount)
				beforeCount = passNums[i];
			i++;
			beforeCount--;
		}
		return true;
	}
};