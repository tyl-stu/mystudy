#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//��ӡ����
//void printup(int l)
//{
//	for (int i = 0; i <= l; i++)
//	{
//		for (int j = 0; j <= l-i-1; j++)
//		{
//			printf(" ");
//		}
//		for (int j = 0; j < 2*(i+1)-1; j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//}
//void printdown(int l)
//{
//	for (int i = l-1; i >= 0; i--)
//	{
//		for (int j = 0; j <= l - i-1; j++)
//		{
//			printf(" ");
//		}
//		for (int j = 0; j < 2 * (i + 1) - 1; j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	printf("��������:>");
//	int l;
//	scanf("%d", &l);
//	printup(l);
//	printdown(l);
//	system("pause");
//	return 0;
//}
//*********************************************************
//��ӡˮ�ɻ���
//void print()
//{
//	printf("ˮ�ɻ����У�>");
//	for (int i = 0; i <= 100000; i++)
//	{
//		int g = i % 10, s = i % 100 / 10;
//		int q = i % 1000 / 100, w = i / 1000;
//		int sum = g*g*g + s*s*s + q*q*q + w*w*w;
//		if (i == sum)
//		{
//			printf("%d ", i);
//		}
//	}
//	printf("\n");
//}
//int main()
//{
//	print();
//	system("pause");
//	return 0;
//}
//***************************************************************
//�����еĺ�
//void value(int *p,int len)
//{
//	int j = 0;
//	for (int i = 0; i < len; i++)
//	{
//		j = j * 10 + 2;
//		*(p + i) = j;
//	}
//	/*for (int i = 0; i < len; i++)
//	{
//		printf("%d ",*(p + i));
//	}*/
//	
//}
//int sum(int *p, int len)
//{
//	int ret = 0;
//	for (int i = 0; i < len; i++)
//	{
//		ret += *(p + i);
//	}
//	return ret;
//}
//
//int main()
//{
//	
//	int n,ret;
//	printf("����ĸ���:>");
//	scanf("%d", &n);
//	int *arr = (int *)malloc(n);
//	value(arr,n);
//	ret = sum(arr, n);
//	printf("���еĺ� = %d \n", ret);
//	system("pause");
//	return 0;
//}
//*********************************************************8
//�ַ�������
//void reverse1(char *p)
//{
//	int len = strlen(p);
//	//printf("%d", len);
//	char *left = p;
//	char *right = p + len - 1;
//	while (left < right)
//	{
//		char t = *left;
//		*left = *right;
//		*right = t;
//
//		left++;
//		right--;
//	}
//	/*char t = *p;
//	*p = *(p + len - 1);
//	*(p + len - 1 )= '\0';
//	if (*(p + 1) != '\0')
//		reverse1(p + 1);
//	*(p + len - 1) = t;*/
//	printf("%s\n", p);
//}
//int main()
//{
//	printf("����һ���ַ���:>");
//	char n[50] = {0};
//	scanf("%s", n);
//	printf("%s\n", n);
//	reverse1(n);
//	printf("%s\n", n);
//	system("pause");
//	return 0;
//}
//**************************************************************
//ʹ��ָ���ӡ��������
//void func(int *p,int n)
//{
//	printf("�������ݣ�>");
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//	printf("\n");
//}
//int main()
//{
//	int arr[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//	int n = sizeof(arr) / sizeof(arr[0]);
//	//int *p = &arr;
//	func(arr,n);
//	system("pause");
//	return 0;
//}
//*****************************************************************
//����������������������ʱ������
//void swap(int a, int b)
//{
//	a = a^b;
//	b = a^b;
//	a = a^b;
//	printf("a = %d,b = %d\n", a, b);
//
//}
//int main()
//{
//	int a, b;
//	printf("input two num:>");
//	scanf("%d %d", &a, &b);
//	printf("a = %d,b = %d\n", a, b);
//	swap(a, b);
//	system("pause");
//	return 0;
//}
//****************************************************************
//ͳ�ƶ�����������1�ĸ���
//int fun(int a)
//{
//	int count = 0;
//	for (int i = 0; i < 32; i++)
//	{
//		if ((a>>i)&1==1)
//		{
//			count++;
//		}
//	}
//	//��������
//	while (a)
//	{
//		a = a&(a - 1);
//		count++;
//	}
//	return count;
//}
//
//int main()
//{
//	printf("input a number:>");
//	int n;
//	scanf("%d", &n);
//	int ret = fun(n);
//	printf("1�ĸ���Ϊ��%d\n", ret);
//	system("pause");
//	return 0;
//}
//********************************************************************
////��ӡ���������Ƶ�����λ��ż��λ
//void print(int n)
//{
//	printf("����λ��");
//	for (int i = 31; i > 0; i -= 2)
//	{
//		printf("%d ", (n >> i) & 1);
//	}
//	printf("\n");
//	printf("ż��λ��");
//	for (int i = 30; i >= 0; i -= 2)
//	{
//		printf("%d ", (n >> i) & 1);
//	}
//	printf("\n");
//
//}
//int main()
//{
//	int n;
//	printf("input a number:>");
//	scanf("%d", &n);
//	print(n);
//	system("pause");
//	return 0;
//}
//***********************************************************
////�������������в�ͬλ�ĸ���
//int snum(int i, int j)
//{
//	int t = i^j;
//	int count = 0;
//	while(t)
//	{
//		t = t&(t - 1);
//		count++;
//	}
//	return count;
//}
//
//int main()
//{
//	int a, b ,n;
//	printf("����������:>");
//	scanf("%d %d", &a, &b);
//	n = snum(a, b);
//	printf("��ͬ�ĸ���:%d\n", n); 
//	system("pause");
//	return 0;
//}