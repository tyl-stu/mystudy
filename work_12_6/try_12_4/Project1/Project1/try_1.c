#include"SeqList.h"
#include<string.h>


void SeqListInit(SeqList *ps)    //顺序表的初始化
{
	assert(ps != NULL);
	ps->nums = NULL;
	ps->size = 0;
	ps->capacity = 0;
}


void SeqListCheckCapacity(SeqList *ps)   //检查顺序表的空间
{
	if (ps->size == ps->capacity)
	{
		//空间已满，或空间为空时，为其开辟空间
		int newCapa = ps->capacity == 0 ? 1 : 2 * ps->capacity;
		ps->nums = (SLDateType *)realloc(ps->nums, newCapa*sizeof(SLDateType));
		ps->capacity = newCapa;

	}
}


void SeqListPrint(SeqList *ps)//打印顺序表中内容
{
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->nums[i]);
	}
	printf("\n");
}


void SeqListElement(SeqList *ps, int pos)//查看pos位置的数据
{
	assert(ps != NULL);
	if (pos >ps->size)
	{
		printf("没有这个数！\n");
	}
	else
	{
		printf("数组中第 %d 个数的值为：%d \n", pos, ps->nums[pos - 1]);
	}


}


void seqListPushBack(SeqList *ps, SLDateType val)//尾插函数
{
	//assert(ps!=NULL);
	////检查容量
	//seqListCheckCapacity(ps);
	////实现尾插
	//ps->nums[ps->size] = val;
	//ps->size++;
	SeqListInsert(ps, ps->size, val);
}


void SeqListPopBack(SeqList *ps)//尾删函数
{
	assert(ps != NULL);
	if (ps->size > 0)
		ps->size--;
}


void SeqListPushFront(SeqList *ps, SLDateType val)//头插函数
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


void SeqListPopFront(SeqList *ps)//头删函数
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


int SeqListEmpty(SeqList *ps)//判断数组是否为空
{
	if (ps == NULL && ps->size == 0)
		return 0;   //返回0代表为空
	else
		return 1;   //返回1代表该数组有值
}


int SeqListSize(SeqList *ps)//求得数组中数的个数
{
	if (ps == NULL)
		return 0;
	else
		return ps->size;
}


int SeqListFind(SeqList *ps, SLDateType x)//在数组中找寻 val 数的位置
{
	assert(ps != NULL);
	int pos = 0;
	while (pos < ps->size)
	{
		//if (x^ps->nums[pos] == 0)
		if (x == ps->nums[pos])
		{
			//printf("%d 在该数组的第 %d 个位置\n", x, pos + 1);
			return pos + 1;
			break;
		}
		pos++;
	}
	if (pos >= ps->size)
	{
		//printf("该数组中没有这个数\n");
		return 0;
	}

}


void SeqListInsert(SeqList *ps, int pos, SLDateType val)//在任意位置插数函数
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


void SeqListErase(SeqList *ps, int pos)//擦除pos索引上的数值
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


void SeqListDestory(SeqList *ps)//销毁这个数组内容
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
	SeqListElement(&s1, 2); // 数组中第二个数是 2
	SeqListPrint(&s1);// 1 2 8 3 5 4 6 9
	SeqListFind(&s1, 4);//4的位置是6
	SeqListPrint(&s1);// 1 2 8 3 5 4 6 9
	SeqListErase(&s1, 3);//去掉第三个位置的数
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
	SeqListElement(&s1, 2);//数组中第二个数是 5 
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