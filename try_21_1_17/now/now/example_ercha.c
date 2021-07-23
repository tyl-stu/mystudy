#include"example.h"
#include"bnode.h"

//������


//ǰ��
void preOrder(BNode *root)
{
	if (root)
	{
		//������
		printf("%c ", root->_data);
		preOrder(root->_left);
		preOrder(root->_right);
	}

}

//����
void inOrder(BNode *root)
{
	if (root)
	{
		//�����
		inOrder(root->_left);
		printf("%c ", root->_data);
		inOrder(root->_right);
	}
}

//����
void postOrder(BNode *root)
{
	if (root)
	{
		//���Ҹ�
		postOrder(root->_left);
		postOrder(root->_right);
		printf("%c ", root->_data);
	}
}

//�ڵ����
int bTreeSize(BNode *root)
{
	if (root == NULL)
		return 0;
	//�������ڵ���� + �������ڵ���� + ��ǰ�ڵ�
	return bTreeSize(root->_left) + bTreeSize(root->_right) + 1;
}

//���ĸ߶�
int bTreeHeight(BNode *root)
{
	if (root == NULL)
		return 0;
	int left = bTreeHeight(root->_left);
	int right = bTreeHeight(root->_right);
	return left > right ? left + 1 : right + 1;
}

//Ҷ�ӽڵ�ĸ���
int bTreeLeafSize(BNode *root)
{
	//����
	if (root == NULL)
		return 0;
	//Ҷ��
	if (root->_left == NULL&&root->_right == NULL)
		return 1;
	//��Ҷ��
	return bTreeLeafSize(root->_left) + bTreeLeafSize(root->_right);
}

//��k��ڵ���� = ���������� K -1 ��ڵ����֮��
int bTreeKSize(BNode *root, int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return bTreeKSize(root->_left, k - 1) + bTreeKSize(root->_right, k - 1);

}

//���ҽ��
BNode * bTreeFind(BNode *root, char ch)
{
	if (root)
	{
		BNode *node;
		if (root->_data == ch)
			return root;
		node = bTreeFind(root->_left, ch);
		if (node)
			return node;
		else
			return bTreeFind(root->_right, ch);
	}
	return NULL;
}

//����  ��˫��ָ�룬�������ָ��ȥ���������
//ָ�����ȫ���ÿգ�û��Ұָ��
//���������ֱ����ָ�룬����ú�ָ��û���ÿգ�
//�ÿյ���ָ��Ŀ���������Ұָ��
void bTreeDestory(BNode **root)
{
	if (*root)
	{
		bTreeDestory(&((*root)->_left));
		bTreeDestory(&((*root)->_right));
		free(*root);
		root = NULL;
	}
}
