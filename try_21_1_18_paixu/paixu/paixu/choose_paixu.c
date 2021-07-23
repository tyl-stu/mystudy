#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

void swap(int *arr,int a,int b)
{
	int t = arr[a];
	arr[a] = arr[b];
	arr[b] = t;
}
//选择排序 之 直接选择排序 实现方法一
void selectSort(int *arr, int n)
{
	//此法亦可以，只是些许的麻烦
	/*int begin = 0;
	while (begin < n)
	{
		int min = begin;
		int i;
		for (i = begin; i < n; i++)
		{
			if (arr[i] < arr[min])
			{
				min = i;
			}
		}
		int t = arr[begin];
		arr[begin] = arr[min];
		arr[min] = t;
		begin++;
	}*/

	//此法亦可以
	int start = 0;
	int end = n - 1;
	while (start < end)
	{
		int min = start;
		int i;
		for (i = start + 1; i <= end; i++)
		{
			if (arr[i] < arr[min])
			{
				min = i;
			}
		}
		//吧最小值存到最开始的位置
		swap(arr, start, min);
		//剩余的未排序的区间 [start + 1,end]
		++start;
	}
	
}
//选择排序 之 直接选择排序 实现方法二
void selectSort2(int *arr, int n)
{
	int start = 0; 
	int end = n - 1;
	//每次从未排序的区间找到一个最大值和一个最小值
	//最小值放在头部，最大值放尾部
	//遍历的次数减少一半
	while (start < end)
	{
		int minIdx = start;
		int maxIdx = start;
		for (int j = start + 1; j <= end; j++)
		{
			if (arr[j] < arr[minIdx])
				minIdx = j;
			if (arr[j] > arr[maxIdx])
				maxIdx = j;
		}
		//最小值放在头部
		swap(arr, start, minIdx);
		//判断最大值的位置是否在起始位置
		if (maxIdx == start)
			maxIdx = minIdx;
		//最大值放在尾部
		swap(arr, end, maxIdx);

		++start;
		--end;
	}


}


//选择排序 之 堆排序
/*大堆   该程序存在一定问题*/
void shiftDown(int *arr, int n, int curPos)
{
	//printf("%d ", arr[1]);
	//左孩子
	int child = 2 * curPos + 1;
	while (child < n)
	{
		//从左右孩子中找到一个最大值的位置
		if (((child + 1) < n) && (arr[child + 1] > arr[child]))
			++child;//和右孩子进行交换
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
void heapSort(int *arr, int n)
{
	//从最后一个非叶子节点开始
	for (int i = (n - 2) / 2; i >= 0; --i)
	{
		shiftDown(arr, n, i);
	}
	int end = n - 1;
	while (end > 0)
	{
		swap(arr, end, 0);
		shiftDown(arr, end, 0);
		--end;
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
	selectSort2(arr, n);
	printArr(arr, n);
	heapSort(arr, n);
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
