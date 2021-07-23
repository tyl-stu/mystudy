#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//循环队列
//队列：带有尾指针的单链表

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
//
//void initQueue(Queue * q)
//{
//	if (q == NULL)
//		return;
//	q->_head = NULL;
//	q->_tail = NULL;
//	q->_size = 0;
//}
//
//struct QNode* creatNode(QDataType val)
//{
//	struct QNode * newNode = (struct QNode*)malloc(sizeof(struct QNode));
//	newNode->_data = val;
//	newNode->_next = NULL;
//}
//
//void queuePush(Queue * q, QDataType val)
//{
//	if (q == NULL)
//		return;
//	//尾插
//	struct QNode*node = creatNode(val);
//	//第一个节点
//	if (q->_head == NULL)
//		q->_head = q->_tail = node;
//	else
//	{
//		q->_tail->_next = node;
//		q->_tail = node;
//	}
//	++q->_size;
//}
//
//void queuePop(Queue * q)
//{
//	//头删
//	if (q == NULL || q->_head == NULL)
//		return;
//	struct QNode * next = q->_head->_next;
//	free(q->_head);
//	q->_head = next;//q的头指向next
//	--q->_size;
//	if (q->_head == NULL)
//		q->_tail = NULL;//只有一个节点头删后，空队列
//}
//
//QDataType queueFront(Queue *q)
//{
//	return q->_head->_data;
//}
//
//QDataType queueBack(Queue *q)
//{
//	return q->_tail->_data;
//}
//
//int queueEmpty(Queue *q)
//{
//	return q->_head == NULL;
//}
//
//int queueSize(Queue *q)
//{
//	if (q == NULL)
//		return 0;
//	return q->_size;
//
//}

/*实现方法一*/
//typedef struct{
//	//队头元素的位置
//	int _front;
//	//队尾元素的下一位置
//	int _rear;
//	//所存元素个数  最后一个元素的位置是k
//	int _k;
//	//所存元素的首地址
//	int *_data;
//}MyCircularQueue;
//
//MyCircularQueue* myCircularQueueCreate(int k)
//{
//	MyCircularQueue * cq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
//	cq->_data = (int *)malloc(sizeof(int)*(k + 1));// 数据空间为 k+1
//	cq->_k = k;
//	cq->_front = cq->_rear = 0;//0~k皆可
//	return cq;
//}
//
//bool myCircularQueueIsFull(MyCircularQueue *obj)
//{
//	//rear +1 % 空间的长度 == front
//	return (obj->_rear + 1) % (obj->_k + 1) == obj->_front;
//}
//
//bool myCircularQueueEnQueue(MyCircularQueue *obj, int value)
//{
//	//判断队列是否为满
//	if (myCircularQueueIsFull(obj))
//		return false;
//	//队尾入队
//	obj->_data[obj->_rear++] = value;
//	//判断队尾是否越界 [0,k],越界则重置
//	if (obj->_rear > obj->_k)
//		obj->_rear = 0;
//	return true;
//}
//
//bool myCircularQueueDeQueue(MyCircularQueue *obj)
//{
//	//队列为空，出队失败
//	if (myCircularQueueIsFull(obj))
//		return false;
//	//队头出队
//	obj->_front++;
//
//	//判断队头是否越界
//	if (obj->_front > obj->_k)
//		obj->_front = 0;
//	return true;
//}
//
//int myCircularQueueFront(MyCircularQueue *obj)
//{
//	//返回队头元素
//	if (myCircularQueueIsFull(obj))
//		return -1;
//	return obj->_data[obj->_front];
//}
//
//int myCircularQueueRear(MyCircularQueue *obj)
//{
//	//返回队尾元素
//	if (myCircularQueueIsFull(obj))
//		return -1;
//	if (obj->_rear != 0)
//		return obj->_data[obj->_rear - 1];
//	else
//		//rear 为0，队尾在数组的末尾
//		return obj->_data[obj->_k];
//}
//
//bool myCircularQueueIsEmpty(MyCircularQueue *obj)
//{
//	return obj->_front == obj->_rear;
//}
//
//void myCircularQueueFree(MyCircularQueue *obj)
//{
//	free(obj->_data);
//	free(obj);
//}

/*实现方法二*/
typedef struct{
	//队头元素的位置
	int _front;
	//队尾元素的下一位置
	int _rear;
	//所存元素个数  最后一个元素的位置是k
	int _k;//元素计数时，是从0开始的
	//所存元素的首地址
	int *_data;
	//当前有效元素个数
	int _size;
}MyCircularQueue;

MyCircularQueue* myCircularQueueCreate(int k)
{
	MyCircularQueue * cq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	cq->_data = (int *)malloc(sizeof(int) * k);// 数据空间为 k,因为有size确定个数
	cq->_k = k;
	cq->_front = cq->_rear = 0;//0~k皆可
	cq->_size = 0;
	return cq;
}

bool myCircularQueueIsFull(MyCircularQueue *obj)
{
	//方法一
	//rear +1 % 空间的长度 == front
	//return (obj->_rear + 1) % (obj->_k + 1) == obj->_front;

	//方法二
	return obj->_size == obj->_k;
}

bool myCircularQueueEnQueue(MyCircularQueue *obj, int value)
{
	//判断队列是否为满
	if (myCircularQueueIsFull(obj))
		return false;
	//队尾入队
	obj->_data[obj->_rear++] = value;
	//判断队尾是否越界 [0,k],越界则重置
	if (obj->_rear >= obj->_k)
		obj->_rear = 0;
	obj->_size++;
	return true;
}

bool myCircularQueueDeQueue(MyCircularQueue *obj)
{
	//队列为空，出队失败
	if (myCircularQueueIsFull(obj))
		return false;
	//队头出队
	obj->_front++;

	//判断队头是否越界
	if (obj->_front >= obj->_k)
		obj->_front = 0;
	obj->_size--;
	return true;
}

int myCircularQueueFront(MyCircularQueue *obj)
{
	//返回队头元素
	if (myCircularQueueIsFull(obj))
		return -1;
	return obj->_data[obj->_front];
}

int myCircularQueueRear(MyCircularQueue *obj)
{
	//返回队尾元素
	if (myCircularQueueIsFull(obj))
		return -1;
	if (obj->_rear != 0)
		return obj->_data[obj->_rear - 1];//元素个数是从0开始计数的
	else
		//rear 为0，队尾在数组的末尾
		return obj->_data[obj->_k - 1];
}

bool myCircularQueueIsEmpty(MyCircularQueue *obj)
{
	/*return obj->_front == obj->_rear;*/
	return obj->_size == 0;
}

void myCircularQueueFree(MyCircularQueue *obj)
{
	free(obj->_data);
	free(obj);
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