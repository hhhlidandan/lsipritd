#include "SeqList.h"

int main()
{
	SeqList s;
	//��ʼ��
	SeqListInit(&s);
	//β��
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	PrintSeqList(&s);
	//βɾ
	SeqListPopBack(&s);
	PrintSeqList(&s);
	//ͷ��
	SeqListPushFront(&s, 0);
	PrintSeqList(&s);
	//ͷɾ
	SeqListPopFront(&s);
	PrintSeqList(&s);
	//����λ�ò���
	SeqListInsert(&s, 2, 5);
	PrintSeqList(&s);
	//����λ��ɾ��
	SeqListErase(&s, 2);
	PrintSeqList(&s);
	//����
	SeqListDestory(&s);
	system("pause");
	return 0;
}