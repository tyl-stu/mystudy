#include"slist.h"

//创建节点
SListNode* BuySListNode(SLTDateType x)
{
	struct SListNode * node = (SListNode *)malloc(sizeof(SListNode));
	node->data = x;
	node->next = NULL;
	return node;
}

//初始化链表
void SListInit(SListNode *plist)
{
	//assert(plist == NULL);
	plist->next = NULL;	
}

// 单链表打印
void SListPrint(SListNode* plist)
{
	assert(plist == NULL);
	
	struct SListNode *cur = plist;
	printf("链表中的数值为：");
	while (cur)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
	
}

// 单链表尾插 *pplist 指向的是节点
void SListPushBack(SListNode** pplist, SLTDateType x)
{
	SListNode *newnode = BuySListNode(x);
	if (*pplist == NULL)
	{
		*pplist = newnode;
	}
	else
	{
		SListNode *cur = *pplist;

		while (cur->next != NULL)
		{
			cur = cur->next;
		}
		cur->next = newnode;	
	}
	
}

// 单链表的尾删
void SListPopBack(SListNode** pplist)
{
	assert(*pplist == NULL);
	SListNode *cur, *prev;
	cur = *pplist,prev = NULL;
	if (cur == NULL || cur->next == NULL)
	{
		free(cur);
		*pplist = NULL;
	}
	else
	{
		while (cur->next != NULL)
		{
			prev = cur;
			cur = cur->next;
		}
		free(cur);
		cur = NULL;
		prev->next = NULL;
	}
	
}

// 单链表的头插
void SListPushFront(SListNode** pplist, SLTDateType x)
{
	SListNode *newnode = BuySListNode(x);
	//SListNode *cur = *pplist;
	//if (cur == NULL)
	if (*pplist == NULL)
	{
		//cur = newnode;
		*pplist = newnode;
	}
	else
	{
		//newnode->next = cur->next;
		//cur = newnode;
		newnode->next = *pplist;//将 *pplist 指向的链表赋给 newNode 的下一个指向
		*pplist = newnode;//再将 newnode 赋给*pplist,从而实现头插
	}
}

// 单链表头删
void SListPopFront(SListNode** pplist)
{
	assert(*pplist);
	SListNode *cur = *pplist;
	if (cur->next == NULL)
	{
		free(cur);
		cur = NULL;
		*pplist = NULL;
	}
	else
	{
		SListNode *next = cur->next;
		free(cur);
		cur = NULL;
		*pplist = next;
	}
}

// 单链表查找
SListNode* SListFind(SListNode* plist, SLTDateType x)
{
	if (plist == NULL || plist->next == NULL)
		return NULL;
	SListNode *cur = plist;
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

// 单链表在pos位置之后插入x
// 分析思考为什么不在pos位置之前插入？
void SListInsertAfter(SListNode* pos, SLTDateType x)
{
	assert(pos == NULL);
	SListNode *newnode = BuySListNode(x);
	SListNode *next = pos->next;
	pos->next = newnode;
	newnode->next = next;
	
}

// 单链表删除pos位置之后的值
// 分析思考为什么不删除pos位置？
void SListEraseAfter(SListNode* pos)
{
	assert(pos == NULL || pos->next == NULL);
	SListNode *next = pos->next;
	SListNode *nextnext = next->next;
	free(next);
	next = NULL;
	pos->next = nextnext;
}

// 单链表的销毁
void SListDestory(SListNode* plist)
{
	assert(plist == NULL || plist->next == NULL);
	SListNode *cur = plist;
	SListNode *next = NULL;
	while (cur)
	{
		next = cur->next;
		free(cur);
		cur = next;
	}
	plist = NULL;
}

void test()
{
	SListNode *lst;
	//lst->next = NULL;
	//SListInit(lst);
	SListPushBack(&lst, 5);
	//SListPrint(lst);
}


int main()
{
	test();

	system("pause");
	return 0;
}