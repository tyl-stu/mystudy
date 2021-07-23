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
//�������� ֮ ð������ ʵ�ַ���
void bubbleSort(int *arr, int n)
{
	//����Ԫ�ؽ��бȽ�
	//��һ�α�����Χ��0~δ�������ݵ����һ��λ��
	int m = n; 
	while (m>1)//�������ÿ��ѭ�������в��� 6 5 4 3 2 1 = 21
	{
		//flag:���һ��ð���������Ƿ����˽�������
		int flag = 0;
		for (int j = 1; j < m; j++)
		{
			if (arr[j-1] > arr[j])
			{
				swap(arr, j-1, j);
				flag = 1;
			}
		}
		//���û�з���������˵��ʣ��Ԫ��ȫ������ -- �������
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

//hoare�Ľ�����ȡ��׼ֵ������ȡ�з�  ��ʼ���м䣬����
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

//�������� ֮ �ڿӷ�
int partion2(int *arr, int begin, int end)
{
	//��ȡ��׼ֵ��λ��
	int mid = getMid(arr, begin, end);
	//�ѻ�׼ֵ�ŵ���ʼλ��
	swap(arr, begin, mid);
	//��һ��ֵ��Ϊ��׼ֵ����һ��λ��Ϊ��ʼ�Ŀӵ�λ��
	int key = arr[begin];
	//int start = begin;
	while (begin < end)
	{
		//int key = start;
		//�Ӻ���ǰ����С�ڻ�׼ֵ��λ��
		while (begin < end && arr[end] >= key)
			--end;
		//���
		arr[begin] = arr[end];

		//��ǰ�����Ҵ��ڻ�׼ֵ��λ��
		while (begin < end && arr[begin] <= key)
			++begin;
		//���
		arr[end] = arr[begin];
	}
	//����λ�÷����׼ֵ
	arr[begin] = key;
	return begin;
}

//�������� ֮ ǰ��ָ�뷨
int partion3(int *arr, int begin, int end)
{
	//��һ��С�ڻ�׼ֵ��λ��
	int prev = begin;
	//��һ��С�ڻ�׼ֵ��λ��
	int cur = begin + 1;
	int key = arr[begin];
	while (cur <= end)
	{
		//��prev��cur������ʱ���򽻻���������,�����ж�����
		if (arr[cur] < key && ++prev != cur)//������
		{
			//��������������������
			swap(arr, prev, cur);
		}
		++cur;
	}
	//������׼ֵ��prev��ֵ
	swap(arr, begin, prev);
	return prev;
}

//�������� ֮ ��������hoare��
//���ػ���֮�󣬻�׼ֵ���ڵ�λ��
int partion(int *arr, int begin, int end)
{
	//��ȡ��׼ֵ��λ��
	int mid = getMid(arr, begin, end);
	//�ѻ�׼ֵ�ŵ���ʼλ��
	swap(arr, begin, mid);  
	//ѡ���׼ֵ
	int key = arr[begin];
	int start = begin;
	while (begin < end)
	{
		//�Ӻ���ǰ����С�ڻ�׼ֵ��λ��
		while (begin < end && arr[end] >= key)
			--end;
		//��ǰ�����Ҵ��ڻ�׼ֵ��λ��
		while (begin < end && arr[begin] <= key)
			++begin;
		//����
		swap(arr, begin, end);
	}
	//�����󽻻���׼ֵ������λ�õ�����
	swap(arr, start, begin);
	return begin;
}

//�ݹ����
void quickSort(int *arr, int begin, int end)//hoare ��ʵ��
{
	if (begin >= end)
		return;
	//div:һ�λ���֮�󣬻�׼ֵλ��
	int div = partion3(arr, begin, end);
	//���������ֽ��п�������
	//[begin,div-1]
	//[div+1,end]
	quickSort(arr, begin, div - 1);
	quickSort(arr, div + 1, end);
	
}

/*�ǵݹ����   ��˳���   */
//void quickSortNor(int *arr, int n)
//{
//	//����һ��˳�����������ֵ�����
//	SeqList sq;
//	initseqList(&sq);
//	//���ȱ�����������   
//	//���ȷ��ң��ٷ���
//	seqListPushBack(&sq, n - 1);
//	seqListPushBack(&sq, 0);
//	//����˳���������������
//	while (!seqListEmpty(&sq))//�ǿղ��ܽ��г������У���������������������
//	{
//		//ȡ��һ������
//		int left = seqListBack(&sq);
//		seqListPopBack(&sq);
//		int right = seqListBack(&sq);
//		seqListPopBack(&sq);
//
//		//��������[left,right]
//		int div = partion(arr, left, right);
//
//		//�������������������
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
/*�ǵݹ����   �ö���     */
void quickSortNor2(int *arr, int n)
{
	//����һ�����У���������ֵ�����
	Queue q;
	initQueue(&q);

	//���ȱ�����������  ���У��Ƚ��ȳ� 
	//���ȷ��ң��ٷ���
	queuePush(&q, 0);
	queuePush(&q, n - 1);
	
	//�������У�������������
	while (!queueEmpty(&q))//�ǿղ��ܽ��г������У���������������������
	{
		//ȡ��һ������
		int left = queueFront(&q);
		queuePop(&q);
		int right = queueFront(&q);
		queuePop(&q);

		//��������[left,right]
		int div = partion(arr, left, right);

		//�������������������
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
