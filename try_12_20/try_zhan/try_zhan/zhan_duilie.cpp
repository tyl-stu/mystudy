#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int STDataType;

//顺序结构实现：实现一个更简单的顺序表
typedef struct stack
{
	STDataType *_data;
	int _size;
	int _capacity;
}stack;

void initStack(stack *st)
{
	//空栈
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
	//尾插
	if (st == NULL)
		return;
	checkCapacity(st);
	st->_data[st->_size++] = val;
}

void stackPop(stack *st)
{
	//尾删
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
		return 1;//返回1为空
	else
		return 0;
	//return st->_size;
}

STDataType stackTop(stack *st)
{
	return st->_data[st->_size - 1];//栈顶元素
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

//栈实现队列：入队：入队栈的入栈
//			出队：出队栈：
//					非空：出栈
//					空：首先把入队栈元素存入出队栈，出队栈在进行出栈
typedef struct
{
	struct stack st1;//入队栈
	struct stack st2;//出队栈
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
		while (n)//相当于 while (!stackEmpty(&obj->st1))
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
	if (stackEmpty(&obj->st2))//判断出队栈是否为空，空，则将入队栈的数据存入到出队栈
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