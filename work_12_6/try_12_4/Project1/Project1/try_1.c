#include"SeqList.h"
#include<string.h>


void SeqListInit(SeqList *ps)    //˳���ĳ�ʼ��
{
	assert(ps != NULL);
	ps->nums = NULL;
	ps->size = 0;
	ps->capacity = 0;
}


void SeqListCheckCapacity(SeqList *ps)   //���˳���Ŀռ�
{
	if (ps->size == ps->capacity)
	{
		//�ռ���������ռ�Ϊ��ʱ��Ϊ�俪�ٿռ�
		int newCapa = ps->capacity == 0 ? 1 : 2 * ps->capacity;
		ps->nums = (SLDateType *)realloc(ps->nums, newCapa*sizeof(SLDateType));
		ps->capacity = newCapa;

	}
}


void SeqListPrint(SeqList *ps)//��ӡ˳���������
{
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->nums[i]);
	}
	printf("\n");
}


void SeqListElement(SeqList *ps, int pos)//�鿴posλ�õ�����
{
	assert(ps != NULL);
	if (pos >ps->size)
	{
		printf("û���������\n");
	}
	else
	{
		printf("�����е� %d ������ֵΪ��%d \n", pos, ps->nums[pos - 1]);
	}


}


void seqListPushBack(SeqList *ps, SLDateType val)//β�庯��
{
	//assert(ps!=NULL);
	////�������
	//seqListCheckCapacity(ps);
	////ʵ��β��
	//ps->nums[ps->size] = val;
	//ps->size++;
	SeqListInsert(ps, ps->size, val);
}


void SeqListPopBack(SeqList *ps)//βɾ����
{
	assert(ps != NULL);
	if (ps->size > 0)
		ps->size--;
}


void SeqListPushFront(SeqList *ps, SLDateType val)//ͷ�庯��
{
	/*assert(ps!=NULL);
	seqListCheckCapacity(ps);
	int end = ps->size;
	while (end > 0)
	{
	ps->nums[end] = ps->nums[end - 1];
	end--;
	}
	ps->nums[0] = val;
	ps->size++;*/
	SeqListInsert(ps, 0, val);
}


void SeqListPopFront(SeqList *ps)//ͷɾ����
{

	assert(ps != NULL);
	int start = 1;
	while (start < ps->size)
	{
		ps->nums[start - 1] = ps->nums[start];
		start++;
	}
	ps->size--;
}


int SeqListEmpty(SeqList *ps)//�ж������Ƿ�Ϊ��
{
	if (ps == NULL && ps->size == 0)
		return 0;   //����0����Ϊ��
	else
		return 1;   //����1�����������ֵ
}


int SeqListSize(SeqList *ps)//������������ĸ���
{
	if (ps == NULL)
		return 0;
	else
		return ps->size;
}


int SeqListFind(SeqList *ps, SLDateType x)//����������Ѱ val ����λ��
{
	assert(ps != NULL);
	int pos = 0;
	while (pos < ps->size)
	{
		//if (x^ps->nums[pos] == 0)
		if (x == ps->nums[pos])
		{
			//printf("%d �ڸ�����ĵ� %d ��λ��\n", x, pos + 1);
			return pos + 1;
			break;
		}
		pos++;
	}
	if (pos >= ps->size)
	{
		//printf("��������û�������\n");
		return 0;
	}

}


void SeqListInsert(SeqList *ps, int pos, SLDateType val)//������λ�ò�������
{
	assert(ps != NULL);
	if (pos >= 0 && pos <= ps->size)
	{
		SeqListCheckCapacity(ps);
		int end = ps->size;
		while (end > pos)
		{
			ps->nums[end] = ps->nums[end - 1];
			end--;
		}
		ps->nums[pos] = val;
		ps->size++;
	}
}


void SeqListErase(SeqList *ps, int pos)//����pos�����ϵ���ֵ
{
	assert(ps != NULL);
	if (pos >= 0 && pos <= ps->size)
	{
		int start = pos + 1;
		while (start < ps->size)
		{
			ps->nums[start - 1] = ps->nums[start];
			start++;
		}
		ps->size--;
	}

}


void SeqListDestory(SeqList *ps)//���������������
{
	assert(ps != NULL);
	free(ps->nums);
	ps->nums = NULL;
	ps->size = 0;
}


void test()
{
	SeqList s1;
	SeqListInit(&s1);
	//seqListCheckCapacity(&s1);
	SeqListPushBack(&s1, 5);
	SeqListPushBack(&s1, 4);
	SeqListPushBack(&s1, 6);
	SeqListPushFront(&s1, 3);
	SeqListPushFront(&s1, 2);//2 3 5 4 6
	SeqListInsert(&s1, 0, 1);//1 2 3 5 4 6
	SeqListInsert(&s1, 2, 8);//1 2 8 3 5 4 6
	SeqListInsert(&s1, 7, 9);//1 2 8 3 5 4 6 9
	printf("size = %d\n", s1.size);//8


	SeqListPrint(&s1); // 1 2 8 3 5 4 6 9
	SeqListElement(&s1, 2); // �����еڶ������� 2
	SeqListPrint(&s1);// 1 2 8 3 5 4 6 9
	SeqListFind(&s1, 4);//4��λ����6
	SeqListPrint(&s1);// 1 2 8 3 5 4 6 9
	SeqListErase(&s1, 3);//ȥ��������λ�õ���
	SeqListPrint(&s1);//// 1 2 8 5 4 6 9
	//seqListPrint(&s1);
	////seqListSize(&s1);


	SeqListPopBack(&s1);//1 2 8  5 4 6 
	SeqListPrint(&s1);
	SeqListPopBack(&s1);//1 2 8  5 4 
	SeqListPrint(&s1);
	SeqListPopFront(&s1);//  2 8  5 4 
	SeqListPrint(&s1);
	SeqListPopFront(&s1);//   8 5 4 
	SeqListPrint(&s1);
	SeqListElement(&s1, 2);//�����еڶ������� 5 
	//seqListSize(&s1);


	SeqListDestory(&s1);
	SeqListPrint(&s1);
}


int main()
{
	test();

	system("pause");
	return 0;
}