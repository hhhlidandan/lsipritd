//��Ŀ����
//һֻ����һ�ο�������1��̨�ף�Ҳ��������2��������Ҳ��������n���������������һ��n����̨���ܹ��ж�����������
class Solution {
public:
	int jumpFloorII(int number) {
		//̨�� 1  2  3     4
		//���� 1 1+1 1+2+1   8
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