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
//		printf("�����Ľ׳� = 1 \n");
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
//		printf("�����Ľ׳� = %d\n", a);
//		return a;
//	}
//}

void ui()
{
	printf("***********\n");
	printf("�������ͣ�\n");
	printf(" 0:�˳�\n");
	printf(" 1:ע��\n");
	printf(" 2:��¼\n");
	printf("***********\n");
}
char zhuce()
{
	char num[100] = { 0 };
	char key[100] = { 0 };
	char arr[2];
	
	printf("�˺�:");
	scanf("%s", num);
	printf("����:");
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
	//��̬���ٿռ� malloc �ͷ� free
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
	printf("��ѡ�����>\n");
	scanf("%d", &n);
	//int a;
	char a[2];
	switch (n)
	{
	case 0:
		printf("ϵͳ�����˳�.....\n");
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
	//// �ַ������������м��ƶ�
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
	//// �� 1!+2!+3!+...+10! = ��
	//int t = 0;
	//for (int i = 1; i <= 10; i++)
	//{
	//	t = t + jieche(i);
	//}
	//printf("1!+2!+3!+...+10! = %d\n", t);
	//***********************************************************
	////�׳�
	//while (1)
	//{
	//	printf("����һ������>");
	//	int n,m, a=1;
	//	scanf_s("%d", &n);
	//	if (n == (0 || 1))
	//	{
	//		printf("�����Ľ׳� = 1 \n");
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
	//		printf("�����Ľ׳� = %d\n", n);
	//	}
	//}
	//******************************************
	// ���ַ�����
	//int arr[] = {0, 11, 22, 33, 44, 55, 66, 77, 88, 99, 100 };
	//int right = sizeof(arr) / sizeof(arr[0])-1;
	//int left = 0, mid = 0;
	//printf("r=%d\n", right);
	//printf("��������>");
	//int a;
	//scanf_s("%d",&a);
	//while (left<=right)
	//{
	//	mid = (right - left) / 2 + left;
	//	if (a < arr[mid])
	//	{
	//		right = mid-1;	
	//		//continue; //continue ���ÿɲ���
	//	}
	//	if (a > arr[mid])
	//	{
	//		left = mid+1;
	//		//continue;
	//	}
	//	else if (a == arr[mid])
	//	{
	//		printf("�������±�Ϊ��%d\n", mid);
	//		break;
	//	}
	//
	//}
	//if (left > right)
	//{
	//	printf("û���������\n");
	//	
	//}
	////*****************************************************
	////������
	//srand(time(0));
	//int num = rand() % 100 + 1;//����1~100���������
	//printf("Ŀ��������:%d\n", num);
	//int a = 0;
	//while (1)
	//{
	//	printf("����������һ��1~100��Χ�ڵ����֣�>");
	//	scanf_s("%d", &a);
	//	if (a > num)
	//	{
	//		printf("����\n");
	//	}
	//	else if (a < num)
	//	{
	//		printf("С��\n");
	//	}
	//	else
	//	{
	//		printf("�¶��ˣ������ǣ�%d\n", num);
	//		break;
	//	}
	//}
	/*
	//�˷��ھ�
	for (int i = 1; i < 10; i++)
	{
		for (int j = i; j < 10; j++)
		{
			printf("%d * %d = %d\t",i, j, i*j);
		}
		printf("\n");
	}*/
	/*
	//ʮ�����������
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
	////1~100��9�ĸ���
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
	//printf("9�ĸ��� = %d\n", j);
	//***************************************
	//������
	//int i = 0;
	//int a = 0;
	//// ���ѭ��������ȡ100~200֮����������ݣ�100�϶��������������i��101��ʼ
	//for (i = 101; i <= 200; i++)
	//{
	//	//�ж�i�Ƿ�Ϊ��������[2, i)֮���ÿ������ȥ��i����ֻҪ��һ�����Ա���������������
	//	int j = 0;
	//	for (j = 2; j<i; j++)
	//	{
	//		if (i%j == 0)
	//		{
	//			break;
	//		}
	//	}
	//	// ����ѭ������֮�����j��i��ȣ�˵��[2, i��֮����������ݶ����ܱ�i��������iΪ����
	//	if (j == i)
	//	{
	//		a++;
	//		printf("%d ", i);
	//	}
	//}��
	//************************************************
	////��ӡ����
	//for (int i = 1000; i <= 2000; i++)
	//{
	//	if (i % 400 == 0 || (i % 4 == 0 && i % 100 != 0))
	//	{
	//		printf("���꣺%d\n", i);
	//	}
	//}
	//**************************************************
	////��ӡ����
	//for (int i = 1000; i <= 2000; i++)
	//{
	//	if (i % 400 == 0 || (i % 4 == 0 && i % 100 != 0))
	//	{
	//		printf("���꣺%d\n", i);
	//	}
	//}
	////������������Լ��
	//int a, b;
	//scanf_s("%d %d", &a, &b);
	//int c;
	//printf("%d �� %d �����Լ��Ϊ��",a,b);
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
	//�ȴ�С
	int a, b, c;
	printf("������������:>");
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
			printf("�Ӵ�С����Ϊ��%d > %d > %d\n", max, mid, min);
		}
		else if (mid < c)
		{
			max = b; mid = c; min = a;
			printf("�Ӵ�С����Ϊ��%d > %d > %d\n", max, mid, min);
		}
		else
		{
			max = b; mid = a; min = c;
			printf("�Ӵ�С����Ϊ��%d > %d > %d\n", max, mid, min);
		}
	}
	else if (max < c)
	{
		max = c;
		mid = a;
		if (max < b)
		{
			max = b; mid = c; min = a;
			printf("�Ӵ�С����Ϊ��%d > %d > %d\n", max, mid, min);
		}
		else if (mid < b)
		{
			max = c; mid = b; min = a;
			printf("�Ӵ�С����Ϊ��%d > %d > %d\n", max, mid, min);
		}
		else
		{
			max = c; mid = a; min = b;
			printf("�Ӵ�С����Ϊ��%d > %d > %d\n", max, mid, min);
		}
	}
	else
	{
		max = a;
		
		if (b>c)
		{
			mid = b; min = c;
			printf("�Ӵ�С����Ϊ��%d > %d > %d\n", max, mid, min);
		}
		else
		{
			mid = c; min = b;
			printf("�Ӵ�С����Ϊ��%d > %d > %d\n", max, mid, min);
		}
	}*/

	system("pause");
	return 0;
}