#include<stdio.h>
#include<stdlib.h>


typedef char DataType;
//二叉树的节点  二叉链
typedef struct BNode
{
	struct BNode *_left;
	struct BNode *_right;
	DataType _data;
}BNode;

typedef struct BTree
{
	//二叉树的根节点
	BNode *_root;

}BTree;

//void createBinaryTree(BTree *bt)
//{
//	//创建一个空树
//	bt->_root = NULL;
//}

//创建一个二叉树，返回二叉树的根节点指针
//数组的顺序为前序遍历
//前序遍历的数组“ABD##E#H##CF##G##”
BNode * creatBinaryTree(DataType arr[],int* idx)
{
	if (arr[*idx] == '#')//# 为空树
	{
		(*idx)++;
		return NULL;
	}
		
	//当前树的根节点
	BNode *root = (BNode*)malloc(sizeof(BNode));
	root->_data = arr[*idx];
	(*idx)++;

	root->_left = creatBinaryTree(arr, idx);
	root->_right = creatBinaryTree(arr, idx);
	return root;
}

//前序
void preOrder(BNode *root)
{
	if (root)
	{
		//根左右
		printf("%c ", root->_data);
		preOrder(root->_left);
		preOrder(root->_right);
	}
	
}

//中序
void inOrder(BNode *root)
{
	if (root)
	{
		//左根右
		inOrder(root->_left);
		printf("%c ", root->_data);
		inOrder(root->_right);
	}
}

//后序
void postOrder(BNode *root)
{
	if (root)
	{
		//左右根
		postOrder(root->_left);
		postOrder(root->_right);
		printf("%c ", root->_data);
	}
}

//节点个数
int bTreeSize(BNode *root)
{
	if (root == NULL)
		return 0;
	//左子树节点个数 + 右子树节点个数 + 当前节点
	return bTreeSize(root->_left) + bTreeSize(root->_right) + 1;
}

//树的高度
int bTreeHeight(BNode *root)
{
	if (root == NULL)
		return 0;
	int left = bTreeHeight(root->_left);
	int right = bTreeHeight(root->_right);
	return left > right ? left + 1 : right + 1;
}

//叶子节点的个数
int bTreeLeafSize(BNode *root)
{
	//空树
	if (root == NULL)
		return 0;
	//叶子
	if (root->_left == NULL&&root->_right == NULL)
		return 1;
	//非叶子
	return bTreeLeafSize(root->_left) + bTreeLeafSize(root->_right);
}

//第k层节点个数 = 左右子树第 K -1 层节点个数之和
int bTreeKSize(BNode *root, int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return bTreeKSize(root->_left, k - 1) + bTreeKSize(root->_right, k - 1);

}

//查找结点
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

//销毁  用双重指针，则可以用指针去代替二叉树
//指针可以全部置空，没有野指针
//但如果参数直接用指针，则调用后指针没有置空，
//置空的是指针的拷贝，存在野指针
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

void test()
{
	char arr[] = "ABD##E#H##CF##G##";
	int idx = 0;
	BNode *root = creatBinaryTree(arr, &idx);
	preOrder(root); printf("\n");
	inOrder(root); printf("\n");
	postOrder(root); printf("\n");
	printf("节点个数：%d \n", bTreeSize(root));
	printf("树的高度：%d \n", bTreeHeight(root));
	printf("叶子节点个数：%d \n", bTreeLeafSize(root));
	printf("第K层节点个数：%d \n",bTreeKSize(root,1));
	bTreeFind(root, 'C');

	bTreeDestory(&root);
}

int main()
{
	test();

	system("pause");
	return 0;
}
