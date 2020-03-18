
#include "Stack.h"

void StackInit(Stack *ps)
{
	assert(ps);
	ps->array = (DataType*)malloc(sizeof(DataType)* 10);
	ps->capacity = 10;
	ps->size = 0;
}
void CheckCapacity(Stack* ps)
{
	if (ps->size >= ps->capacity)
	{
		int newCapacity = ps->capacity * 2;
		DataType* temp = (DataType*)malloc(sizeof(DataType)*newCapacity);
		if (temp)
		{
			//memcpy(temp, ps->array, sizeof(DataType)*ps->capacity);
			for (int i = 0; i < ps->size; i++)
				temp[i] = ps->array[i];
		}
		free(ps->array);
		ps->array = temp;
	}
}
void StackPush(Stack *ps, DataType x)
{
	assert(ps);
	CheckCapacity(ps);
	ps->array[ps->size] = x;
	ps->size++;
}
void StackPop(Stack *ps)
{
	assert(ps);
	if (StackEmpty(ps)) return;
	ps->size--;
}
DataType StackTop(Stack *ps)
{
	assert(ps);
	//if (StackEmpty(ps))  return;
	return ps->array[ps->size - 1];
}
int StackEmpty(Stack* ps)
{
	assert(ps);
	return 0 == ps->size;
}
int StackSize(Stack *ps)
{
	assert(ps);
	return ps->size;

}
void StackDestory(Stack* ps)
{
	assert(ps);
	free(ps->array);
	ps->capacity = 0;
	ps->size = 0;
}


void Test()
{
	Stack s;
	StackInit(&s);
	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	StackPush(&s, 4);
	StackPush(&s, 5);
	StackPush(&s, 6);
	printf("size=%d\n", StackSize(&s));
	printf("top=%d\n", StackTop(&s));
	StackPop(&s);
	StackPop(&s);
	StackPop(&s);
	printf("size=%d\n", StackSize(&s));
	printf("top=%d\n", StackTop(&s));
	StackEmpty(&s);
	StackDestory(&s);
}


class Solution {
public:
	bool isValid(string s) {
		if (s.empty()) return true;
		stack<int> p;
		for (int i = 0; i<s.size(); i++)
		{
			if (p.empty())
				p.push(s[i]);
			else
			{
				if ((p.top() == '('&&s[i] == ')') || \
					(p.top() == '['&&s[i] == ']') || \
					(p.top() == '{'&&s[i] == '}'))
					p.pop();
				else
					p.push(s[i]);
			}
		}
		if (p.empty()) return true;
		else return false;
	}
};