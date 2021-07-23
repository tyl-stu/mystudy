#include"example.h"
#include"queue.h"

BNode * creatBinaryTree(DataType arr[], int* idx)
{
	if (arr[*idx] == '#')//# Ϊ����
	{
		(*idx)++;
		return NULL;
	}

	//��ǰ���ĸ��ڵ�
	BNode *root = (BNode*)malloc(sizeof(BNode));
	root->_data = arr[*idx];
	(*idx)++;

	root->_left = creatBinaryTree(arr, idx);
	root->_right = creatBinaryTree(arr, idx);
	return root;
}


//�������������
void bTreeLevelOrder(BNode *root)
{
	//�������б���ڵ�
	Queue q;
	initQueue(&q);
	//���ڵ�������
	if (root)
	{
		queuePush(&q, root);
	}
	while (!queueEmpty(&q))
	{
		//��ȡ��ͷԪ��
		BNode * front = queueFront(&q);
		//����
		queuePop(&q);

		printf("%c ", front->_data);
		//�����ͷԪ�ص����Һ��ӽڵ�
		if (front->_left)
			queuePush(&q, front->_left);
		if (front->_right)
			queuePush(&q, front->_right);
	}
	printf("\n");
}

//��ȫ������������������ڵ��������м�û�пսڵ�
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
		//��ȡԪ��
		BNode *front = queueFront(&q);
		queuePop(&q);
		//�����ӽڵ����
		if (front)
		{
			queuePush(&q, front->_left);
			queuePush(&q, front->_right);
		}
		else
			break;
			
	}
	//�鿴ʣ��Ԫ���У��Ƿ��зǿսڵ�
	while (!queueEmpty(&q))
	{
		BNode *front = queueFront(&q);
		queuePop(&q);
		if (front)
			//���ʣ��Ԫ���д��ڷǿսڵ㣬˵���ڵ㲻����
			return 0;
	}
	//���зǿսڵ㶼��������
	return 1;
}

/*����ʵ����һ��List
//push_back:β��
//pop_front:ͷɾ
//listEmpty
//head:��ȡ��ͷ*/
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
		printf("�� ");
	else
		printf("�� ");
	
	/*preOrder(root); printf("\n");
	inOrder(root); printf("\n");
	postOrder(root); printf("\n");
	printf("�ڵ������%d \n", bTreeSize(root));
	printf("���ĸ߶ȣ�%d \n", bTreeHeight(root));
	printf("Ҷ�ӽڵ������%d \n", bTreeLeafSize(root));
	printf("��K��ڵ������%d \n", bTreeKSize(root, 1));
	bTreeFind(root, 'C');

	bTreeDestory(&root);*/
}

int main()
{
	test();

	system("pause");
	return 0;
}
