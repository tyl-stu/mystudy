#include"example.h"
#include"queue.h"

BNode * creatBinaryTree(DataType arr[], int* idx)
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


//二叉树层序遍历
void bTreeLevelOrder(BNode *root)
{
	//借助队列保存节点
	Queue q;
	initQueue(&q);
	//根节点存入队列
	if (root)
	{
		queuePush(&q, root);
	}
	while (!queueEmpty(&q))
	{
		//获取队头元素
		BNode * front = queueFront(&q);
		//出队
		queuePop(&q);

		printf("%c ", front->_data);
		//保存队头元素的左右孩子节点
		if (front->_left)
			queuePush(&q, front->_left);
		if (front->_right)
			queuePush(&q, front->_right);
	}
	printf("\n");
}

//完全二叉树：层序遍历，节点连续，中间没有空节点
int isCompleteBtree(BNode *root)
{
	Queue q;
	initQueue(&q);
	if (root)
	{
		queuePush(&q, root);
	}
	while (!queueEmpty(&q))
	{
		//获取元素
		BNode *front = queueFront(&q);
		queuePop(&q);
		//左右子节点入队
		if (front)
		{
			queuePush(&q, front->_left);
			queuePush(&q, front->_right);
		}
		else
			break;
			
	}
	//查看剩余元素中，是否有非空节点
	while (!queueEmpty(&q))
	{
		BNode *front = queueFront(&q);
		queuePop(&q);
		if (front)
			//如果剩余元素中存在非空节点，说明节点不连续
			return 0;
	}
	//所有非空节点都是连续的
	return 1;
}

/*假设实现了一个List
//push_back:尾插
//pop_front:头删
//listEmpty
//head:获取表头*/
//int isCompleteBtree(BNode *root)
//{
//	List l;
//	initList(&l);
//	if (root)
//		push_back(&l, root);
//	while (!listEmpty(&l))
//	{
//		BNode *front = head(&l);
//		pop_front(&l);
//		if (front)
//		{
//			push_back(&l, root->_left);
//			push_back(&l, root->_right);
//
//		}
//		else
//			break;
//	}
//	while (!listEmpty(&l))
//	{
//		BNode *front = head(&l);
//		pop_front(&l);
//		if (front)
//			return 0;
//	}
//	return 1;
//}


void test()
{
	char arr[] = "ABD##E#H##CF##G##";
	int idx = 0;
	BNode *root = creatBinaryTree(arr, &idx);

	bTreeLevelOrder(root);
	if (isCompleteBtree(root) == 1)
		printf("是 ");
	else
		printf("否 ");
	
	/*preOrder(root); printf("\n");
	inOrder(root); printf("\n");
	postOrder(root); printf("\n");
	printf("节点个数：%d \n", bTreeSize(root));
	printf("树的高度：%d \n", bTreeHeight(root));
	printf("叶子节点个数：%d \n", bTreeLeafSize(root));
	printf("第K层节点个数：%d \n", bTreeKSize(root, 1));
	bTreeFind(root, 'C');

	bTreeDestory(&root);*/
}

int main()
{
	test();

	system("pause");
	return 0;
}
