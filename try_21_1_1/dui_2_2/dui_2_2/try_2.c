#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef int HDataType;
typedef struct heap
{
	HDataType *_data;
	int _size;
	int _capacity;
}heap;

void Swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

//�ѵĳ�ʼ��
void heapInit(heap *hp)
{
	if (hp == NULL)
		return;
	hp->_data = NULL;
	hp->_size = hp->_capacity = 0;
}

//���Ƿ�Ϊ��
int heapEmpty(heap *hp)
{
	if (hp == NULL || hp->_size == 0)
		return 1;
	else
		return 0;
}

/*���µ���  С�� */
//void shiftDown(int *arr, int n, int curPos)
//{
//	//printf("%d ", arr[1]);
//	//����
//	int child = 2 * curPos + 1;
//	while (child < n)
//	{
//		//�����Һ������ҵ�һ����Сֵ��λ��
//		if (((child + 1) < n) && (arr[child + 1] < arr[child]))
//			++child;//���Һ��ӽ��н���
//		//��Ҫ���������ݺ���Сֵ���бȽϣ���С����Сֵ������Ҫ��������֮��Ҫ����
//		if (arr[child] < arr[curPos])
//		{
//			int t = arr[curPos];
//			arr[curPos] = arr[child];
//			arr[child] = t;
//
//			//���µ�ǰλ��
//			curPos = child;
//			child = 2 * curPos + 1;
//		}
//		else
//			break;
//	}
//
//}

/*���   �ó������һ������*/
void shiftDown(int *arr, int n, int curPos)
{
	//printf("%d ", arr[1]);
	//����
	int child = 2 * curPos + 1;
	while (child < n)
	{
		//�����Һ������ҵ�һ����Сֵ��λ��
		if (((child + 1) < n) && (arr[child + 1] > arr[child]))
			++child;//���Һ��ӽ��н���
		//��Ҫ���������ݺ���Сֵ���бȽϣ���С����Сֵ������Ҫ��������֮��Ҫ����
		if (arr[child] > arr[curPos])
		{
			int t = arr[curPos];
			arr[curPos] = arr[child];
			arr[child] = t;

			//���µ�ǰλ��
			curPos = child;
			child = 2 * curPos + 1;
		}
		else
			break;
			
	}

}

/*���ϵ���  С��*/
//void shiftUp(int *arr, int n, int curPos)
//{
//	//���ڵ�λ��
//	int parent = (curPos - 1) / 2;
//	while (curPos > 0)
//	{
//		//�Ƚϵ�ǰλ�ú͸��ڵ�
//		if (arr[curPos] < arr[parent])
//		{
//			int t = arr[curPos];
//			arr[curPos] = arr[parent];
//			arr[parent] = t;
//
//			//���������󣬸��µ�ǰλ�ã�����������
//			curPos = parent;
//			parent = (curPos - 1) / 2;
//		}
//		else
//			break;//��������
//	}
//
//
//}

/* ���  */
void shiftUp(int *arr, int n, int curPos)
{
	//���ڵ�λ��
	int parent = (curPos - 1) / 2;
	while (curPos > 0)
	{
		//�Ƚϵ�ǰλ�ú͸��ڵ�
		if (arr[curPos] > arr[parent])
		{
			int t = arr[curPos];
			arr[curPos] = arr[parent];
			arr[parent] = t;

			//���������󣬸��µ�ǰλ�ã�����������
			curPos = parent;
			parent = (curPos - 1) / 2;
		}
		else
			break;//��������
	}

}

void checkCapacity(heap *hp)
{
	if (hp->_size == hp->_capacity)
	{
		hp->_capacity = hp->_capacity == 0 ? 1 : 2 * hp->_capacity;
		hp->_data = (HDataType*)realloc(hp->_data, sizeof(HDataType)*hp->_capacity);
	}
}

//�ѵĲ���
void heapPush(heap *hp, HDataType val)
{
	//�������
	checkCapacity(hp);
	//β��
	hp->_data[hp->_size++] = val;
	//���ϵ���  �����һ��λ�ÿ�ʼ����   ��0��ʼ����
	shiftUp(hp->_data, hp->_size, hp->_size - 1);
	
	//hp->_data[hp->_size] = val;
	//shiftUp(hp->_data, hp->_size+1, hp->_size);
	//hp->_size++;
}

//�ѵ�ɾ����ɾ���Ѷ�Ԫ��  ��β������ɾ��ԭ�Ѷ����ֶ�β��Ԫ�أ�Ȼ�����µ���
void heapPop(heap *hp)
{
	if (hp == NULL || hp->_size == 0)
		return;
	//��β��������
	Swap(&hp->_data[0], &hp->_data[hp->_size - 1]);
	//βɾ
	hp->_size--;
	//���µ���
	shiftDown(hp->_data, hp->_size, 0);
}

//��ȡ�Ѷ�Ԫ��
HDataType heapTop(heap *hp)
{
	return hp->_data[0];
}

//����
void creatHeap(int *arr, int n)
{
	//�����һ����Ҷ�ӽڵ�������µ���
	for (int i = (n - 2) / 2; i >= 0; --i)
	{
		shiftDown(arr, n, i);
	}
}

void PrintTopK(int *a, int n, int k)
{
	heap hp;
	heapInit(&hp);
	for (int i = 0; i < n; i++)
	{
		heapPush(&hp, a[i]);
	}
	while (k--)
	{
		printf("%d ", heapTop(&hp));
		heapPop(&hp);
	}
	printf("\n");
}
void test()
{
	int n = 10000;
	int *a = (int *)malloc(sizeof(int)*n);
	srand(time(0));
	for (size_t i = 0; i < n; i++)
	{
		a[i] = rand() % 1000000;
	}
	a[5] = 1000000 + 1;
	a[1231] = 1000000 + 2;
	a[531] = 1000000 + 3;
	a[115] = 1000000 + 4;
	a[2333] = 1000000 + 5;
	a[5432] = 1000000 + 6;
	a[3] = 1000000 + 7;
	a[823] = 1000000 + 8;
	a[983] = 1000000 + 9;
	a[190] = 1000000 + 10;
	PrintTopK(a, n, 12);
}

//void test()
//{
//	heap hp;
//	heapInit(&hp);
//	heapPush(&hp, 28);
//	heapPush(&hp, 29);
//	heapPush(&hp, 45);
//	heapPush(&hp, 46);
//	heapPush(&hp, 25);
//	heapPush(&hp, 23);
//	heapPush(&hp, 19);
//
//	heapPop(&hp);
//	heapPop(&hp);
//	while (!heapEmpty(&hp))
//	{
//		printf("%d ", heapTop(&hp));
//		heapPop(&hp);
//	}
//	printf("\n");
//}

//void test()
//{
//	//int arr[6] = { 10, 5, 3, 8, 7, 6 };
//	//shiftDown(arr, sizeof(arr) / sizeof(arr[0]), 0);
//	int arr[] = { 100, 20, 3, 6, 89, 12, 15, 36, 25 };
//	creatHeap(arr, sizeof(arr) / sizeof(arr[0]));
//}

int main()
{
	test();

	system("pause");
	return 0;
}