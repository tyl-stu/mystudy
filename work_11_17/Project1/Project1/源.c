#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//有一个数字矩阵，矩阵的每行从左到右是递增的，矩阵从上到下是递增的，请编写程序在这样的矩阵中查找某个数字是否存在。
//void findnum(int(*p)[3], int r, int c, int num)
//{
//	//针对每行或每列一次加1的数组
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
//	//针对每行或每列一次加1的数组
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
//实现一个函数，可以左旋字符串中的k个字符。
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
//	printf("输入原始字符串:>");
//	char *arr = (char *)malloc(50);
//	scanf("%s", arr);
//	printf("输入要左旋的个数:>");
//	int n;
//	scanf("%d", &n);
//	printf("原字符串：%s\n", arr);
//
//	xuan(arr, n);
//	printf("现字符串：%s\n", arr);
//
//	system("pause");
//	return 0;
//}
//***************************************************************************
//判断一个字符串是否为另外一个字符串旋转之后的字符串。
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
//	printf("输入原始字符串:>");
//	char *arr = (char *)malloc(50);
//	scanf("%s", arr);
//	//printf("%s ", arr);
//	printf("输入判断字符串:>");
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
////qosrt库函数的使用，得自行设定比较函数
//int int_cmp(const void * p1, const void * p2)
//{
//	//strcmp(*(char *)p1 ,*(char *)p2) 只是在比较地址大小
//	//strcmp(*(char **)p1 ,*(char **)p2) 比字符串大小
//	return strcmp(*(char **)p1 ,*(char **)p2);
//}
//int int_cmp_2(const void * p1, const void * p2)
//{
//	return (*(int *)p1 - *(int *)p2);
//}
//int main()
//{
//	//利用 qsort() 函数给字符串数组排序
//	// 字符串数组相当于二维数组，所以正常定义时需添加 * 
//	// 且因为此处是指针类型，所以在 int_cmp() 中用了双*，即将p1强制转化为(char **)
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
//	//利用 qsort() 函数给整形数组排序
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
//自模拟qsort()函数，只是用于排序数字
//int cmp(const void *p1, const void *p2)
//{
//	return (*(int *)p1 - *(int *)p2);
//}
//void swap(void *p1, void *p2)
//{
//	
//	// 只是用于交换数字的
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
//// 模拟qsort()函数
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
//void myqsort(void *a, int n, int size, int (*cmp)(void *, void *))//回调函数
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
