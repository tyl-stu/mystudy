#include"queue.h"
//队列：带有尾指针的单链表
//
//typedef int QDataType;
//typedef struct QNode
//{
//	QDataType _data;
//	struct QNode* _next;
//}QNode;
//
//typedef struct Queue
//{
//	//头尾指针
//	struct QNode * _head;
//	struct QNode * _tail;
//	int _size;
//}Queue;

void initQueue(Queue * q)
{
	if (q == NULL)
		return;
	q->_head = NULL;
	q->_tail = NULL;
	q->_size = 0;
}

struct QNode* creatNode(QDataType val)
{
	struct QNode * newNode = (struct QNode*)malloc(sizeof(struct QNode));
	newNode->_data = val;
	newNode->_next = NULL;
}

void queuePush(Queue * q, QDataType val)
{
	if (q == NULL)
		return;
	//尾插
	struct QNode*node = creatNode(val);
	//第一个节点
	if (q->_head == NULL)
		q->_head = q->_tail = node;
	else
	{
		q->_tail->_next = node;
		q->_tail = node;
	}
	++q->_size;
}

void queuePop(Queue * q)
{
	//头删
	if (q == NULL || q->_head == NULL)
		return;
	struct QNode * next = q->_head->_next;
	free(q->_head);
	q->_head = next;//q的头指向next
	--q->_size;
	if (q->_head == NULL)
		q->_tail = NULL;//只有一个节点头删后，空队列
}

QDataType queueFront(Queue *q)
{
	return q->_head->_data;
}

QDataType queueBack(Queue *q)
{
	return q->_tail->_data;
}

int queueEmpty(Queue *q)
{
	return q->_head == NULL;
}

int queueSize(Queue *q)
{
	if (q == NULL)
		return 0;
	return q->_size;

}
//
//void test()
//{
//	struct  Queue q;
//	initQueue(&q);
//	queuePush(&q, 1);
//	queuePush(&q, 2);
//	queuePush(&q, 5);
//
//	while (!queueEmpty(&q))
//	{
//		printf("%d ", queueFront(&q));
//		queuePop(&q);
//	}
//	printf("\n");
//
//	/*queuePop(&q);
//	queuePop(&q);
//	queuePop(&q);*/
//}
//
//int main()
//{
//	test();
//
//	system("pause");
//	return 0;
//}