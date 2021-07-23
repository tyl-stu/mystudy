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

//��������  ���嶼���������ţ���������
bool isValid(char *s)
{
	//����ӳ��
	//����һ
	//char map[3][2] = { { '(', ')' }, { '[', ']' }, { '{', '}' } };
	//������
	char arr[128] = { 0 };
	arr[')'] = '(';
	arr[']'] = '[';
	arr['}'] = '{';

	struct stack st;
	initStack(&st);
	while (*s)
	{
		int flag = 0;//�ж��ǲ��������ţ�Ϊ1����Ϊ0����
		////������
		//����һ��������map��ƥ��
		//for (int i = 0; i < 3; ++i)
		//{
		//	
		//	//if (*s == map[i][0])
		//	//{
		//	//	stackPush(&st, *s);
		//	//	//�ж���һ���ַ�
		//	//	++s;
		//	//	flag = 1;
		//	//	break;
		//	//}
		//}

		//��������������arr��ƥ��
		if (*s == '(' || *s == '[' || *s == '{')
		{
			stackPush(&st, *s);
			++s;
			flag = 1;
		}
		//������
		if (flag == 0)
		{
			//int match = 0;//�ж��Ƿ�ƥ�䣬1Ϊƥ�䣬0Ϊ��

			if (stackEmpty(&st))
				return false;
			//ȡ��ջ��Ԫ��
			char topChar = stackTop(&st);
			stackPop(&st);

			//�ҵ���ǰ�ַ�*s��Ӧ��������
			//����һ���������map��ƥ�䣩
			//for (int i = 0; i < 3; i++)
			//{
			//	//if (map[i][1] == *s)
			//	//{
			//	//	if (topChar == map[i][0])
			//	//	{
			//	//		//�ж���һ���ַ�
			//	//		++s;
			//	//		break;
			//	//	}
			//	//	else
			//	//		return false;//û����ȷƥ��
			//	//}
			//}

			//���������������arr��ƥ�䣩
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
	//ջΪ�գ���ȷ�պ�
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