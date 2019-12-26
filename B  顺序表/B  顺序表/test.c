#include "SeqList.h"

int main()
{
	SeqList s;
	//初始化
	SeqListInit(&s);
	//尾插
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	PrintSeqList(&s);
	//尾删
	SeqListPopBack(&s);
	PrintSeqList(&s);
	//头插
	SeqListPushFront(&s, 0);
	PrintSeqList(&s);
	//头删
	SeqListPopFront(&s);
	PrintSeqList(&s);
	//任意位置插入
	SeqListInsert(&s, 2, 5);
	PrintSeqList(&s);
	//任意位置删除
	SeqListErase(&s, 2);
	PrintSeqList(&s);
	//销毁
	SeqListDestory(&s);
	system("pause");
	return 0;
}