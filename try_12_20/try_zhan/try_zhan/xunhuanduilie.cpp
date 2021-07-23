#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//ѭ������
//���У�����βָ��ĵ�����

//typedef int QDataType;
//typedef struct QNode
//{
//	QDataType _data;
//	struct QNode* _next;
//}QNode;
//
//typedef struct Queue
//{
//	//ͷβָ��
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
//	//β��
//	struct QNode*node = creatNode(val);
//	//��һ���ڵ�
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
//	//ͷɾ
//	if (q == NULL || q->_head == NULL)
//		return;
//	struct QNode * next = q->_head->_next;
//	free(q->_head);
//	q->_head = next;//q��ͷָ��next
//	--q->_size;
//	if (q->_head == NULL)
//		q->_tail = NULL;//ֻ��һ���ڵ�ͷɾ�󣬿ն���
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

/*ʵ�ַ���һ*/
//typedef struct{
//	//��ͷԪ�ص�λ��
//	int _front;
//	//��βԪ�ص���һλ��
//	int _rear;
//	//����Ԫ�ظ���  ���һ��Ԫ�ص�λ����k
//	int _k;
//	//����Ԫ�ص��׵�ַ
//	int *_data;
//}MyCircularQueue;
//
//MyCircularQueue* myCircularQueueCreate(int k)
//{
//	MyCircularQueue * cq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
//	cq->_data = (int *)malloc(sizeof(int)*(k + 1));// ���ݿռ�Ϊ k+1
//	cq->_k = k;
//	cq->_front = cq->_rear = 0;//0~k�Կ�
//	return cq;
//}
//
//bool myCircularQueueIsFull(MyCircularQueue *obj)
//{
//	//rear +1 % �ռ�ĳ��� == front
//	return (obj->_rear + 1) % (obj->_k + 1) == obj->_front;
//}
//
//bool myCircularQueueEnQueue(MyCircularQueue *obj, int value)
//{
//	//�ж϶����Ƿ�Ϊ��
//	if (myCircularQueueIsFull(obj))
//		return false;
//	//��β���
//	obj->_data[obj->_rear++] = value;
//	//�ж϶�β�Ƿ�Խ�� [0,k],Խ��������
//	if (obj->_rear > obj->_k)
//		obj->_rear = 0;
//	return true;
//}
//
//bool myCircularQueueDeQueue(MyCircularQueue *obj)
//{
//	//����Ϊ�գ�����ʧ��
//	if (myCircularQueueIsFull(obj))
//		return false;
//	//��ͷ����
//	obj->_front++;
//
//	//�ж϶�ͷ�Ƿ�Խ��
//	if (obj->_front > obj->_k)
//		obj->_front = 0;
//	return true;
//}
//
//int myCircularQueueFront(MyCircularQueue *obj)
//{
//	//���ض�ͷԪ��
//	if (myCircularQueueIsFull(obj))
//		return -1;
//	return obj->_data[obj->_front];
//}
//
//int myCircularQueueRear(MyCircularQueue *obj)
//{
//	//���ض�βԪ��
//	if (myCircularQueueIsFull(obj))
//		return -1;
//	if (obj->_rear != 0)
//		return obj->_data[obj->_rear - 1];
//	else
//		//rear Ϊ0����β�������ĩβ
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

/*ʵ�ַ�����*/
typedef struct{
	//��ͷԪ�ص�λ��
	int _front;
	//��βԪ�ص���һλ��
	int _rear;
	//����Ԫ�ظ���  ���һ��Ԫ�ص�λ����k
	int _k;//Ԫ�ؼ���ʱ���Ǵ�0��ʼ��
	//����Ԫ�ص��׵�ַ
	int *_data;
	//��ǰ��ЧԪ�ظ���
	int _size;
}MyCircularQueue;

MyCircularQueue* myCircularQueueCreate(int k)
{
	MyCircularQueue * cq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	cq->_data = (int *)malloc(sizeof(int) * k);// ���ݿռ�Ϊ k,��Ϊ��sizeȷ������
	cq->_k = k;
	cq->_front = cq->_rear = 0;//0~k�Կ�
	cq->_size = 0;
	return cq;
}

bool myCircularQueueIsFull(MyCircularQueue *obj)
{
	//����һ
	//rear +1 % �ռ�ĳ��� == front
	//return (obj->_rear + 1) % (obj->_k + 1) == obj->_front;

	//������
	return obj->_size == obj->_k;
}

bool myCircularQueueEnQueue(MyCircularQueue *obj, int value)
{
	//�ж϶����Ƿ�Ϊ��
	if (myCircularQueueIsFull(obj))
		return false;
	//��β���
	obj->_data[obj->_rear++] = value;
	//�ж϶�β�Ƿ�Խ�� [0,k],Խ��������
	if (obj->_rear >= obj->_k)
		obj->_rear = 0;
	obj->_size++;
	return true;
}

bool myCircularQueueDeQueue(MyCircularQueue *obj)
{
	//����Ϊ�գ�����ʧ��
	if (myCircularQueueIsFull(obj))
		return false;
	//��ͷ����
	obj->_front++;

	//�ж϶�ͷ�Ƿ�Խ��
	if (obj->_front >= obj->_k)
		obj->_front = 0;
	obj->_size--;
	return true;
}

int myCircularQueueFront(MyCircularQueue *obj)
{
	//���ض�ͷԪ��
	if (myCircularQueueIsFull(obj))
		return -1;
	return obj->_data[obj->_front];
}

int myCircularQueueRear(MyCircularQueue *obj)
{
	//���ض�βԪ��
	if (myCircularQueueIsFull(obj))
		return -1;
	if (obj->_rear != 0)
		return obj->_data[obj->_rear - 1];//Ԫ�ظ����Ǵ�0��ʼ������
	else
		//rear Ϊ0����β�������ĩβ
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