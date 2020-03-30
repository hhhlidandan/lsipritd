#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<malloc.h>
#include<queue>

typedef int BTDataType;
typedef struct BinTreeNode
{
	struct BinTreeNode* left;
	struct BinTreeNode* right;
	BTDataType val;
}BTNode;

//ǰ�����
void beforeOrder(BTNode* root)
{
	if (root)
	{
		printf("%d ", root->val);
		beforeOrder(root->left);
		beforeOrder(root->right);
	}
}
//�������
void inOrder(BTNode* root)
{
	if (root)
	{
		inOrder(root->left);
		printf("%d ", root->val);
		inOrder(root->right);
	}
}
//�������
void endOrder(BTNode* root)
{
	if (root)
	{
		endOrder(root->left);
		endOrder(root->right);
		printf("%d ", root->val);
	}
}

//�������
//void evelOrder(BTNode* root)
//{
//	if (root == NULL) return;
//	Queue q;
//	init(&q);
//	push(&q, root);
//
//	while (!queueEmpty(&q))
//	{
//		BTNode* pCur = queueFront(&q);
//		queuepop(&p);
//
//		printf("%d ", pCur->val);
//		if (pCur->right)
//			queuepush(&q, pCur->left);
//		if (pCur->right)
//			queuepush(&q, pCur->right);
//	}
//}
BTNode* BTCreatetree();
//void BTdestory(BTNode* root);
int BTSize(BTNode* root);//�������ڵ�ĸ���
int BTleafSize(BTNode* root);//������Ҷ�ӽڵ�ĸ���
int BTcoutKsize(BTNode* root, int k);//��������K��ڵ�ĸ���
BTNode* FindX(BTNode* root,BTDataType x);//����ֵβX�Ľڵ�

int BTHigh(BTNode* root);//��ȡ�������ĸ߶�
BTNode* GetParent(BTNode* root, BTNode* Node);//��ȡNode��˫��

