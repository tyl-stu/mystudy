#include"seqList.h"

void initseqList(SeqList *s1)    //˳���ĳ�ʼ��
{
	/*if (s1 == NULL)
		return;*/
	assert(s1 != NULL);
	s1->nums = NULL;
	s1->size = 0;
	s1->capacity = 0;
}

void seqListCheckCapacity(SeqList *s1)   //���˳���Ŀռ�
{
	if (s1->size == s1->capacity)
	{
		//�ռ���������ռ�Ϊ��ʱ��Ϊ�俪�ٿռ�
		//1�������µĿռ�
		int newCapa = s1->capacity == 0 ? 1 : 2 * s1->capacity;
		//SLDataType *t = (SLDataType *)malloc(newCapa*sizeof(SLDataType));
		//2������
		//memcpy(t, s1->nums, sizeof(SLDataType)*s1->size);
		////3���ͷ�ԭ�пռ�
		//free(s1->nums);
		s1->nums = (SLDataType *)realloc(s1->nums, newCapa*sizeof(SLDataType));

		//4����������
		s1->capacity = newCapa;
		//s1->nums = t;

	}
}

void seqListPrint(SeqList *s1)//��ӡ˳���������
{
	for (int i = 0; i < s1->size; i++)
	{
		printf("%d ", s1->nums[i]);
	}
	printf("\n");
}

void seqListElement(SeqList *s1, int pos)//�鿴posλ�õ�����
{
	/*if (s1 == NULL)
		return;*/
	assert(s1 != NULL);
	if (pos >s1->size)
	{
		printf("û���������\n");
	}
	else
	{
		printf("�����е� %d ������ֵΪ��%d \n", pos, s1->nums[pos - 1]);
	}

}

void seqListPushBack(SeqList *s1, SLDataType val)//β�庯��
{
	//if (s1 == NULL)
	//	return;
	////�������
	//seqListCheckCapacity(s1);
	////ʵ��β��
	//s1->nums[s1->size] = val;
	//s1->size++;
	seqListInsert(s1, s1->size, val);
}

void seqListPopBack(SeqList *s1)//βɾ����
{
	/*if (s1 == NULL)
		return;*/
	assert(s1 != NULL);
	if (s1->size > 0)
		s1->size--;
}

void seqListPushFront(SeqList *s1, SLDataType val)//ͷ�庯��
{
	/*if (s1 == NULL)
		return;
	seqListCheckCapacity(s1);
	int end = s1->size;
	while (end > 0)
	{
		s1->nums[end] = s1->nums[end - 1];
		end--;
	}
	s1->nums[0] = val;
	s1->size++;*/
	seqListInsert(s1, 0, val);
}

void seqListPopFront(SeqList *s1)//ͷɾ����
{
	/*if (s1 == NULL)
		return;*/
	assert(s1 != NULL);
	int start = 1;
	while (start < s1->size)
	{
		s1->nums[start - 1] = s1->nums[start];
		start++;
	}
	s1->size--;
}

int seqListEmpty(SeqList *s1)//�ж������Ƿ�Ϊ��
{
	if (s1 == NULL && s1->size == 0)
		return 0;   //����0����Ϊ��
	else
		return 1;   //����1�����������ֵ
}

int seqListSize(SeqList *s1)//������������ĸ���
{
	if (s1 == NULL)
		return 0;
	else
		return s1->size;
}

void seqListFind(SeqList *s1, SLDataType val)//����������Ѱ val ����λ��
{
	/*if (s1 == NULL)
		return;*/
	assert(s1 != NULL);
	int pos = 0;
	while (pos < s1->size)
	{
		//if (val^s1->nums[pos] == 0)
		if (val == s1->nums[pos])
		{
			printf("%d �ڸ�����ĵ� %d ��λ��\n", val, pos+1);
			break;
		}
		pos++;
	}
	if (pos >= s1->size)
	{
		printf("��������û�������\n");
	}
	
}

void seqListInsert(SeqList *s1, int pos, SLDataType val)//������λ�ò�������
{
	/*if (s1 == NULL)
		return;*/
	assert(s1 != NULL);
	if (pos >= 0 && pos <= s1->size)
	{
		seqListCheckCapacity(s1);
		int end = s1->size;
		while (end > pos)
		{
			s1->nums[end] = s1->nums[end - 1];
			end--;
		}
		s1->nums[pos] = val;
		s1->size++;
	}
}

void seqListErase(SeqList *s1, int pos)//����pos�����ϵ���ֵ
{
	/*if (s1 == NULL)
		return;*/
	assert(s1 != NULL);
	if (pos >= 0 && pos <= s1->size)
	{
		int start = pos + 1;
		while (start < s1->size)
		{
			s1->nums[start - 1] = s1->nums[start];
			start++;
		}
		s1->size--;
	}
	
}

void seqListDestory(SeqList *s1)//���������������
{
	/*if (s1 == NULL)
		return;*/
	assert(s1 != NULL);
	free(s1->nums);
	s1->nums = NULL;
	s1->size = 0;
}

void test()
{
	SeqList s1;
	initseqList(&s1);
	//seqListCheckCapacity(&s1);
	seqListPushBack(&s1, 5);
	seqListPushBack(&s1, 4);
	seqListPushBack(&s1, 6);
	seqListPushFront(&s1, 3);
	seqListPushFront(&s1, 2);//2 3 5 4 6
	seqListInsert(&s1, 0, 1);//1 2 3 5 4 6
	seqListInsert(&s1, 2, 8);//1 2 8 3 5 4 6
	seqListInsert(&s1, 7, 9);//1 2 8 3 5 4 6 9
	printf("size = %d\n", s1.size);//8

	

	seqListPrint(&s1); // 1 2 8 3 5 4 6 9
	seqListElement(&s1,2); // �����еڶ������� 2
	seqListPrint(&s1);// 1 2 8 3 5 4 6 9
	seqListFind(&s1, 4);//4��λ����6
	seqListPrint(&s1);// 1 2 8 3 5 4 6 9
	seqListErase(&s1, 3);//ȥ��������λ�õ���
	seqListPrint(&s1);//// 1 2 8 5 4 6 9
	//seqListPrint(&s1);
	////seqListSize(&s1);

	seqListPopBack(&s1);//1 2 8  5 4 6 
	seqListPrint(&s1);
	seqListPopBack(&s1);//1 2 8  5 4 
	seqListPrint(&s1);
	seqListPopFront(&s1);//  2 8  5 4 
	seqListPrint(&s1);
	seqListPopFront(&s1);//   8 5 4 
	seqListPrint(&s1);
	seqListElement(&s1,2);//�����еڶ������� 5 
	//seqListSize(&s1);

	seqListDestory(&s1);
	seqListPrint(&s1);
}

int main()
{
	test();
	
	system("pause");
	return 0;
}