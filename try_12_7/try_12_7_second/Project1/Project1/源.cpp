#include<stdio.h>
#include<stdlib.h>
//#include"list.h"

typedef int LDataType;

//定义节点:数据 + 指针
typedef struct  listNode
{
	LDataType _data;
	struct listNode* _next;
}listNode;

//链表
typedef struct list  //链表的类型中只包含了链表的头指针
{
	//保存第一个节点的地址
	listNode * _head;
}list;

//链表的定义！！！！！！！



//创建节点
listNode * creatListNode(LDataType val)
{
	//将数据存入节点的 _data 中，然后让 _next 指向 NULL
	listNode * node = (listNode*)malloc(sizeof(LDataType));
	node->_data = val;
	node->_next = NULL;
	return node;
}

//链表初始化   当链表为空时，则头指针指向NULL；不为空，则指向数据的位置
void listInit(list *lst)
{
	//初始化为空的链表
	if (lst == NULL)
		return;
	lst->_head = NULL;
}

//链表尾插操作   创建节点为其赋值时，需动态开辟空间
void listPushBack(list *lst, LDataType val)
{
	if (lst == NULL)
		return;
	if (lst->_head == NULL)
	{
		//插入第一个节点
		//创建节点
		lst->_head = creatListNode(val);
	}
	else
	{
		//从第一个节点开始，遍历找到最后一个节点
		listNode *tail = lst->_head;
		while (tail->_next != NULL)
		{
			tail = tail->_next;
		}

		//创建新的节点，给上述最后一个节点赋值
		tail->_next = creatListNode(val);
	}
}

//链表尾删操作
void listPopBack(list *lst)
{
	if (lst == NULL || lst->_head == NULL)
		return;

	//遍历，去寻找最后一个节点
	struct listNode *prev = NULL;
	struct listNode *tail = lst->_head;
	while (tail->_next != NULL)
	{
		prev = tail;
		tail = tail->_next;
	}

	//释放最后一个节点
	free(tail);
	//更新next
	if (prev == NULL)  //相当于 if (lst->_head->_next == NULL)    ,此种情况是只有一个节点
	{
		lst->_head = NULL;//因为只有一个节点，所以需要对 head 进行置空
	}
	else  // 链表具有多个节点
	{
		prev->_next = NULL;
	}

}

void test()
{
	list lst;
	listInit(&lst);
	listPushBack(&lst, 1);
	listPushBack(&lst, 2);
	listPushBack(&lst, 3);


	listPopBack(&lst);
	//	listPopBack(&lst);
}

int main()
{
	test();

	system("pause");
	return 0;
}
