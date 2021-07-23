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

//堆的初始化
void heapInit(heap *hp)
{
	if (hp == NULL)
		return;
	hp->_data = NULL;
	hp->_size = hp->_capacity = 0;
}

//堆是否为空
int heapEmpty(heap *hp)
{
	if (hp == NULL || hp->_size == 0)
		return 1;
	else
		return 0;
}

/*向下调整  小堆 */
//void shiftDown(int *arr, int n, int curPos)
//{
//	//printf("%d ", arr[1]);
//	//左孩子
//	int child = 2 * curPos + 1;
//	while (child < n)
//	{
//		//从左右孩子中找到一个最小值的位置
//		if (((child + 1) < n) && (arr[child + 1] < arr[child]))
//			++child;//和右孩子进行交换
//		//需要调整的数据和最小值进行比较，若小于最小值，则不需要交换，反之需要交换
//		if (arr[child] < arr[curPos])
//		{
//			int t = arr[curPos];
//			arr[curPos] = arr[child];
//			arr[child] = t;
//
//			//更新当前位置
//			curPos = child;
//			child = 2 * curPos + 1;
//		}
//		else
//			break;
//	}
//
//}

/*大堆   该程序存在一定问题*/
void shiftDown(int *arr, int n, int curPos)
{
	//printf("%d ", arr[1]);
	//左孩子
	int child = 2 * curPos + 1;
	while (child < n)
	{
		//从左右孩子中找到一个最小值的位置
		if (((child + 1) < n) && (arr[child + 1] > arr[child]))
			++child;//和右孩子进行交换
		//需要调整的数据和最小值进行比较，若小于最小值，则不需要交换，反之需要交换
		if (arr[child] > arr[curPos])
		{
			int t = arr[curPos];
			arr[curPos] = arr[child];
			arr[child] = t;

			//更新当前位置
			curPos = child;
			child = 2 * curPos + 1;
		}
		else
			break;
			
	}

}

/*向上调整  小堆*/
//void shiftUp(int *arr, int n, int curPos)
//{
//	//父节点位置
//	int parent = (curPos - 1) / 2;
//	while (curPos > 0)
//	{
//		//比较当前位置和父节点
//		if (arr[curPos] < arr[parent])
//		{
//			int t = arr[curPos];
//			arr[curPos] = arr[parent];
//			arr[parent] = t;
//
//			//交换结束后，更新当前位置，继续往上走
//			curPos = parent;
//			parent = (curPos - 1) / 2;
//		}
//		else
//			break;//结束调整
//	}
//
//
//}

/* 大堆  */
void shiftUp(int *arr, int n, int curPos)
{
	//父节点位置
	int parent = (curPos - 1) / 2;
	while (curPos > 0)
	{
		//比较当前位置和父节点
		if (arr[curPos] > arr[parent])
		{
			int t = arr[curPos];
			arr[curPos] = arr[parent];
			arr[parent] = t;

			//交换结束后，更新当前位置，继续往上走
			curPos = parent;
			parent = (curPos - 1) / 2;
		}
		else
			break;//结束调整
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

//堆的插入
void heapPush(heap *hp, HDataType val)
{
	//检查容量
	checkCapacity(hp);
	//尾插
	hp->_data[hp->_size++] = val;
	//向上调整  从最后一个位置开始往上   从0开始计数
	shiftUp(hp->_data, hp->_size, hp->_size - 1);
	
	//hp->_data[hp->_size] = val;
	//shiftUp(hp->_data, hp->_size+1, hp->_size);
	//hp->_size++;
}

//堆的删除：删除堆顶元素  首尾交换，删除原堆顶（现堆尾）元素，然后向下调整
void heapPop(heap *hp)
{
	if (hp == NULL || hp->_size == 0)
		return;
	//首尾交换交换
	Swap(&hp->_data[0], &hp->_data[hp->_size - 1]);
	//尾删
	hp->_size--;
	//向下调整
	shiftDown(hp->_data, hp->_size, 0);
}

//获取堆顶元素
HDataType heapTop(heap *hp)
{
	return hp->_data[0];
}

//建堆
void creatHeap(int *arr, int n)
{
	//从最后一个非叶子节点进行向下调整
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