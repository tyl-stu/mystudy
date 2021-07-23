#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include"seqList.h"
#include"queue.h"

void swap(int *arr, int a, int b)
{
	int t = arr[a];
	arr[a] = arr[b];
	arr[b] = t;
}
//交换排序 之 冒泡排序 实现方法
void bubbleSort(int *arr, int n)
{
	//相邻元素进行比较
	//第一次遍历范围：0~未排序数据的最后一个位置
	int m = n; 
	while (m>1)//正常情况每次循环所运行步数 6 5 4 3 2 1 = 21
	{
		//flag:标记一轮冒泡排序中是否发生了交换操作
		int flag = 0;
		for (int j = 1; j < m; j++)
		{
			if (arr[j-1] > arr[j])
			{
				swap(arr, j-1, j);
				flag = 1;
			}
		}
		//如果没有发生交换，说明剩余元素全部有序 -- 提高性能
		if (!flag)
			break;
		m--;
	}
	
	/*for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			if (arr[j - 1] > arr[j])
			{
				swap(arr, j - 1, j);
			}
			h++;
		}
	}
	printf("h = %d \n", h);*/
}

//hoare改进：获取基准值：三数取中法  起始，中间，结束
int getMid(int *arr, int begin, int end)
{
	int mid = begin + (end - begin) / 2;
	if (arr[begin] > arr[mid])
	{
		if (arr[mid] > arr[end])  // arr[begin]>arr[mid]>arr[end]
			return mid;
		else if (arr[begin] > arr[end])//arr[begin]>arr[end]>arr[mid]
			return end;
		else  // arr[end]>arr[begin]>arr[mid]
			return begin;
	}
	else//arr[begin] < arr[mid]
	{
		if (arr[mid] < arr[end])//arr[begin] < arr[mid] <arr[end]
			return mid;
		else if (arr[begin] < arr[end])//arr[begin]<arr[end]<arr[mid]
			return end;
		else //arr[end]<arr[begin]<arr[mid]
			return begin;
	}
}

//交换排序 之 挖坑法
int partion2(int *arr, int begin, int end)
{
	//获取基准值的位置
	int mid = getMid(arr, begin, end);
	//把基准值放到起始位置
	swap(arr, begin, mid);
	//第一个值作为基准值，第一个位置为初始的坑的位置
	int key = arr[begin];
	//int start = begin;
	while (begin < end)
	{
		//int key = start;
		//从后往前先找小于基准值的位置
		while (begin < end && arr[end] >= key)
			--end;
		//填坑
		arr[begin] = arr[end];

		//从前往后找大于基准值的位置
		while (begin < end && arr[begin] <= key)
			++begin;
		//填坑
		arr[end] = arr[begin];
	}
	//相遇位置放入基准值
	arr[begin] = key;
	return begin;
}

//交换排序 之 前后指针法
int partion3(int *arr, int begin, int end)
{
	//上一个小于基准值的位置
	int prev = begin;
	//下一个小于基准值的位置
	int cur = begin + 1;
	int key = arr[begin];
	while (cur <= end)
	{
		//当prev与cur不连续时，则交换此两个数,首先判断连续
		if (arr[cur] < key && ++prev != cur)//不连续
		{
			//不连续，交换两数数据
			swap(arr, prev, cur);
		}
		++cur;
	}
	//交换基准值与prev的值
	swap(arr, begin, prev);
	return prev;
}

//交换排序 之 快速排序：hoare法
//返回划分之后，基准值所在的位置
int partion(int *arr, int begin, int end)
{
	//获取基准值的位置
	int mid = getMid(arr, begin, end);
	//把基准值放到起始位置
	swap(arr, begin, mid);  
	//选择基准值
	int key = arr[begin];
	int start = begin;
	while (begin < end)
	{
		//从后往前先找小于基准值的位置
		while (begin < end && arr[end] >= key)
			--end;
		//从前往后找大于基准值的位置
		while (begin < end && arr[begin] <= key)
			++begin;
		//交换
		swap(arr, begin, end);
	}
	//结束后交换基准值和相遇位置的数据
	swap(arr, start, begin);
	return begin;
}

