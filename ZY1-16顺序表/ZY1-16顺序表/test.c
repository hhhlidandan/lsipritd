//�ع��Ͽν���ʱ�临�Ӷ�&�ռ临�Ӷȣ�дһƪ�����ܽ�
//ʵ�ֶ�̬˳�������²�����

#include"SeqList.h"

int main()
{
	PSeqList a;
	//��ʼ��
	SeqListInit(&a);
	// β�� 
	SeqListPushBack(&a,2);
	PrintSeqList(&a);
	// βɾ
	SeqListPopBack(&a);
	//ͷCha
	SeqListPushFront(&a,3);
	SeqListPushFront(&a, 5);
	SeqListPushFront(&a, 4);
	PrintSeqList(&a);
	//�����
	SeqListInsert(&a, 1,5 ); 
	SeqListInsert(&a, 2, 3);
	PrintSeqList(&a);
	//����ɾ
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
	_CheckCapaciy(&a);//����ռ��ͷų���
	PrintSeqList(&a);
	SeqListDestroy(&a);
	system("pause");
	return 0;
}