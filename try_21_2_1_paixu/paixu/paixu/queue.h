#ifndef __QUEUE_H__
#define __QUEUE_H__

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

void initQueue(Queue * q);

struct QNode* creatNode(QDataType val);

void queuePush(Queue * q, QDataType val);

void queuePop(Queue * q);

QDataType queueFront(Queue *q);

QDataType queueBack(Queue *q);

int queueEmpty(Queue *q);

int queueSize(Queue *q);
#endif