#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int STDataType;

//˳��ṹʵ�֣�ʵ��һ�����򵥵�˳���
typedef struct stack
{
	STDataType *_data;
	int _size;
	int _capacity;
}stack;

void initStack(stack *st)
{
	//��ջ
	if (st == NULL)
		return;
	st->_data = NULL;
	st->_size = st->_capacity = 0;
}

void checkCapacity(stack *st)
{
	if (st->_size == st->_capacity)
	{
		int newCap = st->_capacity == 0 ? 1 : 2 * st->_capacity;
		st->_data = (STDataType*)realloc(st->_data, sizeof(STDataType)*newCap);
		st->_capacity = newCap;
	}
}

void stackPush(stack *st, STDataType val)
{
	//β��
	if (st == NULL)
		return;
	checkCapacity(st);
	st->_data[st->_size++] = val;
}

void stackPop(stack *st)
{
	//βɾ
	if (st == NULL || st->_size == 0)
		return;
	--st->_size;
}

int stackSize(stack *st)
{
	if (st == NULL)
		return 0;
	return st->_size;
}

int stackEmpty(stack* st)
{
	if (st == NULL || st->_size == 0)
		return 1;//����1Ϊ��
	else
		return 0;
	//return st->_size;
}

STDataType stackTop(stack *st)
{
	return st->_data[st->_size - 1];//ջ��Ԫ��
}

void stackDestory(stack *st)
{
	if (st)
	{
		if (st->_data)
		{
			free(st->_data);
			st->_data = NULL;
			st->_size = 0;
			st->_capacity = 0;
		}
	}
	
}

//ջʵ�ֶ��У���ӣ����ջ����ջ
//			���ӣ�����ջ��
//					�ǿգ���ջ
//					�գ����Ȱ����ջԪ�ش������ջ������ջ�ڽ��г�ջ
typedef struct
{
	struct stack st1;//���ջ
	struct stack st2;//����ջ
}MyQueue;

MyQueue *myQueueCreate()
{
	MyQueue *q = (MyQueue *)malloc(sizeof(MyQueue));
	initStack(&q->st1);
	initStack(&q->st2);
	return q;
}

void myQueuePush(MyQueue *obj, int x)
{
	stackPush(&obj->st1, x);
}

int myQueuePop(MyQueue *obj)
{
	int data;
	if (!stackEmpty(&obj->st1))
	{
		int n = stackSize(&obj->st1);
		while (n)//�൱�� while (!stackEmpty(&obj->st1))
		{
			int data1 = stackTop(&obj->st1);
			stackPop(&obj->st1);
			stackPush(&obj->st2, data1);
			--n;
		}
		data = stackTop(&obj->st2);
		stackPop(&obj->st2);
	}
	else
	{
		data = stackTop(&obj->st2);
		stackPop(&obj->st2);
	}
	return data;
}

int myQueuePeek(MyQueue *obj)
{
	if (stackEmpty(&obj->st2))//�жϳ���ջ�Ƿ�Ϊ�գ��գ������ջ�����ݴ��뵽����ջ
	{
		while (!stackEmpty(&obj->st1))
		{
			int data = stackTop(&obj->st1);
			stackPop(&obj->st1);
			stackPush(&obj->st2, data);
		}
	}
	return stackTop(&obj->st2);
}

bool myQueueEmpty(MyQueue *obj)
{
	return stackEmpty(&obj->st1) && stackEmpty(&obj->st2);
}

void myQueueFree(MyQueue *obj)
{
	stackDestory(&obj->st1);
	stackDestory(&obj->st2);
	free(obj);
}

//void test()
//{
//	stack st;
//	initStack(&st);
//
//	stackPush(&st, 1);
//	stackPush(&st, 3);
//	stackPush(&st, 7);
//
//	while (!stackEmpty(&st))
//	{
//		printf("%d ", stackTop(&st));
//		stackPop(&st);
//	}
//	printf("\n");
//}
//
//int main()
//{
//	test();
//
//	system("pause");
//	return 0;
//}