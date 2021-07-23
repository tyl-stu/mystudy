#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

#include<stdio.h>
#include<stdlib.h>

//交换两个数组的值
//void print(int a[], int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d ", a[i]);
//	}
//	printf("\n");
//}
//int main()
//{
//	int a[5] = { 0, 0, 0, 0, 0 };
//	int b[5] = { 1, 2, 3, 4, 5 };
//	
//	int n1 = sizeof(a) / sizeof(a[0]);
//	int n2 = sizeof(b) / sizeof(b[0]);
//	print(a, n1);
//	print(b, n2);
//	if (n1 == n2)
//	{
//		for (int i = 0; i < n1; i++)
//		{
//			int t = a[i];
//			a[i] = b[i];
//			b[i] = t;
//		}
//	}
//	print(a, n1);
//	print(b, n2);
//	system("pause");
//	return 0;
//}
//************************************************************
////数组逆置
//void init(int a[],int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		a[i] = 0;
//	}
//}
//void scanf_arr(int a[], int n)
//{
//	printf("输入数:>");
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d", &a[i]);
//	}
//}
//void print(int a[], int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d ", a[i]);
//	}
//	printf("\n");
//}
//void reverse1(int a[], int n)
//{
//	for (int i = 0; i < n / 2; i++)
//	{
//		int t = a[i];
//		a[i] = a[n - i- 1];
//		a[n- i - 1] = t;
//	}
//}
//
//
//int main()
//{
//	int n;
//	printf("请输入数组的元素数:>");
//	scanf("%d", &n);
//	int *arr = (int *)malloc(n);
//	init(arr,n);//数组初始化
//	scanf_arr(arr, n);//修改数组的值
//	reverse1(arr,n);//数组逆置
//	print(arr, n);//数组打印
//
//	system("pause");
//	return 0;
//}
//*******************************************
//冒泡排序
//void order(int a[],int n)
//{
//	for (int j = 0; j<n; j++)
//	{
//		for (int i = j; i<n; i++)
//		{
//			if (a[j]>a[i])//从小到大
//			{
//				int t = a[j];
//				a[j] = a[i];
//				a[i] = t;
//			}
//		}
//		
//	}
//	
//}
//
//int main()
//{
//	printf("所输一组数的个数：>");
//	int n;
//	scanf("%d", &n);
//	int *arr=(int *)malloc(n);
//	printf("输入数:>");
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	
//	order(arr,n);
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	//free(arr);
//	system("pause");
//	return 0;
//}
//*****************************************************************
////无递归求斐波那契数
//void nonum(int n)
//{
//	int *p = (int *)malloc(n);
//	if (n > 2)
//	{
//		*p = 1;
//		*(p + 1) = 1;
//		for (int i = 2; i < n; i++)
//		{
//			*(p + i) = *(p + i - 2) + *(p + i - 1);
//		}
//	}
//	else if (n == 2)
//	{
//		*(p + 1) = 1;
//	}
//	printf("%d\n", *(p + n - 1));
//	//free(p);
//}
//
////有递归求斐波那契数
//int yanum(int n)
//{
//	if (n > 2)
//	{
//		return yanum(n - 1) + yanum(n - 2);
//
//	}
//	else
//		return 1;
//}
//
//int main()
//{
//	printf("请输入一个数：>");
//	int n;
//	scanf("%d", &n);
//	nonum(n);
//	int s = yanum(n);
//	printf("s = %d\n", s);
//	system("pause");
//	return 0;
//}
//********************************************************************
////用递归实现n的k次方
//int multi(int n, int k)
//{
//	if (k > 0)
//	{
//		return n*multi(n, --k);
//	}
//	else
//		return 1;
//	
//}
//
//int main()
//{
//	printf("输入底数：>");
//	int n;
//	scanf("%d", &n);
//	printf("输入次数：>");
//	int k;
//	scanf("%d", &k);
//	int x;
//
//	x = multi(n, k);
//	printf("x = %d\n", x);
//
//	system("pause");
//	return 0;
//}
//*****************************************************************
//求一个数字的各位相加之和
//int  DigitSum(int n)
//{
//	if (n != 0)
//	{
//		int a = n % 10;
//		int sum = a + DigitSum(n / 10);
//		return sum;
//	}
//	else
//		return 0;
//
//}
//
//int main()
//{
//	int n=0; int s;
//	printf("请输入一个非负整数：>");
//	scanf("%d", &n);
//
//	s = DigitSum(n);
//	printf("sum = %d\n", s);
//	system("pause");
//	return 0;
//}
//************************************************************
////三种方法实现字符串逆置
//void reverse_string_1(char * str)
//{
//	printf("%s\n", str);
//	int l = strlen(str);
//	//printf("l = %d\n", l);
//	char *left = str;
//	char *right = str + l - 1;
//	printf("left = %s\n", left);
//	printf("right = %s\n", right);
//	while (left < right)
//	{
//		char t;
//		t = *left;
//		*left = *right;
//		*right = t;
//		printf("left_swap = %s\n", left);
//		printf("right_swap = %s\n", right);
//		
//		left++;
//		right--;
//		printf("left_1 = %s\n", left);
//		printf("right_1 = %s\n", right);
//		
//	} 
//	//printf("无递归：%s\n", str);
//	
//}
//
//void reverse_string(char * str) 
//{
//	int len = strlen(str);
//	char tmp = *str;
//	*str = *(str + len - 1);
//	
//	*(str + len - 1) = '\0';
//	if (strlen(str + 1) >= 2)
//		reverse_string(str + 1);
//
//	*(str + len - 1) = tmp;
//	
//	/*printf("有递归：%s", str);*/
//	
//}
//
//void reverse_string_2(char *str)
//{
//	int len = strlen(str);
//	for (int i = 0; i < len / 2; i++)
//	{
//		//char a = *(str + len - i);
//
//		char t = *(str+i);
//		*(str + i) = *(str + len - i-1);
//		*(str + len - i-1) = t;
//		
//		/*printf("str = %s\n", str + i);
//		printf("str+len-i=%s\n", str+len-i-1);*/
//	}
//	//printf("%s\n", str);
//}
//int main()
//{
//	//char *p = malloc(100);
//	char p[100];
//	printf("请输入一个字符串:>");
//	scanf("%s",p);
//	//reverse_string_1(p);//无递归  有些麻烦
//	//reverse_string_2(p);//无递归  简单
//	reverse_string(p);//有递归
//	printf("逆置后字符串为：%s", p);
//	system("pause");
//	return 0;
//} 
////*************************************************************************************
////有递归 无递归 求取字符串长度
//int func_1(const char *c)
//{
//	if (*c == '\0')
//	{
//		return 0;
//	}
//	else
//	{
//		return 1 + func_1(c + 1);
//	}
//}
//
//int func_2(const char *c)
//{
//	int i = 0;
//	while (*c != '\0')
//	{
//		i += 1;
//		c += 1;
//	}
//	return i;
//}
//
//int main()
//{
//	//char *p = "abcdefgh";
//	//char p[100];
//	char *p = malloc(100);
//	printf("请输入一个字符串：>");
//	scanf("%s", p);
//	printf("字符串：%s\n", p);
//	int v1,v2;
//	v1 = func_1(p);// 有递归
//	printf("有递归：%s 的字符长度为：%d\n",p, v1);
//	v2 = func_2(p);
//	printf("无递归：%s 的字符长度为：%d\n", p, v2);
//	free(p);
//	system("pause");
//	return 0;
//}
//********************************************************************
// 有递归、无递归 求阶乘
//int func_1(int m)
//{
//	if (m <= 1)
//		return 1;
//	else
//		return m*func_1(m - 1);
//}
//
//int func_2(int m)
//{
//	if (m <= 1)
//	{
//		return 1;
//	}
//	else
//	{
//		int j = 1;
//		for (int i = 1; i <= m; i++)
//		{
//			j *= i;
//		}
//		return j;
//	}
//}
//
//int main()
//{
//	int n,v1,v2;
//	printf("请输入一个整数:>");
//	scanf("%d", &n);
//
//	v1 = func_1(n); //有递归
//	printf("递归 ：%d 的阶乘为 %d\n", n,v1);
//	v2 = func_2(n); //无递归
//	printf("无递归 ：%d 的阶乘为 %d\n", n, v2);
//	system("pause");
//	return 0;
//}
// *********************************************************
////打印一个整数的每一位
//void func(unsigned int j)
//{
//	if (j / 10 != 0)
//	{
//		func(j / 10);
//	}
//	printf("%d\n", j % 10);
//}
//
//int main()
//{
//	unsigned int i;
//	printf("请输入一个整数：>");
//	scanf("%d", &i);
//	func(i);
//	system("pause");
//	return 0;
//}