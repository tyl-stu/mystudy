#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include"list.h"

//链表的定义！！！！！！！

// listNode 是节点  ， list 是链表，或者节点的头

//创建节点
listNode * creatListNode(LDataType val)
{
	//将数据存入节点的 _data 中，然后让 _next 指向 NULL
	struct listNode * node = (listNode*)malloc(sizeof(listNode));
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

//链表尾插操作   创建节点为其赋值时，需动态开辟空间   O(n)
void listPushBack(list *lst,LDataType val)
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

//链表尾删操作   O(n)
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
	free(tail);//注意对应空间的开辟
	//更新next
	if (lst->_head->_next == NULL)  //相当于 if(prev == NULL)  ,此种情况是只有一个节点
		lst->_head = NULL;//因为只有一个节点，所以需要对 head 进行置空
	else  // 链表具有多个节点
		prev->_next = NULL;
	
	
}

//头插操作  O(1)
void listPushFront(list *lst, LDataType val)
{
	//相当于将 lst->_head 指向了 node ,然后将 node->next 指向了 lst->_head 原指向的节点

	if (lst == NULL)
		return;
	//创建节点
	struct listNode *node = creatListNode(val);
	//改变第一个节点的元素，head,node,next
	node->_next = lst->_head;
	lst->_head = node;
}

//头删操作  O(1)
void listPopFront(list *lst)
{
	if (lst == NULL || lst->_head == NULL)
		return;

	//需要修改头的指向
	listNode *next = lst->_head->_next;
	free(lst->_head);
	lst->_head = next;
}

//任插操作
void listInsertAfter(listNode *node, LDataType val)
{
	if (node == NULL)
		return;
	listNode *newNode = creatListNode(val);

	listNode *next = node->_next;//做中间变量
	node->_next = newNode;
	newNode->_next = next;

}

//任删操作
void listEraseAfter(listNode * node)//删除所给节点的下一节点
{
	if (node == NULL || node->_next == NULL)
		return;
	listNode *next = node->_next;
	listNode *nextnext = next->_next;

	//释放node 下一个节点，即next
	free(next);
	//再将node的指向改为下一个的下一个节点
	node->_next = nextnext;
}

//查找操作
listNode * listFind(list *lst, LDataType val)
{
	if (lst == NULL || lst->_head == NULL)
		return NULL;

	//从第一个节点开始遍历寻找所找节点
	listNode *cur = lst->_head;
	while (cur)
	{
		if (cur->_data == val)
		{
			return cur;
		}
		cur = cur->_next;
	}
	return NULL;
}

//销毁链表
void listDestory(list *lst)
{
	if (lst == NULL || lst->_head == NULL)
		return;

	//方法1
	/*listNode *cur = lst->_head;
	listNode *next = lst->_head->_next;
	while (cur->_next)
	{
		free(cur);
		cur = next;
		next = cur->_next;	
		
	}
	free(cur);
	cur = NULL;
	lst->_head = NULL;*/

	//方法2
	listNode *cur = lst->_head;
	while (cur)
	{
		listNode *next = cur->_next;
		free(cur);
		cur = next;
	}
	lst->_head = NULL;

	printf("销毁结束！\n");
}

//删除某一个节点
void listErase(list *lst,listNode *node)
{
	if (node == NULL || node->_next == NULL)
		return;
	//list *lst;
	listNode *up = lst->_head;
	//从第一个节点开始遍历寻找所找节点
	while (node != NULL)
	{
		if (up->_next == node)
		{
			listNode *next = node->_next;
			free(node);
			//再将node的指向改为下一个的下一个节点
			up->_next = next;
			break;
		}
		else
		{
			up = up->_next;
		}
	}

}

void test() 
{
	list lst;
	listInit(&lst);
	listPushBack(&lst, 1);
	//listPushBack(&lst, 2);
	//listPushBack(&lst, 3); 

	//listPushFront(&lst, 45);

	//listPopBack(&lst);// 45 1 2
	//listPopFront(&lst);// 1 2 
	//listPushBack(&lst, 777);//1 2 777

	//listNode *cur = listFind(&lst, 2);
	//listEraseAfter(cur);//删除节点数据为2的节点的下一个节点   1 2 

	//listInsertAfter(cur, 66);//在cur节点 添加数据66  1 2 66
	//listErase(&lst,cur);//1 66 

	//listDestory(&lst);
}

int main()
{
	test();

	system("pause");
	return 0;
}
