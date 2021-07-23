#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include"list.h"

//����Ķ��壡������������

// listNode �ǽڵ�  �� list ���������߽ڵ��ͷ

//�����ڵ�
listNode * creatListNode(LDataType val)
{
	//�����ݴ���ڵ�� _data �У�Ȼ���� _next ָ�� NULL
	struct listNode * node = (listNode*)malloc(sizeof(listNode));
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

//����β�����   �����ڵ�Ϊ�丳ֵʱ���趯̬���ٿռ�   O(n)
void listPushBack(list *lst,LDataType val)
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

//����βɾ����   O(n)
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
	free(tail);//ע���Ӧ�ռ�Ŀ���
	//����next
	if (lst->_head->_next == NULL)  //�൱�� if(prev == NULL)  ,���������ֻ��һ���ڵ�
		lst->_head = NULL;//��Ϊֻ��һ���ڵ㣬������Ҫ�� head �����ÿ�
	else  // ������ж���ڵ�
		prev->_next = NULL;
	
	
}

//ͷ�����  O(1)
void listPushFront(list *lst, LDataType val)
{
	//�൱�ڽ� lst->_head ָ���� node ,Ȼ�� node->next ָ���� lst->_head ԭָ��Ľڵ�

	if (lst == NULL)
		return;
	//�����ڵ�
	struct listNode *node = creatListNode(val);
	//�ı��һ���ڵ��Ԫ�أ�head,node,next
	node->_next = lst->_head;
	lst->_head = node;
}

//ͷɾ����  O(1)
void listPopFront(list *lst)
{
	if (lst == NULL || lst->_head == NULL)
		return;

	//��Ҫ�޸�ͷ��ָ��
	listNode *next = lst->_head->_next;
	free(lst->_head);
	lst->_head = next;
}

//�β����
void listInsertAfter(listNode *node, LDataType val)
{
	if (node == NULL)
		return;
	listNode *newNode = creatListNode(val);

	listNode *next = node->_next;//���м����
	node->_next = newNode;
	newNode->_next = next;

}

//��ɾ����
void listEraseAfter(listNode * node)//ɾ�������ڵ����һ�ڵ�
{
	if (node == NULL || node->_next == NULL)
		return;
	listNode *next = node->_next;
	listNode *nextnext = next->_next;

	//�ͷ�node ��һ���ڵ㣬��next
	free(next);
	//�ٽ�node��ָ���Ϊ��һ������һ���ڵ�
	node->_next = nextnext;
}

//���Ҳ���
listNode * listFind(list *lst, LDataType val)
{
	if (lst == NULL || lst->_head == NULL)
		return NULL;

	//�ӵ�һ���ڵ㿪ʼ����Ѱ�����ҽڵ�
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

//��������
void listDestory(list *lst)
{
	if (lst == NULL || lst->_head == NULL)
		return;

	//����1
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

	//����2
	listNode *cur = lst->_head;
	while (cur)
	{
		listNode *next = cur->_next;
		free(cur);
		cur = next;
	}
	lst->_head = NULL;

	printf("���ٽ�����\n");
}

//ɾ��ĳһ���ڵ�
void listErase(list *lst,listNode *node)
{
	if (node == NULL || node->_next == NULL)
		return;
	//list *lst;
	listNode *up = lst->_head;
	//�ӵ�һ���ڵ㿪ʼ����Ѱ�����ҽڵ�
	while (node != NULL)
	{
		if (up->_next == node)
		{
			listNode *next = node->_next;
			free(node);
			//�ٽ�node��ָ���Ϊ��һ������һ���ڵ�
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
	//listEraseAfter(cur);//ɾ���ڵ�����Ϊ2�Ľڵ����һ���ڵ�   1 2 

	//listInsertAfter(cur, 66);//��cur�ڵ� �������66  1 2 66
	//listErase(&lst,cur);//1 66 

	//listDestory(&lst);
}

int main()
{
	test();

	system("pause");
	return 0;
}
