#include<iostream>
using namespace std;
#include<stdio.h>

//实现判断素数
//void func()
//{
//	int a = 100, b = 200;
//	int i = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		int j = 0;
//		for (j = 2; j <= i; j++)
//		{
//			if (i%j == 0)
//			{
//				break;
//			}
//
//		}
//		if (j == i)
//		{
//			printf("%d\n", j);
//		}
//
//	}
//}
//*******************************************
//   实现判断素数
//bool func(int a)
//{
//	int i = 0;
//	if (a > 2)
//	{
//		for (i = 2; i <= a; i++)
//		{
//			if (a%i == 0)
//			{
//				break;
//			}
//		}
//		if (i == a)
//		{
//			return true;
//		}
//		else
//		{
//			return false;
//		}
//	}
//	
//}
//
//int main()
//{
//	int a = 3;
//	for (int j = 100; j <= 200; j++)
//	{
//		if (func(j))
//		{
//			printf("%d\n", j);
//		}
//
//	}
//	
//	system("pause");
//	return 0;
//}

//void func(int y)
//{
//	if ((y % 400 == 0) || (y % 4 == 0 && y % 100 != 0))
//	{
//		printf("是闰年\n");
//	}
//	else
//		printf("不是\n");
//}

int *func(int ar[], int n)
{
	int t;
	t = ar[0];
	ar[0] = ar[n - 1];
	ar[n - 1] = t;

	return ar;
}

//void func(int a)
//{
//	for (int i = 1; i <= a; i++)
//	{
//		for (int j = i; j <= a; j++)
//		{
//			printf("%d * %d = %d\t", i, j, i*j);
//		}
//		printf("\n");
//	}
//}

int main()
{
	/*int year = 0;
	printf("输入年份：>");
	scanf_s("%d", &year);
	func(year);*/

	int a, b;
	printf("input two number:>");
	scanf_s("%d %d", &a, &b);
	int ar[] = { 0 };
	
	ar[0] = a; ar[1] = b;
	printf("a = %d,b = %d\n", ar[0], ar[1]);
	int *br = func(ar, 2);
	printf("a = %d,b = %d\n", *br,*(br+1));


	/*int a = 0;
	printf("input a number:>");
	scanf_s("%d", &a);
	func(a);
*/
	system("pause");
	return 0;
}