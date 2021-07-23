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
	//β��
	struct QNode*node = creatNode(val);
	//��һ���ڵ�
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
	//ͷɾ
	if (q == NULL || q->_head == NULL)
		return;
	struct QNode * next = q->_head->_next;
	free(q->_head);
	q->_head = next;//q��ͷָ��next
	--q->_size;
	if (q->_head == NULL)
		q->_tail = NULL;//ֻ��һ���ڵ�ͷɾ�󣬿ն���
}

QDataType queueFront(Queue *q)//��ö���Ԫ��
{
	return q->_head->_data;
}

QDataType queueBack(Queue *q)//��ö�βԪ��
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

////����һ����һ������ʵ��
////ʵ���ö��й���ջ
//typedef struct{
//	//���г�Ա
//	struct Queue q;
//	
//}MyStack;
//
//MyStack *myStackCreate()
//{
//	//struct MyStack st;//���ַ��������⣬��Ϊ�ں����д���������ʱ������
//	//return &st; //����һ�������ñ����ͻᱻ����
//
//	//��̬����
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
//	{//��ջ�ǳ�ջ��Ԫ�أ���Ӧ�����о������һλԪ��
//		//�����������Ƚ��ȳ�������Ҫ�����һ��Ԫ�أ����轫ǰ���Ԫ�����ų����ٷŽ�����
//		//�Ӷ�ʵ��ջ���Ƚ����
//		//���ӣ����
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
//	return queueBack(&obj->q);//ջ��ջ�����Ƕ��е����һλ
//	//��Ϊջ���Ƚ�������������Ƚ��ȳ����칹���Ƚ����������
//	//ջ�����൱�ڶ��е����һλ
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

//���������ö�������ʵ��
//ʵ���ö��й���ջ
typedef struct{
	//���г�Ա
	struct Queue q1;
	struct Queue q2;

}MyStack;

MyStack *myStackCreate()
{
	//struct MyStack st;//���ַ��������⣬��Ϊ�ں����д���������ʱ������
	//return &st; //����һ�������ñ����ͻᱻ����

	//��̬����
	MyStack *st = (MyStack*)malloc(sizeof(MyStack));
	initQueue(&(st->q1));
	initQueue(&st->q2);
	return st;
}

void myStackPush(MyStack *obj, int x)
{
	//���ǿն��н�����ջ����
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
		{//��ջ�ǳ�ջ��Ԫ�أ���Ӧ�����о������һλԪ��
			//�����������Ƚ��ȳ�������Ҫ�����һ��Ԫ�أ����轫ǰ���Ԫ�����ų����ٷŽ�����
			//�Ӷ�ʵ��ջ���Ƚ����
			//���ӣ����
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
		{//��ջ�ǳ�ջ��Ԫ�أ���Ӧ�����о������һλԪ��
			//�����������Ƚ��ȳ�������Ҫ�����һ��Ԫ�أ����轫ǰ���Ԫ�����ų����ٷŽ�����
			//�Ӷ�ʵ��ջ���Ƚ����
			//���ӣ����
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
	//ջ��ջ�����Ƕ��е����һλ
	//��Ϊջ���Ƚ�������������Ƚ��ȳ����칹���Ƚ����������
	//ջ�����൱�ڶ��е����һλ
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