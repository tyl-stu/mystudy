#ifndef _EXAMPLE_H_
#define _EXAMPLE_H_


#include<stdio.h>
#include<stdlib.h>
#include"bnode.h"

//typedef char DataType;
////�������Ľڵ�  ������
//typedef struct BNode
//{
//	struct BNode *_left;
//	struct BNode *_right;
//	DataType _data;
//}BNode;
//
typedef struct BTree
{
	//�������ĸ��ڵ�
	BNode *_root;

}BTree;

//����һ�������������ض������ĸ��ڵ�ָ��
//�����˳��Ϊǰ�����
//ǰ����������顰ABD##E#H##CF##G##��
//BNode * creatBinaryTree(DataType arr[], int* idx)
//{
//	if (arr[*idx] == '#')//# Ϊ����
//	{
//		(*idx)++;
//		return NULL;
//	}
//
//	//��ǰ���ĸ��ڵ�
//	BNode *root = (BNode*)malloc(sizeof(BNode));
//	root->_data = arr[*idx];
//	(*idx)++;
//
//	root->_left = creatBinaryTree(arr, idx);
//	root->_right = creatBinaryTree(arr, idx);
//	return root;
//}

//ǰ��
void preOrder(BNode *root);

//����
void inOrder(BNode *root);

//����
void postOrder(BNode *root);

//�ڵ����
int bTreeSize(BNode *root);

//���ĸ߶�
int bTreeHeight(BNode *root);

//Ҷ�ӽڵ�ĸ���
int bTreeLeafSize(BNode *root);

//��k��ڵ���� = ���������� K -1 ��ڵ����֮��
int bTreeKSize(BNode *root, int k);

//���ҽ��
BNode * bTreeFind(BNode *root, char ch);

//����  ��˫��ָ�룬�������ָ��ȥ���������
//ָ�����ȫ���ÿգ�û��Ұָ��
//���������ֱ����ָ�룬����ú�ָ��û���ÿգ�
//�ÿյ���ָ��Ŀ���������Ұָ��
void bTreeDestory(BNode **root);



#endif