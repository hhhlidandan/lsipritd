class Solution {
public:
	/**
	*
	* @param passNums int����һά���� ÿ���ؿ���ͨ��֤��Ч�ڣ������ɽ���ؿ�������һ������ΪA�ǣ����һ������ΪB�ǣ�
	* @param passNumsLen int passNums���鳤��
	* @return bool������
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