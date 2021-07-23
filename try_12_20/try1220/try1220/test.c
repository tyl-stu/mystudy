#include<stdio.h>
#include<stdlib.h>
//实现带头双向循环链表

typedef int LDataType;

//双向节点
typedef struct ListNode
{
	LDataType _data;
	struct ListNode * _prev;
	struct ListNode * _next;
}ListNode;

//双向带头链表
typedef struct List
{
	struct ListNode * _head;
}List;

//初始化链表
void listInit(List *lst)
{
	//构建循环结构
	//创建头节点
	lst->_head = (struct ListNode*)malloc(sizeof(struct ListNode));
	//循环
	lst->_head->_prev = lst->_head->_next = lst->_head;
}

//创建新节点
struct ListNode * creatNode(LDataType val)
{
	struct ListNode * node = (struct ListNode*)malloc(sizeof(struct ListNode));
	node->_data = val;
	node->_next = NULL;
	node->_prev = NULL;
	return node;
}

//尾插
void listPushBack(List *lst,LDataType val)
{
	struct ListNode* tail = lst->_head->_prev;//尾节点
	struct ListNode* newNode = creatNode(val);//新节点

	tail->_next = newNode;//原尾节点next指向所加节点，
	newNode->_prev = tail;//所加节点prev指向原尾节点

	lst->_head->_prev = newNode;//头节点的prev指向所加节点
	newNode->_next = lst->_head;//所加节点的next指向头节点

	//listInsert(lst->_head, val);
}

//尾删
void listPopBack(List *lst)
{
	//空链表不能删除，会破坏循环结构
	if (lst->_head->_prev == lst->_head)
		return;//空链表
	struct ListNode * tail = lst->_head->_prev;
	struct ListNode * prev = tail->_prev;
	prev->_next = lst->_head;
	lst->_head->_prev = prev;
	free(tail);
}

//头插
void listPushFront(List *lst, LDataType val)
{
	struct ListNode *newNode = creatNode(val);
	struct ListNode *tail = lst->_head->_next;

	newNode->_next = tail;
	tail->_prev = newNode;

	lst->_head->_next = newNode;
	newNode->_prev = lst->_head;

	//listInsert(lst->_head->_next, val);
}

//头删
void listPopFront(List *lst)
{
	if (lst->_head->_prev == lst->_head)
		return;//空链表
	struct ListNode *tail = lst->_head->_next;
	struct ListNode *back = tail->_next;

	lst->_head->_next = back;
	back->_prev = lst->_head;
	free(tail);
}

//任插
void listInsert(ListNode *node, LDataType val)
{
	struct ListNode *newNode = creatNode(val);
	struct ListNode *tail = node->_prev;

	node->_prev = newNode;
	newNode->_next = node;

	tail->_next = newNode;
	newNode->_prev = tail;
}

//任删
void listErase(ListNode *node)
{
	if (node == node->_prev)
		return;
	struct ListNode *prev = node->_prev;
	struct ListNode *next = node->_next;
	free(node);
	prev->_next = next;
	next->_prev = prev;
	
	//头删：listErase(lst._head->next)
	//尾删：listErase(lst._head->prev)
}

//链表销毁
void listDestory(List *lst)
{
	struct ListNode * cur = lst->_head->_next;
	while (cur != lst->_head)
	{
		struct ListNode *next = cur->_next;
		free(cur);
		cur = next;
	}
	free(lst->_head);
	lst->_head = NULL;
}

//打印
void printList(List *lst)
{
	struct ListNode * cur = lst->_head->_next;
	while (cur != lst->_head)
	{
		printf("%d ", cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}

void test()
{
	struct List lst;
	listInit(&lst);
	listPushBack(&lst, 1);
	listPushBack(&lst, 2);
	listPushBack(&lst, 3);
	printList(&lst);// 1 2 3

	listPopBack(&lst);
	listPopBack(&lst);//1
	listPushFront(&lst, 8);
	listPushFront(&lst, 10);
	printList(&lst);//10 8 1

	listPopFront(&lst);
	//listPopFront(&lst);
	printList(&lst);//8 1

	listInsert(lst._head, 15);//尾插
	listInsert(lst._head->_next, 21);
	listInsert(lst._head->_next, 27);//头插
	printList(&lst);

	listErase(lst._head->_prev);//尾删
	listErase(lst._head->_next);//头删
	listErase(lst._head->_next);//头删
	listErase(lst._head->_next);//头删
	printList(&lst);//1

	listDestory(&lst);
}

int main()
{
	test();

	system("pause");
	return 0;
}
