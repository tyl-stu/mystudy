#include<stdio.h>
#include<stdlib.h>
//ʵ�ִ�ͷ˫��ѭ������

typedef int LDataType;

//˫��ڵ�
typedef struct ListNode
{
	LDataType _data;
	struct ListNode * _prev;
	struct ListNode * _next;
}ListNode;

//˫���ͷ����
typedef struct List
{
	struct ListNode * _head;
}List;

//��ʼ������
void listInit(List *lst)
{
	//����ѭ���ṹ
	//����ͷ�ڵ�
	lst->_head = (struct ListNode*)malloc(sizeof(struct ListNode));
	//ѭ��
	lst->_head->_prev = lst->_head->_next = lst->_head;
}

//�����½ڵ�
struct ListNode * creatNode(LDataType val)
{
	struct ListNode * node = (struct ListNode*)malloc(sizeof(struct ListNode));
	node->_data = val;
	node->_next = NULL;
	node->_prev = NULL;
	return node;
}

//β��
void listPushBack(List *lst,LDataType val)
{
	struct ListNode* tail = lst->_head->_prev;//β�ڵ�
	struct ListNode* newNode = creatNode(val);//�½ڵ�

	tail->_next = newNode;//ԭβ�ڵ�nextָ�����ӽڵ㣬
	newNode->_prev = tail;//���ӽڵ�prevָ��ԭβ�ڵ�

	lst->_head->_prev = newNode;//ͷ�ڵ��prevָ�����ӽڵ�
	newNode->_next = lst->_head;//���ӽڵ��nextָ��ͷ�ڵ�

	//listInsert(lst->_head, val);
}

//βɾ
void listPopBack(List *lst)
{
	//��������ɾ�������ƻ�ѭ���ṹ
	if (lst->_head->_prev == lst->_head)
		return;//������
	struct ListNode * tail = lst->_head->_prev;
	struct ListNode * prev = tail->_prev;
	prev->_next = lst->_head;
	lst->_head->_prev = prev;
	free(tail);
}

//ͷ��
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

//ͷɾ
void listPopFront(List *lst)
{
	if (lst->_head->_prev == lst->_head)
		return;//������
	struct ListNode *tail = lst->_head->_next;
	struct ListNode *back = tail->_next;

	lst->_head->_next = back;
	back->_prev = lst->_head;
	free(tail);
}

//�β�
void listInsert(ListNode *node, LDataType val)
{
	struct ListNode *newNode = creatNode(val);
	struct ListNode *tail = node->_prev;

	node->_prev = newNode;
	newNode->_next = node;

	tail->_next = newNode;
	newNode->_prev = tail;
}

//��ɾ
void listErase(ListNode *node)
{
	if (node == node->_prev)
		return;
	struct ListNode *prev = node->_prev;
	struct ListNode *next = node->_next;
	free(node);
	prev->_next = next;
	next->_prev = prev;
	
	//ͷɾ��listErase(lst._head->next)
	//βɾ��listErase(lst._head->prev)
}

//��������
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

//��ӡ
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

	listInsert(lst._head, 15);//β��
	listInsert(lst._head->_next, 21);
	listInsert(lst._head->_next, 27);//ͷ��
	printList(&lst);

	listErase(lst._head->_prev);//βɾ
	listErase(lst._head->_next);//ͷɾ
	listErase(lst._head->_next);//ͷɾ
	listErase(lst._head->_next);//ͷɾ
	printList(&lst);//1

	listDestory(&lst);
}

int main()
{
	test();

	system("pause");
	return 0;
}
