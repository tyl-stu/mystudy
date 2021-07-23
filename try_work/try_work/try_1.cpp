#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;
//#include<stdlib.h>
//#include<stdio.h>
//#include<time.h>
#include<windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//int jieche(int n)
//{
//	int m, a = 1;
//	if (n == (0 || 1))
//	{
//		printf("该数的阶乘 = 1 \n");
//		return 1;
//	}
//	else
//	{
//		m = n;
//		for (int i = 1; i <=m; i++)
//		{
//			a = a*n ;
//			n--;
//		}
//		printf("该数的阶乘 = %d\n", a);
//		return a;
//	}
//}

void ui()
{
	printf("***********\n");
	printf("服务类型：\n");
	printf(" 0:退出\n");
	printf(" 1:注册\n");
	printf(" 2:登录\n");
	printf("***********\n");
}
char zhuce()
{
	char num[100] = { 0 };
	char key[100] = { 0 };
	char arr[2];
	
	printf("账号:");
	scanf("%s", num);
	printf("密码:");
	scanf("%s", key);
	cout << endl;
	cout << num << endl << key << endl;
	arr[0] = *num;
	
	return *arr;
	//return 1;
}

int main()
{
	
	/*
	//动态开辟空间 malloc 释放 free
	int *p = (int *)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++)
	{
		p[i] = i;
	}
	for (int i = 0; i < n; i++)
	{
		printf("%d\n", p[i]);
	}
	free(p);*/
	
	ui();
	int n;
	printf("请选择服务：>\n");
	scanf("%d", &n);
	//int a;
	char a[2];
	switch (n)
	{
	case 0:
		printf("系统正在退出.....\n");
		break;
	case 1:
		a[2] = zhuce();
		break;
	case 2:
		break;
	default:
		break;

	}
	cout << "hahj" << endl;
	cout << a[0] << endl << a[1] << endl;
	//// 字符串从两边向中间移动
	//char arr1[] = "hello *******";
	//char arr2[] = "******* world";
	//int len1 = (sizeof(arr1) / sizeof(arr1[0])) - 2;
	//int len2 = (sizeof(arr2) / sizeof(arr2[0])) - 2;
	//char a, b;
	//while (1)
	//{
	//	printf("%s %s\n", arr1, arr2);
	//	for (int j = len1; j>0; j--)
	//	{
	//		b = arr1[j - 1];
	//		arr1[j - 1] = arr1[j];
	//		arr1[j] = b;
	//	}
	//	for (int i = 0; i<len2; i++)
	//	{
	//		a = arr2[i];
	//		arr2[i] = arr2[i + 1];
	//		arr2[i + 1] = a;
	//	}
	//	Sleep(1000);
	//}
	//*******************************************************
	//// 求 1!+2!+3!+...+10! = ？
	//int t = 0;
	//for (int i = 1; i <= 10; i++)
	//{
	//	t = t + jieche(i);
	//}
	//printf("1!+2!+3!+...+10! = %d\n", t);
	//***********************************************************
	////阶乘
	//while (1)
	//{
	//	printf("输入一个数：>");
	//	int n,m, a=1;
	//	scanf_s("%d", &n);
	//	if (n == (0 || 1))
	//	{
	//		printf("该数的阶乘 = 1 \n");
	//	}
	//	else
	//	{
	//		m = n;
	//		for (int i = 1; i <m; i++)
	//		{
	//			//a = a*n ;
	//			//n--;
	//			n = n*(m - i);
	//		}
	//		printf("该数的阶乘 = %d\n", n);
	//	}
	//}
	//******************************************
	// 二分法找数
	//int arr[] = {0, 11, 22, 33, 44, 55, 66, 77, 88, 99, 100 };
	//int right = sizeof(arr) / sizeof(arr[0])-1;
	//int left = 0, mid = 0;
	//printf("r=%d\n", right);
	//printf("输入数：>");
	//int a;
	//scanf_s("%d",&a);
	//while (left<=right)
	//{
	//	mid = (right - left) / 2 + left;
	//	if (a < arr[mid])
	//	{
	//		right = mid-1;	
	//		//continue; //continue 可用可不用
	//	}
	//	if (a > arr[mid])
	//	{
	//		left = mid+1;
	//		//continue;
	//	}
	//	else if (a == arr[mid])
	//	{
	//		printf("该数的下标为：%d\n", mid);
	//		break;
	//	}
	//
	//}
	//if (left > right)
	//{
	//	printf("没有这个数！\n");
	//	
	//}
	////*****************************************************
	////猜数字
	//srand(time(0));
	//int num = rand() % 100 + 1;//产生1~100内随机数字
	//printf("目标数字是:%d\n", num);
	//int a = 0;
	//while (1)
	//{
	//	printf("请随意输入一个1~100范围内的数字：>");
	//	scanf_s("%d", &a);
	//	if (a > num)
	//	{
	//		printf("大了\n");
	//	}
	//	else if (a < num)
	//	{
	//		printf("小了\n");
	//	}
	//	else
	//	{
	//		printf("猜对了，数字是：%d\n", num);
	//		break;
	//	}
	//}
	/*
	//乘法口诀
	for (int i = 1; i < 10; i++)
	{
		for (int j = i; j < 10; j++)
		{
			printf("%d * %d = %d\t",i, j, i*j);
		}
		printf("\n");
	}*/
	/*
	//十个数里找最大
	int a[10] = { 0 };
	int i = 0;
	int max = 0;
	for (i = 0; i<10; i++)
	{
		scanf("%d", &a[i]);
	}
	max = a[0];
	for (i = 1; i<10; i++)
	{
		if (a[i]>max)
			max = a[i];
	}
	printf("max = %d\n", max);*/
	/*float a = 0.0,b=0.0,c=0.0;
	for (int i = 1; i <= 100; i++)
	{
		if (i % 2 == 0)
		{
			a += 1.0 / i;
		}
		else
		{
			b += 1.0 / i;
		}
	}
	c = b - a;
	printf("%.6f\n",c);*/
	/*int i = 0;
	double sum = 0.0;
	int flag = 1;
	for (i = 1; i <= 100; i++)
	{
		sum += flag*1.0 / i;
		flag = -flag;
	}
	printf("%lf\n", sum);*/
	////1~100中9的个数
	//int j = 0;
	//for (int i = 1; i < 100; i++)
	//{
	//	
	//	if (i / 10 == 9)
	//	{
	//		j += 1;
	//	}
	//	if (i % 10 == 9)
	//	{
	//		j += 1;
	//	}
	//}
	//printf("9的个数 = %d\n", j);
	//***************************************
	//求素数
	//int i = 0;
	//int a = 0;
	//// 外层循环用来获取100~200之间的所有数据，100肯定不是素数，因此i从101开始
	//for (i = 101; i <= 200; i++)
	//{
	//	//判断i是否为素数：用[2, i)之间的每个数据去被i除，只要有一个可以被整除，则不是素数
	//	int j = 0;
	//	for (j = 2; j<i; j++)
	//	{
	//		if (i%j == 0)
	//		{
	//			break;
	//		}
	//	}
	//	// 上述循环结束之后，如果j和i相等，说明[2, i）之间的所有数据都不能被i整除，则i为素数
	//	if (j == i)
	//	{
	//		a++;
	//		printf("%d ", i);
	//	}
	//}。
	//************************************************
	////打印荣年
	//for (int i = 1000; i <= 2000; i++)
	//{
	//	if (i % 400 == 0 || (i % 4 == 0 && i % 100 != 0))
	//	{
	//		printf("闰年：%d\n", i);
	//	}
	//}
	//**************************************************
	////打印荣年
	//for (int i = 1000; i <= 2000; i++)
	//{
	//	if (i % 400 == 0 || (i % 4 == 0 && i % 100 != 0))
	//	{
	//		printf("闰年：%d\n", i);
	//	}
	//}
	////输出两数的最大公约数
	//int a, b;
	//scanf_s("%d %d", &a, &b);
	//int c;
	//printf("%d 和 %d 的最大公约数为：",a,b);
	//while (c = a%b)
	//{
	//	a = b;
	//	b = c;
	//}
	//printf("%d \n", b);
	/*for (int i = 0; i<100; i++)

	{

		if (i % 3 == 0)

		{

			printf("%d ", i);

		}

	}*/
	/*
	//比大小
	int a, b, c;
	printf("请输入三个数:>");
	scanf_s("%d %d %d", &a, &b, &c);
	int t;
	if (a < b)
	{
		t = b;b = a;a = t;		
	}
	if (a < c)
	{
		t = c; c = a; a = t;
	}
	if (b < c)
	{
		t = c; c = b; b = t;
	}
	printf("a:%d,b:%d,c:%d\n", a, b, c);*/
	/*int max, mid, min;
	max = a;
	if (max < b)
	{
		max = b;
		mid = a;
		if (max < c)
		{
			max = c; mid = b; min = a;
			printf("从大到小排列为：%d > %d > %d\n", max, mid, min);
		}
		else if (mid < c)
		{
			max = b; mid = c; min = a;
			printf("从大到小排列为：%d > %d > %d\n", max, mid, min);
		}
		else
		{
			max = b; mid = a; min = c;
			printf("从大到小排列为：%d > %d > %d\n", max, mid, min);
		}
	}
	else if (max < c)
	{
		max = c;
		mid = a;
		if (max < b)
		{
			max = b; mid = c; min = a;
			printf("从大到小排列为：%d > %d > %d\n", max, mid, min);
		}
		else if (mid < b)
		{
			max = c; mid = b; min = a;
			printf("从大到小排列为：%d > %d > %d\n", max, mid, min);
		}
		else
		{
			max = c; mid = a; min = b;
			printf("从大到小排列为：%d > %d > %d\n", max, mid, min);
		}
	}
	else
	{
		max = a;
		
		if (b>c)
		{
			mid = b; min = c;
			printf("从大到小排列为：%d > %d > %d\n", max, mid, min);
		}
		else
		{
			mid = c; min = b;
			printf("从大到小排列为：%d > %d > %d\n", max, mid, min);
		}
	}*/

	system("pause");
	return 0;
}