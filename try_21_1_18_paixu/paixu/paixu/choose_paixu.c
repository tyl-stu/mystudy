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
//ѡ������ ֮ ֱ��ѡ������ ʵ�ַ���һ
void selectSort(int *arr, int n)
{
	//�˷�����ԣ�ֻ��Щ����鷳
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

	//�˷������
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
		//����Сֵ�浽�ʼ��λ��
		swap(arr, start, min);
		//ʣ���δ��������� [start + 1,end]
		++start;
	}
	
}
//ѡ������ ֮ ֱ��ѡ������ ʵ�ַ�����
void selectSort2(int *arr, int n)
{
	int start = 0; 
	int end = n - 1;
	//ÿ�δ�δ����������ҵ�һ�����ֵ��һ����Сֵ
	//��Сֵ����ͷ�������ֵ��β��
	//�����Ĵ�������һ��
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
		//��Сֵ����ͷ��
		swap(arr, start, minIdx);
		//�ж����ֵ��λ���Ƿ�����ʼλ��
		if (maxIdx == start)
			maxIdx = minIdx;
		//���ֵ����β��
		swap(arr, end, maxIdx);

		++start;
		--end;
	}


}


//ѡ������ ֮ ������
/*���   �ó������һ������*/
void shiftDown(int *arr, int n, int curPos)
{
	//printf("%d ", arr[1]);
	//����
	int child = 2 * curPos + 1;
	while (child < n)
	{
		//�����Һ������ҵ�һ�����ֵ��λ��
		if (((child + 1) < n) && (arr[child + 1] > arr[child]))
			++child;//���Һ��ӽ��н���
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
void heapSort(int *arr, int n)
{
	//�����һ����Ҷ�ӽڵ㿪ʼ
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


//��ӡ����
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
//	printf("��������\n");
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
//	printf("ֱ�Ӳ�������ʱ�䣺%d\n", end - begin);
//
//	begin = clock();
//	shellSort(copy2, n);
//	end = clock();
//	printf("ϣ������ʱ�䣺%d\n", end - begin);
//}
int main()
{
	test();

	system("pause");
	return 0;
}
