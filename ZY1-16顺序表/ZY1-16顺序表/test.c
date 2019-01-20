//回顾上课讲的时间复杂度&空间复杂度，写一篇博客总结
//实现动态顺序表的以下操作：

#include"SeqList.h"

int main()
{
	PSeqList a;
	//初始化
	SeqListInit(&a);
	// 尾插 
	SeqListPushBack(&a,2);
	PrintSeqList(&a);
	// 尾删
	SeqListPopBack(&a);
	//头Cha
	SeqListPushFront(&a,3);
	SeqListPushFront(&a, 5);
	SeqListPushFront(&a, 4);
	PrintSeqList(&a);
	//任意插
	SeqListInsert(&a, 1,5 ); 
	SeqListInsert(&a, 2, 3);
	PrintSeqList(&a);
	//任意删
	SeqListErase(&a,3);
	SeqListFind(&a, 5);
	SeqListRemove(&a, 2);
	PrintSeqList(&a);
	SeqListRemoveAll(&a, 3);
	SeqListSize(&a);
	SeqListCapacity(&a);
	PrintSeqList(&a);
	SeqListEmpty(&a);
	SeqListFront(&a);
	SeqListBack(&a);
	_CheckCapaciy(&a);//检验空间释放充足
	PrintSeqList(&a);
	SeqListDestroy(&a);
	system("pause");
	return 0;
}