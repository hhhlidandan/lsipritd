//����һ�� 32 λ���з�������������Ҫ�����������ÿλ�ϵ����ֽ��з�ת��
//ʾ�� 1:
//���� : 123
//��� : 321
//ʾ�� 2 :
//���� : -123
//��� : -321
//ʾ�� 3 :
//���� : 120
//��� : 21
	/* class Solution {
	 public:
		 int reverse(int x) {
			 long result = 0;
			 while (x)
			 {
				 result = result * 10 + x % 10;
				 x /= 10;
			 }
			 if (result>INT_MAX || result<INT_MIN)//�ж��Ƿ�Խ��
				 return 0;
			 return result;
		 }
	 };*/