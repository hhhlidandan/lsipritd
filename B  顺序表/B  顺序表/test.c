#include "SeqList.h"

int main()
{
	SeqList s;
	//初始化
	SeqListInit(&s);
	//尾插
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 2);
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
	//检测data是否在顺序表中
	SeqListFind(&s, 5);
	PrintSeqList(&s);
	// 移除顺序表中第一个值为data的元素
	SeqListRemove(&s, 2);
	PrintSeqList(&s);
	// 移除顺序表中所有值为data的元素
	SeqListRemoveAll(&s, 2);
	PrintSeqList(&s);

	// 获取顺序表有效元素个数 
	SeqListSize(&s);
	PrintSeqList(&s);
	// 获取顺序表的容量 
	SeqListCapacity(&s);
	PrintSeqList(&s);

	SeqListEmpty(&s);//检测顺序表是否为空
	SeqListFront(&s);// 获取顺序表中第一个元素 
	SeqListBack(&s);// 获取顺序表中最后一个元素
	//销毁
	SeqListDestory(&s);
	system("pause");
	return 0;
}