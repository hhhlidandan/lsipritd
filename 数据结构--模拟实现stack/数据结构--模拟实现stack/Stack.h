#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#include<assert.h>
typedef int DataType;
typedef struct Stack
{
	DataType* array;
	int capacity;
	int size;
}Stack;

void StackInit(Stack *ps);
void CheckCapacity(Stack* ps);
void StackPush(Stack *ps,DataType x);
void StackPop(Stack *ps);
DataType StackTop(Stack *ps);
int StackEmpty(Stack* ps);
int StackSize(Stack *ps);
void StackDestory(Stack* ps);
void Test();