#include "BinaryTree.c"
int main()
{
	BTNode* root = BTCreatetree();
	printf("ǰ��");
	beforeOrder(root);
	printf("\n");
	printf("����");
	inOrder(root);
	printf("\n");
	printf("����");
	endOrder(root);
	printf("\n");

	//void BTdestory(BTNode* root);
	printf("�������ڵ�ĸ���:%d \n", BTSize(root));//
	printf("������Ҷ�ӽڵ�ĸ���:%d \n", BTleafSize(root));
	printf("��������K��ڵ�ĸ���:%d \n", BTcoutKsize(root, 2));
	FindX(root, 3);//����ֵβX�Ľڵ�
	printf("��ȡ�������ĸ߶�:%d \n", BTHigh(root));
	GetParent(root, FindX(root, 3));//��ȡNode��˫��
	system("pause");
	return 0;
}