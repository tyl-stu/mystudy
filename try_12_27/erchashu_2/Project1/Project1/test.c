
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//���µ���   
//С��
void shiftDown(int *arr, int n, int curPos)
{
	printf("%d ", arr[1]);
	//����
	int child = 2 * curPos + 1;
	while (child < n)
	{
		//�����Һ������ҵ�һ����Сֵ��λ��
		if (((child + 1) < n) && (arr[child + 1] < arr[child]))
			++child;//���Һ��ӽ��н���
		//��Ҫ���������ݺ���Сֵ���бȽϣ���С����Сֵ������Ҫ��������֮��Ҫ����
		if (arr[child] < arr[curPos])
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

/*���   �ó������һ������*/
//void shiftDown_2(int *arr, int n, int curPos)
//{
//	printf("%d ", arr[1]);
//	//����
//	int child = 2 * curPos + 1;
//	while (child < n)
//	{
//		//�����Һ������ҵ�һ����Сֵ��λ��
//		if (((child + 1) < n) && (arr[child + 1] > arr[child]))
//			++child;//���Һ��ӽ��н���
//		//��Ҫ���������ݺ���Сֵ���бȽϣ���С����Сֵ������Ҫ��������֮��Ҫ����
//		if (arr[child] > arr[curPos])
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
//		{
//			curPos = child;
//			child++;
//			//break;
//		}
//			
//	}
//
//}

//����
void creatHeap(int *arr, int n)
{
	//�����һ����Ҷ�ӽڵ�������µ���
	for (int i = (n - 2) / 2; i >= 0; --i)
	{
		shiftDown(arr, n, i);
	}
}

void test()
{
	//int arr[6] = { 10, 5, 3, 8, 7, 6 };
	//shiftDown(arr, sizeof(arr) / sizeof(arr[0]), 0);
	int arr[] = { 100, 20, 3, 6, 89, 12, 15, 36, 25 };
	creatHeap(arr, sizeof(arr) / sizeof(arr[0]));
}

int main()
{
	test();

	system("pause");
	return 0;
}