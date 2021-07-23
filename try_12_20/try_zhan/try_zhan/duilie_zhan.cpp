#include<stdio.h>
#include<stdlib.h>

//队列：带有尾指针的单链表
typedef int QDataType;
typedef struct QNode
{
	QDataType _data;
	struct QNode* _next;
}QNode;

typedef struct Queue
{
	//头尾指针
	struct QNode * _head;
	struct QNode * _tail;
	int _size;
}Queue;

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

QDataType queueFront(Queue *q)//获得队首元素
{
	return q->_head->_data;
}

QDataType queueBack(Queue *q)//获得队尾元素
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

void queueDestory(Queue *q)
{
	QNode *cur = q->_head;
	while (cur)
	{
		QNode *next = cur->_next;
		free(cur);
		cur = next;
	}
	q->_head = q->_tail = NULL;
}

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

////方法一：用一个队列实现
////实现用队列构成栈
//typedef struct{
//	//队列成员
//	struct Queue q;
//	
//}MyStack;
//
//MyStack *myStackCreate()
//{
//	//struct MyStack st;//这种方法有问题，因为在函数中创建的是临时变量，
//	//return &st; //函数一结束，该变量就会被销毁
//
//	//动态创建
//	MyStack *st = (MyStack*)malloc(sizeof(MyStack));
//	initQueue(&(st->q));
//	return st;
//}
//
//void myStackPush(MyStack *obj, int x)
//{
//	queuePush(&obj->q, x);
//}
//
//int myStackPop(MyStack *obj)
//{
//	int n = queueSize(&obj->q);
//	while (n > 1)
//	{//出栈是出栈顶元素，对应到队列就是最后一位元素
//		//而队列又是先进先出，所以要出最后一个元素，则需将前面的元素先排出，再放进队列
//		//从而实现栈的先进后出
//		//出队，入队
//		int front = queueFront(&obj->q);
//		queuePop(&obj->q);
//		queuePush(&obj->q, front);
//		--n;
//	}
//	int top = queueFront(&obj->q);
//	queuePop(&obj->q);
//	return top;
//}
//
//int myStackTop(MyStack *obj)
//{
//	return queueBack(&obj->q);//栈的栈顶就是队列的最后一位
//	//因为栈是先进后出，队列是先进先出，徐构成先进后出，所以
//	//栈顶就相当于队列的最后一位
//}
//
//bool myStackEmpty(MyStack *obj)
//{
//	return queueEmpty(&obj->q);
//}
//
//void myStackFree(MyStack *obj)
//{
//	queueDestory(&obj->q);
//	free(obj);
//}

//方法二：用二个队列实现
//实现用队列构成栈
typedef struct{
	//队列成员
	struct Queue q1;
	struct Queue q2;

}MyStack;

MyStack *myStackCreate()
{
	//struct MyStack st;//这种方法有问题，因为在函数中创建的是临时变量，
	//return &st; //函数一结束，该变量就会被销毁

	//动态创建
	MyStack *st = (MyStack*)malloc(sizeof(MyStack));
	initQueue(&(st->q1));
	initQueue(&st->q2);
	return st;
}

void myStackPush(MyStack *obj, int x)
{
	//给非空队列进行入栈操作
	if (!queueEmpty(&obj->q1))
		queuePush(&obj->q1, x);
	else
		queuePush(&obj->q2, x);
}

int myStackPop(MyStack *obj)
{
	int top;
	if (!queueEmpty(&obj->q1))
	{
		int n = queueSize(&obj->q1);
		while (n > 1)
		{//出栈是出栈顶元素，对应到队列就是最后一位元素
			//而队列又是先进先出，所以要出最后一个元素，则需将前面的元素先排出，再放进队列
			//从而实现栈的先进后出
			//出队，入队
			int front = queueFront(&obj->q1);
			queuePop(&obj->q1);
			queuePush(&obj->q2, front);
			--n;
		}
		int top = queueFront(&obj->q1);
		queuePop(&obj->q1);
	}
	else
	{
		int n = queueSize(&obj->q2);
		while (n > 1)
		{//出栈是出栈顶元素，对应到队列就是最后一位元素
			//而队列又是先进先出，所以要出最后一个元素，则需将前面的元素先排出，再放进队列
			//从而实现栈的先进后出
			//出队，入队
			int front = queueFront(&obj->q2);
			queuePop(&obj->q2);
			queuePush(&obj->q1, front);
			--n;
		}
		int top = queueFront(&obj->q2);
		queuePop(&obj->q2);
	}
	
	return top;
}

int myStackTop(MyStack *obj)
{
	if (!queueEmpty(&obj->q1))
		return queueBack(&obj->q1);
	else
		return queueBack(&obj->q2);
	//栈的栈顶就是队列的最后一位
	//因为栈是先进后出，队列是先进先出，徐构成先进后出，所以
	//栈顶就相当于队列的最后一位
}

bool myStackEmpty(MyStack *obj)
{
	return queueEmpty(&obj->q1) && queueEmpty(&obj->q2);
}

void myStackFree(MyStack *obj)
{
	queueDestory(&obj->q1);
	queueDestory(&obj->q2);
	free(obj);
}