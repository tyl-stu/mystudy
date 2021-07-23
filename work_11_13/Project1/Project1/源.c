#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a = 2;
	int *p = a;
	int *q = &a;
	char *c = "abcd";
	printf("%d : \n", p);
	printf("%d : %p\n", *q, q);
	printf("%c : %p\n", *c, c);
	system("pause");
	return 0;
}

//将一个数组中的奇数放在前，偶数放在后
//void  swap(int *a,int len)
//{
//	int *left = a;
//	int *right = (a + len - 1);
//	while (left < right)
//	{
//		//从前往后找偶数
//		while ((left < right) && (*left % 2 != 0))
//		{
//			left++;
//		}
//		//从后往前找奇数
//		while ((left < right) && (*right % 2 == 0))
//		{
//			right--;
//		}
//		//将前后位的奇偶交换位置，前半为奇，后半为偶
//		if (left < right)
//		{
//			int t = *left;
//			*left = *right;
//			*right = t;
//		}
//	}
//
//}
//void swap1(int arr[], int n)
//{
//	int ou[50] = { 0 },ji[50] = { 0 }, all[50] = { 0 };
//	static int j1 = 0, j2 = 0;
//	for (int i = 0; i < n; i++)
//	{
//		if (arr[i] % 2 == 0)
//		{
//			ou[j1] = arr[i];
//			j1++;
//		}
//		else
//		{
//			ji[j2] = arr[i];
//			j2++;
//		}
//	}
//	for (int i = 0; i < j2; i++)
//	{
//		printf("%d ", ji[i]);
//		all[i] = ji[i];
//	}printf("\n");
//	for (int i = 0; i < j1; i++)
//	{
//		printf("%d ", ou[i]);
//		all[j2 + i] = ou[i];
//	}printf("\n");
//	
//	for (int i = 0; i < j1 + j2; i++)
//	{
//		printf("%d ", all[i]);
//	}printf("\n");
//
//}
//int main()
//{
//	int arr[8] = { 0 };//
//	printf("输入数组：>");
//	for (int i = 0; i < 8;i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	for (int i = 0; i < 8; i++)
//	{
//		printf("%d ", arr[i]);
//	}printf("\n");
//	int l = sizeof(arr) / sizeof(arr[0]);
//	swap(arr, 8);
//	for (int i = 0; i < 8; i++)
//	{
//		printf("%d ", arr[i]);
//	}printf("\n");
//	system("pause");
//	return 0;
//}
//***********************************************************************************************
//************************************************************************************************
//关于自定义函数返回数组之简单练习
//int *www(int *a, int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d ", *(a+i));
//	}printf("\n");
//	return a;//返回了数组的首地址，不需要用 *a
//}
//int *vvv(int n)
//{
//	int *m = &n;
//	printf("%d ", m);
//	return m;
//}
//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5 };
//	int *brr = www(arr, 5);  //此处的 brr 相当于赋值 了函数中返回数组的地址
//	for (int i = 0; i < 5; i++)
//	{
//		printf("%d ", *(brr+i));
//	}
//	
//	printf("\n");
//	system("pause");
//	return 0;
//}
//***********************************************************************************************
//************************************************************************************************
//模拟 strcpy()
//strcpy(a,b)将b中的字符串复制给a
//void strcpy1(char *a, char *b)
//{
//	int  i = 0;
//	while (*(b + i) != '\0')
//	{
//		*(a + i) = *(b + i);
//		i++;
//	}
//	*(a + i ) = '\0';
//}
//int main()
//{
//		
//	printf("输入 a 字符串：>");
//	char *arr = (char *)malloc(50);
//	scanf("%s", arr);
//	printf("%s \n", arr);
//	printf("输入 b 字符串：>");
//	char *brr = (char *)malloc(50);
//	scanf("%s", brr);
//	printf("%s \n", brr);
//	strcpy1(arr, brr);
//	printf("strcpy(a,b) = %s\n", arr);
//	free(arr);
//	free(brr);
//	system("pause");
//	return 0;
//}
//****************************************************************
//模拟strlen()
//int strlen1(char *p)
//{
//	int i = 0;
//	int count = 0;
//	while (*(p++) != '\0')
//	{
//		count++;
//		//i++;
//	}
//	return count;
//}
//int main()
//{
//	printf("输入一个字符串：>");
//	char arr[50] = { 0 };
//	scanf("%s", arr);
//	printf("%s \n", arr);
//	int count = strlen1(arr);
//	printf("字符串长度: %d\n", count);
//	system("pause");
//	return 0;
//}
//*******************************************************8
//程序死循环解释
//此题详解可见 bite 11月13日的作业
//int main()
//{
//	//此程序有两个问题  1、越界(因为数组只有10位，但循环了12次，所以会越界)  2、死循环
//	//死循环是因为  存放i的地址与arr[9]的地址差8个字节，即2个整形变量
//	//当循环到第12次时，arr[12]=0会将i的值置为0，从而导致死循环
//
//	int j = 0;
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	for (int i = 0; i <= 12; i++)
//	{
//		arr[i] = 0;
//		printf("hello bit\n");
//	}
//	system("pause");
//	return 0;
//}
//**********************************************************************************
//喝汽水问题 --- 此问题可简化为等差数列，即 2*n-1
//int sum(int n)
//{
//	int ret = n;
//	int t = 0;
//	while (n)
//	{
//		if (n % 2 != 0)
//		{
//			t++;
//		}
//		if (t > 1 && t % 2 == 0)
//		{
//			ret = ret + 1;
//		}
//		n = n / 2;
//		ret = ret + n;
//	}
//	
//	return ret;
//}
//int main()
//{
//	printf("输入钱数：>");
//	int r;
//	scanf("%d", &r);
//	int ret = sum(r);
//	printf("所喝汽水的个数为：%d \n", ret);
//	system("pause");
//	return 0;
//}