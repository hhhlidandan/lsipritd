#include "SeqList.h"

int main()
{
	SeqList s;
	//��ʼ��
	SeqListInit(&s);
	//β��
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
	//���data�Ƿ���˳�����
	SeqListFind(&s, 5);
	PrintSeqList(&s);
	// �Ƴ�˳����е�һ��ֵΪdata��Ԫ��
	SeqListRemove(&s, 2);
	PrintSeqList(&s);
	// �Ƴ�˳���������ֵΪdata��Ԫ��
	SeqListRemoveAll(&s, 2);
	PrintSeqList(&s);

	// ��ȡ˳�����ЧԪ�ظ��� 
	SeqListSize(&s);
	PrintSeqList(&s);
	// ��ȡ˳�������� 
	SeqListCapacity(&s);
	PrintSeqList(&s);

	SeqListEmpty(&s);//���˳����Ƿ�Ϊ��
	SeqListFront(&s);// ��ȡ˳����е�һ��Ԫ�� 
	SeqListBack(&s);// ��ȡ˳��������һ��Ԫ��
	//����
	SeqListDestory(&s);
	system("pause");
	return 0;
}