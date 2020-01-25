#pragma once

#include<iostream>
#include<windows.h>
#pragma warning(disable:4996)
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
class Stu
{
public:
	void InitStudent(char* name, int age, char* gender);
	void PrintStudent();
public:
	char _name[20];
	int _age;
	char _gender[10];
};