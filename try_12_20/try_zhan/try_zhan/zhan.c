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

//括号例题  整体都是先左括号，再右括号
bool isValid(char *s)
{
	//括号映射
	//方法一
	//char map[3][2] = { { '(', ')' }, { '[', ']' }, { '{', '}' } };
	//方法二
	char arr[128] = { 0 };
	arr[')'] = '(';
	arr[']'] = '[';
	arr['}'] = '{';

	struct stack st;
	initStack(&st);
	while (*s)
	{
		int flag = 0;//判断是不是左括号，为1是左，为0是右
		////左括号
		//方法一：与上述map相匹配
		//for (int i = 0; i < 3; ++i)
		//{
		//	
		//	//if (*s == map[i][0])
		//	//{
		//	//	stackPush(&st, *s);
		//	//	//判断下一个字符
		//	//	++s;
		//	//	flag = 1;
		//	//	break;
		//	//}
		//}

		//方法二：与上述arr相匹配
		if (*s == '(' || *s == '[' || *s == '{')
		{
			stackPush(&st, *s);
			++s;
			flag = 1;
		}
		//右括号
		if (flag == 0)
		{
			//int match = 0;//判断是否匹配，1为匹配，0为非

			if (stackEmpty(&st))
				return false;
			//取出栈顶元素
			char topChar = stackTop(&st);
			stackPop(&st);

			//找到当前字符*s对应的左括号
			//方法一（与上面的map相匹配）
			//for (int i = 0; i < 3; i++)
			//{
			//	//if (map[i][1] == *s)
			//	//{
			//	//	if (topChar == map[i][0])
			//	//	{
			//	//		//判断下一个字符
			//	//		++s;
			//	//		break;
			//	//	}
			//	//	else
			//	//		return false;//没有正确匹配
			//	//}
			//}

			//方法二（与上面的arr相匹配）
			if (arr[*s] == topChar)
			{
				++s;
				//match = 1;
				break;
			}
			else
				return false;
		}
	}
	//栈为空：正确闭合
	return stackEmpty(&st);
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