//递归快排
void quickSort(int *arr, int begin, int end)//hoare 的实现
{
	if (begin >= end)
		return;
	//div:一次划分之后，基准值位置
	int div = partion3(arr, begin, end);
	//左右两部分进行快速排序
	//[begin,div-1]
	//[div+1,end]
	quickSort(arr, begin, div - 1);
	quickSort(arr, div + 1, end);
	
}

/*非递归快排   用顺序表   */
//void quickSortNor(int *arr, int n)
//{
//	//创建一个顺序表，保存待划分的区间
//	SeqList sq;
//	initseqList(&sq);
//	//首先保存整个区间   
//	//首先放右，再放左
//	seqListPushBack(&sq, n - 1);
//	seqListPushBack(&sq, 0);
//	//遍历顺序表，处理所有区间
//	while (!seqListEmpty(&sq))//非空才能进行程序运行！！！！！！！！！！！
//	{
//		//取出一个区间
//		int left = seqListBack(&sq);
//		seqListPopBack(&sq);
//		int right = seqListBack(&sq);
//		seqListPopBack(&sq);
//
//		//划分区间[left,right]
//		int div = partion(arr, left, right);
//
//		//保存产生的两个新区间
//		//[left,div-1]
//		if (left < div - 1)
//		{
//			seqListPushBack(&sq, div - 1);
//			seqListPushBack(&sq, left);
//		}
//		//[div+1,right]
//		if (div + 1 < right)
//		{
//			seqListPushBack(&sq, right);
//			seqListPushBack(&sq, div + 1);
//		}
//	}
//}
/*非递归快排   用队列     */
void quickSortNor2(int *arr, int n)
{
	//创建一个队列，保存待划分的区间
	Queue q;
	initQueue(&q);

	//首先保存整个区间  队列：先进先出 
	//首先放右，再放左
	queuePush(&q, 0);
	queuePush(&q, n - 1);
	
	//遍历队列，处理所有区间
	while (!queueEmpty(&q))//非空才能进行程序运行！！！！！！！！！！！
	{
		//取出一个区间
		int left = queueFront(&q);
		queuePop(&q);
		int right = queueFront(&q);
		queuePop(&q);

		//划分区间[left,right]
		int div = partion(arr, left, right);

		//保存产生的两个新区间
		//[left,div-1]
		if (left < div - 1)
		{
			queuePush(&q, left);
			queuePush(&q, div - 1);
		}
		//[div+1,right]
		if (div + 1 < right)
		{
			queuePush(&q, div + 1);
			queuePush(&q, right);
		}
	}
}



//打印数组
void printArr(int *arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}printf("\n");
}

void test()
{
	int arr[] = { 6, 3, 1, 8, 7, 2, 4 };
	int n = sizeof(arr) / sizeof(arr[0]);
	printArr(arr, n);
	bubbleSort(arr, n);
	printArr(arr, n);
	quickSort(arr, 0, n - 1);
	printArr(arr, n);
	quickSortNor2(arr, 0, n - 1);
	printArr(arr, n);
}

//void test2()
//{
//	int n;
//	printf("数据量：\n");
//	scanf_s("%d", &n);
//	srand(time(NULL));
//	int *arr = (int *)malloc(sizeof(int)*n);
//	int *copy1 = (int *)malloc(sizeof(int)*n);
//	int *copy2 = (int *)malloc(sizeof(int)*n);
//	for (int i = 0; i < n; i++)
//	{
//		arr[i] = rand();
//	}
//	memcpy(copy1, arr, sizeof(int)*n);
//	memcpy(copy2, arr, sizeof(int)*n);
//
//	time_t begin = clock();
//	insert(copy1, n);
//	time_t end = clock();
//	printf("直接插入排序时间：%d\n", end - begin);
//
//	begin = clock();
//	shellSort(copy2, n);
//	end = clock();
//	printf("希尔排序时间：%d\n", end - begin);
//}
int main()
{
	test();

	system("pause");
	return 0;
}
