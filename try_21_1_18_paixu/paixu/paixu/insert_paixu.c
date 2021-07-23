#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

//直接插入排序
void insert(int *arr, int n)
{
	//假设第一个数据有序
	//未插入的数据：(1,n)
	for (int i = 1; i < n; i++)
	{
		//从有序数据的最后一个位置向前遍历
		int end = i - 1;
		int data = arr[i];
		while (end >= 0 && arr[end] >= data)//arr[end] >= data 不稳定； arr[end] > data 稳定
		{
			//大的数据向后移动
			arr[end + 1] = arr[end];
			--end;
		}
		arr[end + 1] = data;//给arr[0]赋大值
	}
}

//希尔插入排序
void shellSort(int *arr, int n)
{
	int gap = n;//gap 为 n，其会将arr分为n组
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		//最后一趟排序，间隔必须为1，保证所有数据都在同一组
		//一趟希尔排序
		for (int i = gap; i < n; i++)
		{
			//同一组数据,最后一个有序数据的位置
			int end = i - gap;
			//待插入的数据
			int data = arr[i];
			while (end >= 0 && arr[end] > data)
			{
				arr[end + gap] = arr[end];
				end -= gap;
			}
			arr[end + gap] = data;
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
	insert(arr, n);
	printArr(arr, n);
	shellSort(arr, n);
	printArr(arr, n);
}

void test2()
{
	int n;
	printf("数据量：\n");
	scanf_s("%d", &n);
	srand(time(NULL));
	int *arr = (int *)malloc(sizeof(int)*n);
	int *copy1 = (int *)malloc(sizeof(int)*n);
	int *copy2 = (int *)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand();
	}
	memcpy(copy1, arr, sizeof(int)*n);
	memcpy(copy2, arr, sizeof(int)*n);

	time_t begin = clock();
	insert(copy1, n);
	time_t end = clock();
	printf("直接插入排序时间：%d\n", end - begin);

	begin = clock();
	shellSort(copy2, n);
	end = clock();
	printf("希尔排序时间：%d\n", end - begin);
}
int main()
{
	test2();

	system("pause");
	return 0;
}


/*

void test()
{
	int arr[] = { 6, 3, 1, 8, 7, 2, 4 };
	int n = sizeof(arr) / sizeof(arr[0]);
	insert(arr, n, 5);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
}

int main()
{
	test();

	system("pause");
	return 0;
}*/