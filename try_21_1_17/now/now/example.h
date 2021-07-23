#ifndef _EXAMPLE_H_
#define _EXAMPLE_H_


#include<stdio.h>
#include<stdlib.h>
#include"bnode.h"

//typedef char DataType;
////二叉树的节点  二叉链
//typedef struct BNode
//{
//	struct BNode *_left;
//	struct BNode *_right;
//	DataType _data;
//}BNode;
//
typedef struct BTree
{
	//二叉树的根节点
	BNode *_root;

}BTree;

//创建一个二叉树，返回二叉树的根节点指针
//数组的顺序为前序遍历
//前序遍历的数组“ABD##E#H##CF##G##”
//BNode * creatBinaryTree(DataType arr[], int* idx)
//{
//	if (arr[*idx] == '#')//# 为空树
//	{
//		(*idx)++;
//		return NULL;
//	}
//
//	//当前树的根节点
//	BNode *root = (BNode*)malloc(sizeof(BNode));
//	root->_data = arr[*idx];
//	(*idx)++;
//
//	root->_left = creatBinaryTree(arr, idx);
//	root->_right = creatBinaryTree(arr, idx);
//	return root;
//}

//前序
void preOrder(BNode *root);

//中序
void inOrder(BNode *root);

//后序
void postOrder(BNode *root);

//节点个数
int bTreeSize(BNode *root);

//树的高度
int bTreeHeight(BNode *root);

//叶子节点的个数
int bTreeLeafSize(BNode *root);

//第k层节点个数 = 左右子树第 K -1 层节点个数之和
int bTreeKSize(BNode *root, int k);

//查找结点
BNode * bTreeFind(BNode *root, char ch);

//销毁  用双重指针，则可以用指针去代替二叉树
//指针可以全部置空，没有野指针
//但如果参数直接用指针，则调用后指针没有置空，
//置空的是指针的拷贝，存在野指针
void bTreeDestory(BNode **root);



#endif