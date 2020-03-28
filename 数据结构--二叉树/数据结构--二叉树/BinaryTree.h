#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<malloc.h>

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

BTNode* BTCreatetree(BTDataType* Node, int n, int* p);
void BTdestory(BTNode* root);
int BTSize(BTNode* root);//�������ڵ�ĸ���
int BTleafSize(BTNode* root);//������Ҷ�ӽڵ�ĸ���
int BTcoutKsize(BTNode* root, int k);//��������K��ڵ�ĸ���
BTNode* FindX(BTNode* root,BTDataType x);//����ֵβX�Ľڵ�

int BTHigh(BTNode* root);//��ȡ�������ĸ߶�
BTNode* GetParent(BTNode* root, BTNode* Node);//��ȡNode��˫��