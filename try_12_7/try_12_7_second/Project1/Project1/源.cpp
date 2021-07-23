#include<stdio.h>
#include<stdlib.h>
//#include"list.h"

typedef int LDataType;

//����ڵ�:���� + ָ��
typedef struct  listNode
{
	LDataType _data;
	struct listNode* _next;
}listNode;

//����
typedef struct list  //�����������ֻ�����������ͷָ��
{
	//�����һ���ڵ�ĵ�ַ
	listNode * _head;
}list;

//����Ķ��壡������������



//�����ڵ�
listNode * creatListNode(LDataType val)
{
	//�����ݴ���ڵ�� _data �У�Ȼ���� _next ָ�� NULL
	listNode * node = (listNode*)malloc(sizeof(LDataType));
	node->_data = val;
	node->_next = NULL;
	return node;
}

//�����ʼ��   ������Ϊ��ʱ����ͷָ��ָ��NULL����Ϊ�գ���ָ�����ݵ�λ��
void listInit(list *lst)
{
	//��ʼ��Ϊ�յ�����
	if (lst == NULL)
		return;
	lst->_head = NULL;
}

//����β�����   �����ڵ�Ϊ�丳ֵʱ���趯̬���ٿռ�
void listPushBack(list *lst, LDataType val)
{
	if (lst == NULL)
		return;
	if (lst->_head == NULL)
	{
		//�����һ���ڵ�
		//�����ڵ�
		lst->_head = creatListNode(val);
	}
	else
	{
		//�ӵ�һ���ڵ㿪ʼ�������ҵ����һ���ڵ�
		listNode *tail = lst->_head;
		while (tail->_next != NULL)
		{
			tail = tail->_next;
		}

		//�����µĽڵ㣬���������һ���ڵ㸳ֵ
		tail->_next = creatListNode(val);
	}
}

//����βɾ����
void listPopBack(list *lst)
{
	if (lst == NULL || lst->_head == NULL)
		return;

	//������ȥѰ�����һ���ڵ�
	struct listNode *prev = NULL;
	struct listNode *tail = lst->_head;
	while (tail->_next != NULL)
	{
		prev = tail;
		tail = tail->_next;
	}

	//�ͷ����һ���ڵ�
	free(tail);
	//����next
	if (prev == NULL)  //�൱�� if (lst->_head->_next == NULL)    ,���������ֻ��һ���ڵ�
	{
		lst->_head = NULL;//��Ϊֻ��һ���ڵ㣬������Ҫ�� head �����ÿ�
	}
	else  // ������ж���ڵ�
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
