#include<stdio.h>
#include<iostream>
using namespace std;
void getonce(int a[], int n){
	int result = 0, count = 1;
	for (int i = 0; i < n; i++){
		result ^= a[i];
	}
	if (result == 0){
		cout << "������û��ֻ����һ�ε�Ԫ��" << endl;
		return;
	}
	cout << "result=" << result << endl; //�������е������
	while (result != 0){
		if (result && 1 == 1)  //�ҳ���һ�γ���1��λ��
			break;
		else{
			result >>= 1;
			count <<= 1;
		}
	}
	cout << "count=" << count << endl;//���Դӵ�λ����λ��һ�γ���1��λ��
	int first = 0;
	int second = 0;
	for (int j = 0; j < n; j++){
		if ((a[j] & count) == 0){
			first ^= a[j];
			cout << "firstgroup=" << a[j] << " "; //���Ե�һ��Ľ�� 
		}
		else{
			second ^= a[j];
			cout << "secondgroup=" << a[j] << " ";//���Եڶ���Ľ��
		}
	}
	cout << endl;
	if (((first | 0) != 0) && (second | 0 != 0)){
		cout << "first=" << first << endl;
		cout << "second=" << second << endl;
	}
	else if ((first | 0) != 0){
		cout << "����ֻ��һ��Ԫ�ز�ͬ" << endl;
		cout << first << endl;
	}
	else{
		cout << "����ֻ��һ��Ԫ�ز�ͬ" << endl;
		cout << second << endl;
	}
}

int main(){
	int a[] = { 23, 23, 23, 78, 23, 78 };
	int b[] = { 1, 1, 4, 1, 1, 1 };
	getonce(a, 6);
	getonce(b, 6); 
	system("pause");

	return 0;
}
