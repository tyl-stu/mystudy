#ifndef __LIST_H__
#define __LIST_H__


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

#endif