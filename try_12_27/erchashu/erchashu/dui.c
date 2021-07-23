#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//向下调整
//小堆
void shiftDown(int *arr, int n, int curPos)
{
	printf("%d ", arr[1]);
	//左孩子
	int child = 2 * curPos + 1;
	while (child < n)
	{
		//从左右孩子中找到一个最小值的位置
		if (((child + 1) < n) && (arr[child + 1] < arr[child]))
			++child;//和右孩子进行交换
		//需要调整的数据和最小值进行比较，若小于最小值，则不需要交换，反之需要交换
		if (arr[child] < arr[curPos])
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

void test()
{
	int arr[6] = { 10, 5, 3, 8, 7, 6 };
	shiftDown(arr, sizeof(arr)/sizeof(arr[0]), 0);
}

int main()
{
	test();

	system("pause");
	return 0;
}