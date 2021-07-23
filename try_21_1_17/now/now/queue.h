#ifndef _QUEUE_H_
#define _QUEUE_H_


#include<stdio.h>
#include<stdlib.h>
#include"bnode.h"

//���У�����βָ��ĵ�����

typedef BNode* QDataType;
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