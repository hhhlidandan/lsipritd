#include "SList.h"
int main()
{
		SList s;
		SListInit(&s);
		SListPushBack(&s, 0);//β��
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

		SListPopBack(&s);//βɾ
		PrintSList(&s);

		SListPushFront(&s, 0);//ͷ��
		PrintSList(&s);

		SListPopFront(&s);//ͷɾ
		PrintSList(&s);

		//����λ�ò���
		Node* ret = SListFind(&s, 2);//��λ��
		SListInsert(&s, ret, 8);
		PrintSList(&s);

		//����λ��ɾ��
		ret = SListFind(&s, 2);
		SListErase(&s, ret);
		PrintSList(&s);

		//���data�Ƿ���������
		SListIsFindData(&s, 2);
		PrintSList(&s);

		// �Ƴ������е�һ��ֵΪdata��Ԫ�� 
		SListRemove(&s, 0);
		PrintSList(&s);

		// �Ƴ�����������ֵΪdata��Ԫ��
		//SListRemoveAll(&s, 1);
		//PrintSList(&s);

		// ��ȡ������ЧԪ�ظ��� 
		SListSize(&s);//
		PrintSList(&s);
		// ��������Ƿ�Ϊ��
		SListEmpty(&s);
		PrintSList(&s);
		//��ȡ�����еĵ�һ��Ԫ��
		SListFront(&s);
		PrintSList(&s);
		//��ȡ�����еĵ�һ��Ԫ��
		SListBack(&s);
		PrintSList(&s);
		//��������
		SListDestory(&s);
		PrintSList(&s);
	system("pause");
	return 0;
}