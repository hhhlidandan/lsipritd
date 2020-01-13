#include "SList.h"
int main()
{
		SList s;
		SListInit(&s);
		SListPushBack(&s, 0);//尾插
		SListPushBack(&s, 0);
		SListPushBack(&s, 1);
		SListPushBack(&s, 1);
		SListPushBack(&s, 2);
		SListPushBack(&s, 2);
		SListPushBack(&s, 4);
		SListPushBack(&s, 4);
		SListPushBack(&s, 5);
		SListPushBack(&s, 5);
		SListPushBack(&s, 7);
		SListPushBack(&s, 8);
		SListPushBack(&s, 9);
		SListPushBack(&s, 9);
		PrintSList(&s);

		SListPopBack(&s);//尾删
		PrintSList(&s);

		SListPushFront(&s, 0);//头插
		PrintSList(&s);

		SListPopFront(&s);//头删
		PrintSList(&s);

		//任意位置插入
		Node* ret = SListFind(&s, 2);//找位置
		SListInsert(&s, ret, 8);
		PrintSList(&s);

		//任意位置删除
		ret = SListFind(&s, 2);
		SListErase(&s, ret);
		PrintSList(&s);

		//检测data是否是链表中
		SListIsFindData(&s, 2);
		PrintSList(&s);

		// 移除链表中第一个值为data的元素 
		SListRemove(&s, 0);
		PrintSList(&s);

		// 移除链表中所有值为data的元素
		//SListRemoveAll(&s, 1);
		//PrintSList(&s);

		// 获取链表有效元素个数 
		SListSize(&s);//
		PrintSList(&s);
		// 检测链表是否为空
		SListEmpty(&s);
		PrintSList(&s);
		//获取链表中的第一个元素
		SListFront(&s);
		PrintSList(&s);
		//获取链表中的第一个元素
		SListBack(&s);
		PrintSList(&s);
		//销毁链表
		SListDestory(&s);
		PrintSList(&s);
	system("pause");
	return 0;
}