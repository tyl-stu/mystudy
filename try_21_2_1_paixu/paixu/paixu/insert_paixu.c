#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

//ֱ�Ӳ�������
void insert(int *arr, int n)
{
	//�����һ����������
	//δ��������ݣ�(1,n)
	for (int i = 1; i < n; i++)
	{
		//���������ݵ����һ��λ����ǰ����
		int end = i - 1;
		int data = arr[i];
		while (end >= 0 && arr[end] >= data)//arr[end] >= data ���ȶ��� arr[end] > data �ȶ�
		{
			//�����������ƶ�
			arr[end + 1] = arr[end];
			--end;
		}
		arr[end + 1] = data;//��arr[0]����ֵ
	}
}

//ϣ����������
void shellSort(int *arr, int n)
{
	int gap = n;//gap Ϊ n����Ὣarr��Ϊn��
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		//���һ�����򣬼������Ϊ1����֤�������ݶ���ͬһ��
		//һ��ϣ������
		for (int i = gap; i < n; i++)
		{
			//ͬһ������,���һ���������ݵ�λ��
			int end = i - gap;
			//�����������
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
	insert(arr, n);
	printArr(arr, n);
	shellSort(arr, n);
	printArr(arr, n);
}

void test2()
{
	int n;
	printf("��������\n");
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
	printf("ֱ�Ӳ�������ʱ�䣺%d\n", end - begin);

	begin = clock();
	shellSort(copy2, n);
	end = clock();
	printf("ϣ������ʱ�䣺%d\n", end - begin);
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