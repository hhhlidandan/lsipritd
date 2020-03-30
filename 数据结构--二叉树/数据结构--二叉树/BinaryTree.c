#include "BinaryTree.h"
BTNode* BuyBinTreeNode(BTDataType val)
{
	BTNode* pNewNode = (BTNode*)malloc(sizeof(BTNode));
	if (pNewNode == NULL)
	{
		assert(0);
		return NULL;
	}
	pNewNode->left =NULL;
	pNewNode->right =NULL;
	pNewNode->val =val;
	return pNewNode;
}
BTNode* BTCreatetree()//��֤�����Ƿ���ȷ
{
	BTNode* node1 = BuyBinTreeNode(1);
	BTNode* node2 = BuyBinTreeNode(2);
	BTNode* node3 = BuyBinTreeNode(3);
	BTNode* node4 = BuyBinTreeNode(4);
	BTNode* node5 = BuyBinTreeNode(5);
	BTNode* node6 = BuyBinTreeNode(6);

	BTNode* root = node1;
	node1->left = node2;
	node1->right = node4;
	node2->left = node3;
	//node2->right = NULL;
	node4->left = node5;
	node4->right = node6;
	//node5->left = NULL;
	//node5->right = NULL;
	return root;
}

//void BTdestory(BTNode* root);
int BTSize(BTNode* root)//�������ڵ�ĸ���
{
	if (root)
		return 1 + BTSize(root->left) + BTSize(root->right);
	return 0;
}
int BTleafSize(BTNode* root)//������Ҷ�ӽڵ�ĸ���:û�����������Ľڵ�
{
	if (root == NULL) return 0;
	if (root->left&&root->right)
		return BTleafSize(root->left)+BTleafSize(root->right);
	return 1;
}
int BTcoutKsize(BTNode* root, int k)//��������K��ڵ�ĸ���
{
	if (k<=0||root == NULL) return 0;
	if (k == 1) return 1;
	return BTcoutKsize(root->left,k-1) + BTcoutKsize(root->right,k-1);
}
BTNode* FindX(BTNode* root, BTDataType x)//����ֵβX�Ľڵ�
{
	BTNode* Node = NULL;
	if (root == NULL) return NULL;
	if (root->val == x) return root;
	if ((Node = FindX(root->left, x)) || (Node = FindX(root->right, x)))
		return Node;
	return NULL;
	//return FindX(root->left, x) || FindX(root->right, x);�������У��������������
}

int BTHigh(BTNode* root)//��ȡ�������ĸ߶�
{
	if (root == NULL) return 0;
	int leftH =1+ BTHigh(root->left);
	int rightH =1+ BTHigh(root->right);
	return leftH > rightH ? leftH : rightH;
	//if (root == NULL) return 0;
	//int leftH = BTHigh(root->left);
	//int rightH = BTHigh(root->right);
	//return leftH > rightH ? leftH+1 : rightH+1;
}
BTNode* GetParent(BTNode* root, BTNode* Node)//��ȡNode��˫��
{
	BTNode* Cur = NULL;
	if (root == NULL || Node == NULL || root == Node) return NULL;
	if (root->left == Node || root->right == Node)	return root;
	if ((Cur = GetParent(root->left, Node)) || (Cur = GetParent(root->right, Node)))
		return Cur;
	return NULL;
}