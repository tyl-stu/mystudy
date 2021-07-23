#ifndef __QUEUE_H__
#define __QUEUE_H__

#include<stdio.h>
#include<stdlib.h>
//���У�����βָ��ĵ�����

typedef int QDataType;
typedef struct QNode
{
	QDataType _data;
	struct QNode* _next;
}QNode;

typedef struct Queue
{
	//ͷβָ��
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