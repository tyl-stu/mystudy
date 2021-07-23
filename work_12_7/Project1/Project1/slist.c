#include"slist.h"

//�����ڵ�
SListNode* BuySListNode(SLTDateType x)
{
	struct SListNode * node = (SListNode *)malloc(sizeof(SListNode));
	node->data = x;
	node->next = NULL;
	return node;
}

//��ʼ������
void SListInit(SListNode *plist)
{
	//assert(plist == NULL);
	plist->next = NULL;	
}

// �������ӡ
void SListPrint(SListNode* plist)
{
	assert(plist == NULL);
	
	struct SListNode *cur = plist;
	printf("�����е���ֵΪ��");
	while (cur)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
	
}

// ������β�� *pplist ָ����ǽڵ�
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

// �������βɾ
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

// �������ͷ��
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
		newnode->next = *pplist;//�� *pplist ָ��������� newNode ����һ��ָ��
		*pplist = newnode;//�ٽ� newnode ����*pplist,�Ӷ�ʵ��ͷ��
	}
}

// ������ͷɾ
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

// ���������
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

// ��������posλ��֮�����x
// ����˼��Ϊʲô����posλ��֮ǰ���룿
void SListInsertAfter(SListNode* pos, SLTDateType x)
{
	assert(pos == NULL);
	SListNode *newnode = BuySListNode(x);
	SListNode *next = pos->next;
	pos->next = newnode;
	newnode->next = next;
	
}

// ������ɾ��posλ��֮���ֵ
// ����˼��Ϊʲô��ɾ��posλ�ã�
void SListEraseAfter(SListNode* pos)
{
	assert(pos == NULL || pos->next == NULL);
	SListNode *next = pos->next;
	SListNode *nextnext = next->next;
	free(next);
	next = NULL;
	pos->next = nextnext;
}

// �����������
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