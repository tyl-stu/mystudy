#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//��һ�����־��󣬾����ÿ�д������ǵ����ģ�������ϵ����ǵ����ģ����д�����������ľ����в���ĳ�������Ƿ���ڡ�
//void findnum(int(*p)[3], int r, int c, int num)
//{
//	//���ÿ�л�ÿ��һ�μ�1������
//	if ((*(p[0]) + (c - 1) + (r - 1)) >= num)
//	{
//		printf("in the a array\n");
//	}
//	else
//		printf("not in the a array\n");
//	//printf("%d", *(p[0]));
//}
//void findnum_2(int(*q)[3], int r, int c, int num)
//{
//	//���ÿ�л�ÿ��һ�μ�1������
//	if (num % 2 == 1)
//	{
//		if ((*(q[0]) + (c - 1)*2 + (r - 1)*2) >= num)
//		{
//			printf("in the b array\n");
//		}
//		else
//			printf("not in the b array\n");
//	}
//	else
//		printf("not in the b array\n");
//	//printf("%d", *(p[0]));
//}
//int main()
//{
//	int a[][3] = { { 1, 2, 3 }, { 2, 3, 4 }, { 3, 4, 5 } };
//	int b[][3] = { { 1, 3, 5 }, { 3, 5, 7 }, { 5, 7, 9 } };
//	printf("input a num(1~5):>");
//	int n;
//	scanf("%d", &n);
//	findnum(a, 3, 3, n);
//	findnum_2(b, 3, 3, n);
//	system("pause");
//	return 0;
//}
//**********************************************************
//ʵ��һ�����������������ַ����е�k���ַ���
//void xuan(char *p1, int s)
//{
//	int n = strlen(p1);
//	s = s%n;
//	for (int i = 0; i < s; i++)
//	{
//		for (int j = n-1; j > 0; j--)
//		{
//			char t = *p1;
//			*p1 = *(p1 + j);
//			*(p1 + j) = t;
//		}
//		
//	}
//}
//int main()
//{
//	printf("����ԭʼ�ַ���:>");
//	char *arr = (char *)malloc(50);
//	scanf("%s", arr);
//	printf("����Ҫ�����ĸ���:>");
//	int n;
//	scanf("%d", &n);
//	printf("ԭ�ַ�����%s\n", arr);
//
//	xuan(arr, n);
//	printf("���ַ�����%s\n", arr);
//
//	system("pause");
//	return 0;
//}
//***************************************************************************
//�ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ�����
//int judge(char *p1,char *p2)
//{
//	int n1 = strlen(p1), n2 = strlen(p2);
//	char y1 = p1; char y2 = p2;
//	printf("%s \n", p1);
//	printf("%s \n", p2);
//	
//	if (n1 == n2)
//	{
//		for (int i = 0; i < n1; i++)
//		{
//
//			for (int j = 0; j < n1; j++)
//			{
//				char t = *p1;
//				*p1 = *(p1 + j);
//				*(p1 + j) = t;
//
//			}
//			if (strcmp(p1, p2) == 0)
//			{
//				return 1;
//			}
//		}
//		return 0;
//	}
//	else
//		return 0;
//
//}
//
//int main()
//{
//	printf("����ԭʼ�ַ���:>");
//	char *arr = (char *)malloc(50);
//	scanf("%s", arr);
//	//printf("%s ", arr);
//	printf("�����ж��ַ���:>");
//	char *brr = (char *)malloc(50);
//	scanf("%s", brr);
//	//printf("%s ", brr);
//	int ret = judge(arr,brr);
//	printf("%d ",ret);
//	
//
//
//	system("pause");
//	return 0;
//}
//**************************************************************
////qosrt�⺯����ʹ�ã��������趨�ȽϺ���
//int int_cmp(const void * p1, const void * p2)
//{
//	//strcmp(*(char *)p1 ,*(char *)p2) ֻ���ڱȽϵ�ַ��С
//	//strcmp(*(char **)p1 ,*(char **)p2) ���ַ�����С
//	return strcmp(*(char **)p1 ,*(char **)p2);
//}
//int int_cmp_2(const void * p1, const void * p2)
//{
//	return (*(int *)p1 - *(int *)p2);
//}
//int main()
//{
//	//���� qsort() �������ַ�����������
//	// �ַ��������൱�ڶ�ά���飬������������ʱ����� * 
//	// ����Ϊ�˴���ָ�����ͣ������� int_cmp() ������˫*������p1ǿ��ת��Ϊ(char **)
//	char *arr[] = { "bbbb", "aaaa", "dddd", "cccc" ,"eeee"};
//	int n = sizeof(arr) / sizeof(arr[0]);
//	for (int i = 0; i < n; i++)
//	{
//		printf("%s ", arr[i]);
//	}printf("\n");
//	qsort(arr, n, sizeof(char *), int_cmp);
//	for (int i = 0; i <n; i++)
//	{
//		printf("%s ", arr[i]);
//	}printf("\n");
//
//	//���� qsort() ������������������
//	int arr2[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
//	int n2 = sizeof(arr2) / sizeof(arr2[0]);
//	for (int i = 0; i < n2; i++)
//	{
//		printf("%d ", arr2[i]);
//	}printf("\n");
//	qsort(arr2, n2, sizeof(int), int_cmp_2);
//	for (int i = 0; i <n2; i++)
//	{
//		printf("%d ", arr2[i]);
//	}printf("\n");
//
//	system("pause");
//	return 0;
//}
//*******************************************************************
//��ģ��qsort()������ֻ��������������
//int cmp(const void *p1, const void *p2)
//{
//	return (*(int *)p1 - *(int *)p2);
//}
//void swap(void *p1, void *p2)
//{
//	
//	// ֻ�����ڽ������ֵ�
//	if (*(int *)p1 > *(int *)p2)
//	{
//		int t = *(int *)p1;
//		*(int *)p1 = *(int *)p2;
//		*(int *)p2 = t;
//	}
//
//}
//void myqsort(void *a, int n, int(*cmp)(void *, void*))
//{
//	for (int i = 0; i < n - 1; i++)
//	{
//		for (int j = 0; j < n - 1 - i; j++)
//		{
//			if (cmp((int *)a + j, (int *)a + (j + 1)) > 0)
//			{
//				swap((int *)a + j, (int *)a + (j + 1));
//			}
//		}
//	}
//}
//
//int main()
//{
//	int arr[] = { 4, 8, 7, 5, 2, 9, 1, 3, 8, 0 };
//	
//	
//	int s = sizeof(arr) / sizeof(arr[0]);
//	for (int i = 0; i < s; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	myqsort(arr, s, cmp);
//	for (int i = 0; i < s; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}
//***************************************************************************8
//// ģ��qsort()����
//int cmp(const void *p1, const void *p2)
//{
//	return (*(int *)p1 - *(int *)p2);
//}
//
//void swap(void *p1, void *p2, int size)
//{
//	for (int i = 0; i < size; i++)
//	{
//		char tmp = *((char *)p1 + i);
//		*((char *)p1 + i) = *((char *)p2 + i);
//		*((char *)p2 + i) = tmp;
//	}
//}
//void myqsort(void *a, int n, int size, int (*cmp)(void *, void *))//�ص�����
//{
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n - 1 - i; j++)
//		{
//			if (cmp((char *)a + j*size, (char *)a + (j + 1)*size)>0)
//			{
//				swap((char *)a + j*size, (char *)a + (j + 1)*size, size);
//			}
//		}
//	}
//}
//
//int main()
//{
//	int arr[] = { 8, 7, 5, 9, 1, 4, 5, 3, 2, 0 };
//	//char arr[] = { 'b', 'c', 'a', 'd' };
//	int s = sizeof(arr) / sizeof(arr[0]);
//	printf("%d ", s);
//	for (int i = 0; i < s; i++)
//	{
//		printf("%d ", arr[i]);
//	}printf("\n");
//
//	myqsort(arr, s, sizeof(arr[0]), cmp);
//	for (int i = 0; i < s; i++)
//	{
//		printf("%d ", arr[i]);
//	}printf("\n");
//
//	system("pause");
//	return 0;
//}
