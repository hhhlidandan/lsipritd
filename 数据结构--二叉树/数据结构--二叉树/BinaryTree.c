#include "BinaryTree.h"


//BTNode* BTCreatetree(BTDataType* Node, int n, int* p)
//{
//}

void BTdestory(BTNode* root);
int BTSize(BTNode* root);//�������ڵ�ĸ���
int BTleafSize(BTNode* root);//������Ҷ�ӽڵ�ĸ���
int BTcoutKsize(BTNode* root, int k);//��������K��ڵ�ĸ���
BTNode* FindX(BTNode* root, BTDataType x);//����ֵβX�Ľڵ�

int BTHigh(BTNode* root);//��ȡ�������ĸ߶�
BTNode* GetParent(BTNode* root, BTNode* Node);//��ȡNode��˫��