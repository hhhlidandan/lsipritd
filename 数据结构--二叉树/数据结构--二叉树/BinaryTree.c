#include "BinaryTree.h"


//BTNode* BTCreatetree(BTDataType* Node, int n, int* p)
//{
//}

void BTdestory(BTNode* root);
int BTSize(BTNode* root);//二叉树节点的个数
int BTleafSize(BTNode* root);//二叉树叶子节点的个数
int BTcoutKsize(BTNode* root, int k);//二叉树第K层节点的个数
BTNode* FindX(BTNode* root, BTDataType x);//查找值尾X的节点

int BTHigh(BTNode* root);//获取二叉树的高度
BTNode* GetParent(BTNode* root, BTNode* Node);//获取Node的双亲