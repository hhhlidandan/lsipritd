////#include<stdio.h>
//#include<stdlib.h>
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//int main()
//{
//	int n;
//	cout << "����Ԫ�ظ�����";
//	cin >> n;
//	vector<int> arr(n);
//	int i = 0;
//	int count = 0;
//	cout << "����Ԫ�أ�";
//	while (n--)
//	{
//		cin >> arr[i];
//		count += arr[i];
//		i++;
//	}
//	int size = arr.size();
//	cout << "ƽ����" << count / size << endl;
//	sort(arr.begin(), arr.end());
//	if (size % 2 == 0)//ż��
//		cout << "��λ��" << (arr[size / 2] + arr[size / 2 - 1]) / 2 << endl;
//	else//����
//		cout << "��λ��" << arr[size / 2] << endl;	
//	system("pause");
//	return 0;
//}